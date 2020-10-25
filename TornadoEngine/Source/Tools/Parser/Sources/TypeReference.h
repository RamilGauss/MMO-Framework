/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsCppParser
{
    struct TTypeReference
    {
        std::string mOriginalName;// In origianl source:  A::B

        //For searching in TypeManager
        std::string mShortTypeName;// B
        std::string mLongTypeName;// ns::A::B
    };
}