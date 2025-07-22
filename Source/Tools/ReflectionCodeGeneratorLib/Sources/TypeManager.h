/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include "Base/Common/SingletonManager.h"
#include "Parser/Sources/TypeInfo.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TTypeManager
    {
    public:
        void Add(nsCppParser::TTypeInfo* typeInfo);
        nsCppParser::TTypeInfo* Get(const std::string& fullTypeName);

        TTypeManager() = default;
    private:
        std::map<std::string, nsCppParser::TTypeInfo*> mFullNameTypeMap;
    };
}