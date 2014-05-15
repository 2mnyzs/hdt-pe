#include "log.h"
#include <cassert>
#include <ctime>

const char* LevelName[] = {"Always Show", "ERROR", "WARNING", "INFO", "DEBUG" };

Logger::Logger(const char* path):i_maxLevel(DEFAULT_LOG_LEVEL)
{
	out = fopen(path, "w");
	if(!out)
		out = stderr;
}

void Logger::WriteRaw( const char* fmt, ...  )
{
	auto locker = SmartLock();

	va_list arg;
	va_start(arg, fmt);
	vfprintf(out, fmt, arg);
	va_end(arg);
	fprintf(out, "\n");

	fflush(out);
}

void Logger::Write( int level, const char* fmt, ...  )
{
	auto locker = SmartLock();

	assert( level >= 0 && level <= LOG_DEBUG );
	if( level > i_maxLevel )return;

	time_t rawtm;
	tm timeinfo;

	time(&rawtm);
	localtime_s(&timeinfo, &rawtm);

	strftime(buffer, 50, "%c", &timeinfo);
	fprintf(out, "[%s]%s: ", buffer, LevelName[level]);

	va_list arg;
	va_start(arg, fmt);
	vfprintf(out, fmt, arg);
	va_end(arg);
	fprintf(out, "\n");

	fflush(out);
}