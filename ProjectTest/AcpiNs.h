#ifndef _AcpiWin_H_
#define _AcpiWin_H_
#include "Log.h"
#include <string>
#include <list>

namespace AcpiWin {

    class AcpiNs {
    public:
       // Log logger;
        std::string Path;    // acpi path
        std::string Type;   // Type of data
        std::string strValue;
        long long int ulValue;
      
        std::string strValueType;
        unsigned char* pbValue;
        std::string GetType(int type);
        //AcpiNs();
        AcpiNs(std::string path, int type)
        {
            Path = path;
            Type = GetType(type);
        }

    private:
        AcpiWin::AcpiNs* Parent;
        std::list<AcpiWin::AcpiNs> ChildItems;
        /// <summary>
        /// Constructor of acpi name space
        /// </summary>
        /// <param name="path"></param>
        /// <param name="type"></param>


    };
}
#endif