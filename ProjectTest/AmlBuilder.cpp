#include "AmlBuilder.h"
#include "AcpiWin.h"

AcpiWin::AcpiNs* AcpiWin::AmlBuilder::acpiNSRoot;
std::map<std::string, void(AcpiWin::AmlBuilder::*)(AcpiWin::AcpiNs)> AcpiWin::AmlBuilder::mAcpiGetDataMap ;
std::map<int, std::string> AcpiWin::AmlBuilder::mAcpiTypeMap ;

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
        type = this->pacpilib->GetType(acpiNS.GetPath());
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr= this->pacpilib->GetValue(acpiNS.GetPath(),utype);
            if (intptr != nullptr) {
                acpiNS.SetUlValue(readInt64(intptr+0x10));
                //std::cout << "ulValue" << acpiNS.ulValue << std::endl;
                logger.logInfo("ulValue" + acpiNS.GetUlValue());
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
        type = this->pacpilib->GetType(acpiNS.GetPath());
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.GetPath(), utype);
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
        type = this->pacpilib->GetType(acpiNS.GetPath());
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.GetPath(), utype);
            if (intptr != nullptr) {
                UINT32 val = (UINT32) * (intptr);
                if (val == 0x426F6541) {
                    int DataLength =*(intptr + 0x4);
                    if (acpiNS.GetPbValue() == nullptr) {
                        //acpiNS.pbValue = byte[DataLength];
                        //std::memcpy(acpiNS.pbValue,intptr, DataLength);
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
        type = this->pacpilib->GetType(acpiNS.GetPath());
        if (type != -1) {
            USHORT utype = (USHORT)type;
            int* intptr = this->pacpilib->GetValue(acpiNS.GetPath(), utype);
            if (intptr != nullptr) {
                UINT32 val = (UINT32) * (intptr);
                if (val == 0x426F6541) {
                    int DataLength = *(intptr + 0x4);
                    if (acpiNS.GetPbValue() == nullptr) {
                        acpiNS.SetPbValue(new unsigned char[DataLength]);
                        std::memcpy(acpiNS.GetPbValue(), intptr, DataLength);
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
void AcpiWin::AmlBuilder::initMacpiTypeMap()
{

	// mAcpiTypeMap.insert();
	mAcpiTypeMap[-1] = "Uninitialized";;
	mAcpiTypeMap[0] = "Scope";
	mAcpiTypeMap[1] = "Integer";
	mAcpiTypeMap[2] = "String";
	mAcpiTypeMap[3] = "Buffer";
	mAcpiTypeMap[4] = "Package";
	mAcpiTypeMap[5] = "FieldUnit";
	mAcpiTypeMap[6] = "Device";
	mAcpiTypeMap[7] = "Sync";
	mAcpiTypeMap[8] = "Method";
	mAcpiTypeMap[9] = "Mutex";
	mAcpiTypeMap[0xA] = "OperationRegion";
	mAcpiTypeMap[0xB] = "PowerSource";
	mAcpiTypeMap[0xC] = "Processor";
	mAcpiTypeMap[0xD] = "ThermalZone";
	mAcpiTypeMap[0xE] = "BufferUnit";
	mAcpiTypeMap[0xF] = "DDBHandle";
	mAcpiTypeMap[0x10] = "Debug";
	mAcpiTypeMap[0x80] = "Alias";
	mAcpiTypeMap[0x81] = "DataAlias";
	mAcpiTypeMap[0x82] = "BankField";
	mAcpiTypeMap[0x83] = "Field";
	mAcpiTypeMap[0x84] = "IndexField";
	mAcpiTypeMap[0x85] = "Data";
	mAcpiTypeMap[0x86] = "DataField";
	mAcpiTypeMap[0x87] = "DataObj";
	mAcpiTypeMap[0x88] = "Rev";
	mAcpiTypeMap[0x89] = "CreateField";
	mAcpiTypeMap[0x8A] = "External";

}

AcpiWin::AmlBuilder::AmlBuilder()
{

    if (mAcpiTypeMap.empty()) {
        // 还未初始化
        // 进行初始化操作
        initMacpiTypeMap();
    }
    
    if (mAcpiGetDataMap.size() == 0)
    {
        mAcpiGetDataMap["Method"] = &AcpiWin::AmlBuilder::GetMethodData;
        mAcpiGetDataMap["Integer"] = &AcpiWin::AmlBuilder::GetIntData;
        mAcpiGetDataMap["String"] = &AcpiWin::AmlBuilder::GetStringData;
        mAcpiGetDataMap["Buffer"] = &AcpiWin::AmlBuilder::GetBufferData;
        mAcpiGetDataMap["Pacakge"] = &AcpiWin::AmlBuilder::GetPackgeData;
        mAcpiGetDataMap["FieldUnit"] = &AcpiWin::AmlBuilder::GetFieldData;
    }
   

    if (acpiNSRoot == nullptr)
    {
        acpiNSRoot = new AcpiWin::AcpiNs("\\___", -1);
    }
    acpiScope = acpiNSRoot;
    
}