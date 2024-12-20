/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TFrameworkResources
    {
        std::string resourcesContentMapPath;
        std::string prefabsContentMapPath;
        std::string scenesContentMapPath;
#pragma IGNORE_ATTRIBUTE
        std::string resourcesContentMapAbsPath;
#pragma IGNORE_ATTRIBUTE
        std::string prefabsContentMapAbsPath;
#pragma IGNORE_ATTRIBUTE
        std::string scenesContentMapAbsPath;
    };
}
