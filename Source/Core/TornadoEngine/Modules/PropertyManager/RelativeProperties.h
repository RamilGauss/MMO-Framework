/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <BiMap.h>

#include "TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport TRelativeProperties
    {
        TBiMap<std::string, std::string> componentType;
    };
}