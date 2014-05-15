#include "HookRender.h"
#include "HookMemory.h"

UINT32 UnkRender::TEST_0069CBD0()
{
	EXCEPTION_CAPTURE_BEGIN
		CWorld::getSingleton()->InitThread();
		auto ret = CALL_MEMBER_FN(this, UNKNOWN_0069CBD0)();
		CWorld::getSingleton()->DoUpdate();
		return ret;
	EXCEPTION_CAPTURE_END
}
/*
UINT32 UnkRender::TEST_00BF2AD0(UINT32 unk)
{
	auto ret = CALL_MEMBER_FN(this, UNKNOWN_00BF2AD0)(unk);
	return ret;
}

void UnkRender::TEST_00C79790(UINT a, UINT b, UINT c, UINT d, UINT e)
{
	CALL_MEMBER_FN(this, UNKNOWN_00C79790)(a, b, c, d, e);
}

UINT32 UnkRender::TEST_00CE7DF0()
{
	auto ret = CALL_MEMBER_FN(this, UNKNOWN_00CE7DF0)();
	return ret;
}

void UnkRender::TEST_00AAD8D0(UINT unk)
{
//	auto node = (NiNode*)this;
	CALL_MEMBER_FN(this, UNKNOWN_00AAD8D0)(unk);
}
*/
void HookRender()
{
	auto TEST_0069CBD0 = &UnkRender::TEST_0069CBD0;
	DetourAttach((void**)UnkRender::_UNKNOWN_0069CBD0_GetPtr(), *(void**)(&TEST_0069CBD0));
	//DetourAttach((void**)UnkRender::_UNKNOWN_00AAD8D0_GetPtr(), (void*)GetFnAddr(&UnkRender::TEST_00AAD8D0));
	//auto TEST_00CE7DF0 = &UnkRender::TEST_00CE7DF0;
	//DetourAttach((void**)UnkRender::_UNKNOWN_00CE7DF0_GetPtr(), *(void**)(&TEST_00CE7DF0));
	//auto TEST_00C79790 = &UnkRender::TEST_00C79790;
	//DetourAttach((void**)UnkRender::_UNKNOWN_00C79790_GetPtr(), *(void**)(&TEST_00C79790));
	//DetourAttach((void**)UNKNOWN_00C79790, TEST_00C79790);
}

void DehookRender()
{
	auto TEST_0069CBD0 = &UnkRender::TEST_0069CBD0;
	DetourDetach((void**)UnkRender::_UNKNOWN_0069CBD0_GetPtr(), *(void**)(&TEST_0069CBD0));
	//DetourDetach((void**)UnkRender::_UNKNOWN_00AAD8D0_GetPtr(), (void*)GetFnAddr(&UnkRender::TEST_00AAD8D0));
	//DetourDetach((void**)&UNKNOWN_00BECCF0, TEST_00BECCF0);
}
