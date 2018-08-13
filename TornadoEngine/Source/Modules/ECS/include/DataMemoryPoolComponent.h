#pragma once
#include "MemoryPool.h"
#include "TypeDef.h"
#include "SingletonManager.h"

template<typename Type>
struct DllExport TDataMemoryPoolComponent
{
  Type* p = nullptr;
  int size = 0;

  typename TMemoryPool<Type>::TDescPointer* mPtrDesc = nullptr;

  // inline можно, все равно данные будут браться из общего пула (он не подвержен опасности разных указателей в разных библиотеках)
  static inline TMemoryPool<Type>* mMemoryPool = nullptr;

  TDataMemoryPoolComponent( int s )
  {
    if( mMemoryPool == nullptr )
      mMemoryPool = SingletonManager()->Get<TMemoryPool<Type>>();

    Init( s );
  }
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
};

namespace PooledComponents
{
  typedef TDataMemoryPoolComponent<unsigned char> TUchar;
}