/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include "MemberExtendedTypeInfo.h"
#include "Types.h"

namespace nsCppParser
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TMemberInfo
    {
        std::set<std::string> mPragmaTextSet;// #pragma TEXT

        AccessLevel mAccessLevel;

        std::string mName;

        std::string mTypeName;

        VariableCategory mCategory;

        TMemberExtendedTypeInfo mExtendedInfo;

        void CreateExtArray(std::vector<TMemberExtendedTypeInfo>& arr);
    };
}