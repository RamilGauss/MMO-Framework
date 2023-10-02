/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "GuidConstants.h"
#include "MathStructs.h"

namespace nsTornadoEngine
{
    struct DllExport TInstantiateSceneParams
    {
        std::string guid;

        // optionality
        std::string universeGuid = TGuidConstants::DEFAULT_UNIVERSE;
        nsMathTools::TMatrix16 rootMatrix;
        std::string tag;
        std::string sceneInstanceGuid;
    };
}
