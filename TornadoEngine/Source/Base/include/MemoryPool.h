/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <memory>
#include <map>
#include <list>
#include "VectorRise.h"
#include "TypeDef.h"

template<typename Type>
class DllExport TMemoryPool
{
public:
  struct TDescPointer
  {
    Type* p = nullptr;
    int size = 0;
  };

  TDescPointer* Pop( int size );
  void Push( TDescPointer* pDesc );

  void Clear();
private:
  typedef TVectorRise<TDescPointer*> TVectorRiseDescPtr;

  typedef std::map<int, TVectorRiseDescPtr*> TIntVectorDescPtrMap;
  typedef typename TIntVectorDescPtrMap::iterator   TIntVectorDescPtrMapIt;
  typedef typename TIntVectorDescPtrMap::value_type TIntVectorDescPtrMapVT;

  TIntVectorDescPtrMap mSizePtrMap;

  // для хранения всех указателей
  TVectorRiseDescPtr mPool;

  TDescPointer* Allocate( int size );

  TVectorRiseDescPtr* GetVectorRiseDescPtr( int size );
};
//--------------------------------------------------------------------------------------
template<typename Type>
typename TMemoryPool<Type>::TDescPointer* TMemoryPool<Type>::Pop( int size )
{
  TDescPointer* pDesc = nullptr;
  auto pVecRise = GetVectorRiseDescPtr( size );
  if( pVecRise->mCounter == 0 )
  {
    pDesc = Allocate( size );
  }
  else
  {
    pDesc = pVecRise->mVec[pVecRise->mCounter - 1];
    pVecRise->PopBack();
  }
  return pDesc;
}
//--------------------------------------------------------------------------------------
template<typename Type>
void TMemoryPool<Type>::Push( TDescPointer* pDesc )
{
  auto pVecRise = GetVectorRiseDescPtr( pDesc->size );
  if( pVecRise->mCounter >= pVecRise->mVec.size() )
    pVecRise->IncreaseVec();

  pVecRise->Append( pDesc );
}
//--------------------------------------------------------------------------------------
template<typename Type>
typename TMemoryPool<Type>::TVectorRiseDescPtr* TMemoryPool<Type>::GetVectorRiseDescPtr( int size )
{
  auto fit = mSizePtrMap.find( size );
  if( fit == mSizePtrMap.end() )
  {
    mSizePtrMap.insert( TIntVectorDescPtrMapVT( size, new TVectorRiseDescPtr() ) );
    fit = mSizePtrMap.find( size );
  }
  return fit->second;
}
//--------------------------------------------------------------------------------------
template<typename Type>
typename TMemoryPool<Type>::TDescPointer* TMemoryPool<Type>::Allocate( int size )
{
  auto* pDesc = new TDescPointer();
  pDesc->p = new Type[size];
  pDesc->size = size;

  if( mPool.mVec.size() == mPool.mCounter )
    mPool.IncreaseVec();
  mPool.Append( pDesc );
  return pDesc;
}
//--------------------------------------------------------------------------------------
template<typename Type>
void TMemoryPool<Type>::Clear()
{
  for( size_t i = 0; i < mPool.mCounter; i++ )
  {
    auto pDesc = mPool.mVec[i];
    if( pDesc->size == 1 )
      delete mPool.mVec[i]->p;
    else if( pDesc->size > 0 )
      delete [] mPool.mVec[i]->p;
    delete mPool.mVec[i];
  }
  mPool.Clear();

  for( auto pair : mSizePtrMap )
  {
    delete pair.second;
  }
  mSizePtrMap.clear();
}
//--------------------------------------------------------------------------------------
