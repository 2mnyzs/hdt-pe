#pragma once

#include <detours.h>
#include "common.h"
#include "netimmerse_helper.h"

class HookHeap
{
public:
	MEMBER_FN_PREFIX(HookHeap);
	// haven't verified alignment vars
	DEFINE_MEMBER_FN_HOOK(Allocate, void *, 0x00A48D60, UInt32 size, UInt32 alignment, bool aligned);

	void* Allocate(UInt32 size, UInt32 alignment, bool aligned);
};

struct UnkRCManager
{
	int unk00[9];
	int gcThreadID;
	int unk28[2];
	HANDLE eventGCRun;
	HANDLE semaphoreGCFinish;

	static volatile bool isManagerReady;

	MEMBER_FN_PREFIX(UnkRCManager);
	DEFINE_MEMBER_FN_HOOK(WaitForRun, void, 0x00AF8630);

	void WaitForRun();
};

struct UnkHeapStruct0{

	int unk[0x1E];
	UnkRCManager *data78;

};

struct UnkHeapStruct1{
	MEMBER_FN_PREFIX(UnkHeapStruct1);
	DEFINE_MEMBER_FN_HOOK(Unknown00436740, void, 0x00436740);

	void TEST_00436740();
};

#define HavokMemoryRouterTLSIndex (*(int*)0x01BB6B08)
// we know nothing about this
class hkSkyrimMemoryAllocator : public hkMemoryAllocator
{
public:

	MEMBER_FN_PREFIX(hkSkyrimMemoryAllocator);
	DEFINE_MEMBER_FN_HOOK(dtor, void, 0x00daba50, int flag);
	DEFINE_MEMBER_FN_HOOK(blockAlloc, void*, 0x00e3a260, int numBytes);
	DEFINE_MEMBER_FN_HOOK(blockFree, void, 0x00e3a2c0, void* p, int numBytes);
	DEFINE_MEMBER_FN_HOOK(bufAlloc, void*, 0x00e39c50, int& reqNumBytesInOut);
	DEFINE_MEMBER_FN_HOOK(bufFree, void, 0x00e39c70, void* p, int numBytes);
	DEFINE_MEMBER_FN_HOOK(bufRealloc, void, 0x00e3a380, void* p, int numBytes, int& reqNumBytesInOut);
	DEFINE_MEMBER_FN_HOOK(blockAllocBatch, void, 0x00e39c80, void** ptrsOut, int numPtrs, int blockSize);
	DEFINE_MEMBER_FN_HOOK(blockFreeBatch, void, 0x00e39ce0, void** ptrsIn, int numPtrs, int blockSize);
	DEFINE_MEMBER_FN_HOOK(getMemoryStatistics, void, 0x00e39d40, MemoryStatistics& u);
	DEFINE_MEMBER_FN_HOOK(getAllocatedSize, int, 0x00e3a330, const void* obj, int nbytes);
	DEFINE_MEMBER_FN_HOOK(resetPeakMemoryStatistics, void, 0x006c50e0);
	DEFINE_MEMBER_FN_HOOK(getExtendedInterface, void, 0x00e3a450);
	
	void* blockAllocGuard(int numBytes);
	void blockFreeGuard(void* ptr, int numBytes);

	inline static hkMemoryRouter* getMemoryRouter(){ return (hkMemoryRouter*)TlsGetValue(HavokMemoryRouterTLSIndex); }
	
	static void releaseAll();
	
private:
	struct Fragment
	{
		void* p;
		int size;
	};
	typedef Queue<void*, 0x1000000> FragmentQueue;

	static FragmentQueue fragments;
	static bool useDelayRecycle;
};

void HookMemory();
void DehookMemory();
