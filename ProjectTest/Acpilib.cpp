#include "AcpiLib.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <stdio.h>
#include "AcpiWin.h"
AcpiWin::Acpilib::Acpilib()
{
  hDll = LoadLibrary(L"Acpilib.dll"); // 加载DLL文件，获得DLL模块的句柄
}
AcpiWin::Acpilib::~Acpilib() {
	FreeLibrary(hDll);
}
HANDLE AcpiWin::Acpilib::openAcpiService(HMODULE hdll)
{
    HANDLE handle = NULL;

    if (hdll != NULL) {
        typedef HANDLE(*OpenAcpiService)();
        OpenAcpiService openAcpiService = (OpenAcpiService)GetProcAddress(hdll, "OpenAcpiService"); // 获取DLL函数的地址
        if (openAcpiService != NULL) {
            handle = openAcpiService(); // 通过函数指针调用DLL函数 //返回driver的句柄
            std::cout << "OpenAcpiService handle is ok" << std::endl;
            LOG.writelog(L"OpenAcpiService handle is ok");
            return handle;

        }
        else {
            LOG.writelog(L"Failed to get function address.");
            //std::cout << "Failed to get function address." << std::endl;
            return handle;
        }
    }
    else {
        LOG.writelog(L"Open ACPI Service Failed to load DLL.");
       // std::cout << "Open ACPI Service Failed to load DLL." << std::endl;
    }

    return handle;
}

HMODULE AcpiWin::Acpilib::getModule()
{

    return this->hDll;
}

VOID AcpiWin::Acpilib::SetModule(HMODULE hmodule)
{
    this->hDll = hmodule;
}

HANDLE AcpiWin::Acpilib::getDriver()
{
    return this->hDriver;
}

VOID AcpiWin::Acpilib::SetHdriver(HANDLE hdriver)
{
    this->hDriver = hdriver;
    return VOID();
}

VOID AcpiWin::Acpilib::SaveAcpiOBJ(const wchar_t* p,HMODULE hDll)
/*++
SaveAcpiOBJ Description:
  Save acpi objects from to file
Arguments:
  p -saved file name
Return Value:
  NA

--*/
{
    
    
    if (hDll != NULL) {
        typedef void(*SaveAcpiOBJ)(const wchar_t* p);
        SaveAcpiOBJ saveAcpiOBJ = (SaveAcpiOBJ)GetProcAddress(hDll, "SaveAcpiObjects"); // 获取DLL函数的地址
        if (saveAcpiOBJ != NULL) {
           // std::cout << "SaveAcpiObjects handle is ok" << std::endl;
            LOG.writelog(L"SaveAcpiObjects handle is ok.");
            // const int 和HANDLE 都可以返回ture 如何取舍
         saveAcpiOBJ(p); // 通过函数指针调用DLL函数

        }

    }

}

BOOL AcpiWin::Acpilib::fileExits(const std::string& filename)
{

    std::ifstream file(filename);
    return file.good();
   
}


BOOL AcpiWin::Acpilib::DriverLoaded()
{
   HANDLE hDriver = this->getDriver();
   if (INVALID_HANDLE_VALUE == hDriver)
   {
       return FALSE;
   }

   return TRUE;
   }

int AcpiWin::Acpilib::GetType(std::string path)
{
    if (hDll != NULL) {
        typedef int(*GetType)(std::string path);
        GetType getType = (GetType)GetProcAddress(hDll, "GetNSType"); // 获取DLL函数的地址
        if (getType != NULL) {
            int rst = getType(path); 
            std::cout << rst << std::endl;
            return rst;
        }
        else {
            LOG.writelog(L"GetNSType 为空指针");
        }

    } {
        LOG.writelog(L"dll 文件加载失败");
    }

}
    
    

BOOL AcpiWin::Acpilib::QueryAcpiNS(HMODULE hdll)
{


    if (hDll != NULL) {
        typedef BOOL(*QueryAcpiNS)(HANDLE hDriver, const int x, UINT MethodOff);
        QueryAcpiNS queryAcpiNS = (QueryAcpiNS)GetProcAddress(hDll, "QueryAcpiNS"); // 获取DLL函数的地址
        if (queryAcpiNS != NULL) {
            //HANDLE handle = 0;
            const int x = 0;
          
           // const int 和HANDLE 都可以返回ture 如何取舍
           BOOL rst = queryAcpiNS(hDriver, x, 0xC1); // 通过函数指针调用DLL函数
            //std::cout << "handle is ok" << std::endl;
           if (rst == TRUE) {
               LOG.writelog(L"queryAcpiNS RESULT TRUE");
           }
           else {
               LOG.writelog(L"queryAcpiNS RESULT FALSE");
           }
           
           
            return rst;
        }
        else {
            LOG.writelog(L"qacpins is null");
            //std::cout << "acpins is null" << std::endl;
        }

        return false;
    }
    return false;
}







