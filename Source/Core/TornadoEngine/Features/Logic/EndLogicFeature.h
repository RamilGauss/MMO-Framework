/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "LogicMakerFeature.h"
#include "LogicBuilderFeature.h"
#include "LogicTerminatorFeature.h"

#include "SceneFeature.h"
#include "PrefabFeature.h"

namespace nsLogicWrapper
{
    class DllExport TEndLogicFeature : public nsECSFramework::TFeature
    {
        TLogicMakerFeature mLogicMakerFeature;
        TLogicBuilderFeature mLogicBuilderFeature;
        TLogicTerminatorFeature mLogicTerminatorFeature;

        TSceneFeature mSceneFeature;
        TPrefabFeature mPrefabFeature;
    public:
        void InitConveyor() override;
    };
}