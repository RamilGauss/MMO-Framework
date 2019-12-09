/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "DataExchange2ThreadElement.h"

class DllExport TAllocatorPool
{
  void* mAlloc = nullptr;
public:
  TAllocatorPool();
  ~TAllocatorPool();

  DataExchange2Thread::TElement* Allocate();
  void Deallocate( DataExchange2Thread::TElement* pElement );
};
