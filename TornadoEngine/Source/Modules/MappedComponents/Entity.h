/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <memory>
#include <map>
#include <functional>
#include <typeindex>

#include "IComponent.h"
#include "ContainerArrObj.h"

namespace nsMappedComponents
{
  class DllExport TEntity
  {
  public:
    typedef TContainerArrObj<IComponent> TComponentContainer;// shared_ptr не хочет с этим работать!
    typedef std::map<std::type_index, TComponentContainer> TComponentMap;

    using RemoveFunc = std::function<void()>;
    typedef std::map<std::type_index, RemoveFunc> TTypeRemoveFuncMap;

    virtual ~TEntity();// for auto remove all components
    void Done();

    template<typename Component>
    void AddComponent( Component& c, RemoveFunc removeFunc );
    template<typename Component>
    void RemoveComponent();
    template<typename Component>
    bool GetComponent( Component& c );
    template<typename Component>
    bool HasComponent();
    bool HasComponent( std::type_index type );

    template<typename Component>
    void UpdateComponent( Component& c );
  private:
    TComponentMap mComponentMap;
    TTypeRemoveFuncMap mForRemoveMap;
  private:
    template<typename Component>
    std::type_index GetType();
    
    RemoveFunc GetFirstRemoveFunc();
  };
  //----------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::AddComponent( Component& c, RemoveFunc removeFunc )
  {
    auto componentType = GetType<Component>();
    mForRemoveMap.insert( {componentType, removeFunc} );

    auto pC = new Component();
    *pC = c;
    TComponentContainer container;
    container.EntrustByCount( (char*) pC );
    mComponentMap.insert( {componentType, container} );
  }
  //----------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::RemoveComponent()
  {
    auto componentType = GetType<Component>();
    mForRemoveMap.erase( componentType );
    mComponentMap.erase( componentType );
  }
  //----------------------------------------------------------------------------------------
  template<typename Component>
  bool TEntity::GetComponent( Component& c )
  {
    auto componentType = GetType<Component>();
    auto fit = mComponentMap.find( componentType );
    if ( fit == mComponentMap.end() )
      return false;
    c = ( (Component*) fit->second.GetPtr() )[0];
    return true;
  }
  //----------------------------------------------------------------------------------------
  template<typename Component>
  void TEntity::UpdateComponent( Component& c )
  {
    auto componentType = GetType<Component>();
    auto pC = (Component*) mComponentMap[componentType].GetPtr();
    pC[0] = c;
  }
  //----------------------------------------------------------------------------------------
  template<typename Component>
  bool TEntity::HasComponent()
  {
    auto componentType = GetType<Component>();
    return HasComponent( componentType );
  }
  //----------------------------------------------------------------------------------------
  template<typename Component>
  std::type_index TEntity::GetType()
  {
    return std::type_index( typeid( Component ) );
  }
  //----------------------------------------------------------------------------------------
}
