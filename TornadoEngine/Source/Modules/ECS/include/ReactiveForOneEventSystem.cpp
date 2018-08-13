#include "ReactiveForOneEventSystem.h"

using namespace MWorks::ECS;

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

  mSTRO.Work( *entities );// сортировать, убрать дублированные и восстановить порядок создания сущностей
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
