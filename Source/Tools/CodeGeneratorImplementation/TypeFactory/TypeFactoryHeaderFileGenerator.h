/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeFactoryFileGenerator.h"
#include <format>
#include <fmt/core.h>

namespace nsCodeGeneratorImplementation
{
    class TTypeFactoryHeaderFileGenerator : public TTypeFactoryFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
std::format("    static void* {}(int {});", s_New, s_rtti),
std::format("    static void {}(void* p, int {});", s_Delete, s_rtti),
std::format("    static bool {}(int {});", s_Has, s_rtti),
            "",
std::format("    static void {}();", s_Init),
            "private:",
std::format("    struct {}", s_Data),
            "    {",
            "        int rtti = 0;",
std::format("        std::function<void* ()> {};", s_newFunc),
std::format("        std::function<void (void*)> {};", s_deleteFunc),
            "    };",
            "",
std::format("    static std::vector<{}> {};", s_Data, s_mDataVector),
        };

    public:
        virtual void Work() override;
    };
}

