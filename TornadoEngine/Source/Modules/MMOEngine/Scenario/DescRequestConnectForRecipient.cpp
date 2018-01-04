/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DescRequestConnectForRecipient.h"
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

namespace nsMMOEngine
{
  TDescRequestConnectForRecipient::TDescRequestConnectForRecipient()
  {
    key        = 0;
    random_num = 0;
    id_session = 0;
  }
  void TDescRequestConnectForRecipient::Generate()
  {
    srand( (unsigned)time( NULL ) );
    short* pShort = (short*)&random_num;
    pShort[0] = rand();
    pShort[1] = rand();
  }
}
