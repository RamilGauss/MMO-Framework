/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <vector>

#include "System.h"
#include "VectorRise.h"
#include "ConnectTypeManager.h"
#include "SortedThinningRestoreOrder.h"
#include "SingletonManager.h"

namespace nsECSFramework
{
  class DllExport TBaseReactiveSystem : public TSystem
  {
  protected:
    TEntityLoopList mEntLoopList;
    int mEventWaiterID;
  public:
    virtual bool Filter( TEntityID& eid )
    {
      return true;
    }

    virtual void Reactive( TEntityID& eid ) = 0;
  };
}
