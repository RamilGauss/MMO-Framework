/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "Base/Common/TypeDef.h"
#include "Base/Common/RunTimeTypeIndex.h"

// not Thread-safe!
class DllExport TSingletonManager
{
    typedef std::vector<void*> TPtrVector;

    TPtrVector mTypeObjVec;

    TRunTimeTypeIndex<TSingletonManager> mGlobalTypeIdentifier;
public:
    template<typename Type>
    Type* Get()
    {
        auto index = mGlobalTypeIdentifier.Type<Type>();
        size_t count = index + 1;
        if ( mTypeObjVec.size() < count ) {
            mTypeObjVec.resize(count);
        }
        if ( mTypeObjVec[index] == nullptr ) {
            mTypeObjVec[index] = new Type();
        }
        return (Type*) mTypeObjVec[index];
    }
};

extern DllExport TSingletonManager* SingletonManager();
