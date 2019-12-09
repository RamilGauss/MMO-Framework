/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

#include "TypeIdentifier.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"
#include "ComplexType.h"
#include "ContainerForReactive.h"
#include "HelpStructs.h"

namespace nsECSFramework
{
  class DllExport TEntityManager
  {
    typedef TTypeIdentifier<TEntityManager> TTypeID;
    TTypeID* mTypeIndex;
  public:
    TEntityManager( int entityCount = 1024 );
    virtual ~TEntityManager();

    void Setup( std::string path = boost::dll::this_line_location().string() );

    // entity
    TEntityID CreateEntity();
    void DestroyEntity( TEntityID id );

    // components
    template <typename Component>
    void SetComponent( TEntityID eid, Component& c );// => add or set event
    template <typename Component>
    const Component* ViewComponent( TEntityID eid );// for view, fast,
    template <typename Component>
    bool GetComponent( TEntityID eid, Component& c );// for change, copy, with check
    template <typename Component>
    Component GetComponent( TEntityID eid );// for change, copy
    template <typename Component>
    void RemoveComponent( TEntityID eid );// => remove event
    template <typename Component>
    bool HasComponent( TEntityID eid );

    // filters
    template <typename Component>
    DllExport TEntityID NoInline GetByUnique( Component& c )
    {// definition must be after declaration!
      auto index = TypeIndex<Component>();
      auto pMap = mUniqueMapVec[index];
      if ( pMap == nullptr )
        return None;
      auto fit = pMap->find( &c );
      if ( fit == pMap->end() )
        return None;
      return fit->second;
    }
    template <typename ... Args>
    DllExport TEntityList* NoInline GetByValue( Args& ... args )
    {// definition must be after declaration!
      auto index = TypeIndex<Args...>();
      auto pMap = mValueCollectionVec[index];
      if ( pMap == nullptr )
        return nullptr;

      TEntityList* pResult = nullptr;
      auto pComplexType = mComplexTypeMemoryPool->Pop();
      Fill( pComplexType, args ... );// берем адреса из стека, безопасно, потому что переменные еще существуют в методе
      auto fit = pMap->find( pComplexType );
      if ( fit != pMap->end() )
        pResult = fit->second;

      // вернуть обратно в пул
      pComplexType->Done();
      mComplexTypeMemoryPool->Push( pComplexType );
      return pResult;
    }
    template <typename ... Args>
    DllExport TEntityList* NoInline GetByHas()
    {// definition must be after declaration!
      auto index = TypeIndex<Args...>();
      auto pList = (TEntityList*)mHasCollectionVec[index];
      return pList;
    }
    // мгновенная реакция на удаления для освобождения ресурсов
    template<typename Component>
    TCallBackRegistrator2<TEntityID, IComponent*>* RegisterOnRemoveComponent();
  protected:
    // events
    friend class TReactiveOnAddSystem;
    friend class TReactiveOnUpdateSystem;
    friend class TReactiveOnRemoveSystem;

    TContainerForReactive mAddCollector;
    TContainerForReactive mUpdateCollector;
    TContainerForReactive mRemoveCollector;

    template<typename Component>
    int OnAdd();
    template<typename Component>
    int OnUpdate();
    template<typename Component>
    int OnRemove();
  private:
    typedef std::map<TComplexType*, TEntityList*, ptr_less<TComplexType*>> TComplexTypePtrListPtrMap;
    typedef TColanderVector<TComplexTypePtrListPtrMap*> TComplexTypePtrListPtrMapPtrVec;

    typedef TColanderVector<void*> TVoidPtrVector;
    typedef TColanderVector<TEntityList*> TListPtrVector;

    typedef std::map<IComponent*, TEntityID, component_ptr_less<IComponent*>> TUniqueMap;
    typedef TColanderVector<TUniqueMap*> TUniqueMapPtrVector;

    TListPtrVector mHasCollectionVec;// fill in setup
    TComplexTypePtrListPtrMapPtrVec mValueCollectionVec;// fill in setup
    TUniqueMapPtrVector mUniqueMapVec;// fill in setup

    TMemoryObjectPool<TEntity>* mEntityMemoryPool;
    TMemoryObjectPool<TComplexType>* mComplexTypeMemoryPool;
    TMemoryObjectPool<TLinkToList<TEntityID>>* mLinkToListMemoryPool;
    TMemoryObjectPool<TEntityList>* mEntityListMemoryPool;
    TMemoryObjectPool<TUniqueMap>* mUniqueMapMemoryPool;
    TMemoryObjectPool<TComplexTypePtrListPtrMap>* mComplexTypePtrListPtrMapMemoryPool;


    TEntityList mReserverIndexInEntities;
    TVectorRise<TEntity*> mEntities;

    TListPtrVector mOnAddCallBack;
    TListPtrVector mOnUpdateCallBack;
    TListPtrVector mOnRemoveCallBack;

    typedef std::list<short> TShortList;
    typedef TColanderVector<TShortList> TListVector;

    // в каких коллекциях участвует данный тип
    TListVector mHasTypeInCollection;// fill in setup
    TListVector mValueTypeInCollection;// fill in setup

    // из каких типов состоит коллекция
    TListVector mHasCollectionWithTypes;// fill in setup
    TListVector mValueCollectionWithTypes;// fill in setup

    typedef TCallBackRegistrator2<TEntityID, IComponent*> TCB_EntPtrCom;
    typedef TColanderVector<TCB_EntPtrCom*> TCBVector;

