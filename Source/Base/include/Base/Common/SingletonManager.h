/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <array>

#include "Base/Common/TypeDef.h"
#include "Base/Common/RunTimeTypeIndex.h"

// Thread-safe
class DllExport TSingletonManager
{
    std::array<void*, 1024 * 10> mObjArray = { nullptr };

    std::recursive_mutex mMutex;

    TRunTimeTypeIndex<TSingletonManager> mGlobalTypeIdentifier;
public:
    template<typename Type>
    Type* Get()
    {
        auto index = mGlobalTypeIdentifier.Type<Type>();
        static std::atomic_bool isNeedInit = true;
        if (isNeedInit) {
            std::lock_guard<std::recursive_mutex> guard(mMutex);
            if (mObjArray[index] == nullptr) {
                mObjArray[index] = new Type();
            }
            isNeedInit = false;
        }
        return (Type*)mObjArray[index];
    }
};

extern DllExport TSingletonManager* SingletonManager();
