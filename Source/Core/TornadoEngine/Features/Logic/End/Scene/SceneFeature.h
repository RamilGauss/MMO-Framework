/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Logic/End/Scene/StartedScenesInitSystem.h"
#include "TornadoEngine/Features/Logic/End/Scene/SceneInstantiatingSystem.h"

namespace nsLogicWrapper
{
    class DllExport TSceneFeature : public nsECSFramework::TFeature
    {
        TStartedScenesInitSystem mStartedScenesInitSystem;

        TSceneInstantiatingSystem mSceneInstantiatingSystem;
    public:
        void InitConveyor() override;
    };
}