/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "DataManager.h"

namespace nsMMOEngine
{
  class TMaster;
  class TBaseMasterLogic
  {
  protected:
    TMaster* mMaster = nullptr;

    TDataManager mDataMng;
  public:
    TBaseMasterLogic( TMaster* p )
    {
      mMaster = p;
    }
  };
}
