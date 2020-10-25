/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MemberInfo.h"
#include "Types.h"
#include "TypeReference.h"

namespace nsCppParser
{
    struct DllExport TInheritanceInfo : public TTypeReference
    {
        std::string mParentTypeName;// то что в исходном варианте  A::B

        std::string mShortParentTypeName;// B
        std::string mLongParentTypeName;// ns::A::B

        AccessLevel mInheritanceAccessLevel = AccessLevel::PRIVATE;
    };
}