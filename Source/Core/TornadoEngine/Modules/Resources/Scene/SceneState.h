#pragma once

/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "Base/Zones/ContextStateInProcess.h"

namespace nsTornadoEngine
{
    struct DllExport TSceneState
    {
        bool inProcess = false;
        nsBase::nsZones::TContextStateInProcess progress;
        std::string zoneName;
    };
}
