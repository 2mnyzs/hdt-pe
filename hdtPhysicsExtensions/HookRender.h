#pragma once

#include "common.h"
#include "detours.h"
#include "ppapi_helper.h"
#include "netimmerse_helper.h"

#include "World.h"

#include "HookArmor.h"
#include "HookWeapon.h"

class UnkRender
{
public:
	
	MEMBER_FN_PREFIX(UnkRender);

	// maybe draw scene
	UINT32 TEST_0069CBD0();
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_0069CBD0, UINT32, 0x0069CBD0);

	// maybe endDraw, call d3ddevice->present
	UINT32 TEST_00CE7DF0();
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00CE7DF0, UINT32, 0x00CE7DF0);

	UINT32 TEST_00CDA6A0();
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00CDA6A0, UINT32, 0x00CDA6A0);
	
	UINT32 TEST_00BF2AD0(UINT32);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00BF2AD0, UINT32, 0x00BF2AD0, UINT32);

	void TEST_00C79790(UINT, UINT, UINT, UINT, UINT);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00C79790, void, 0x00C79790, UINT, UINT, UINT, UINT, UINT);

	//NiNode::UpdateUpwardPass();
	void TEST_00AAD8D0(UINT unk);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00AAD8D0, void, 0x00BAB7E0, UINT);
};

void HookRender();
void DehookRender();