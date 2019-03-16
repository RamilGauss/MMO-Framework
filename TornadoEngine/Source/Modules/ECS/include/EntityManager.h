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
#include <type_traits>

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"

namespace nsECSFramework
{
  class DllExport TEntityManager
  {
    typedef TTypeIdentifier<TEntityManager> TTypeID;
    TTypeID mTypeIndex;
  public:
    TEntityManager( int entityCount );

    template <typename ... Args>
    TTypeIdentifier<TEntityManager>::TypeCounter TypeIndex()
    {
      return mTypeIndex.type<Args...>();
    }

    template <typename C0, typename C1, typename ... Components >
    void SetMixCombination();

    TEntityID CreateEntity();
    void DestroyEntity( TEntityID id );

    template <typename Component>
    void AddComponent( TEntityID id, Component& c );
    template <typename Component>
    void UpdateComponent( TEntityID id, Component& c );
    template <typename Component>
    const Component& GetComponent( TEntityID id );
    template <typename Component>
    void RemoveComponent( TEntityID id );

    template <typename Component>
    TEntityID GetUnique( Component& c );

    template <typename Component>
    const TEntityLoopList& GetMulti( Component& c );

    template <typename C0, typename C1>
    const TEntityLoopList& GetMultiMix( C0& c0, C1& c1 );

    template <typename C0, typename C1, typename C2>
    const TEntityLoopList& GetMultiMix( C0& c0, C1& c1, C2& c2 );

    template <typename C0>
    const TEntityLoopList& GetHas();
    template <typename C0, typename C1>
    const TEntityLoopList& GetHas();
    template <typename C0, typename C1, typename C2>
    const TEntityLoopList& GetHas();

    template <typename Component>
    TCallBackRegistrator2<TEntityID, Component&>* OnAdd();
    template <typename Component>
    TCallBackRegistrator2<TEntityID, Component&>* OnUpdate();
    template <typename Component>
    TCallBackRegistrator2<TEntityID, Component&>* OnRemove();
  private:
    template<typename Component>
    void GalvanizeMixCombination( std::list<TTypeID::TypeCounter>& tidList );
    template<typename C0, typename C1, typename ... Components>
    void GalvanizeMixCombination( std::list<TTypeID::TypeCounter>& tidList );

    TMemoryObjectPool<TEntity>* mEntityMemoryPool;

    TVectorRise<TEntity*> mEntities;

    TEntity* GetEntity( TEntityID id ) const;

    template<typename Component>
    using UnqiqueMap = std::map<Component, TEntityID>;

    template<typename Component>
    using MultiMap = std::map<Component, TEntityList*>;

    // unique
    typedef TColanderVector<void*> TVoidPtrVector;
    TVoidPtrVector mUniqueMapVector;

    // has
    TColanderVector<std::list<TEntityID>*> mHasListVector;

    // multi MultiMap*
    TVoidPtrVector mMultiVector;

    // multi mix - type id(A) - index, хранит список index на объект из mCombinationMapVector
    TColanderVector<std::list<int>> mIndexOnMixCombinationVector;
    // mix combinations хранит MultiMap
    TVoidPtrVector mCombinationMapVector;


    template<typename Component>
    using CallBackPtr = TCallBackRegistrator2<TEntityID, Component&>;

