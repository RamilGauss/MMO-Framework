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
    struct DllExport TInstantiatePrefabParams
    {
        std::string guid;
        std::string sceneInstanceGuid;
        std::string parentGuid = TGuidConstants::NONE;
        nsMathTools::TMatrix16 rootMatrix;

        std::string absPath;

        std::string projectionToUniverseGuid;// ???
    };
}
