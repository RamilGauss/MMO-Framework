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
  struct TEntityData
  {
    EntityID mID;

    typedef std::vector<IComponent*> TComponentVec;
    //TComponentVec mComponents;
  };
  class DllExport Entity
  {
    TEntityData* mData = new TEntityData();
    //EntityID mID;

    //typedef std::vector<IComponent*> TComponentVec;
    //TComponentVec mComponents;
  public:

    template<typename Component>
    void AddComponent( Component& c );
    template<typename Component>
    Component& GetComponent();
    template<typename Component>
    void UpdateComponent( Component& c );
    template<typename Component>
    void RemoveComponent( Component& c );

    inline void SetID( EntityID id );

    inline void Done();
  };
  template<typename Component>
  void Entity::AddComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  Component& Entity::GetComponent()
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void Entity::UpdateComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void Entity::RemoveComponent( Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
}