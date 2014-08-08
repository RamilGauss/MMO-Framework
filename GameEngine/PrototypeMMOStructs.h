/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOStructsH
#define PrototypeMMOStructsH

#include "TypeDef.h"

struct DllExport PrototypeMMODescOpen
{
  unsigned short port;
  unsigned char  subNet;
  PrototypeMMODescOpen();
  PrototypeMMODescOpen(unsigned short p, unsigned char  sN = 0);
};

#endif
