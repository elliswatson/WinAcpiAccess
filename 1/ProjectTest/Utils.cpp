#include "Utils.h"
#include <codecvt>
#include <windows.h>


utils::Utils::Utils(const std::string& str)
{
	pcst = string2constChar(str);
	cstr = string2Char(str);
}

utils::Utils::~Utils()
{
	delete[]pcst;
	delete cstr;
}

std::wstring utils::Utils::chartoWstring(const char* pchar)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conveerter;
	std::wstring wideStr = conveerter.from_bytes(pchar);
	return wideStr;
}

const char* utils::Utils::string2constChar(std::string str)//string to cast const char *
{
	const size_t bufferSize = str.length() + 1;
	char* constc = new char[bufferSize];
	strncpy_s(constc, bufferSize, str.c_str(), _TRUNCATE);
	return constc;
}


char* utils::Utils::string2Char(std::string str)
{
	const size_t bufferSize = str.length() + 1;
	char* cstr = new char[bufferSize];
	strncpy_s(cstr, bufferSize, str.c_str(), _TRUNCATE);
	return cstr;
	
}

std::string utils::Utils::wstring2String(std::wstring wstr)
{
	int size = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	if (size == 0) {
		return "";
	}

	std::string result(size, '\0');
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &result[0], size, nullptr, nullptr);

	return result;
}
