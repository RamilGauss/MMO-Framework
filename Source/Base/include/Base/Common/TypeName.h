/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsBase
{
    class DllExport TTypeName
    {
    public:
        template <typename T>
        static std::string Get()
        {
            std::string typeName = typeid(T).name();

            const std::string STRUCT = "struct";
            const std::string CLASS = "class";
            const std::string ENUM = "enum";

            auto classIndex = typeName.find(CLASS);
            auto structIndex = typeName.find(STRUCT);
            auto enumIndex = typeName.find(ENUM);

            if (classIndex == std::string::npos &&
                structIndex == std::string::npos &&
                enumIndex == std::string::npos) {
                return typeName;
            }

            if (classIndex != std::string::npos) {
                return typeName.substr(classIndex + 1 + CLASS.size());
            }
            if (structIndex != std::string::npos) {
                return typeName.substr(structIndex + 1 + STRUCT.size());
            }

            return typeName.substr(enumIndex + 1 + ENUM.size());
        }
    };
}