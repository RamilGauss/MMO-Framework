/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  template<typename Component>
  class DllExport TReactiveOnAddSystem : public TBaseReactiveSystem
  {
  public:
    TReactiveOnAddSystem( bool useThinning = true ) : TBaseReactiveSystem( useThinning )
    {
      auto pEntMng = GetEntityManager();
      mEventWaiterID = pEntMng->OnAdd<Component>();
      mCollector = &( pEntMng->mAddCollector );
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
        if ( pEntMng->HasComponent<Component>( entity ) == false )
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