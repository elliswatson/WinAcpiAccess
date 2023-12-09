#include "Log.h"
#include <iostream>
#include "fstream"


#ifdef GOOGLE_LOGGER
AcpiWin::Logger::Logger()
{

	FLAGS_log_dir = "./logs/log.txt";
	google::InitGoogleLogging("");
	google::SetLogDestination(google::GLOG_INFO, FLAGS_log_dir.c_str());
	

}

AcpiWin::Logger::~Logger()
{
	google::ShutdownGoogleLogging();
	
}


void AcpiWin::Logger::logInfo(const std::string& message)
{
	
	LOG(INFO) << message;
	google::FlushLogFiles(google::GLOG_INFO);
}

void AcpiWin::Logger::logWarning(const std::string& message)
{
	
	LOG(WARNING) << message;
	google::FlushLogFiles(google::GLOG_INFO);
}

void AcpiWin::Logger::logError(const std::string& message)
{
	LOG(ERROR) << message;
	google::FlushLogFiles(google::GLOG_INFO);
}
#endif

AcpiWin::Logger::Logger(const std::string filepath)
{
	
}
