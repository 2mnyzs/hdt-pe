#include "HookMemory.h"
#include "behaviorHelper.h"

static UnkHeapStruct0** const gcPtr = (UnkHeapStruct0**)0x012E3534;

void (*OLD_0042C840)() = (void (*)())0x0042C840;
void (*OLD_0042C870)() = (void (*)())0x0042C870;
/*
00AF8620  mov         eax,dword ptr [ecx+30h]  
00AF8623  push        eax  
00AF8624  call        dword ptr ds:[106B15Ch]  SetEvent(eventGCRun);
00AF862A  ret  

00AF8630  mov         eax,dword ptr [ecx+30h]  
00AF8633  push        0FFFFFFFFh  
00AF8635  push        eax  
00AF8636  call        dword ptr ds:[106B158h]  WaitForSingleObject(eventGCRun, INFINITE);
00AF863C  ret  

0042C840  mov         eax,dword ptr ds:[012E3534h]  
0042C845  push        esi  
0042C846  mov         esi,dword ptr [eax+78h]  
0042C849  push        edi  
0042C84A  mov         edi,dword ptr [esi+24h]  
0042C84D  call        dword ptr ds:[106B20Ch]	; GetCurrentThreadID();
0042C853  cmp         edi,eax					; if(gcThreadID == GetCurrentThreadID())
0042C855  je          0042C86A					;	return;
0042C857  mov         ecx,esi  
0042C859  call        00AF8620					; 
0042C85E  mov         ecx,dword ptr [esi+34h]  
0042C861  push        0FFFFFFFFh  
0042C863  push        ecx  
0042C864  call        dword ptr ds:[106B158h]	; WaitForSingleObject(eventGCFinish, 0xFFFFFFFF); this is what cause infinite loading.
0042C86A  pop         edi						; The Event is an auto-reset event. If another thread call gc then infinite loading happen
0042C86B  pop         esi  
0042C86C  ret  */
void TEST_0042C840()
{
	auto gc = (*gcPtr)->data78;
	if(gc->gcThreadID == GetCurrentThreadId())
		return;

	SetEvent(gc->eventGCRun);
	WaitForSingleObject(gc->semaphoreGCFinish, 100);
}

void TEST_0042C870()
{
	auto gc = (*gcPtr)->data78;
	if(gc->gcThreadID == GetCurrentThreadId())
		return;

	SetEvent(gc->eventGCRun);
	LONG previousCount;
	ReleaseSemaphore(gc->semaphoreGCFinish, 1, &previousCount);
}

volatile bool UnkRCManager::isManagerReady = false;

void UnkRCManager::WaitForRun()
{
	if(gcThreadID == GetCurrentThreadId())
	{
		isManagerReady = true;
		WaitForSingleObject(eventGCRun, INFINITE);
		isManagerReady = false;
	}
	else WaitForSingleObject(eventGCRun, INFINITE);
}

void UnkHeapStruct1::TEST_00436740(){
	if(UnkRCManager::isManagerReady)
		CALL_MEMBER_FN(this, Unknown00436740)();
}

void* HookHeap::Allocate(UInt32 size, UInt32 alignment, bool aligned)
{
	auto ret = CALL_MEMBER_FN(this, Allocate)(size, alignment, aligned);
	if(!ret)
	{
		wchar_t msg[100];
		swprintf_s(msg, L"Allocate %d bytes with alignment %d bytes failed", size, alignment);
		MessageBoxW(0, L"Memory allocate failed", msg, MB_OK);
	}
	return ret;
}

auto OLD_00BE70B0 = (void (*)(hkbBehaviorGraph* a, hkbBehaviorGraph* b))0x00BE70B0;
// hkbBehaviorGraph
void TEST_00BE70B0(hkbBehaviorGraph* a, hkbBehaviorGraph* b)
{
	EXCEPTION_CAPTURE_BEGIN
		OLD_00BE70B0(a, b);
	EXCEPTION_CAPTURE_END
}

struct Fragment
{
	void* p;
	int size;
};

