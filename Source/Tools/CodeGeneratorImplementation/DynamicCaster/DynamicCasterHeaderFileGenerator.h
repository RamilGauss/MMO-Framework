/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DynamicCasterFileGenerator.h"

#include <format>
#include <fmt/core.h>

namespace nsCodeGeneratorImplementation
{
    class TDynamicCasterHeaderFileGenerator : public TDynamicCasterFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
std::format("    static void {}();", s_Init),
std::format("    static const std::map<int, std::set<int>>& {}();// rtti <---> rtti-es", s_GetRttiCombinations),
std::format("    static void* {}(int {}, void* p, int {});", s_Cast, s_SrcRtti, s_DstRtti),
            "private:",
std::format("    struct {}", s_Data),
            "    {",
            "        int rtti = 0;",
std::format("        std::function<void*(void*)> {} = nullptr;", s_castFunc),
            "    };",
            "",
std::format("    static std::vector<std::vector<{}>> {};", s_Data, s_mDataVector),
std::format("    static std::map<int, std::set<int>> {};", s_mRttiCombinations),
            "",
        };

    public:
        virtual void Work() override;
    };
}

