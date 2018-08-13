#include "BaseReactiveSystem.h"

using namespace MWorks::ECS;

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
  int filtered = 0;
  for( size_t i = 0; i < pEntities->mCounter; i++ )
  {
    auto& entity = pEntities->mVec[i];
    if( GetRegistry()->valid( entity ) )// entity существует
      if( Filter( entity ) )
      {
        pEntities->mVec[filtered] = entity;
        filtered++;
      }
  }
  pEntities->mCounter = filtered;
}
//--------------------------------------------------------------------------------------
