#include "HookWeapon.h"
#include "ResourceManager.h"

static Lockable lockWeapon;
static std::unordered_set<NiObject*> weaponList;

void OnWeaponRelease(NiObject* weapon)
{
	auto iter = weaponList.find(weapon);
	if(iter != weaponList.end())
	{
		CWorld::getSingleton()->RemoveSystemObject((UINT32)weapon);
		weaponList.erase(iter);
	}
}

// Load weapon mesh
auto UNKNOWN_0046F530 = (NiNode* (*)(UINT32 unk0, UINT32 unk1, UINT32 unk2, UINT32 unk3, UINT32 unk4))0x0046F530;
NiNode* TEST_0046F530(UINT32 unk0, UINT32 unk1, UINT32 unk2, UINT32 unk3, UINT32 unk4)
{
	CWorld::getSingleton()->InitThread();
	auto weapon = UNKNOWN_0046F530(unk0, unk1, unk2, unk3, unk4);
	if(!weapon) return weapon;
	// Attach physics system here

	auto id = (UINT32)weapon;
	
	lockWeapon.lock();
	weaponList.insert(weapon);
	ResourceManager::get()->RegisterCallback(weapon, OnWeaponRelease);
	lockWeapon.unlock();

	char prefix[10];
	sprintf_s(prefix, "%08x ", prefix);
	CWorld::getSingleton()->ScanAndAdd(id, prefix, weapon, weapon);

	return weapon;
}

void HookWeapon()
{
	DetourAttach((void**)&UNKNOWN_0046F530, TEST_0046F530);
}

void DehookWeapon()
{
	DetourDetach((void**)&UNKNOWN_0046F530, TEST_0046F530);
}
