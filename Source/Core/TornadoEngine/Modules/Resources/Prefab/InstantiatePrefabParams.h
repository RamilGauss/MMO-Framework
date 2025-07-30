/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TornadoEngine/Modules/Resources/Common/GuidConstants.h"
#include "TornadoEngine/Share/MathStructs.h"

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

        TInstantiatePrefabParams() {}

        TInstantiatePrefabParams(const std::string& guid, const std::string& sceneInstanceGuid)
        {
            this->guid = guid;
            this->sceneInstanceGuid = sceneInstanceGuid;
        }

        TInstantiatePrefabParams(const std::string& guid, const std::string& sceneInstanceGuid, const std::string& parentGuid)
        {
            this->guid = guid;
            this->sceneInstanceGuid = sceneInstanceGuid;
            this->parentGuid = parentGuid;
        }
    };
}
