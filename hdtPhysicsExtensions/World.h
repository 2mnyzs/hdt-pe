#pragma once

#include "common.h"
#include "Character.h"

class CWorld
{
private:
	CWorld(void);
	~CWorld(void);

public:
	
	void DoUpdate();
	
	void Suspend();
	void Resume();
	void ClearScene();

	static void InitThread();

	void Reactive();
	
	static CWorld* getSingleton();

	void AddSystemObject(UINT32 id, const std::string& prefix, NiNode* skeleton, const char* path);
	void RemoveSystemObject(UINT32 id);

	void ScanAndAdd(UINT32 id, const std::string& prefix, NiNode* skeleton, NiNode* node);

	void SwitchToSeperateClock();
	void SwitchToInternalClock();
	
private:
	
	void AddCharacter(int formID);
	void StepWorld(float interval);
	
	Lockable m_lock;
	std::unordered_set<UINT32> m_threadInit;
	hkpWindRegion* m_wind;
	hkpWorld* m_pWorld;
	hkMemoryRouter* m_pMemoryRouter;
	hkpCollisionFilter* m_collisionFilter;

	hkJobQueue* m_jobQueue;
	hkJobThreadPool* m_jobThreadPool;

	float m_timeLastUpdate;
	bool m_useSeperatedClock;

	std::unordered_map<UINT, std::shared_ptr<CCharacter>> m_characters;
	std::unordered_multimap<UINT,std::shared_ptr<CSystemObject>> m_systems;
	
	TESObjectCELL* m_pCell;
	std::atomic<UINT> m_suspended;

	void CheckForUpdate();
	void ScanCell();
};