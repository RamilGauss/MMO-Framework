/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EcsSystemExtensionFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TEcsSystemExtensionHeaderFileGenerator : public TEcsSystemExtensionFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
fmt::format("    static nsECSFramework::TSystem* {}(void* p, int {});", s_DynamicCast, s_rtti),
            "private:",
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::function<nsECSFramework::TSystem* (void*)> {};", s_castFunc),
            "    };",
            "",
fmt::format("    static std::vector<{}> {};", s_Data, s_mDataVector),
            "",
fmt::format("    static void {}();", s_Init),
        };

    public:
        virtual void Work() override;
    };
}

