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
#include "SortedThinningRestoreOrder.h"
#include "SingletonManager.h"

namespace nsECSFramework
{
  class DllExport TBaseReactiveSystem : public TSystem
  {
  protected:
    int mEventWaiterID;
    TSortedThinningRestoreOrder<TEntityID> mSTRO;
    TContainerForReactive* mCollector;

    bool mUseThinning;
  public:
    TBaseReactiveSystem( bool useThinning = true );
    virtual bool Filter( TEntityID& eid );

    virtual void Reactive( TEntityIdVectorRise& entities ) = 0;

    void Update() override final;

  protected:
    virtual void Filter( TEntityIdVectorRise& entities ) = 0;
  };
}
