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

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

#include "TypeDef.h"
#include "TypeIdentifier.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"
#include "ComplexType.h"

namespace nsECSFramework
{
  struct TComponentEventListener
  {
    enum State
    {
      Begin, Middle, End
    };

    State state;

    TEntityList::iterator it;
  };

  struct TComponentEventList
  {
    TEntityList list;
    std::vector<TComponentEventListener> mVec;

    TEntityList::iterator mCurrentIterator;
  };

  template<class T>
  struct ptr_less
  {
    bool operator()( const T& pLHS, const T& pRHS ) const
    {
      return *pLHS < *pRHS;
    }
  };
  template<class T>
  struct component_ptr_less
  {
    bool operator()( const T& lhs, const T& rhs ) const
    {
      auto pL = (const IComponent*)lhs;
      auto pR = (const IComponent*)rhs;
      return pL->IsLess( pR );
    }
  };
  // usage: std::map<T*,second,ptr_less<T*>> mMap;

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
    TEntityID GetByUnique( Component& c );
    template <typename ... Args>
    TEntityList* GetByValue( Args& ... );
    template <typename ... Args>
    TEntityList* GetByHas();

    // events
    template<typename Component>
    int OnAdd( void* pObject );
    template<typename Component>
    int OnUpdate( void* pObject );
    template<typename Component>
    int OnRemove( void* pObject );

    void GetAddEvents( int id, TEntityLoopList& entListLoop );
    void GetUpdateEvents( int id, TEntityLoopList& entListLoop );
    void GetRemoveEvents( int id, TEntityLoopList& entListLoop );
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
  private:// inner use
    template <typename ... Args>
    DllExport unsigned int TypeIndex()
    {
      return mTypeIndex->type<Args...>();
    }

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

  private:// reflection
    template <typename ... Args>
    constexpr DllExport void GetByUnique_helper() const noexcept
    {
    }
    template <typename ... Args>
    constexpr DllExport void GetByHas_helper() const noexcept
    {
    }
    template <typename ... Args>
    constexpr DllExport void GetByValue_helper() const noexcept
    {
    }

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
    //CallBackPtr<Component>* pCB = nullptr;
    auto index = TypeIndex<Component>();
    if ( pEntity->HasComponent( index ) )
    {
      pC = (Component*)pEntity->GetComponent( index );
      //pCB = ( CallBackPtr<Component>* )mOnUpdateCallBack[index];

      TryRemoveFromUnique( eid, pC, index );
      TryRemoveFromValue( eid, index, pEntity );
    }
    else
    {
      pC = pEntity->AddComponent<Component>( index );
      //pCB = ( CallBackPtr<Component>* )mOnAddCallBack[index];

      TryAddInHas( eid, index, pEntity );
    }

    *pC = c;
    TryAddInUnique( eid, pC, index );
    TryAddInValue( eid, index, pEntity );
    //if ( pCB != nullptr )
      //pCB->Notify( eid, pC );// TODO: push_back( eid );
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

    //auto cbRemove = ( CallBackPtr<Component>* )mOnRemoveCallBack[index];
    //if ( cbRemove != nullptr )
      //cbRemove->Notify( eid, pC );

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
  template <typename Component>
  TEntityID TEntityManager::GetByUnique( Component& c )
  {
    GetByUnique_helper<Component>();

    auto index = TypeIndex<Component>();
    auto pMap = mUniqueMapVec[index];
    if ( pMap == nullptr )
      return None;
    auto fit = pMap->find( &c );
    if ( fit == pMap->end() )
      return None;
    return fit->second;
  }
  //---------------------------------------------------------------------------------------
  template <typename ... Args>
  TEntityList* TEntityManager::GetByValue( Args& ... args )
  {
    GetByValue_helper<Args...>();

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
  //---------------------------------------------------------------------------------------
  template <typename ... Args>
  TEntityList* TEntityManager::GetByHas()
  {
    GetByHas_helper<Args...>();

    auto index = TypeIndex<Args...>();
    auto pList = (TEntityList*)mHasCollectionVec[index];
    return pList;
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnAdd( void* pObject )
  {
    return 0;
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnUpdate( void* pObject )
  {
    return 0;
  }
  //---------------------------------------------------------------------------------------
  template<typename Component>
  int TEntityManager::OnRemove( void* pObject )
  {
    return 0;
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
}