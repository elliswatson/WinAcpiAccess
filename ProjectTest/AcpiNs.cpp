#include "AcpiNs.h"
#include "AmlBuilder.h"
#include "AcpiWin.h"
#include "Utils.h"
#include <codecvt>
std::string AcpiWin::AcpiNs::GetPath() const { return this->Path; }
void AcpiWin::AcpiNs::SetPath(std::string val) { this->Path = val; }
std::string AcpiWin::AcpiNs::GetType() const { return this->Type; }
void AcpiWin::AcpiNs::SetType(std::string val) { this->Type = val; }
uint64_t AcpiWin::AcpiNs::GetUlValue() const { return this->ulValue; }
void AcpiWin::AcpiNs::SetUlValue(uint64_t val) { this->ulValue = val; }
std::string AcpiWin::AcpiNs::GetStrValueType() const { return this->strValueType; }
void AcpiWin::AcpiNs::SetStrValueType(std::string val) { this->strValueType = val; }
unsigned char* AcpiWin::AcpiNs::GetPbValue() const { return this->pbValue; }
void AcpiWin::AcpiNs::SetPbValue(unsigned char* val) { this->pbValue = val; }
std::string AcpiWin::AcpiNs::GetType(int type)
{
	try
	{
		return AcpiWin::AmlBuilder::mAcpiTypeMap[type];
	}
	catch (const std::exception& ex)
	{
		//std::wstring_convert<std::codecvt_utf8<wchar_t>> conveerter;
		//std::wstring wideStr = conveerter.from_bytes(ex.what());
		logger.logError(ex.what());
		return "InvalidAcpiType";
	}
}
