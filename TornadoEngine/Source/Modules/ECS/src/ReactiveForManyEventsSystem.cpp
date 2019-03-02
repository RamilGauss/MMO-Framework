/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ReactiveForManyEventsSystem.h"
#include "FastUpperBound.h"

using namespace nsECSFramework;

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
