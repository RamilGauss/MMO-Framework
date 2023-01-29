/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <unordered_map>

#include "TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport TRelativeProperties
    {
        std::unordered_map<std::string, std::string> value;// component -> type
    };
}