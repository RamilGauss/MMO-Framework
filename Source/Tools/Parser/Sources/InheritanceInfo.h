/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Parser/Sources/MemberInfo.h"
#include "Parser/Sources/Types.h"
#include "Parser/Sources/TypeReference.h"

namespace nsCppParser
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TInheritanceInfo : public TTypeReference
    {
        AccessLevel mInheritanceAccessLevel = AccessLevel::PRIVATE;
    };
}