/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "Marshaller.h"
#include "MemoryPool.h"
#include "SingletonManager.h"

class DllExport TMemoryPoolAllocator
{// инфраструктура для маршаллинга
  using Deallocate = std::function<void()>;

  typedef std::unordered_map<void*, Deallocate> TPtrPtrMap;
  typedef TPtrPtrMap::value_type TPtrPtrMapVT;

  struct TMap
  {
    TPtrPtrMap value;
  };

  static inline TMap* mMap = nullptr;
public:
  static void TryInitMap()
  {
    if( mMap == nullptr )
      mMap = SingletonManager()->Get<TMap>();
  }

  template<typename Type>
  static void* AllocateFunc()
  {
    TryInitMap();

    auto pDesc = SingletonManager()->Get<TMemoryPool<Type>>()->Pop( 1 );
    Deallocate deallocateFunc { [pDesc]()// заготовка для освобождения памяти
    {
      SingletonManager()->Get<TMemoryPool<Type>>()->Push( pDesc );
    } };
    void* p = pDesc->p;// запомнить функцию по указателю на выделенный объект
    mMap->value.insert( TPtrPtrMapVT( p, deallocateFunc ) );
    return p;
  }
  static void DeallocateFunc( void* p )
  {
    TryInitMap();

    mMap->value[p]();
  }
};