#include "Log.h"
#include <iostream>
#include "fstream"


#if 0
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
#ifndef GOOGLE_LOGGER
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

AcpiWin::Logger::Logger()
{
	
	console_logger_ = spdlog::stdout_color_mt("console");
	logger_ = spdlog::basic_logger_mt("file","logs/log.txt");
	
	spdlog::set_level(spdlog::level::trace);
	
}

void AcpiWin::Logger::logTrace(const std::string& message)
{
	logger_->trace(message);
	console_logger_->trace(message);
	logger_->flush();
}

void AcpiWin::Logger::logDebug(const std::string& message)
{
	logger_->debug(message);
	console_logger_->debug(message);
	logger_->flush();
}
void AcpiWin::Logger::logInfo(const std::string& message)
{
	logger_->info(message);
	console_logger_->info(message);
	logger_->flush();
}

void AcpiWin::Logger::logWarning(const std::string& message)
{
	console_logger_->warn(message);
	logger_->warn(message);
	logger_->flush();
}

void AcpiWin::Logger::logError(const std::string& message)
{
	logger_->error(message);
	console_logger_->error(message);
	logger_->flush();
}
#endif
