#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>

	class Utils {
	private:
		const char* pcst;
		char* cstr;

	public:
		Utils(const std::string& str) ;
		
		~Utils();
		std::wstring chartoWstring(const char* pchar);
		const char* string2constChar(std::string str);
		char* string2Char(std::string str);
		std::string wstring2String(std::wstring wstr);
		static std::string cout();
	};
#endif