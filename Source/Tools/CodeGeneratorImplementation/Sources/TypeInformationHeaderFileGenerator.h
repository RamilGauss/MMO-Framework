/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeInformationFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TTypeInformationHeaderFileGenerator : public TTypeInformationFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            fmt::format("    static std::list<std::string> {};", s_mTypeNameList),
            "",
            fmt::format("    static std::vector<std::string> {};", s_mNameVector),
            fmt::format("    static std::map<std::string, int> {};", s_mNameRttiMap),
            "",
            fmt::format("    static void {}();", s_Init),
            "",
            "public:",
            fmt::format("    static const std::list<std::string>* {}();", s_GetTypeNameList),
            "",
            fmt::format("    static const std::string* {}(int {});", s_ConvertTypeToName, s_rtti),
            fmt::format("    static bool {}(const std::string& {}, int& {});", s_ConvertNameToType, s_typeName, s_rtti),
        };

    public:
        void Work() override;
    };
}

