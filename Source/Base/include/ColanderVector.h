/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <vector>

template<typename Type>
class DllExport TColanderVector
{
    std::vector<Type> mVec;
public:
    Type& operator [] (int index)
    {
        if (mVec.size() <= index) {
            mVec.resize(index * 2 + 1);
        }
        return mVec[index];
    }

    inline Type* Begin() const
    {
        return (Type*)&mVec[0];
    }

    int Size()
    {
        return mVec.size();
    }
};
