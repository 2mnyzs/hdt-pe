#include "HookArmor.h"

auto DoMeshInterporation = (UINT32 (*)(NiNode* mesh0, NiNode* mesh1, void*, int, int))0x0046F010 ;

void HookArmor()
{
	DetourAttach((void**)MyClass::_UNKNOWN_0046F0B0_GetPtr(), (void*)GetFnAddr(&MyClass::TEST_0046F0B0));
	DetourAttach((void**)MyClass::_UNKNOWN_0046E720_GetPtr(), (void*)GetFnAddr(&MyClass::TEST_0046E720));
	//DetourAttach((void**)MyClass::_UNKNOWN_00432070_GetPtr(), *(void**)(&TEST_00432070));
	//auto TEST_00734F50 = &MyClass::TEST_00734F50;
	//auto TEST_00AB53E0 = &MyClass::TEST_00AB53E0;
	//DetourAttach((void**)MyClass::_UNKNOWN_00734F50_GetPtr(), *(void**)(&TEST_00734F50));
	//DetourAttach((void**)MyClass::_UNKNOWN_00AB53E0_GetPtr(), *(void**)(&TEST_00AB53E0));
}

void DehookArmor()
{
	DetourDetach((void**)MyClass::_UNKNOWN_0046F0B0_GetPtr(), (void*)GetFnAddr(&MyClass::TEST_0046F0B0));
	DetourDetach((void**)MyClass::_UNKNOWN_0046E720_GetPtr(), (void*)GetFnAddr(&MyClass::TEST_0046E720));
}

struct ArmorAttachInfo
{
	NiNode* armor;
	NiNode* skeleton;
	UINT32 id;
	std::string prefix;
};

static Lockable lockArmor;
static std::unordered_map<NiObject*, ArmorAttachInfo> armorInfos;
static std::unordered_set<NiObject*> addonInfos;

void OnArmorRelease(NiObject* armor)
{
	auto iter = armorInfos.find(armor);
	if(iter != armorInfos.end())
	{
		const auto& info = iter->second;
		CWorld::getSingleton()->RemoveSystemObject(info.id);
		ClearNode(info.skeleton, info.prefix);
		info.skeleton->DecRef();
		armorInfos.erase(iter);
	}
}

void OnAddonRelease(NiObject* addon)
{
	auto iter = addonInfos.find(addon);
	if(iter != addonInfos.end())
	{
		CWorld::getSingleton()->RemoveSystemObject((UINT32)addon);
		addonInfos.erase(iter);
	}
}

NiNode* MyClass::TEST_0046E720(NiNode* armor, NiNode* npc,UINT32 unk2,UINT32 unk3,UINT32 unk4,UINT32 unk5)
{
	char prefix[10];
	
	sprintf_s(prefix, "%08x ", armor);
	RenameNode(npc, armor, prefix);
	
	auto armornpc = CastNiNode(armor->GetObjectByName("NPC"));
	if(armornpc)
		for(int i=0; i<armornpc->m_children.m_arrayBufLen; ++i)
		{
			if(armornpc->m_children[i])
				CombineTree(m_root, armornpc);
		}
	else CombineTree(m_root, armor);

	auto armorInSkeleton = CALL_MEMBER_FN(this, UNKNOWN_0046E720)(armor, npc, unk2, unk3, unk4, unk5);
	
	if(armorInSkeleton)
	{
		ArmorAttachInfo info;
		info.skeleton = npc;
		info.id = (UINT32)armor;
		info.prefix = prefix;
	
		npc->IncRef();
		lockArmor.lock();
		armorInfos.insert(std::make_pair(armorInSkeleton, info));
		ResourceManager::get()->RegisterCallback(armorInSkeleton, OnArmorRelease);

		CWorld::getSingleton()->ScanAndAdd(info.id, prefix, npc, armor);
		lockArmor.unlock();
	}
	else ClearNode(npc, prefix);

	return armorInSkeleton;
}

NiNode* MyClass::TEST_0046F0B0(NiNode* armor, UINT32 idx, UINT32 unk2, UINT32 unk3, UINT32 unk4)
{
	CWorld::getSingleton()->InitThread();

	auto ret = CALL_MEMBER_FN(this, UNKNOWN_0046F0B0)(armor, idx, unk2, unk3, unk4);
	auto *flag = ((char*)this) + ((idx+1)<<5);	// unk, get it by asm.
	if(!*flag)
	{
		//Attach physics system
		//lockArmor.lock();
		addonInfos.insert(armor);
		ResourceManager::get()->RegisterCallback(armor, OnAddonRelease);
		//lockArmor.unlock();

		auto id = (UINT32)armor;
		char prefix[10];
		sprintf_s(prefix, "%08x ", armor);
		CWorld::getSingleton()->ScanAndAdd(id, prefix, armor, armor);
	}
	return ret;
}
