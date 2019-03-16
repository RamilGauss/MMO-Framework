/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include "Components.h"
#include "Config.h"
#include "BL_Debug.h"
#include "ColanderVector.h"

namespace nsECSFramework
{
  class DllExport TEntity
  {
    typedef TColanderVector<IComponent*> TComponentVec;
    TComponentVec mComponents;

    std::list<short> mComponetIndexInUse;
  public:
    template<typename Component>
    Component* AddComponent( Component& c, int index );
    template<typename Component>
    Component& GetComponent( int index );
    template<typename Component>
    void UpdateComponent( Component& c, int index );
    template<typename Component>
    void RemoveComponent( int index );

    void SetID( TEntityID id );

    void Done();
  private:
  };
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component* TEntity::AddComponent( Component& c, int index )
  {
    auto isEmpty = mComponents[index] == nullptr;
    if ( isEmpty == false )
    {
      BL_FIX_BUG();
      return nullptr;
    }
    auto pC = new Component();
    *pC = c;
    mComponents[index] = pC;
    mComponetIndexInUse.push_front( index );

    auto it = mComponetIndexInUse.begin();
    pC->mInEntityLinkList.Set( mComponetIndexInUse, it );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component& TEntity::GetComponent( int index )
  {
    return *( mComponents[index] );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::UpdateComponent( Component& c, int index )
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::RemoveComponent( int index )
  {
    auto pC = mComponents[index];
    if ( pC == nullptr )
      return;
    pC->mInEntityLinkList.Erase();
    for( auto& linkToList : pC->mContainerLinkList )
    { 
      linkToList.Erase();
    }
  }
  //---------------------------------------------------------------------------------------
}