#include "World.h"
void* hkSkyrimMemoryAllocator::blockAllocGuard(int numBytes)
{
	//auto ret = CALL_MEMBER_FN(this, blockAlloc)(numBytes);
	CWorld::InitThread();
	auto ret = _aligned_malloc(numBytes, 16);
	if(!ret)
	{
		fragments.lock();
		while(!fragments.isEmpty())
		{
			_aligned_free(fragments.front());
			fragments.popFront();

			ret = _aligned_malloc(numBytes, 16);
			if(ret) break;
		}
		fragments.unlock();
	}

	if(!ret)
	{
		char msg[1000];
		hkMemoryAllocator::MemoryStatistics s;
		getMemoryStatistics(s);
		sprintf_s(msg, "Allocate %d bytes failed\n"
			"Heap size : %d\n"
			"In used : %d\n"
			"Peak used : %d\n"
			"Available : %d\n"
			"Total Available : %d\n"
			"Largest block available : %d\n"
			, numBytes, s.m_allocated, s.m_inUse, s.m_peakInUse, s.m_available, s.m_totalAvailable, s.m_largestBlock);
		MessageBoxA(0, "Havok memory allocate failed", msg, MB_OK);
	}
	return ret;
}

void hkSkyrimMemoryAllocator::blockFreeGuard(void* ptr, int numBytes)
{
	//CALL_MEMBER_FN(this, blockFree)(ptr, numBytes);
	CWorld::InitThread();
	
	fragments.lock();
	if(fragments.isFull())
	{
		_aligned_free(fragments.front());
		fragments.popFront();
	}
	fragments.pushBack(ptr);
	fragments.unlock();
	//_aligned_free(fragments.front());
}

hkSkyrimMemoryAllocator::FragmentQueue hkSkyrimMemoryAllocator::fragments;

void hkSkyrimMemoryAllocator::releaseAll()
{
	fragments.lock();
	while(!fragments.isEmpty())
	{
		_aligned_free(fragments.front());
		fragments.popFront();
	}
	fragments.unlock();
}

void HookMemory()
{
	//DetourAttach((void**)&OLD_0042C840, TEST_0042C840);
	//DetourAttach((void**)&OLD_0042C870, TEST_0042C870);
	//DetourAttach((void**)&OLD_00BE70B0, TEST_00BE70B0);
	DetourAttach((void**)HookHeap::_Allocate_GetPtr(), (void*)GetFnAddr(&HookHeap::Allocate));
	DetourAttach((void**)hkSkyrimMemoryAllocator::_blockAlloc_GetPtr(), (void*)GetFnAddr(&hkSkyrimMemoryAllocator::blockAllocGuard));
	DetourAttach((void**)hkSkyrimMemoryAllocator::_blockFree_GetPtr(), (void*)GetFnAddr(&hkSkyrimMemoryAllocator::blockFreeGuard));
	DetourAttach((void**)UnkRCManager::_WaitForRun_GetPtr(), (void*)GetFnAddr(&UnkRCManager::WaitForRun));
	DetourAttach((void**)UnkHeapStruct1::_Unknown00436740_GetPtr(), (void*)GetFnAddr(&UnkHeapStruct1::TEST_00436740));
}

void DehookMemory()
{
	//DetourDetach((void**)&OLD_0042C840, TEST_0042C840);
	//DetourDetach((void**)&OLD_0042C870, TEST_0042C870);
	//DetourDetach((void**)&OLD_00BE70B0, TEST_00BE70B0);
	DetourDetach((void**)HookHeap::_Allocate_GetPtr(), (void*)GetFnAddr(&HookHeap::Allocate));
	DetourDetach((void**)UnkHeapStruct1::_Unknown00436740_GetPtr(), (void*)GetFnAddr(&UnkHeapStruct1::TEST_00436740));
	DetourDetach((void**)UnkRCManager::_WaitForRun_GetPtr(), (void*)GetFnAddr(&UnkRCManager::WaitForRun));
	DetourDetach((void**)hkSkyrimMemoryAllocator::_blockAlloc_GetPtr(), (void*)GetFnAddr(&hkSkyrimMemoryAllocator::blockAllocGuard));
	DetourDetach((void**)hkSkyrimMemoryAllocator::_blockFree_GetPtr(), (void*)GetFnAddr(&hkSkyrimMemoryAllocator::blockFreeGuard));
}
