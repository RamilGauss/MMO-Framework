/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ReactiveForOneEventSystem.h"

using namespace nsECSFramework;

TReactiveForOneEventSystem::TReactiveForOneEventSystem() : TBaseReactiveSystem( false )
{

}
//-------------------------------------------------------------------
void TReactiveForOneEventSystem::Update()
{
  auto pConnTypeMng = mConTypeMngPtrVec[0];
  auto entities = pConnTypeMng->GetEntities( this );
  if( entities->mCounter == 0 )
    return;

  //mSTRO.Work( *entities );// сортировать, убрать дублированные и восстановить порядок создания сущностей
  if( entities->mCounter == 0 )
    return;

  // фильтрация
  Filter( entities );
  if( entities->mCounter == 0 )
    return;

  // готовый результат
  Reactive( entities->mVec, entities->mCounter );
  // обязательно очистить (требования IConnectTypeManager)
  entities->Clear();
}
//-------------------------------------------------------------------
