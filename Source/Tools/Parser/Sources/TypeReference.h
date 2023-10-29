/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "TypeDef.h"

namespace nsCppParser
{
#pragma REFLECTION_ATTRIBUTE
    struct TTypeReference
    {
        // namespace bb{
        // class Foo : public aa::AA<xx::X, yy::Y>
        // }
        std::string mOriginalName;// In origianl source:  aa::AA<xx::X, yy::Y>

        std::string mOriginalTypeName;// In origianl source:  aa::AA
        std::string mOriginalNameSpace;// In origianl source:  aa

        //For searching in TypeManager
        std::string mShortTypeName;// AA
        std::string mNameSpace;// bb::aa
        std::string mLongTypeName;// bb::aa::AA

        std::list<std::string> originalTemplates;//[xx::X, yy::Y]

        void SetupTemplates();
    };
}