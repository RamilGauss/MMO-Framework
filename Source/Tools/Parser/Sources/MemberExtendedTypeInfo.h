/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>

#include "TypeDef.h"
#include "Types.h"

namespace nsCppParser
{
    struct DllExport TMemberExtendedTypeInfo
    {
        TypeCategory mCategory;

        AccessMethod mAccessMethod = AccessMethod::OBJECT;

        std::vector<TMemberExtendedTypeInfo> mTemplateChildArr;

        std::string mShortType;// Z

        std::string mLongType;// X::Y::Z
        std::string mNameSpace;// X::Y

        std::string mSmartPtrType;// std::auto_ptr, std::shared_ptr, std::weak_ptr, std::unique

        void Reset();

    public:
        bool IsContainer();

        std::string GetCollectSubType();
        std::string GetTypeNameWithNameSpace();
        std::string GetTypeNameWithNameSpaceReflection();

        std::string GetAccessOperator();
    };
}