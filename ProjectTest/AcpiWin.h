#ifndef AcpiWin_H_
#define AcpiWin_H_
#include "Log.h"

namespace AcpiWin {
	//std::mutex Logger::mutex_;
	static Logger& logger = Logger::GetInstance();

}

#endif
