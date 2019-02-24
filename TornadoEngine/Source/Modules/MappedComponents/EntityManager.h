/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <memory>
#include <set>
#include <list>
#include <vector>
#include <functional>
#include <boost/bimap/bimap.hpp>

#include "SingletonManager.h"
#include "IComponent.h"
#include "IMappedComponent.h"
#include "ContainerArrObj.h"
#include "Entity.h"

namespace nsMappedComponents
{
  class DllExport TEntityManager
  {
    TSingletonManager mSM;// for unique map, group, multi
  public:
    typedef unsigned int Identity;
    typedef Identity EntityID;
    typedef Identity MultiID;

    const Identity None = 0;

    typedef std::set<EntityID> TSortedEntity;

    // сообщить какие возможны варианты использования поиска
    template<typename Multi, typename Group>
    void JoinMultiToGroup();

    // create/destroy
    EntityID CreateEntity();
    void DestroyEntity( EntityID id );
    // components
    template<typename Component>
    void AddComponent( EntityID id, Component& c );
    template<typename Component>
    void UpdateComponent( EntityID id, Component& newValue );
    template<typename Component>
    void RemoveComponent( EntityID id );
    template<typename Component>
    bool GetComponent( EntityID id, Component& c );

    // search
    template<typename Component>
    EntityID GetUnique( Component& c );

    template<typename Component>
    MultiID GetMultiID( Component& c );
    template<typename Component, typename Group>
    MultiID GetMultiID( Component& c, Group& g );

    int GetMultiCount( MultiID mid );

    TSortedEntity::iterator GetBegin( MultiID mid );
    TSortedEntity::iterator GetEnd( MultiID mid );
  private:
    // и для Entity и Multi
    Identity mIdentityForCreate = 1;

    typedef std::shared_ptr<TEntity> TEntityPtr;
    std::map<EntityID, TEntityPtr> mEntityComponentListMap;// все Entity

    // via id
    template <typename Component>
    using TComponentEntityMap = std::map<Component, Identity>;// unique

    typedef std::shared_ptr<TSortedEntity> TSharedPtrSortedEntity;
    typedef std::map<Identity, TSharedPtrSortedEntity> TIdentityEntitiesMap;

    template <typename Component>
    using TTypeIdentityMap = std::map<Component, Identity>;// multi -> identity

    template <typename Component>
    using TIntTypeIdentityMap = std::map<int, TTypeIdentityMap<Component>>;// номер группы -> Multi identity

    template <typename Component>
    using TGroupMap = std::map<std::type_index, TIntTypeIdentityMap<Component>>;// тип группы -> тип Multi 

    TIdentityEntitiesMap mIdentityEntitiesMap;
  private:
    using RemoveFunc = std::function<void()>;
    typedef std::map<std::type_index, RemoveFunc> TTypeRemoveFuncMap;

    using UpdateFunc = std::function<void( EntityID id )>;

    using UpdateMultiFunc = std::function<void( EntityID id, void* oldMultiValue, void* newMultiValue )>;
    using UpdateMultiInGroupFunc = std::function<void( EntityID id, void* oldMultiValue, void* newMultiValue )>;
    using UpdateMultiByGroupFunc = std::function<void( EntityID id, void* oldGroupValue, void* newGroupValue )>;

    struct TUpdateMultiAndGroup
    {
      UpdateFunc addMultiByGroupFunc;
      UpdateFunc removeMultiByGroupFunc;
      UpdateMultiInGroupFunc updateMultiInGroupFunc;
      UpdateMultiByGroupFunc updateMultiByGroupFunc;
    };

    typedef std::list<std::type_index> TTypeList;
    typedef std::map<std::type_index, std::type_index> TTypeTypeMap;
    typedef std::map<std::type_index, TTypeList> TTypeTypeListMap;
    typedef std::map<std::type_index, TUpdateMultiAndGroup> TTypeUpdateFuncMap;
    TTypeTypeMap mMultiGroupMap;
    TTypeTypeListMap mGroupMultiMap;
    TTypeUpdateFuncMap mMultiTypeFuncMap;

  private:
    template<typename Multi>
    void AddMulti( EntityID id, Multi& m );
    template<typename Multi, typename Group>
    void AddMultiByGroup( EntityID id );
    template<typename Multi>
    void RemoveMulti( EntityID id, Multi& m );
    template<typename Multi, typename Group>
    void RemoveMultiByGroup( EntityID id );
    template<typename Multi>
    void UpdateMulti( EntityID id, Multi& oldValue, Multi& newValue );// переместить в другую карту
    template<typename Multi, typename Group>
    void UpdateMultiInGroup( EntityID id, Multi& oldValue, Multi& newValue );// переместить внутри группы в другую карту
    template<typename Multi, typename Group>
    void UpdateMultiByGroup( EntityID id, Group& oldValue, Group& newValue );// переместить в другую группу

