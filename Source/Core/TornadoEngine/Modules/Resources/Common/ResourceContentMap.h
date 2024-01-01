/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <unordered_map>
#include <string>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TResourceContentMap
    {
        std::unordered_map<std::string, std::string> guidPathMap;
    };
}
