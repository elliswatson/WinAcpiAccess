#ifndef _AmlBuilder_H_
#define _AmlBuilder_H_

#include <map>
#include <string>
#include <list>
#include "AcpiNs.h"
#include "AcpiLib.h"
namespace AcpiWin {
	

	class AmlBuilder {
    private:
        static AcpiWin::AcpiNs* acpiNSRoot;
        //acpiNSRoot = new AcpiWin::AcpiNs("\\___", -1);
        AcpiWin::AcpiNs* acpiScope;
	public:
        AcpiWin::Acpilib* pacpilib;
        AcpiWin::Acpilib GetAcpilib();
        void SetAcpiLib(AcpiWin::Acpilib acpilib);
		static std::map<int ,std::string> mAcpiTypeMap;
        static std::map<std::string, void(AcpiWin::AmlBuilder::*)(AcpiWin::AcpiNs acpins)> mAcpiGetDataMap;
        //AmlBuilder();
        void GetMethodData(AcpiWin::AcpiNs acpiNS);
        void GetIntData(AcpiWin::AcpiNs acpiNS);
        void GetStringData(AcpiWin::AcpiNs acpiNS);
        void GetBufferData(AcpiWin::AcpiNs acpiNS);
        void GetPackgeData(AcpiWin::AcpiNs acpiNS);
        void GetFieldData(AcpiWin::AcpiNs acpiNS);
        int GetNsType(std::string* pString, AcpiWin::Acpilib acpilib);

        static void initMacpiTypeMap();
        AmlBuilder();
      
	};
}
#endif
