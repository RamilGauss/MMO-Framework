/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include <string>

// когда нужно проверить выражение и тут же выйти в случае отрицательного результата
#define RET_FALSE(f) \
if( f==false ) \
  return false;

//--------------------------------------------------
#pragma pack(push, 1)

struct TIP_Port
{
    unsigned int ip;
    unsigned short port;
    TIP_Port() {}
    TIP_Port(unsigned int _ip, unsigned short _port)
    {
        this->ip = _ip;
        this->port = _port;
    }
    void Set(unsigned int _ip, unsigned short _port)
    {
        this->ip = _ip;
        this->port = _port;
    }
    bool operator < (const TIP_Port& other) const
    {
        if (ip < other.ip) {
            return true;
        }

        if (ip > other.ip) {
            return false;
        }
        
        if (port < other.port) {
            return true;
        }
        return false;
    }

    bool operator == (const TIP_Port& other) const
    {
        return ip == other.ip && port == other.port;
    }

    const char* ToString()
    {
        static std::string _toString;

        char s[100];
        unsigned char* p = (unsigned char*) &ip;
        sprintf(s, "%u.%u.%u.%u:%u", p[3], p[2], p[1], p[0], port);
        _toString = s;
        return _toString.data();
    }
};

template <>
struct std::hash<TIP_Port>
{
    size_t operator () (TIP_Port const& ipPort) const
    {
        return std::hash<unsigned int>()(ipPort.ip) ^ std::hash<unsigned short>()(ipPort.port);
    }
};

#pragma pack(pop)

extern int DllExport GetCountCoreCPU();
extern bool DllExport GetBrandCPU(std::string& CPUBrandString);

// NOT Thread Safe!
extern void DllExport CreateConsole();
extern void DllExport DeleteConsole();
extern bool DllExport IsConsoleExist();

extern bool DllExport SetCurrentPathByFile(char* sPath);

extern std::string DllExport GetRandomString(int len);

template <class Type>
bool A_more_B_cycle(Type A, Type B)
{
    if (A > B) {
        if (A - B > Type(-1) / 2) return false;
        else return true;
    } else
        if (B - A > Type(-1) / 2) return true;

    return false;
}
