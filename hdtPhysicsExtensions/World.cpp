#include "World.h"

void errorReport(const char* ch, void* p)
{
	LogInfo("Havok Report\n%s", ch);
}

static const float* timeStamp = (float*)0x12E355C;

CWorld::CWorld(void)
{
	m_pWorld = 0;
	m_pMemoryRouter = 0;
	m_collisionFilter = 0;
	m_pCell = 0;

	m_suspended = 0;
	
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	m_pMemoryRouter = hkMemoryInitUtil::initDefault( hkMallocAllocator::m_defaultMallocAllocator, hkMemorySystem::FrameInfo( 128 * 1024 * 1024 ) );
	hkBaseSystem::init( m_pMemoryRouter, errorReport );
	m_threadInit.insert(GetCurrentThreadId());
		
	int numThreads = 1;
	hkHardwareInfo hwInfo;
	hkGetHardwareInfo(hwInfo);
	numThreads = hwInfo.m_numThreads*2;
	LogInfo("System run with %d threads", numThreads);

	hkJobQueueCinfo jobQueueInfo;
	jobQueueInfo.m_jobQueueHwSetup.m_numCpuThreads = numThreads+1;
	m_jobQueue = new hkJobQueue(jobQueueInfo);
	
	hkCpuJobThreadPoolCinfo jobPoolInfo;
	jobPoolInfo.m_numThreads = numThreads;
	m_jobThreadPool = new hkCpuJobThreadPool(jobPoolInfo);

	hkpWorldCinfo info;
	info.m_gravity.set(0, 0, -9.8);
	//info.m_gravity.set(0, 0, 0);
	info.setBroadPhaseWorldSize(1e+6);
	info.m_broadPhaseType = hkpWorldCinfo::BROADPHASE_TYPE_SAP;
	info.m_broadPhaseBorderBehaviour = hkpWorldCinfo::BROADPHASE_BORDER_DO_NOTHING;
	info.setupSolverInfo(hkpWorldCinfo::SOLVER_TYPE_8ITERS_HARD);
	info.m_simulationType = hkpWorldCinfo::SIMULATION_TYPE_MULTITHREADED;
	info.m_enableDeactivation = false;

	m_pWorld = new hkpWorld(info);
	m_pWorld->markForWrite();
	
	auto* pFilter = new hkpConstraintCollisionFilter(new MyGroupFilter);
	m_collisionFilter = pFilter;
	m_pWorld->setCollisionFilter(pFilter);
	pFilter->init(m_pWorld);

	hkpWorld::registerWithJobQueue(m_jobQueue);
	hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(m_pWorld, hkpConstraintAtom::METHOD_STABILIZED);
	hkpAgentRegisterUtil::registerAllAgents(m_pWorld->getCollisionDispatcher());
	
	m_pWorld->unmarkForWrite();
	
	m_timeLastUpdate = *timeStamp;

	LogInfo("Havok simulated world created.");
}

CWorld::~CWorld(void)
{
	m_pWorld->markForWrite();
	m_characters.clear();
	m_systems.clear();
	m_pWorld->removeAll();
	m_pWorld->removeReference();
	m_pWorld->unmarkForWrite();

	m_collisionFilter->removeReference();

	m_jobThreadPool->waitForCompletion();
	delete m_jobQueue;
	delete m_jobThreadPool;

	m_pWorld = 0;
	m_collisionFilter = 0;
	
	hkBaseSystem::quit();
	hkMemoryInitUtil::quit();
	m_pMemoryRouter = 0;
}

void CWorld::Suspend()
{
	m_suspended++;
}

void CWorld::Resume()
{
	--m_suspended;
}

void CWorld::SwitchToSeperateClock()
{
	m_lock.lock();
	m_useSeperatedClock = true;
	m_timeLastUpdate = clock()*0.001;
	m_lock.unlock();
}

void CWorld::SwitchToInternalClock()
{
	m_lock.lock();
	m_useSeperatedClock = false;
	m_timeLastUpdate = *timeStamp;
	m_lock.unlock();
}

CWorld* CWorld::getSingleton()
{
	static CWorld g_World;
	return &g_World;
}

void CWorld::InitThread()
{
	if(!hkMemoryRouter::getInstancePtr())
		hkBaseSystem::initThread(CWorld::getSingleton()->m_pMemoryRouter);
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
}

void CWorld::StepWorld(float interval)
{
	if(interval > 0.3) interval = 0.3;

	if(m_characters.size() || m_systems.size())
	{
		m_pWorld->markForWrite();
		for(auto& i : m_characters)
			i.second->WriteToWorld(1/interval);
		for(auto& i : m_systems)
		{
			i.second->AddToWorld(m_pWorld);
			i.second->WriteToWorld(1/interval);
		}
		m_pWorld->unmarkForWrite();
		
		/*m_pWorld->initMtStep(m_jobQueue, interval);
		m_jobThreadPool->processAllJobs(m_jobQueue);
		
		m_jobThreadPool->waitForCompletion();
		m_pWorld->finishMtStep();*/
		while(interval >= TIME_TICK*1.25)
		{
			m_pWorld->stepMultithreaded(m_jobQueue, m_jobThreadPool, TIME_TICK);
			interval -= TIME_TICK;
		}
		m_pWorld->stepMultithreaded(m_jobQueue, m_jobThreadPool, interval);
	
		m_pWorld->markForRead();
		for(auto& i : m_characters)
			i.second->ReadFromWorld();
		for(auto& i : m_systems)
			i.second->ReadFromWorld();
		m_pWorld->unmarkForRead();
	}
}