    TCBVector mRemoveCBVector;
  public:// inner use
#pragma GCC push_options
#pragma GCC optimize ("O0")
    template <typename ... Args>
    BOOST_SYMBOL_EXPORT unsigned int NoInline TypeIndex()
    {
      return mTypeIndex->type<Args...>();
    }
#pragma GCC pop_options
  private:
    TEntity* GetEntity( TEntityID id ) const;

    void RemoveComponent( TEntityID eid, TEntity* pEntity, int index );

    template<typename T0>
    void Fill( TComplexType* pComplexType, T0& t0 );
    template<typename T0, typename T1, typename ... Args>
    void Fill( TComplexType* pComplexType, T0& t0, T1& t1, Args& ... args );

    void TryAddInUnique( TEntityID eid, IComponent* pC, int index );
    void TryRemoveFromUnique( TEntityID eid, IComponent* pC, int index );

    void TryAddInHas( TEntityID eid, int index, TEntity* pEntity );
    void TryAddInValue( TEntityID eid, int index, TEntity* pEntity );

    void TryRemoveFromHas( TEntityID eid, int index, TEntity* pEntity );
    void TryRemoveFromValue( TEntityID eid, int index, TEntity* pEntity );


    void NotifyOnRemoveComponent( int index, TEntityID entity, IComponent* pC );

  private:
    boost::dll::experimental::smart_library mLib;

    typedef std::list<std::string> TStrList;
    typedef std::set<std::string> TStrSet;
    typedef std::list<TStrSet> TStrSetList;
    typedef std::map<TStrSet, TStrList> TStrSetStrListMap;
    typedef std::map<TStrSet, int> TStrSetIntMap;
    typedef std::map<TStrSet, std::string> TStrSetStrMap;

    TStrSetStrMap mTypeIndexNameFuncMap;
    TStrSetIntMap mCompnentsTypeIndexMap;
    // после поиска использования функций
    TStrSetList mUniqueSet;
    TStrSetList mHasComponentList;
    TStrSetList mValueComponentList;

    void Fill( const std::string& methodName, std::string& demangled, TStrSet& strSet );
    void FindTypesOfMethod( const std::string& methodName, TStrSetList& resultList );
    void FindTypeIndex( const std::string& methodName, TStrSetStrMap& resultMap );
  };
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::SetComponent( TEntityID eid, Component& c )
  {
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return;
    }

    Component* pC = nullptr;
    auto index = TypeIndex<Component>();
    if ( pEntity->HasComponent( index ) )
    {
      pC = (Component*)pEntity->GetComponent( index );

      mUpdateCollector.Set( index, eid );

      TryRemoveFromUnique( eid, pC, index );
      TryRemoveFromValue( eid, index, pEntity );
    }
    else
    {
      pC = pEntity->AddComponent<Component>( index );
      mAddCollector.Set( index, eid );

      TryAddInHas( eid, index, pEntity );
    }

    *pC = c;
    TryAddInUnique( eid, pC, index );
    TryAddInValue( eid, index, pEntity );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const Component* TEntityManager::ViewComponent( TEntityID eid )
  {
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return nullptr;
    }
    auto index = TypeIndex<Component>();
    auto pC = (Component*)pEntity->GetComponent( index );
    return pC;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  bool TEntityManager::GetComponent( TEntityID eid, Component& c )
  {
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return false;
    }
    auto index = TypeIndex<Component>();
    auto pC = (Component*)pEntity->GetComponent( index );
    if ( pC == nullptr )
      return false;
    c = *pC;
    return true;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  Component TEntityManager::GetComponent( TEntityID eid )
  {
    Component c;
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return c;
    }
    auto index = TypeIndex<Component>();
    auto pC = (Component*)pEntity->GetComponent( index );
    if ( pC == nullptr )
      return c;
    c = *pC;
    return c;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::RemoveComponent( TEntityID eid )
  {
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return;
    }

    auto index = TypeIndex<Component>();
    auto pC = (Component*)pEntity->GetComponent( index );

    mRemoveCollector.Set( index, eid );
    NotifyOnRemoveComponent( index, eid, pC );

    RemoveComponent( eid, pEntity, index );
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  bool TEntityManager::HasComponent( TEntityID eid )
  {
    auto pEntity = GetEntity( eid );
    if ( pEntity == nullptr )
    {
      BL_FIX_BUG();
      return false;
    }
    auto index = TypeIndex<Component>();
    return pEntity->HasComponent( index );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnAdd()
  {
    auto index = TypeIndex<Component>();
    return mAddCollector.Register( index );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnUpdate()
  {
    auto index = TypeIndex<Component>();
    return mUpdateCollector.Register( index );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnRemove()
  {
    auto index = TypeIndex<Component>();
    return mRemoveCollector.Register( index );
  }
  //---------------------------------------------------------------------------------------
  template<typename T0>
  void TEntityManager::Fill( TComplexType* pComplexType, T0& t0 )
  {
    auto index = TypeIndex<T0>();
    pComplexType->parts[index] = &t0;
    pComplexType->mComponentTypeIdentifierList.push_back( index );
  }
  //---------------------------------------------------------------------------------------
  template<typename T0, typename T1, typename ... Args>
  void TEntityManager::Fill( TComplexType* pComplexType, T0& t0, T1& t1, Args& ... args )
  {
    Fill( pComplexType, t0 );
    Fill( pComplexType, t1, args ... );
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  TCallBackRegistrator2<TEntityID, IComponent*>* TEntityManager::RegisterOnRemoveComponent()
  {
    auto index = TypeIndex<Component>();
    auto pCB = mRemoveCBVector[index];
    if ( pCB == nullptr )
    {
      pCB = new TCB_EntPtrCom();
      mRemoveCBVector[index] = pCB;
    }
    return pCB;
  }
  //---------------------------------------------------------------------------------------
}