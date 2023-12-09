#include "AmlBuilder.h"
#include "AcpiWin.h"




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
int64_t readInt64(const void* address) {
    const int64_t* ptr = static_cast<const int64_t*>(address);
    return *ptr;
}
void AcpiWin::AmlBuilder::GetIntData(AcpiWin::AcpiNs acpiNS)
{
    if (this->pacpilib != nullptr) {
        int type = -1;
        logger.logInfo("type" + type);
        //std::cout <<  << std::endl;
        type = this->pacpilib->GetType(acpiNS.Path);
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr= this->pacpilib->GetValue(acpiNS.Path,utype);
            if (intptr != nullptr) {
                acpiNS.ulValue = readInt64(intptr+0x10);
                //std::cout << "ulValue" << acpiNS.ulValue << std::endl;
                logger.logInfo("ulValue" + acpiNS.ulValue);
                this->pacpilib->FreeArg(intptr);
            }
        }
       // type = (*pacpilib).
    }
        
}

void AcpiWin::AmlBuilder::GetStringData(AcpiWin::AcpiNs acpiNS)
{
    if (this->pacpilib != nullptr) {
        int type = -1;
        type = this->pacpilib->GetType(acpiNS.Path);
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.Path, utype);
            if (intptr != nullptr) {
                std::string strValue= std::to_string(*(intptr+0x10));
                this->pacpilib->FreeArg(intptr);
            }
        }
        // type = (*pacpilib).
    }

}

void AcpiWin::AmlBuilder::GetBufferData(AcpiWin::AcpiNs acpiNS)
{

    if (this->pacpilib != nullptr) {
        int type = -1;
        type = this->pacpilib->GetType(acpiNS.Path);
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.Path, utype);
            if (intptr != nullptr) {
                UINT32 val = (UINT32) * (intptr);
                if (val == 0x426F6541) {
                    int DataLength =*(intptr + 0x4);
                    if (acpiNS.pbValue == nullptr) {
                        acpiNS.pbValue = new byte[DataLength];
                        std::memcpy(acpiNS.pbValue,intptr, DataLength);
                    }
                }
                this->pacpilib->FreeArg(intptr);
            }

        }
    }
}

void AcpiWin::AmlBuilder::GetPackgeData(AcpiWin::AcpiNs acpiNS)
{

    if (this->pacpilib != nullptr) {
        int type = -1;
        type = this->pacpilib->GetType(acpiNS.Path);
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.Path, utype);
            if (intptr != nullptr) {
                UINT32 val = (UINT32) * (intptr);
                if (val == 0x426F6541) {
                    int DataLength = *(intptr + 0x4);
                    if (acpiNS.pbValue == nullptr) {
                        acpiNS.pbValue = new byte[DataLength];
                        std::memcpy(acpiNS.pbValue, intptr, DataLength);
                    }
                }
                this->pacpilib->FreeArg(intptr);
            }

        }
    }
}

void AcpiWin::AmlBuilder::GetFieldData(AcpiWin::AcpiNs acpiNS)
{

    if (this->pacpilib != nullptr)
    {
        //int type = -1;
        //type = acpiLib.GetType(acpiNS.Path);
        //if (type != -1)
        //{
        //    ushort utype = (ushort)type;
        //    IntPtr intPtr = acpiLib.GetValue(acpiNS.Path, ref utype);
        //    if (intPtr != IntPtr.Zero)
        //    {
        //        int DataLength = Marshal.ReadInt32(intPtr + 0x4);                        
        //        acpiLib.FreeArg(intPtr);
        //    }
        //}
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


