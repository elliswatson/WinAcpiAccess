#ifndef _LOG_H_
#define _LOG_H_
#include <string>
#include <spdlog/spdlog.h>
namespace AcpiWin {
#ifdef GOOGLE_LOGGER
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
	public:
		Logger(const std::string filepath);

	};
}
#endif