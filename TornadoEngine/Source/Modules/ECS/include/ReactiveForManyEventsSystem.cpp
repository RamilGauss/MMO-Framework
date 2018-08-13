#include "ReactiveForManyEventsSystem.h"
#include "FastUpperBound.h"

using namespace MWorks::ECS;

TReactiveForManyEventsSystem::TReactiveForManyEventsSystem() : TBaseReactiveSystem( true )
{

}
//-------------------------------------------------------------------
void TReactiveForManyEventsSystem::Update()
{
  // конъюнкция списков с сохранением порядка
  mReactionEntities.Clear();
  // объединение из разных источников
  for( auto pConTypeMng : mConTypeMngPtrVec )
  {
    auto entities = pConTypeMng->GetEntities( this );
    mSTRO.Work( *entities );// прореживание каждого списка от "мёртвых" сущностей
    mReactionEntities += *entities;
    entities->Clear();
  }
  if( mReactionEntities.mCounter == 0 )
    return;

  // общее прореживание
  mSTRO.Work( mReactionEntities );
  if( mReactionEntities.mCounter == 0 )
    return;

  Filter( &mReactionEntities );
  if( mReactionEntities.mCounter == 0 )
    return;

  Reactive( mReactionEntities.mVec, mReactionEntities.mCounter );
}
//-------------------------------------------------------------------
