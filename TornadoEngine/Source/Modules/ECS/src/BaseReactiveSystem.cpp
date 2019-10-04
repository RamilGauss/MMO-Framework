/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseReactiveSystem.h"


namespace nsECSFramework
{
  TBaseReactiveSystem::TBaseReactiveSystem( bool useThinning )
  {
    mUseThinning = useThinning;
  }
  //-----------------------------------------------------------------------------
  bool TBaseReactiveSystem::Filter( TEntityID& eid )
  {
    return true;
  }
  //-----------------------------------------------------------------------------
  void TBaseReactiveSystem::Update()
  {
    mCollector->Get( mEventWaiterID, [this]( TEntityIdVectorRise& entities )
    {
      if ( entities.mCounter == 0 )
        return;

      if ( mUseThinning )
        mSTRO.Work( entities );// сортировать, убрать дублированные и восстановить порядок создания сущностей
      if ( entities.mCounter == 0 )
        return;

      // фильтрация
      Filter( entities );
      if ( entities.mCounter == 0 )
        return;

      // готовый результат
      Reactive( entities );
    } );
  }
  //-----------------------------------------------------------------------------
}
