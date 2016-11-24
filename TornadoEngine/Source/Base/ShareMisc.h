/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ShareMiscH
#define ShareMiscH

#include "TypeDef.h"

// когда нужно проверить выражение и тут же выйти в случае отрицательного результата
#define RET_FALSE(f) \
if( f==false ) \
  return false;

//--------------------------------------------------
#ifdef WIN32
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
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

extern int DllExport GetCountCoreCPU();

// NOT Thread Safe!
extern void DllExport CreateConsole();
extern void DllExport DeleteConsole();
extern bool DllExport IsConsoleExist();

extern bool DllExport SetCurrentPathByFile(char* sPath);

template <class Type>
bool A_more_B_cycle(Type A, Type B)
{
  if(A>B)
  {
    if(A-B>Type(-1)/2) return false;
    else return true;
  }
  else
    if(B-A>Type(-1)/2) return true;

  return false;
}
//--------------------------------------------------

#endif
