/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>
#include <set>

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/Types.h"
#include "Parser/Sources/TypeReference.h"
#include "Parser/Sources/FriendInfo.h"

namespace nsCppParser
{
    struct DllExport TMethodContent
    {
        // WIP
    };

    struct DllExport TTemplateArgument
    {
        // WIP
        TemplateArgument mType;
        std::string mValue;
        std::string mDefaultValue;
    };

    struct DllExport TMethodInfo
    {
        std::string mName;

        std::set<std::string> mPragmaTextSet;

        AccessLevel mAccessLevel;

        MethodCategoryType mCategory;

        TTypeReference mReturnedType;

        std::vector<TTypeReference> mArguments;

        std::vector<TTemplateArgument> mTemplateArguments;

        TMethodContent mContent;
    };
}