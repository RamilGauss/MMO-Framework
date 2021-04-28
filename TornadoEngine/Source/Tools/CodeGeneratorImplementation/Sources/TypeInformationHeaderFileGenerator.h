/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeInformationFileGenerator.h"
#include "fmt/core.h"

namespace nsReflectionCodeGenerator
{
    class TTypeInformationHeaderFileGenerator : public TTypeInformationFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            fmt::format("    static std::list<std::string> {};", s_mTypeNameList),
            fmt::format("    static std::list<int> {};", s_mTypeIdentifierList),
            "",
            fmt::format("    static std::map<int, std::string> {};", s_mIdentifierNameMap),
            fmt::format("    static std::map<std::string, int> {};", s_mNameIdentifierMap),
            "",
            fmt::format("    static void {}();", s_Init),
            "",
            "public:",
            fmt::format("    static const std::list<std::string>* {}();", s_GetTypeNameList),
            fmt::format("    static const std::list<int>* {}();", s_GetTypeIdentifierList),
            "",
            fmt::format("    static bool {}(int {}, std::string& {});", s_ConvertTypeToName, s_typeIdentifier, s_typeName),
            fmt::format("    static bool {}(const std::string& {}, int& {});", s_ConvertNameToType, s_typeName, s_typeIdentifier),
        };

    public:
        virtual void Work() override;
    };
}

