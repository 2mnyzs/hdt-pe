#include "HookMessage.h"
#include "World.h"

static HHOOK hook = 0;

LRESULT CALLBACK HookCallback(int code, WPARAM wParam, LPARAM lParam)
{
	if(code == HC_ACTION)
	{
		auto msg = (CWPSTRUCT*)lParam;
		switch(msg->message)
		{
		case WM_ACTIVATE:
			if(msg->wParam != WA_INACTIVE)
				CWorld::getSingleton()->Reactive();
			break;
		}
	}
	
	return CallNextHookEx(0, code, wParam, lParam);;
}

void HookMessage(HANDLE hDllHandle)
{
	hook = SetWindowsHookExW(WH_CALLWNDPROC, HookCallback, (HINSTANCE)hDllHandle, GetCurrentThreadId());
}

void DehookMessage()
{
	UnhookWindowsHookEx(hook);
}