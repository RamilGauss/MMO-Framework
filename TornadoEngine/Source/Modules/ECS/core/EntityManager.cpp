/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "SingletonManager.h"
#include "Entity.h"

#include <intrin.h>

using namespace nsECSFramework;

TEntityManager::TEntityManager( int entityCount )
{

  mEntityMemoryPool = SingletonManager()->Get<TMemoryObjectPool<Entity>>();
}
//----------------------------------------------------------------------------------------------------
EntityID TEntityManager::CreateEntity()
{
  const EntityID id = mEntities.mCounter;
  auto pEntity = mEntityMemoryPool->Pop();
  pEntity->SetID( id );
  mEntities.Append( pEntity );
  return id;
}
//----------------------------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( EntityID id )
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
Entity* TEntityManager::GetEntity( EntityID id ) const
{
  return mEntities.mVec[id];
}
//----------------------------------------------------------------------------------------------------
