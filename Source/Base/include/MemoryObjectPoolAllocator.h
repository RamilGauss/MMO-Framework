/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SingletonManager.h"
#include "MemoryObjectPool.h"

// not Thread-safe!
class DllExport TMemoryObjectPoolAllocator
{
public:
    template<typename Type>
    static Type* AllocateFunc()
    {
        return SingletonManager()->Get<TMemoryObjectPool<Type>>()->Pop();
    }
    template<typename Type>
    static void DeallocateFunc(Type* p)
    {
        if (p == nullptr)
            return;

        SingletonManager()->Get<TMemoryObjectPool<Type>>()->Push(p);
    }
};
