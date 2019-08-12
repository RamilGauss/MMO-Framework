/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "ComponentInfo.h"
#include "Config.h"
#include "BL_Debug.h"
#include "ColanderVector.h"

namespace nsECSFramework
{
  class DllExport TEntity
  {
    typedef TColanderVector<TComponentInfo*> TComponentVec;// from memory pool
    TComponentVec mComponents;

    std::list<short> mComponentIndexInUse;

    TMemoryObjectPool<TComponentInfo>* mComponentInfoMemoryPool;
  public:
    TEntity();

    template<typename Component>
    Component* AddComponent( Component& c, int index );
    bool HasComponent( int index );
    template<typename Component>
    Component* GetComponent( int index );
    template<typename Component>
    void UpdateComponent( Component& c, int index );
    void RemoveComponent( int index );

    void Done();
  private:
  };
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component* TEntity::AddComponent( Component& c, int index )
  {
    auto pCI = mComponents[index];
    if ( pCI != nullptr )
    {
      BL_FIX_BUG();
      return nullptr;
    }
    mComponentIndexInUse.push_front( index );
    mComponents[index] = pCI;

    pCI = mComponentInfoMemoryPool->Pop();
    pCI->Init();
    auto it = mComponentIndexInUse.begin();
    pCI->mLinkToList.Set( mComponentIndexInUse, it );

    *( ( Component*) pCI->p ) = c;
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component* TEntity::GetComponent( int index )
  {
    auto pCI = mComponents[index];
    if ( pCI == nullptr )
      return nullptr;
    return ( Component*) ( pCI->p );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::UpdateComponent( Component& c, int index )
  {
    auto pCI = mComponents[index];
    if ( pCI == nullptr )
      return;
    *( ( Component*) ( pCI->p ) ) = c;
  }
  //---------------------------------------------------------------------------------------
}