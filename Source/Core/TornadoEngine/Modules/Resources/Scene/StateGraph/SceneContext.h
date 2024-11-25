/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/HopProcessContext.h"

#include "Modules/Resources/Scene/InstantiateSceneParams.h"

namespace nsTornadoEngine
{
    struct DllExport TSceneContext : nsBase::nsZones::THopProcessContext
    {
        std::string sceneAbsPath;

        TInstantiateSceneParams instantiateSceneParams;




    };

    using TSceneContextPtr = std::shared_ptr<TSceneContext>;
}
