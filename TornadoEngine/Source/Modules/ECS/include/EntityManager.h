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

#include "TypeDef.h"
#include "TypeIdentifier.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "TypeIdentifier.h"
#include "ColanderVector.h"
#include "IComponent.h"

namespace nsECSFramework
{
  class DllExport TComplexType
  {
  public:
    TColanderVector<IComponent*> parts;
    std::list<unsigned char> mComponentTypeIdentifierList;

    bool operator < ( const TComplexType& other ) const
    {
      // я знаю, что данная операция не меняет объекты, но нужен не константный объект, потому что массив не поддерживает не константный объект
      // hack
      auto pThis = ( TComplexType*) this;
      auto pOther = ( TComplexType*) & other;

      for ( auto& index : mComponentTypeIdentifierList )
      {
        if ( pThis->parts.operator[]( index )->IsLess( pOther->parts.operator[]( index ) ) )
          return false;
      }
      return true;
    }

    void Done()
    {
      for ( auto& index : mComponentTypeIdentifierList )
        parts.operator[]( index ) = nullptr;
      mComponentTypeIdentifierList.clear();
    }
  };

  class DllExport TEntityManager
  {
    typedef TTypeIdentifier<TEntityManager> TTypeID;
    TTypeID* mTypeIndex;
  public:
    TEntityManager( int entityCount = 1024 );

    void Setup( std::string path = boost::dll::this_line_location().string() );

    template <typename ... Args>
    unsigned int TypeIndex()
    {
      return mTypeIndex->type<Args...>();
    }

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
    template <typename T>
    TEntityID GetByUnique( T& t );
    template <typename ... Args>
    std::list<TEntityID>* GetByValue( Args& ... );
    template <typename ... Args>
    std::list<TEntityID>* GetByHas();

    // events
    template<typename Component>
    using CallBackPtr = TCallBackRegistrator2<TEntityID, Component*>;

    template <typename Component>
    CallBackPtr<Component>* OnAdd();
    template <typename Component>
    CallBackPtr<Component>* OnUpdate();
    template <typename Component>
    CallBackPtr<Component>* OnRemove();
  private:
    typedef TColanderVector<void*> TVoidPtrVector;

    std::vector<std::list<TEntityID>*> mHasCollectionVec;
    TVoidPtrVector mValueCollectionVec;// map<T,list<TEntityID>*>*
    TVoidPtrVector mUniqueMapVec;// map<T,TEntityID>*


    std::list<TEntityID> mReserverIndexInEntities;
    TMemoryObjectPool<TEntity>* mEntityMemoryPool;

    TVectorRise<TEntity*> mEntities;

    TEntity* GetEntity( TEntityID id ) const;

    template<typename Component>
    using UnqiqueMap = std::map<Component, TEntityID>;

    template<typename Component>
    using MultiMap = std::map<Component, TEntityList*>;


    TVoidPtrVector mOnAddCallBack;
    TVoidPtrVector mOnUpdateCallBack;
    TVoidPtrVector mOnRemoveCallBack;

  private:
    template<typename Type>
    void* CreateMapByType();

    template<typename Type>
    void DestroyMapByType( void* p );
  };
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::SetComponent( TEntityID eid, Component& c )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  const Component* TEntityManager::ViewComponent( TEntityID eid )
  {

  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  bool TEntityManager::GetComponent( TEntityID eid, Component& c )
  {
    return false;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  Component TEntityManager::GetComponent( TEntityID eid )
  {
    return Component();
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  void TEntityManager::RemoveComponent( TEntityID eid )
  {
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  bool TEntityManager::HasComponent( TEntityID eid )
  {
    return false;
  }
  //---------------------------------------------------------------------------------------
  template <typename T>
  TEntityID TEntityManager::GetByUnique( T& t )
  {
    return None;
  }
  //---------------------------------------------------------------------------------------
  template <typename ... Args>
  std::list<TEntityID>* TEntityManager::GetByValue( Args& ... )
  {
    return nullptr;
  }
  //---------------------------------------------------------------------------------------
  template <typename ... Args>
  std::list<TEntityID>* TEntityManager::GetByHas()
  {
    return nullptr;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component*>* TEntityManager::OnAdd()
  {
    return &mOnAddCallBack;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component*>* TEntityManager::OnUpdate()
  {
    return &mOnUpdateCallBack;
  }
  //---------------------------------------------------------------------------------------
  template <typename Component>
  TCallBackRegistrator2<TEntityID, Component*>* TEntityManager::OnRemove()
  {
    return &mOnRemoveCallBack;
  }
  //---------------------------------------------------------------------------------------
}