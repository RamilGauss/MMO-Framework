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
  class DllExport TReactiveOnAddSystem : public TBaseReactiveSystem
  {
  public:

    TReactiveOnAddSystem()
    {
      mEventWaiterID = GetEntityManager()->OnAdd<Component>( this );
    }

    void Update() override final
    {
      auto pEntMng = GetEntityManager();
      pEntMng->GetAddEvents( mEventWaiterID, mEntLoopList );
      TEntityID eid;
      while ( mEntLoopList.Next( eid ) )
      {
        if ( pEntMng->HasComponent<Component>( eid ) )
        {
          if ( Filter( eid ) )
            Reactive( eid );
        }
      }
    }
  };
}