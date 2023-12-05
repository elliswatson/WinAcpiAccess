// AcpiwinAccess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "AcpiLib.h"
#include "AmlBuilder.h"
#include <iostream>

int main()
{
    AcpiWin::Acpilib acpilib;
    HANDLE hdriver = acpilib.openAcpiService(acpilib.getModule());
    acpilib.SetHdriver(hdriver);
    const wchar_t* pName = L"acpi.bin";
    //BOOL driverfg = acpilib.DriverLoaded();
    acpilib.QueryAcpiNS(acpilib.getModule());
    acpilib.SaveAcpiOBJ(pName, acpilib.getModule());


    /*
    std::ifstream file(L"Acpilib.dll");
    BOOL bl = file.good();
    //const wchar_t* str = L"Acpilib.dll";
    std::cout << "file" << bl << std::endl;
    
    HMODULE hDll = LoadLibrary(L"Acpilib.dll"); // 加载DLL文件，获得DLL模块的句柄
    if (hDll != nullptr) {
        std::cout << "hello this is hdll"<<std::endl;
    }
    */
    //std::cout << "driverfg"<< driverfg << std::endl;
    std::cout << "hello" << std::endl;
    system("pause");

    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

