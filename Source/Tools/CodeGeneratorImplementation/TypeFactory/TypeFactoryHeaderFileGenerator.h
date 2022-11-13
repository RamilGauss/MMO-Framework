/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeFactoryFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TTypeFactoryHeaderFileGenerator : public TTypeFactoryFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
fmt::format("    static void* {}(int {});", s_New, s_rtti),
fmt::format("    static void {}(void* p, int {});", s_Delete, s_rtti),
fmt::format("    static bool {}(int {});", s_Has, s_rtti),
            "private:",
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::function<void* ()> {};", s_newFunc),
fmt::format("        std::function<void (void*)> {};", s_deleteFunc),
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

