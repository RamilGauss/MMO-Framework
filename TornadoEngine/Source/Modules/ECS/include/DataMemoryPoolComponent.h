/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "MemoryPool.h"
#include "TypeDef.h"
#include "SingletonManager.h"

template<typename Type>
struct DllExport TDataMemoryPoolComponent
{
  Type* p = nullptr;
  int size = 0;
private:
  typename TMemoryPool<Type>::TPointerDesc* mPtrDesc = nullptr;

  static TMemoryPool<Type>* mMemoryPool;
public:
  TDataMemoryPoolComponent( nsECSFramework::THugeRegistry* pR, int s = 1 )
  {
    if( mMemoryPool == nullptr )
      mMemoryPool = SingletonManager()->Get<TMemoryPool<Type>>();

    Init( s );
    // for call Done yourself after entity destroying
    pR->destruction<TDataMemoryPoolComponent<Type>>().connect<&DestroyHandler>();
  }
private:
  void Init( int s )
  {
    size = s;
    mPtrDesc = mMemoryPool->Pop( size );
    p = mPtrDesc->p;
  }
  void Done()
  {
    mMemoryPool->Push( mPtrDesc );
    size = 0;
    p = nullptr;
  }
  static void DestroyHandler( nsECSFramework::THugeRegistry &r, nsECSFramework::TEntity e )
  {
    r.get<PooledComponents::TUchar>( e ).Done();
  }
};

template<typename Type>
TMemoryPool<Type>* TDataMemoryPoolComponent<Type>::mMemoryPool = nullptr;

namespace PooledComponents
{
  typedef TDataMemoryPoolComponent<unsigned char> TUchar;
}
