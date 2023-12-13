#ifndef AcpiWin_H_
#define AcpiWin_H_
#include "Log.h"
#include "AcpiNs.h"
#include "AmlBuilder.h"
#include "AcpiLib.h"
#include "Utils.h"

namespace AcpiWin {
	//std::mutex Logger::mutex_;
	//AcpiWin::AcpiNs AcpiWin::AmlBuilder::acpiNSRoot ;
	static Logger& logger = Logger::GetInstance();
	
}
#endif