void CWorld::AddCharacter(int formID)
{
	//auto idx = std::find_if(m_characters.begin(), m_characters.end(),
	//	[=](std::shared_ptr<CCharacter> p)->bool{ return p->GetID() == formID; });
	auto idx = m_characters.find(formID);
	if(idx != m_characters.end())
		return;

	auto obj = std::shared_ptr<CCharacter>(new CCharacter(formID));
	if(obj->CreateIfValid())
	{
		LogInfo("Add character %08x", formID);
		m_characters.insert(std::make_pair(formID, obj));
		obj->AddToWorld(m_pWorld);
	}
}

void CWorld::ScanCell()
{
	auto player = DYNAMIC_CAST( LookupFormByID(0x14), TESForm, TESObjectREFR );
	if(!player) goto FAILED;
	auto cell = player->parentCell;
	if(!cell) goto FAILED;
	
	m_pWorld->markForWrite();
	if(m_pCell != cell)
	{
		LogInfo("Cell changed...");
		m_characters.clear();
		m_pCell = cell;

		for(auto& i : m_systems)
		{
			i.second->RemoveFromWorld();
			i.second->AddToWorld(m_pWorld);
		}
	}
	else
	{
		for(auto i=m_characters.begin(); i!=m_characters.end();)
		{
			auto form = i->first;
			auto object = (TESObjectREFR*)LookupFormByID(form);
			if(object->parentCell != cell)
			{
				LogInfo("%08x no longer in cell, release it", form);
				m_characters.erase(i++);
			}
			else if(!i->second->CreateIfValid())
			{
				LogInfo("%08x now invalid, release it", form);
				m_characters.erase(i++);
			}
			else (i++)->second->AddToWorld(m_pWorld);
		}

		for(int i=0; i<cell->objectList.count; ++i)
		{
			auto object = cell->objectList.arr.entries[i];
			if(DYNAMIC_CAST(object, TESObjectREFR, Actor))
				AddCharacter(object->formID);
		}
	}

	m_pWorld->unmarkForWrite();
	return;

FAILED:
	
	m_pWorld->markForWrite();
	m_characters.clear();
	m_pCell = 0;
	m_pWorld->unmarkForWrite();
}

void CWorld::ClearScene()
{
	m_lock.lock();
	m_pWorld->markForWrite();
	m_characters.clear();
	m_pCell = 0;
	for(auto& i : m_characters)
	{
		i.second->RemoveFromWorld();
		i.second->AddToWorld(m_pWorld);
	}
	for(auto& i : m_systems)
		i.second->RemoveFromWorld();
	m_pWorld->unmarkForWrite();
	m_timeLastUpdate = *timeStamp;
	m_lock.unlock();
}

#include "HookArmor.h"
#include "HookWeapon.h"
#include "HookHair.h"

#include "HookMemory.h"

void CWorld::DoUpdate()
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	if(m_suspended) return;
	
	//ScanHair();

	m_lock.lock();

	auto currTime = m_useSeperatedClock ? clock()*0.001 : *timeStamp;
	auto interval = currTime - m_timeLastUpdate;

	if(interval > TIME_TICK * 0.5)
	{
		m_timeLastUpdate = currTime;
		ScanCell();
		//if(m_savedDeltaTime > TIME_TICK_US*2) m_savedDeltaTime = TIME_TICK_US*2;
		StepWorld(interval);
	}
	
	hkSkyrimMemoryAllocator::releaseAll();
	m_lock.unlock();
}

void CWorld::AddSystemObject(UINT32 id, const std::string& prefix, NiNode* skeleton, const char* path)
{
	auto locker = m_lock.SmartLock();

	auto system = LoadPhysicsFile(path);
	if(!system)
	{
		LogWarning("Invalid havok serialize file : %s", path);
		return;
	}
	
	LogInfo("Physics system loaded : %s", path);
	CSystemObject::RenameBodies(skeleton, system, prefix);
	auto obj = std::shared_ptr<CSystemObject>(new CSystemObject);
	if(obj && obj->BindPhysicsInfo(system, skeleton))
		m_systems.insert(std::make_pair(id, obj));
	system->removeReference();
}

void CWorld::RemoveSystemObject(UINT32 id)
{
	m_lock.lock();
	
	m_pWorld->markForWrite();
	m_systems.erase(id);
	m_pWorld->unmarkForWrite();

	m_lock.unlock();
}

void CWorld::ScanAndAdd(UINT32 id, const std::string& prefix, NiNode* skeleton, NiNode* node)
{
	for(int i=0; i<node->m_extraDataLen; ++i)
	{
		auto stringData = ni_cast(node->m_extraData[i], NiStringExtraData);
		if(stringData && stringData->m_name == "HDT Havok Path" && stringData->m_stringData.data)
			AddSystemObject(id, prefix, skeleton, stringData->m_stringData.data);
		auto strings = ni_cast(node->m_extraData[i], NiStringsExtraData);
		if(strings && strings->m_name == "HDT Havok Path")
			for(int i=0; i<strings->m_count; ++i)
				if(strings->m_strings[i].data)
					AddSystemObject(id, prefix, skeleton, strings->m_strings[i].data);
	}
}

void CWorld::Reactive()
{
	m_lock.lock();

	m_timeLastUpdate = *timeStamp;
	
	m_pWorld->markForWrite();
	for(auto& i : m_characters)
	{
		i.second->RemoveFromWorld();
		i.second->AddToWorld(m_pWorld);
	}

	for(auto& i : m_systems)
	{
		i.second->RemoveFromWorld();
		i.second->AddToWorld(m_pWorld);
	}
	m_pWorld->unmarkForWrite();

	m_lock.unlock();
}