    TVoidPtrVector mOnAddCallBack;
    TVoidPtrVector mOnUpdateCallBack;
    TVoidPtrVector mOnRemoveCallBack;



  };
  //---------------------------------------------------------------------------------------
  template<typename Component>
  void TEntityManager::GalvanizeMixCombination( std::list<TTypeID::TypeCounter>& tidList )
  {
    tidList.push_back( TypeIndex<Component>() );
  }
  //---------------------------------------------------------------------------------------
  template<typename C0, typename C1, typename ... Components>
  void TEntityManager::GalvanizeMixCombination( std::list<TTypeID::TypeCounter>& tidList )
  {
    auto isMultiMix = std::is_base_of<IMultiMixComponent, C0>::value;
    assert( isMultiMix );
    GalvanizeMixCombination<C0>( tidList );
    GalvanizeMixCombination<C1, Components ...>( tidList );
  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1, typename ... Components >
  void TEntityManager::SetMixCombination()
  {
    auto mixTID = TypeIndex<C0, C1, Components ... >();

    std::list<TTypeID::TypeCounter> tidList;
    GalvanizeMixCombination<C0, C1, Components ... >( tidList );
    for ( auto tid : tidList )
    {
      mIndexOnMixCombinationVector[tid].push_back( mixTID );
    }
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::AddComponent( TEntityID id, Component& c )
  {
    auto tid = TypeIndex<Component>();

    auto pEntity = GetEntity( id );
    pEntity->AddComponent( c, tid );

    auto isHas = std::is_base_of<IHasComponent, Component>::value;
    auto isMulti = std::is_base_of<IMultiComponent, Component>::value;
    auto isUnique = std::is_base_of<IUniqueComponent, Component>::value;
    auto isMultiMix = std::is_base_of<IMultiMixComponent, Component>::value;

    if ( isUnique )
    {
      if ( mUniqueMapVector[tid] == nullptr )
        mUniqueMapVector[tid] = new UnqiqueMap<Component>();
      ( ( UnqiqueMap<Component>* )mUniqueMapVector[tid] )->insert( {c, id} );
      return;
    }
    if ( isHas )
    {
      if ( mHasListVector[tid] == nullptr )
        mHasListVector[tid] = new std::list<TEntityID>();
      auto pList = mHasListVector[tid];
      pList->push_back( id );

      auto backIt = pList->back();
    }
    if ( isMulti )
    {

    }
    if ( isMultiMix )
    {

    }
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::UpdateComponent( TEntityID id, Component& c )
  {
    auto tid = TypeIndex<Component>();
    auto pEntity = GetEntity( id );
    pEntity->UpdateComponent( c, tid );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const Component& TEntityManager::GetComponent( TEntityID id )
  {
    auto tid = TypeIndex<Component>();
    auto pEntity = GetEntity( id );
    return pEntity->GetComponent( tid );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::RemoveComponent( TEntityID id )
  {
    auto tid = TypeIndex<Component>();
    auto pEntity = GetEntity( id );
    pEntity->RemoveComponent( tid );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TEntityID TEntityManager::GetUnique( Component& c )
  {
    auto index = TypeIndex<Component>();
    auto unqiqueMap = ( UnqiqueMap<Component>* ) mUniqueMapVector[index];
    if ( unqiqueMap == nullptr )
      return None;
    auto fit = unqiqueMap->find( c );
    if ( fit == unqiqueMap->end() )
      return None;
    return fit->second;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const TEntityLoopList& TEntityManager::GetMulti( Component& c )
  {
    auto index = TypeIndex<Component>();
  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1>
  const TEntityLoopList& TEntityManager::GetMultiMix( C0& c0, C1& c1 )
  {
    auto index = TypeIndex<C0, C1>();
  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1, typename C2>
  const TEntityLoopList& TEntityManager::GetMultiMix( C0& c0, C1& c1, C2& c2 )
  {
    auto index = TypeIndex<C0, C1, C2>();
  }
  //---------------------------------------------------------------------------------------
  template <typename C0>
  const TEntityLoopList& TEntityManager::GetHas()
  {
    auto index = TypeIndex<C0>();
  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1>
  const TEntityLoopList& TEntityManager::GetHas()
  {
    auto index = TypeIndex<C0, C1>();
  }
  //---------------------------------------------------------------------------------------
  template <typename C0, typename C1, typename C2>
  const TEntityLoopList& TEntityManager::GetHas()
  {
    auto index = TypeIndex<C0, C1, C2>();
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component&>* TEntityManager::OnAdd()
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component&>* TEntityManager::OnUpdate()
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component&>* TEntityManager::OnRemove()
  {

  }
  //---------------------------------------------------------------------------------------
}