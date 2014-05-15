#pragma once

#include "log.h"

void PrintException(_EXCEPTION_POINTERS* info);

#ifndef _DEBUG

#define EXCEPTION_CAPTURE_BEGIN \
	__try{
#define EXCEPTION_CAPTURE_END \
	}__except( PrintException(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER )	\
	{\
		LogError("Plugin is trying to save game");\
		auto saver = BGSSaveLoadManager::GetSingleton();\
		saver->Save("hdtPhysicsExtension Autosave");\
		exit(-1);\
	}

#else

#define EXCEPTION_CAPTURE_BEGIN
#define EXCEPTION_CAPTURE_END

#endif