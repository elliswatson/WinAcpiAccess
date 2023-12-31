#include "Utils.h"
#include <codecvt>
#include <windows.h>
#include <chrono>

Utils::Utils(const std::string& str)
{
	pcst = string2constChar(str);
	cstr = string2Char(str);
}

Utils::~Utils()
{
	delete[]pcst;
	delete cstr;
}

std::wstring Utils::chartoWstring(const char* pchar)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conveerter;
	std::wstring wideStr = conveerter.from_bytes(pchar);
	return wideStr;
}

const char* Utils::string2constChar(std::string str)//string to cast const char *
{
	const size_t bufferSize = str.length() + 1;
	char* constc = new char[bufferSize];
	strncpy_s(constc, bufferSize, str.c_str(), _TRUNCATE);
	return constc;
}


char* Utils::string2Char(std::string str)
{
	const size_t bufferSize = str.length() + 1;
	char* cstr = new char[bufferSize];
	strncpy_s(cstr, bufferSize, str.c_str(), _TRUNCATE);
	return cstr;
	
}

std::string Utils::wstring2String(std::wstring wstr)
{
	int size = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	if (size == 0) {
		return "";
	}

	std::string result(size, '\0');
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &result[0], size, nullptr, nullptr);

	return result;
}

std::string Utils::cout()
{
	// TODO: �ڴ˴����� return ���
	//L"%Y-%m-%d %H:%M:%S");
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	std::tm localtime;

	localtime_s(&localtime, &now_time_t);
	char timestamp[20];
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &localtime);
	std::string str(timestamp);
	return str;
}



