#include "Log.h"
#include <chrono>
#include <iomanip>
#include <codecvt>
AcpiWin::Log::Log(const wchar_t* pstr ): file(pstr)
{
	if (!file.is_open())
	{
		std::cout << "failed to open file" << std::endl;
	}
}

AcpiWin::Log::~Log()
{
	if (file.is_open()) {
		file.close();
	}
}

std::fstream AcpiWin::Log::getfile()
{
	return std::fstream();
}

void AcpiWin::Log::writelog(const wchar_t* str)
{
	//L"%Y-%m-%d %H:%M:%S");
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	std::tm localtime;

	localtime_s(&localtime, &now_time_t);
	char timestamp[20];
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &localtime);

	std::wstring_convert<std::codecvt_utf8<wchar_t>> conveerter;
	std::wstring wideStr = conveerter.from_bytes(timestamp);

	if (file.is_open())
	{
		file << "[" << wideStr << "]" << str << std::endl;
	}
}
