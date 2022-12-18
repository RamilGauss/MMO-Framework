/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <array>
#include <string>

#include "TypeDef.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TConstants
    {
        static const std::string CORE_COMPONENT_CONFIG;

        static const std::array<std::string, 5> HEADER_EXTENSIONS;
    };
}
