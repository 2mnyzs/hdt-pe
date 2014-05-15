#include "common.h"

const char* const INIPath = "data/skse/plugins/"PLUGIN_NAME".ini";
const char* const LogPath = "data/skse/plugins/"PLUGIN_NAME".log";

Logger* Logger::getSingleton()
{
	static Logger _g_Log(LogPath);
	return &_g_Log;
}

const float fPluginVersion = 1.4f;
