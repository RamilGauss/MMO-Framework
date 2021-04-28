/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionFileGenerator.h"
#include "fmt/core.h"

namespace nsReflectionCodeGenerator
{
    class TReflectionHeaderFileGenerator : public TReflectionFileGenerator
    {
        const std::list<std::string> s_Decl =
        {
            "public:",
fmt::format("    static void* {}(const std::string& {});", s_New, s_typeName),
            "private:",
fmt::format("    struct {}", s_Data),
            "    {",
fmt::format("        std::string {};", s_typeName),
fmt::format("        std::function<void* ()> {};", s_newFunc),
            "    };",
            "",
fmt::format("    static std::map<std::string, {}> {};", s_Data, s_mTypeNameMap),
            "",
fmt::format("    static void {}();", s_Init),
        };

    public:
        virtual void Work() override;
    };
}

