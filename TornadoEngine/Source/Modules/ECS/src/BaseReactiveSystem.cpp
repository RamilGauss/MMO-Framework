/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseReactiveSystem.h"

using namespace nsECSFramework;

TBaseReactiveSystem::TBaseReactiveSystem( bool moreThanOneEvent )
{
  mMoreThanOneEvent = moreThanOneEvent;
}
//--------------------------------------------------------------------------------------
void TBaseReactiveSystem::IncrementAndCheckEventCount()
{
  mEventCounter++;
  if( mMoreThanOneEvent == false )
  {
    assert( mEventCounter == 1 );
  }
}
//--------------------------------------------------------------------------------------
void TBaseReactiveSystem::AddConnectTypeManager( IConnectTypeManager* p )
{
  mConTypeMngPtrVec.push_back( p );
}
//--------------------------------------------------------------------------------------
void TBaseReactiveSystem::Filter( TVectorRise<TEntity> *pEntities )
{
  // entity
  //int filtered = 0;
  //for( size_t i = 0; i < pEntities->mCounter; i++ )
  //{
  //  auto& entity = pEntities->mVec[i];
  //  if( GetRegistry()->valid( entity ) )// entity существует
  //    if( Filter( entity ) )
  //    {
  //      pEntities->mVec[filtered] = entity;
  //      filtered++;
  //    }
  //}
  //pEntities->mCounter = filtered;
}
//--------------------------------------------------------------------------------------
