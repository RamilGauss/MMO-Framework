/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include "TypeDef.h"


namespace nsMMOEngine
{
  struct MMO_ENGINE_EI TDescOpen
  {
    unsigned short port;
    unsigned char  subNet;
    TDescOpen();
    TDescOpen(unsigned short p, unsigned char  sN = 0);
  };
}

#endif
