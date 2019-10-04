/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  template<typename Component>
  class DllExport TReactiveOnRemoveSystem : public TBaseReactiveSystem
  {
  public:
    TReactiveOnRemoveSystem( bool useThinning = true ) : TBaseReactiveSystem( useThinning )
    {
      auto pEntMng = GetEntityManager();
      mEventWaiterID = pEntMng->OnRemove<Component>();
      mCollector = &( pEntMng->mRemoveCollector );
    }
  protected:
    void Filter( TEntityIdVectorRise& entities ) override
    {
      auto pEntMng = GetEntityManager();
      // entity
      int filtered = 0;
      for ( size_t i = 0; i < entities.mCounter; i++ )
      {
        auto& entity = entities.mVec[i];
        if ( pEntMng->HasComponent<Component>( entity ) )
          continue;
        if ( Filter( entity ) )
        {
          entities.mVec[filtered] = entity;
          filtered++;
        }
      }
      entities.mCounter = filtered;
    }
  };
}