    template<typename Multi, typename Group>
    void AddMultiInGroup( EntityID id, int num, Multi& m );
    template<typename Multi, typename Group>
    void EraseMultiInGroup( EntityID id, int num, Multi& m );
  private:
    template<typename Component, typename Group>
    TGroupMap<Component>* GetGroupMng();

    template<typename Component>
    TTypeIdentityMap<Component>* GetMultiMng();
  private:
    TEntity* FindEntity( EntityID id );

    template<typename Component>
    void AddToMap( EntityID id, Component& c );
    template<typename Component>
    void RemoveFromMap( EntityID id, Component& c );

    Identity NewIdentity();
  };
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::JoinMultiToGroup()
  {
    auto groupType = std::type_index( typeid( Group ) );
    auto multiType = std::type_index( typeid( Multi ) );
    auto fit = mGroupMultiMap.find( groupType );
    if ( fit == mGroupMultiMap.end() )
      mGroupMultiMap.insert( {groupType, TTypeList { multiType }} );
    else
      fit->second.push_back( multiType );
    mMultiGroupMap.insert( {multiType, groupType} );

    TUpdateMultiAndGroup updateMG;
    updateMG.addMultiByGroupFunc = [this]( EntityID id )
    {
      AddMultiByGroup<Multi, Group>( id );
    };
    updateMG.removeMultiByGroupFunc = [this]( EntityID id )
    {
      RemoveMultiByGroup<Multi, Group>( id );
    };
    updateMG.updateMultiInGroupFunc = [this]( EntityID id, void* oldMultiValue, void* newMultiValue )
    {
      auto pOld = (Multi*) oldMultiValue;
      auto pNew = (Multi*) newMultiValue;
      UpdateMultiInGroup<Multi, Group>( id, *pOld, *pNew );
    };
    updateMG.updateMultiByGroupFunc = [this]( EntityID id, void* oldGroupValue, void* newGroupValue )
    {
      auto pOld = (Group*) oldGroupValue;
      auto pNew = (Group*) newGroupValue;
      UpdateMultiByGroup<Multi, Group>( id, *pOld, *pNew );
    };
    mMultiTypeFuncMap.insert( {multiType, updateMG} );
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::AddComponent( EntityID id, Component& c )
  {
    auto pEntity = FindEntity( id );
    if ( pEntity == nullptr )
      return;

    if ( pEntity->HasComponent<Component>() )
      return;

    auto componentType = std::type_index( typeid( Component ) );
    pEntity->AddComponent( c, [this, id]() {RemoveComponent<Component>( id ); } );

    auto isUnique = std::is_base_of<IUniqueComponent, Component>::value;
    if ( isUnique )
    {
      AddToMap( id, c );// only unique
      return;
    }
    auto isGroup = std::is_base_of<IGroupedComponent, Component>::value;
    auto isMulti = std::is_base_of<IMultiComponent, Component>::value;
    if ( isGroup )
    {
      auto multiTypeList = mGroupMultiMap.find( componentType );
      if ( multiTypeList != mGroupMultiMap.end() )
      {
        for ( auto multiType : multiTypeList->second )
        {
          if ( pEntity->HasComponent( multiType ) )
            mMultiTypeFuncMap[multiType].addMultiByGroupFunc( id );
        }
      }
    }
    if ( isMulti )
    {
      auto joinedGroupType = mMultiGroupMap.find( componentType );
      if ( joinedGroupType != mMultiGroupMap.end() )
      {
        auto groupType = joinedGroupType->second;
        if ( pEntity->HasComponent( groupType ) )
          mMultiTypeFuncMap[componentType].addMultiByGroupFunc( id );
      }
      AddMulti<Component>( id, c );
    }
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::UpdateComponent( EntityID id, Component& newValue )
  {
    auto pEntity = FindEntity( id );
    if ( pEntity == nullptr )
      return;

    Component oldValue;
    if ( pEntity->GetComponent( oldValue ) == false )
      return;

    auto componentType = std::type_index( typeid( Component ) );
    auto isUnique = std::is_base_of<IUniqueComponent, Component>::value;
    if ( isUnique )
    {
      RemoveFromMap( id, oldValue );
      AddToMap( id, newValue );
    }

    auto isGroup = std::is_base_of<IGroupedComponent, Component>::value;
    auto isMulti = std::is_base_of<IMultiComponent, Component>::value;
    if ( isGroup )
    {
      auto multiTypeList = mGroupMultiMap.find( componentType );
      if ( multiTypeList != mGroupMultiMap.end() )
      {
        for ( auto multiType : multiTypeList->second )
        {
          if ( pEntity->HasComponent( multiType ) )
            mMultiTypeFuncMap[multiType].updateMultiByGroupFunc( id, &oldValue, &newValue );
        }
      }
    }
    if ( isMulti )
    {
      auto joinedGroupType = mMultiGroupMap.find( componentType );
      if ( joinedGroupType != mMultiGroupMap.end() )
      {
        auto groupType = joinedGroupType->second;
        if ( pEntity->HasComponent( groupType ) )
          mMultiTypeFuncMap[componentType].updateMultiInGroupFunc( id, &oldValue, &newValue );
      }
      UpdateMulti<Component>( id, oldValue, newValue );
    }
    pEntity->UpdateComponent<Component>( newValue );
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::RemoveComponent( EntityID id )
  {
    auto pEntity = FindEntity( id );
    if ( pEntity == nullptr )
      return;

    Component c;
    if ( pEntity->GetComponent( c ) == false )
      return;

    auto componentType = std::type_index( typeid( Component ) );

    auto isUnique = std::is_base_of<IUniqueComponent, Component>::value;
    if ( isUnique )
      RemoveFromMap( id, c );
    else
    {
      auto isGroup = std::is_base_of<IGroupedComponent, Component>::value;
      auto isMulti = std::is_base_of<IMultiComponent, Component>::value;
      if ( isGroup )
      {
        auto multiTypeList = mGroupMultiMap.find( componentType );
        if ( multiTypeList != mGroupMultiMap.end() )
        {
          for ( auto multiType : multiTypeList->second )
          {
            if ( pEntity->HasComponent( multiType ) )
              mMultiTypeFuncMap[multiType].removeMultiByGroupFunc( id );
          }
        }
      }
      if ( isMulti )
      {
        auto joinedGroupType = mMultiGroupMap.find( componentType );
        if ( joinedGroupType != mMultiGroupMap.end() )
        {
          auto groupType = joinedGroupType->second;
          if ( pEntity->HasComponent( groupType ) )
            mMultiTypeFuncMap[componentType].removeMultiByGroupFunc( id );
        }
        RemoveMulti<Component>( id, c );
      }
    }
    // можно без проверки, потому что компонент уже нашли
    pEntity->RemoveComponent<Component>();
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  bool TEntityManager::GetComponent( EntityID id, Component& c )
  {
    auto pEntity = FindEntity( id );
    if ( pEntity == nullptr )
      return false;
    return pEntity->GetComponent( c );
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  TEntityManager::EntityID TEntityManager::GetUnique( Component& c )
  {
    auto pMap = mSM.Get<TComponentEntityMap<Component>>();
    auto fit = pMap->find( c );
    if ( fit == pMap->end() )
      return None;
    return fit->second;
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  TEntityManager::MultiID TEntityManager::GetMultiID( Component& c )
  {
    auto componentType = std::type_index( typeid( Component ) );
    auto multiMng = GetMultiMng<Component>();
    return multiMng->operator[]( c );
  }
  //-------------------------------------------------------------------------------
  template<typename Component, typename Group>
  TEntityManager::MultiID TEntityManager::GetMultiID( Component& c, Group& g )
  {
    auto groupType = std::type_index( typeid( Group ) );
    auto componentType = std::type_index( typeid( Component ) );
    auto groupMng = GetGroupMng<Component, Group>();
    auto& numPartedMng = groupMng->operator[]( groupType );
    auto num = g.GetGroupNumber();
    auto& multiMng = numPartedMng[num];
    return multiMng[c];
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
  template<typename Component, typename Group>
  TEntityManager::TGroupMap<Component>* TEntityManager::GetGroupMng()
  {
    auto groupType = std::type_index( typeid( Group ) );
    auto pGM = mSM.Get<TGroupMap<Component>>();
    auto fit = pGM->find( groupType );
    if ( fit == pGM->end() )
    {
      TIntTypeIdentityMap<Component> numType;
      Group g;
      int count = g.GetGroupCount();
      for ( int i = 0; i < count; i++ )
        numType.insert( {i, TTypeIdentityMap<Component>()} );

      pGM->insert( {groupType, numType} );
    }
    return pGM;
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  TEntityManager::TTypeIdentityMap<Component>* TEntityManager::GetMultiMng()
  {
    return mSM.Get<TTypeIdentityMap<Component>>();
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::AddToMap( EntityID id, Component& c )
  {
    auto pMap = mSM.Get<TComponentEntityMap<Component>>();
    pMap->insert( {c, id} );
  }
  //-------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::RemoveFromMap( EntityID id, Component& c )
  {
    auto pMap = mSM.Get<TComponentEntityMap<Component>>();
    pMap->erase( c );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi>
  void TEntityManager::AddMulti( EntityID id, Multi& m )
  {
    MultiID mid;
    auto multiMng = GetMultiMng<Multi>();
    auto fit = multiMng->find( m );
    if ( fit == multiMng->end() )
    {// add new 
      mid = NewIdentity();
      mIdentityEntitiesMap.insert( {mid, TSharedPtrSortedEntity( new TSortedEntity() )} );
      multiMng->insert( {m, mid} );
    }
    else
      mid = fit->second;
    mIdentityEntitiesMap[mid]->insert( id );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::AddMultiByGroup( EntityID id )
  {
    MultiID mid;
    Group g;
    GetComponent( id, g );
    Multi m;
    GetComponent( id, m );

    AddMultiInGroup<Multi, Group>( id, g.GetGroupNumber(), m );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi>
  void TEntityManager::RemoveMulti( EntityID id, Multi& m )
  {
    auto multiMng = GetMultiMng<Multi>();
    auto mid = multiMng->operator[]( m );
    if ( mid != None )
      mIdentityEntitiesMap[mid]->erase( id );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::RemoveMultiByGroup( EntityID id )
  {
    Group g;
    GetComponent( id, g );
    Multi m;
    GetComponent( id, m );
    EraseMultiInGroup<Multi, Group>( id, g.GetGroupNumber(), m );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi>
  void TEntityManager::UpdateMulti( EntityID id, Multi& oldValue, Multi& newValue )
  {
    RemoveMulti( id, oldValue );
    AddMulti( id, newValue );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::UpdateMultiInGroup( EntityID id, Multi& oldValue, Multi& newValue )
  {
    Group g;
    GetComponent( id, g );
    EraseMultiInGroup<Multi, Group>( id, g.GetGroupNumber(), oldValue );
    AddMultiInGroup<Multi, Group>( id, g.GetGroupNumber(), newValue );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::UpdateMultiByGroup( EntityID id, Group& oldValue, Group& newValue )
  {
    Multi c;
    GetComponent( id, c );
    EraseMultiInGroup<Multi, Group>( id, oldValue.GetGroupNumber(), c );
    AddMultiInGroup<Multi, Group>( id, newValue.GetGroupNumber(), c );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::AddMultiInGroup( EntityID id, int num, Multi& m )
  {
    auto groupType = std::type_index( typeid( Group ) );
    auto groupMng = GetGroupMng<Multi, Group>();
    auto& groupPartedMng = groupMng->operator[]( groupType );
    auto& multiMng = groupPartedMng[num];
    auto fit = multiMng.find( m );
    MultiID mid;
    if ( fit == multiMng.end() )// search mid
    {// add new
      mid = NewIdentity();
      mIdentityEntitiesMap.insert( {mid, TSharedPtrSortedEntity( new TSortedEntity() )} );
      multiMng.insert( {m, mid} );
    }
    else
      mid = fit->second;
    if ( mid != None )
      mIdentityEntitiesMap[mid]->insert( id );
  }
  //-------------------------------------------------------------------------------
  template<typename Multi, typename Group>
  void TEntityManager::EraseMultiInGroup( EntityID id, int num, Multi& m )
  {
    auto groupType = std::type_index( typeid( Group ) );
    auto groupMng = GetGroupMng<Multi, Group>();
    auto& groupPartedMng = groupMng->operator[]( groupType );
    auto& multiMng = groupPartedMng[num];
    auto fit = multiMng.find( m );
    if ( fit == multiMng.end() )// search mid
      return;
    auto mid = fit->second;
    if ( mid != None )
      mIdentityEntitiesMap[mid]->erase( id );
    if ( mIdentityEntitiesMap[mid]->size() == 0 )// уменьшить место
      multiMng.erase( m );
  }
  //-------------------------------------------------------------------------------
}

