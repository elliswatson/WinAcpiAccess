#ifndef _LOG_H_
#define _LOG_H_
#include <string>
#include <spdlog/spdlog.h>
namespace AcpiWin {
#if 0
#include <glog/logging.h>
#define GLOG_NO_ABBREVIATED_SEVERITIES 


	class Logger {
	private:
		int FLAG_init;
		Logger();
		~Logger();
	public:
		
		Logger(const std::string&) = delete;
		Logger& operator=(const Logger&)=delete;
		Logger(Logger&&) = delete;
		Logger& operator=(Logger&&) = delete;
		static Logger& GetInstance() {
			static Logger instance;
			return instance;
		};
		void logInfo(const std::string& message);
		void logWarning(const std::string& message);
		void logError(const std::string& message);
	
		
	};

#endif // GOOGLE_LOGGER


	class Logger {
	private:
		std::shared_ptr<spdlog::logger> logger_;
		std::shared_ptr<spdlog::logger> console_logger_;
		
		Logger();
	public:
		Logger(const std::string&) = delete;
		Logger& operator=(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(Logger&&) = delete;
		static Logger& GetInstance() {
			static Logger instance;

			
			return instance;
		};
		void logTrace(const std::string& message);
		void logDebug(const std::string& message);
		void logInfo(const std::string& message);
		void logWarning(const std::string& message);
		void logError(const std::string& message);


	};
}
#endif