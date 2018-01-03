/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WDescOpen.h"

namespace WrapperMMOEngine
{
  WDescOpen::WDescOpen()
  {
    subNet = 0;
  }
  //-------------------------------------------------------------------------
  WDescOpen::WDescOpen(unsigned short p, unsigned char  sN )
  {
    port   = p;
    subNet = sN;
  }
  //-------------------------------------------------------------------------
}
