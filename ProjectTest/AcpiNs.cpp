#include "AcpiNs.h"
#include "AmlBuilder.h"
#include "AcpiWin.h"
#include "Utils.h"
#include <codecvt>

std::string AcpiWin::AcpiNs::GetType(int type)
{
	try
	{
		//return AcpiWin::AmlBuilder::mAcpiTypeMap[type];
	}
	catch (const std::exception& ex)
	{
		//std::wstring_convert<std::codecvt_utf8<wchar_t>> conveerter;
		//std::wstring wideStr = conveerter.from_bytes(ex.what());
		logger.logError(ex.what());
		return "InvalidAcpiType";
	}
}
