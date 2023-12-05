#include "AmlBuilder.h"





AcpiWin::Acpilib AcpiWin::AmlBuilder::GetAcpilib()
{
    
    return *(this->pacpilib);
}

void AcpiWin::AmlBuilder::SetAcpiLib(AcpiWin::Acpilib acpilib)
{
    this->pacpilib = &acpilib;
}

void AcpiWin::AmlBuilder::GetMethodData(AcpiWin::AcpiNs acpiNS)
{

}

void AcpiWin::AmlBuilder::GetIntData(AcpiWin::AcpiNs acpiNS)
{
    if (this->pacpilib != nullptr) {
        int type = -1;
       // type = (*pacpilib).
    }
        
}

int AcpiWin::AmlBuilder::GetNsType(std::string* pString , AcpiWin::Acpilib acpilib)
{
    HMODULE hdll = acpilib.getModule();
    HANDLE handle = NULL;

    if (hdll != NULL) {
        typedef int(*GetNsType)(std::string* pstring);
        GetNsType getNsType = (GetNsType)GetProcAddress(hdll, "GetNSType"); // 获取DLL函数的地址
        if (getNsType != NULL) {
            
            return getNsType(pString);
        }
        else {
            std::cout << "Failed to get NsType." << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "GetNSType Failed to load DLL." << std::endl;
    }

    return FALSE;
    
   

}


