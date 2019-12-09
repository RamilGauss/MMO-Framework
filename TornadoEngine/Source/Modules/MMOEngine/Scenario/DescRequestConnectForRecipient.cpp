/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DescRequestConnectForRecipient.h"
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

namespace nsMMOEngine
{
  void TDescRequestConnectForRecipient::Generate()
  {
    srand( (unsigned)time( nullptr ) );
    short* pShort = (short*)&random_num;
    pShort[0] = rand();
    pShort[1] = rand();
  }
}
