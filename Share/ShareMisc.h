/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ShareMiscH
#define ShareMiscH

#include "TypeDef.h"

#define RET_FALSE(f) \
  if(f==false) \
  return false;
//--------------------------------------------------
#if defined( WIN32 )
#pragma pack(push, 1)
#endif

struct TIP_Port
{
  unsigned int ip;
  unsigned short port;
  TIP_Port(){}
  TIP_Port(unsigned int _ip, unsigned short _port)
  {
    ip   = _ip;
    port = _port;
  }
  void Set(unsigned int _ip, unsigned short _port)
  {
    ip   = _ip;
    port = _port;
  }
  bool operator < (const TIP_Port& right) const
  {
    if(ip < right.ip)
      return true;
    else
      if(ip == right.ip)
        if(port < right.port)
          return true;
    return false;
  }
};

#if defined( WIN32 )
#pragma pack(pop)
#endif



extern int SHARE_EI GetCountCoreCPU();

// NOT Thread Safe!
extern void SHARE_EI CreateConsole();
extern void SHARE_EI DeleteConsole();
extern bool SHARE_EI IsConsoleExist();

//--------------------------------------------------

#endif
