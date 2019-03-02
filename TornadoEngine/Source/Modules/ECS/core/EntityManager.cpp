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

  mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TEntity>>();
}
//----------------------------------------------------------------------------------------------------
EntityID TEntityManager::CreateEntity()
{
  EntityID id = mEntities.mCounter;
  mEntities.Append( mEntityMemoryPool->Pop() );
  return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( EntityID id )
{
  auto lastIndex = mEntities.mCounter - 1;
  auto pEntity = mEntities.mVec[id];
  // swap last and current
  if ( lastIndex != id )
  {
    auto lastEntity = mEntities.mVec[lastIndex];
    mEntities.mVec[lastIndex] = nullptr;
    mEntities.mVec[id] = lastEntity;
    lastEntity->SetID( id );
  }

  pEntity->Done();
  mEntityMemoryPool->Push( pEntity );
  mEntities.PopBack();
}
//----------------------------------------------------------------------------------------------------
TEntity* TEntityManager::GetEntity( EntityID id ) const
{
  return mEntities.mVec[id];
}
//----------------------------------------------------------------------------------------------------
