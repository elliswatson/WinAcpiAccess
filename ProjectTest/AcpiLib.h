#ifndef _AcpiLib_H_
#define _AcpiLib_H_
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <memory>
namespace AcpiWin {
	

	class Acpilib {
	public:
		
		//= LoadLibrary(L"AcpiLib.dll");
		//Acpilib();
		Acpilib();
		~Acpilib();
		HANDLE openAcpiService(HMODULE hdll);
		BOOL QueryAcpiNS(HMODULE hdll);
		HMODULE getModule();
		VOID SetModule(HMODULE hmodule);
		HANDLE getDriver();
		VOID SetHdriver(HANDLE hdriver);
		VOID SaveAcpiOBJ(const wchar_t* p, HMODULE hDll);
		BOOL fileExits(const std::string& filename);
		BOOL DriverLoaded();
		int GetType(std::string path);
	private :
		HANDLE hDriver;
		HMODULE hDll;

	};

}
	



#endif