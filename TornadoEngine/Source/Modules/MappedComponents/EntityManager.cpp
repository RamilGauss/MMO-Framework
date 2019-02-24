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
  FindEntity( id )->Done();
  
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
TEntityManager::TSortedEntity::iterator TEntityManager::GetBegin( MultiID mid )
{
  if ( mid == None )
    return TSortedEntity::iterator();

  return mIdentityEntitiesMap[mid]->begin();
}
//-------------------------------------------------------------------------------
TEntityManager::TSortedEntity::iterator TEntityManager::GetEnd( MultiID mid )
{
  if ( mid == None )
    return TSortedEntity::iterator();

  return mIdentityEntitiesMap[mid]->end();
}
//-------------------------------------------------------------------------------

