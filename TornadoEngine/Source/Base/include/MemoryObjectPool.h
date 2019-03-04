/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "VectorRise.h"
#include <assert.h>

// not Thread-safe!
template<typename Type>
class DllExport TMemoryObjectPool
{
  TVectorRise<Type*> mReserveArr;
  TVectorRise<Type*> mCommonArr;
public:
  inline Type* Pop();
  inline void Push( Type* p );
private:
  Type* Allocate()
  {
    auto p = new Type();
    mCommonArr.Append( p );
    return p;
  }
};

template<typename Type>
Type* TMemoryObjectPool<Type>::Pop()
{
  if ( mReserveArr.mCounter == 0 )
    return Allocate();
  return mReserveArr.mVec[--mReserveArr.mCounter];
}

template<typename Type>
void TMemoryObjectPool<Type>::Push( Type* p )
{
  mReserveArr.Append( p );
}

