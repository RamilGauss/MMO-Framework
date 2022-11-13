/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DynamicCasterFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TDynamicCasterHeaderFileGenerator : public TDynamicCasterFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
fmt::format("    static void* {}(int {}, void* p, int {});", s_Cast, s_SrcRtti, s_DstRtti),
            "private:",
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::function<void*(void*)> {};", s_castFunc),
            "    };",
            "",
fmt::format("    static std::vector<std::vector<{}>> {};", s_Data, s_mDataVector),
            "",
fmt::format("    static void {}();", s_Init),
        };

    public:
        virtual void Work() override;
    };
}

