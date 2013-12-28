/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Structs.h"

using namespace nsMMOEngine;

TDescOpen::TDescOpen()
{
  subNet = 0;
}
//-------------------------------------------------------------------------
TDescOpen::TDescOpen(unsigned short p, unsigned char  sN)
{
  port   = p;
  subNet = sN;
}
//-------------------------------------------------------------------------
