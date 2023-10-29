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
            fmt::format("    static std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> {};", s_mTypeInfoVector),
            "",
            "public:",
            fmt::format("    static void {}();", s_Init),
            "",
            fmt::format("    static const nsCppParser::TTypeInfo* {}(int {});", s_Get, s_rtti),
        };

    public:
        void Work() override;
    };
}

