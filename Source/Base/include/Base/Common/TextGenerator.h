/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <map>

#include <fmt/core.h>

#include <inja/inja.hpp>

#include "Base/Common/TypeDef.h"

namespace nsBase
{
    struct DllExport TLine
    {
        int8_t tabDiff = 0;
        std::string str;
    };

    struct DllExport TFormatFuncDeclaration
    {
        std::string name;
        int argCount = 1;
        inja::CallbackFunction func;
    };

    class DllExport TTextGenerator
    {
        std::list<TLine> mLines;

        const std::string RET_SYMBOL = "\n";

        uint8_t mTabSize = 4;
    public:
        TTextGenerator(const std::list<TLine>& lines);

        void SetTabSize(uint8_t value);

        // Apply data and functions for formatting of Lines
        bool Apply(const inja::json& data, const std::list<TFormatFuncDeclaration>& formatFuncDeclarations = {});

        // Render lines to string
        std::string Render() const;
    };
}