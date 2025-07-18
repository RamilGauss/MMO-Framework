/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/VectorRise.h"
#include <assert.h>
// not Thread-safe!

#if _DEBUG

// Slow, but safe (check if push again same value)
template<typename Type>
class DllExport TMemoryObjectPool
{
#pragma pack(push, 1)
    class TObjectDesc
    {
        friend class TMemoryObjectPool;
        Type obj;
        unsigned char poped = false;
    };
#pragma pack(pop)

    TVectorRise<TObjectDesc*> mCommonArr;
    TVectorRise<TObjectDesc*> mReserveArr;
public:
    Type* Pop()
    {
        TObjectDesc* pDesc = nullptr;
        if (mReserveArr.mCounter == 0) {
            pDesc = Allocate();
        } else {
            pDesc = mReserveArr.mVec[mReserveArr.mCounter - 1];
            mReserveArr.PopBack();
        }
        pDesc->poped = true;
        return &(pDesc->obj);
    }
    void Push(Type* p)
    {
        auto pDesc = (TObjectDesc*) p;
        if (pDesc->poped == false) {
            return;
        }
        pDesc->poped = false;

        mReserveArr.Append(pDesc);
    }
private:
    TObjectDesc* Allocate()
    {
        auto pDesc = new TObjectDesc();
        mCommonArr.Append(pDesc);
        return pDesc;
    }
};
#else

// fast, but unsafe
template<typename Type>
class DllExport TMemoryObjectPool
{
    TVectorRise<Type*> mReserveArr;
    TVectorRise<Type*> mCommonArr;
public:
    inline Type* Pop();
    inline void Push(Type* p);
private:
    Type* Allocate()
    {
        auto p = new Type();
        mCommonArr.Append(p);
        return p;
    }
};

template<typename Type>
Type* TMemoryObjectPool<Type>::Pop()
{
    if (mReserveArr.mCounter == 0) {
        return Allocate();
    }
    return mReserveArr.mVec[--mReserveArr.mCounter];
}

template<typename Type>
void TMemoryObjectPool<Type>::Push(Type* p)
{
    mReserveArr.Append(p);
}

#endif