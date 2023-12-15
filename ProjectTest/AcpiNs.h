#ifndef _AcpiNS_H_
#define _AcpiNS_H_
#include "Log.h"
#include <string>
#include <list>
#include <cstdint>

namespace AcpiWin {

    class AcpiNs {
    public:
       // Log logger;
        std::string Path;    //acpi path
        std::string Type;   // Type of data
        std::string strValue;
        uint64_t ulValue;
        std::string strValueType; 
        unsigned char* pbValue;  
        void SetPath(std::string val);
        std::string GetType(int type);
        //AcpiNs();
        AcpiNs(std::string path, int type)
        {
            SetPath(path);
            SetType(GetType(type));
        }
		std::string GetPath() const;
		//void SetPath(std::string val);
		std::string GetType() const;
		void SetType(std::string val);
		uint64_t GetUlValue() const;
		void SetUlValue(uint64_t val);
		std::string GetStrValueType() const;
		void SetStrValueType(std::string val);
		unsigned char* GetPbValue() const;
		void SetPbValue(unsigned char* val);

    private:
        AcpiWin::AcpiNs* Parent;
        std::list<AcpiWin::AcpiNs> ChildItems;

    };
}
#endif