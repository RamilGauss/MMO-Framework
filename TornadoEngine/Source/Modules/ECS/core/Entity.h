/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <vector>
#include "Components.h"
#include "Config.h"

namespace nsECSFramework
{
  class DllExport TEntity
  {
    EntityID mID;

    typedef std::vector<IComponent*> TComponentVec;
    TComponentVec mComponents;
  public:

    template<typename Component>
    void AddComponent( Component& c );
    template<typename Component>
    Component& GetComponent();
    template<typename Component>
    void UpdateComponent( Component& c );
    template<typename Component>
    void RemoveComponent( Component& c );

    void SetID( EntityID id );

    void Done();
  };
  template<typename Component>
  void TEntity::AddComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component& TEntity::GetComponent()
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::UpdateComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::RemoveComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
}