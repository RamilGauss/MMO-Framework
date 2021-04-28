/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TProgramInfo
    {
    public:
        static const std::string NAME;
        static const std::string VERSION_MAJOR;
        static const std::string VERSION_MINOR_HIGH;
        static const std::string VERSION_MINOR_LOW;
        static const int COUNTER_BUILD;
        static const std::string INFO;

        static std::string Get();
    };
}
