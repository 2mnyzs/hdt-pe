#include "exception.h"

#include <psapi.h>
#include <DbgHelp.h>

void AccessViolation(EXCEPTION_RECORD* record)
{
	LogError("AccessViolation, try to %s 0x%08x failed",
		record->ExceptionInformation[0]?"write":"read",
		record->ExceptionInformation[1]
	);
}

void CppException(EXCEPTION_RECORD* record)
{
	__try{
		auto magic = (type_info****)record->ExceptionInformation[2];
		auto rtti = magic[3][1][1];
		LogError("C++ Exception %s", rtti->name());
	} __except (EXCEPTION_EXECUTE_HANDLER) {}
}

BOOL CALLBACK SymEnumerateModulesProc(
	PCSTR ModuleName,
	DWORD BaseOfDll,
	PVOID UserContext
)
{
	auto map = (std::map<DWORD, std::string>*)UserContext;
	map->insert(std::make_pair(BaseOfDll, ModuleName));
	return true;
}

void PrintCallStack(PCONTEXT context)
{
	STACKFRAME frame;
	ZeroMemory(&frame, sizeof(frame));
	frame.AddrPC.Offset = context->Eip;
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrStack.Offset = context->Esp;
	frame.AddrStack.Mode = AddrModeFlat;
	frame.AddrFrame.Offset = context->Ebp;
	frame.AddrFrame.Mode = AddrModeFlat;

	LogError("Call Stack (Skyrim ignored the frame pointer register (ebp) so it may not correct) :");
	
	HANDLE hProcess = GetCurrentProcess();
	HANDLE hThread = GetCurrentThread();

	std::map<DWORD, std::string> moduleMap;
	SymEnumerateModules(hProcess, SymEnumerateModulesProc, &moduleMap);

	for( ; ; )
	{
		if( !StackWalk(IMAGE_FILE_MACHINE_I386, hProcess, hThread, &frame, context, 0, SymFunctionTableAccess, SymGetModuleBase, 0 ) )
			break;
		
		if( frame.AddrPC.Offset == 0 )
			break;
		BYTE symbolBuffer[ sizeof( SYMBOL_INFO ) + 1024 ];
		PSYMBOL_INFO pSymbol = ( PSYMBOL_INFO ) symbolBuffer;

		pSymbol->SizeOfStruct = sizeof( symbolBuffer );
		pSymbol->MaxNameLen = 1024;

		DWORD64 symDisplacement = 0;
		auto moduleName = moduleMap[SymGetModuleBase(hProcess, frame.AddrPC.Offset)].c_str();
		if( SymFromAddr( hProcess, frame.AddrPC.Offset, 0, pSymbol ) )
		{
			IMAGEHLP_LINE lineInfo = { sizeof(IMAGEHLP_LINE) };
			DWORD dwLineDisplacement;
			if( SymGetLineFromAddr( hProcess, frame.AddrPC.Offset, &dwLineDisplacement, &lineInfo ) )
				LogError( "\t%s : %s in %s line %u", moduleName, pSymbol->Name, lineInfo.FileName, lineInfo.LineNumber );
			else LogError( "\t%s : %s", moduleName, pSymbol->Name );
		}
		else LogError( "\t%s : 0x%08x", moduleName, frame.AddrPC.Offset );
	}
}

void PrintException(_EXCEPTION_POINTERS* info)
{
	LogError("Fatal error occured");

	auto exception = info->ExceptionRecord;
	HMODULE modules[1024], module = 0;
	DWORD moduleCount;
	EnumProcessModules(GetCurrentProcess(), modules, 1024, &moduleCount);
	for(int i=0; i<moduleCount; ++i)
	{
		MODULEINFO info;
		GetModuleInformation(GetCurrentProcess(), modules[i], &info, sizeof(info));
		if(info.lpBaseOfDll <= exception->ExceptionAddress && exception->ExceptionAddress < (char*)info.lpBaseOfDll+info.SizeOfImage)
			module = modules[i];
	}

	char buf[MAX_PATH];
	GetModuleFileNameA(module, buf, sizeof(buf));
	LogError("Code : 0x%08x", exception->ExceptionCode);
	LogError("Flag : 0x%08x", exception->ExceptionFlags);
	LogError("Module : %s", buf);
	LogError("Address : 0x%08x", exception->ExceptionAddress);
	LogError("Module Address : 0x%08x", module);

	switch(exception->ExceptionCode)
	{
	case 0xC0000005:
		AccessViolation(exception);
		break;

	case 0xE06D7363:
		CppException(exception);
		break;

	default:
		break;
	}
		
	PrintCallStack(info->ContextRecord);

	HANDLE dump = CreateFileA("data/skse/plugins/hdtPhysicsExtensions.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	
	MINIDUMP_EXCEPTION_INFORMATION einfo;
	einfo.ThreadId = ::GetCurrentThreadId();
	einfo.ExceptionPointers = info;
	einfo.ClientPointers = false;
	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		dump,
		MiniDumpWithFullMemory,
		&einfo, 0, 0);

	CloseHandle(dump);

	LogError("Minidump saved in hdtPhysicsExtensions.dmp");
}
