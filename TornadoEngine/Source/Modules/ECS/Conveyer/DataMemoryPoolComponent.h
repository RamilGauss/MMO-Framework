#pragma once
#include "MemoryPool.h"
#include "TypeDef.h"

template<typename Type>
struct DllExport TDataMemoryPoolComponent
{
  Type* p = nullptr;
  int size = 0;

  typename TMemoryPool<Type>::TDescPointer* mPtrDesc = nullptr;

  TDataMemoryPoolComponent(int s)
  {
    Init(s);
  }
  void Init(int s)
  {
    size = s;
    mPtrDesc = TMemoryPool<Type>::Singleton()->Pop(size);
    p = mPtrDesc->p;
  }
  void Done()
  {
    TMemoryPool<Type>::Singleton()->Push(mPtrDesc);
    size = 0;
    p = nullptr;
  }
};

namespace PooledComponents
{
  typedef TDataMemoryPoolComponent<unsigned char> TUchar;
  typedef TDataMemoryPoolComponent<std::string>   TString;
  typedef TDataMemoryPoolComponent<std::wstring>  TWString;
}