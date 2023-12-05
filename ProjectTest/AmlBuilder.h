#ifndef _AmlBuilder_H_
#define _AmlBuilder_H_

#include <map>
#include <string>
#include <list>
#include "AcpiNs.h"
#include "AcpiLib.h"
namespace AcpiWin {
	

	class AmlBuilder {
	public:
		static std::map<int ,std::string> mAcpiTypeMap;
        void GetMethodData(AcpiWin::AcpiNs acpiNS);
        void GetIntData(AcpiWin::AcpiNs acpiNS);
        void GetStringData(AcpiWin::AcpiNs acpiNS);
        void GetBufferData(AcpiWin::AcpiNs acpiNS);
        void GetPackgeData(AcpiWin::AcpiNs acpiNS);
        void GetFieldData(AcpiWin::AcpiNs acpiNS);
        int GetNsType(std::string* pString, AcpiWin::Acpilib acpilib);

		static void initMacpiTypeMap(AcpiWin::AmlBuilder amlbuilder) {
           
                // mAcpiTypeMap.insert();
                mAcpiTypeMap[-1] = "Uninitialized";;
                 mAcpiTypeMap[0] = "Scope";
                 mAcpiTypeMap[1] = "Integer";
                 mAcpiTypeMap[2] = "String";
                 mAcpiTypeMap[3] = "Buffer";
                 mAcpiTypeMap[4] = "Pacakge";
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
		
        
	};
}
#endif
