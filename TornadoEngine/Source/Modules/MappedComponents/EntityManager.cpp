/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "BL_Debug.h"

using namespace nsMappedComponents;

TEntityManager::EntityID TEntityManager::CreateEntity()
{
  TEntityPtr entity( new TEntity() );
  auto newID = NewIdentity();
  mEntityComponentListMap.insert( {newID, entity} );
  return newID;
}
//-------------------------------------------------------------------------------
void TEntityManager::DestroyEntity( EntityID id )
{
  auto pEntity = FindEntity( id );
  if ( pEntity == nullptr )
    return;

  mCBDestroyEntities.Notify( id );

  pEntity->Done();

  mEntityComponentListMap.erase( id );
}
//-------------------------------------------------------------------------------
int TEntityManager::GetMultiCount( MultiID mid )
{
  if ( mid == None )
    return 0;

  return mIdentityEntitiesMap[mid]->size();
}
//-------------------------------------------------------------------------------
TEntityManager::Identity TEntityManager::NewIdentity()
{
  auto ret = mIdentityForCreate;

  mIdentityForCreate++;
  return ret;
}
//-------------------------------------------------------------------------------
TEntityManager::TSortedEntity& TEntityManager::GetEntities( MultiID mid )
{
  if ( mid == None )
    return mEmptySet;

  auto s = mIdentityEntitiesMap[mid];
  return *( s.get() );
}
//-------------------------------------------------------------------------------
TEntity* TEntityManager::FindEntity( EntityID id )
{
  auto fit = mEntityComponentListMap.find( id );
  if ( mEntityComponentListMap.end() == fit )
    return nullptr;
  return fit->second.get();
}
//-------------------------------------------------------------------------------
TCallBackRegistrator1<TEntityManager::EntityID>* TEntityManager::GetCBOnDestroy()
{
  return &mCBDestroyEntities;
}
//-------------------------------------------------------------------------------
