#ifndef _LOG_H_
#define _LOG_H_
#include <fstream>
#include <iostream>
namespace AcpiWin {
	class Log {
	private :
		const wchar_t* logfile = L"log.txt";
		std::wofstream file;
	public:
		
		Log(const wchar_t* pstr);
		~Log();
		std::fstream getfile();
		void writelog(const wchar_t* str);

	};
}

#endif