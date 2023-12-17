/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "RunTimeTypeInformationFileGenerator.h"
#include <format>
#include <fmt/core.h>

namespace nsCodeGeneratorImplementation
{
    class TRunTimeTypeInformationHeaderFileGenerator : public TRunTimeTypeInformationFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            std::format("    static std::list<std::string> {};", s_mTypeNameList),
            std::format("    static std::list<int> {};", s_mRttiList),
            "",
            std::format("    static std::vector<std::string> {};", s_mNameVector),
            std::format("    static std::unordered_map<std::string, int> {};", s_mNameRttiMap),
            "",
            "public:",
            std::format("    static void {}();", s_Init),
            "",
            std::format("    static const std::list<std::string>* {}();", s_GetTypeNameList),
            std::format("    static const std::list<int>* {}();", s_GetRttiList),
            "",
            std::format("    static const std::string* {}(int {});", s_ConvertTypeToName, s_rtti),
            std::format("    static bool {}(const std::string& {}, int& {});", s_ConvertNameToType, s_typeName, s_rtti),
        };

    public:
        void Work() override;
    };
}

