/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

using namespace nsECSFramework;

TEntityManager::TEntityManager( int entityCount )
{
  mEntities.mVec.resize( entityCount );
  mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::Setup()
{

}
//----------------------------------------------------------------------------------------------------
TEntityID TEntityManager::CreateEntity()
{
  const TEntityID id = (const TEntityID) mEntities.mCounter;
  mEntities.Append( mEntityMemoryPool->Pop() );
  return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( TEntityID id )
{
  const auto pBegin = mEntities.mVec.data();

  auto ppID = pBegin + id;
  auto pEntity = *ppID;

  const auto lastIndex = mEntities.mCounter - 1;
  // swap last and current
  if ( lastIndex != id )
  {
    *ppID = *( pBegin + lastIndex );
    ( *ppID )->SetID( id );
  }

  pEntity->Done();
  mEntityMemoryPool->Push( pEntity );
  mEntities.PopBack();
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity( TEntityID id ) const
{
  return mEntities.mVec[id];
}
//----------------------------------------------------------------------------------------------------
