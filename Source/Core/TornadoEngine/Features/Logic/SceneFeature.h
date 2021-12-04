/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "StartedScenesInitSystem.h"
#include "NeedUnloadSceneSystem.h"
#include "NeedDestroySceneSystem.h"

namespace nsLogicWrapper
{
    class DllExport TSceneFeature : public nsECSFramework::TFeature
    {
        TStartedScenesInitSystem mStartedScenesInitSystem;
        TNeedUnloadSceneSystem mNeedUnloadSceneSystem;
        TNeedDestroySceneSystem mNeedDestroySceneSystem;
    public:
        void InitConveyor() override;
    };
}