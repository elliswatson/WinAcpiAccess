﻿// AcpiwinAccess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "AcpiLib.h"
#include "AmlBuilder.h"
#include <iostream>
#include "Utils.h"
//#include "stdlib.h"
#include "AcpiWin.h"
#include <thread>
//#include <chrono>
//#include "AcpiWin.h"
int main()
{   
    AcpiWin::logger.logInfo("test");
    AcpiWin::Acpilib acpilib;
    HANDLE hdriver = acpilib.openAcpiService(acpilib.getModule());
    acpilib.SetHdriver(hdriver);
    const wchar_t* pName = L"acpi.bin";
    //BOOL driverfg = acpilib.DriverLoaded();
    //acpilib.QueryAcpiNS(acpilib.getModule());
    //acpilib.SaveAcpiOBJ(pName, acpilib.getModule());

    /*
    
   // const char* pstr = "helloworld";
    //std::wstring str = utils.chartoWstring(pstr);
    //std::wcout << str << std::endl;
    //std::cout << str << std::endl;
    std::string str = "你好啊，消毒";
    utils::Utils utils(str);
    //std::cout << str << std::endl;
    const char* pcst = nullptr;
    pcst = utils.string2constChar(str);
   
     std::cout <<"pcst" << pcst << std::endl;
    char * charstr = utils.string2Char(str);
    
    std::cout << "charstr" << charstr << std::endl;
    std::wstring wstr(L"你好世界");
    std::wcout << "wstr" << wstr << std::endl;
    std::string dstr = utils.wstring2String(wstr);
    std::cout << "dstr" << dstr << std::endl;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(500));
    }
    */
    std::cout << "this is a err";
    std::cin.get();
    AcpiWin::logger.logError("this is error");
    AcpiWin::logger.logTrace("this is trace");
    AcpiWin::logger.logDebug("this is debug");
    AcpiWin::logger.logWarning("this is warning");
    AcpiWin::logger.logInfo("this is info");
    /*以下内容有错误
    AcpiWin::AmlBuilder amdbuilder;
    amdbuilder.pacpilib = &acpilib;
    AcpiWin::AcpiNs acpins("\\",0);
    acpins.Path = "\\____SB_PCI0_HID";
    amdbuilder.GetIntData(acpins);
    */

   
   
   
   
    system("pause");
   
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

