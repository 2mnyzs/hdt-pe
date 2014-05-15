#pragma once

#include "common.h"
#include "detours.h"
#include "ppapi_helper.h"
#include "netimmerse_helper.h"
#include "ResourceManager.h"

#include "World.h"

class MyClass
{
public:
	
	NiNode* TEST_0046F0B0(NiNode* armor, UINT32 idx, UINT32 unk2, UINT32 unk3, UINT32 unk4);
	NiNode* TEST_0046E720(NiNode* skeleton, NiNode* armor, UINT32 unk2, UINT32 unk3, UINT32 unk4, UINT32 unk5);

	MEMBER_FN_PREFIX(MyClass);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_0046F0B0, NiNode*, 0x0046F0B0, NiNode* armor, UINT32 idx, UINT32 unk2, UINT32 unk3, UINT32 unk4);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_0046E720, NiNode*, 0x0046E720, NiNode* skeleton, NiNode* armor, UINT32 unk2, UINT32 unk3, UINT32 unk4, UINT32 unk5);

	UINT32 unk0;
	NiNode* m_root;
	UINT32 unk1[1000];	// should contain an array with element size 32;
};

void HookArmor();
void DehookArmor();
//void ScanArmor();
