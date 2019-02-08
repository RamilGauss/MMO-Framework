/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "VectorRise.h"

// not Thread-safe!

template<typename Type>
class DllExport TMemoryObjectPool
{
#ifdef WIN32
#pragma pack(push, 1)
#endif
  class TObjectDesc
  {
    friend class TMemoryObjectPool;
    Type obj;
    unsigned char poped = false;
  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif

  TVectorRise<TObjectDesc*> mCommonArr;
  TVectorRise<TObjectDesc*> mReserveArr;
public:
  Type* Pop()
  {
    TObjectDesc* pDesc = nullptr;
    if ( mReserveArr.mCounter == 0 )
      pDesc = Allocate();
    else
    {
      pDesc = mReserveArr.mVec[mReserveArr.mCounter - 1];
      mReserveArr.PopBack();
    }
    pDesc->poped = true;
    return &( pDesc->obj );
  }
  void Push( Type* p )
  {
    auto pDesc = (TObjectDesc*) p;
    if ( pDesc->poped == false )
      return;
    pDesc->poped = false;

    if ( mReserveArr.mCounter >= mReserveArr.mVec.size() )
      mReserveArr.IncreaseVec();

    mReserveArr.Append( pDesc );
  }
private:
  TObjectDesc* Allocate()
  {
    auto pDesc = new TObjectDesc();
    if ( mCommonArr.mVec.size() == mCommonArr.mCounter )
      mCommonArr.IncreaseVec();
    mCommonArr.Append( pDesc );
    return pDesc;
  }
};
