/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Marshaller.h"
#include "MemoryPool.h"

class DllExport TMemoryPoolAllocator
{// инфраструктура для маршаллинга
  using Deallocate = std::function<void()>;

  typedef std::unordered_map<void*, Deallocate> TPtrPtrMap;
  typedef TPtrPtrMap::value_type TPtrPtrMapVT;

  static inline TPtrPtrMap mMap;
public:
  template<typename Type>
  static void* AllocateFunc()
  {
    auto pDesc = TMemoryPool<Type>::Singleton()->Pop( 1 );
    Deallocate deallocateFunc { [pDesc]()// заготовка для освобождения памяти
    {
      TMemoryPool<Type>::Singleton()->Push( pDesc );
    } };
    void* p = pDesc->p;// запомнить функцию по указателю на выделенный объект
    mMap.insert( TPtrPtrMapVT( p, deallocateFunc ) );
    return p;
  }
  static void DeallocateFunc( void* p )
  {
    mMap[p]();
  }
};