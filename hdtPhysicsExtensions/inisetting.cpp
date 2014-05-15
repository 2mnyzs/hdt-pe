#include "inisetting.h"

template <> short GetPrivateProfile(const char* clsnm, const char* rcrdnm, short def, const char* ini)
{
	return GetPrivateProfileInt(clsnm, rcrdnm, def, ini);
}

template <> unsigned GetPrivateProfile(const char* clsnm, const char* rcrdnm, unsigned def, const char* ini)
{
	return GetPrivateProfileInt(clsnm, rcrdnm, def, ini);
}

template <> int GetPrivateProfile(const char* clsnm, const char* rcrdnm, int def, const char* ini)
{
	return GetPrivateProfileInt(clsnm, rcrdnm, def, ini);
}

template <> double GetPrivateProfile(const char* clsnm, const char* rcrdnm, double def, const char* ini)
{
	char buf[20];
	GetPrivateProfileString(clsnm, rcrdnm, std::to_string(def).c_str(), buf, 20, ini);
	return atof(buf);
}

template <> float GetPrivateProfile(const char* clsnm, const char* rcrdnm, float def, const char* ini)
{
	return GetPrivateProfile<double>(clsnm, rcrdnm, def, ini);
}

template <> bool GetPrivateProfile(const char* clsnm, const char* rcrdnm, bool def, const char* ini)
{
	char buf[20];
	GetPrivateProfileString(clsnm, rcrdnm, std::to_string(def).c_str(), buf, 20, ini);
	std::string str = buf;
	for(auto& i : str)
		i = tolower(i);

	return !(str == "false" || str == "0");
}

template <> std::string GetPrivateProfile(const char* clsnm, const char* rcrdnm, std::string def, const char* ini)
{
	char buf[500];
	GetPrivateProfileString(clsnm, rcrdnm, def.c_str(), buf, 500, ini);	
	return buf;
}

template <> long long GetPrivateProfile(const char* clsnm, const char* rcrdnm, long long def, const char* ini)
{
	char buf[500];
	GetPrivateProfileString(clsnm, rcrdnm, std::to_string(def).c_str(), buf, 500, ini);	
	return _atoi64(buf);
}

template<> void WritePrivateProfile(const char* clsnm, const char* rcrdnm, const char* const& val, const char* ini)
{
	WritePrivateProfileString(clsnm, rcrdnm, val, ini);
}

template<> void WritePrivateProfile(const char* clsnm, const char* rcrdnm, const std::string& val, const char* ini)
{
	WritePrivateProfileString(clsnm, rcrdnm, val.c_str(), ini);
}

template<> void WritePrivateProfile(const char* clsnm, const char* rcrdnm, const bool& val, const char* ini)
{
	WritePrivateProfileString(clsnm, rcrdnm, val?"true":"false", ini);
}
