/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"

namespace nsECSFramework
{
  class DllExport TEntityManager
  {
  public:
    TEntityManager( int entityCount );

    inline EntityID CreateEntity();
    inline void DestroyEntity( EntityID id );

    template <typename Component>
    void AddComponent( EntityID id, Component& c );
    template <typename Component>
    void UpdateComponent( EntityID id, Component& c );
    template <typename Component>
    const Component& GetComponent( EntityID id );
    template <typename Component>
    void RemoveComponent( EntityID id );

    template <typename Component>
    EntityID GetUnique( EntityID id, Component& c );

    template <typename Component>
    const TEntityList& GetMulti( EntityID id, Component& c );

    template <typename C0, typename C1>
    const TEntityList& GetMultiMix( EntityID id, C0& c0, C1& c1 );

    template <typename C0, typename C1, typename C2>
    const TEntityList& GetMultiMix( EntityID id, C0& c0, C1& c1, C2& c2 );

    template <typename C0>
    const TEntityList& GetHas( EntityID id );
    template <typename C0, typename C1>
    const TEntityList& GetHas( EntityID id );
    template <typename C0, typename C1, typename C2>
    const TEntityList& GetHas( EntityID id );

    //void OnAddCallback();
    //void OnUpdateCallback();
    //void OnRemoveCallback();
    //void OnDestroyCallback();
  private:
    TMemoryObjectPool<nsECSFramework::Entity>* mEntityMemoryPool;

    TVectorRise<nsECSFramework::Entity*> mEntities;

    nsECSFramework::Entity* GetEntity( EntityID id ) const;
  };
  template <typename Component>
  void TEntityManager::AddComponent( EntityID id, Component& c )
  {
    auto pEntity = GetEntity( id );
    pEntity->AddComponent( c );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::UpdateComponent( EntityID id, Component& c )
  {
    auto pEntity = GetEntity( id );
    pEntity->UpdateComponent( c );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const Component& TEntityManager::GetComponent( EntityID id )
  {
    auto pEntity = GetEntity( id );
    return pEntity->GetComponent();
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::RemoveComponent( EntityID id )
  {
    auto pEntity = GetEntity( id );
    pEntity->RemoveComponent();
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  EntityID TEntityManager::GetUnique( EntityID id, Component& c )
  {
    return 0;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const TEntityList& TEntityManager::GetMulti( EntityID id, Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1>
  const TEntityList& TEntityManager::GetMultiMix( EntityID id, C0& c0, C1& c1 )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1, typename C2>
  const TEntityList& TEntityManager::GetMultiMix( EntityID id, C0& c0, C1& c1, C2& c2 )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename C0>
  const TEntityList& TEntityManager::GetHas( EntityID id )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1>
  const TEntityList& TEntityManager::GetHas( EntityID id )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1, typename C2>
  const TEntityList& TEntityManager::GetHas( EntityID id )
  {

  }
  //---------------------------------------------------------------------------------------
}