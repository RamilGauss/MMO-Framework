/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/pool/pool.hpp>
#include "AllocatorPool.h"

#define USE_BOOST_MEMORY_POOL

#define ALLOCATOR ((boost::pool<>*)mAlloc)

using namespace DataExchange2Thread;

TAllocatorPool::TAllocatorPool()
{
#ifdef USE_BOOST_MEMORY_POOL
  mAlloc = new boost::pool<>(sizeof(TElement));
#else
  mAlloc = NULL;
#endif
}
//-----------------------------------------------------------------------------------
TAllocatorPool::~TAllocatorPool()
{
  delete mAlloc;
}
//-----------------------------------------------------------------------------------
TElement* TAllocatorPool::Allocate()
{
#ifdef USE_BOOST_MEMORY_POOL
  return (TElement*)ALLOCATOR->malloc();
#else
  return new TElement();
#endif
}
//-----------------------------------------------------------------------------------
void TAllocatorPool::Deallocate( TElement* pElement )
{
#ifdef USE_BOOST_MEMORY_POOL
  ALLOCATOR->free(pElement);
#else
  delete pElement;
#endif
}
//-----------------------------------------------------------------------------------
