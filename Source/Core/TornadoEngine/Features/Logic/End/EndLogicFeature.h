/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Logic/End/Maker/LogicMakerFeature.h"
#include "TornadoEngine/Features/Logic/End/Builder/LogicBuilderFeature.h"
#include "TornadoEngine/Features/Logic/End/Terminator/LogicTerminatorFeature.h"

#include "TornadoEngine/Features/Logic/End/Scene/SceneFeature.h"
#include "TornadoEngine/Features/Logic/End/Object/ObjectFeature.h"

namespace nsLogicWrapper
{
    class DllExport TEndLogicFeature : public nsECSFramework::TFeature
    {
        TLogicMakerFeature mLogicMakerFeature;
        TLogicBuilderFeature mLogicBuilderFeature;
        TLogicTerminatorFeature mLogicTerminatorFeature;

        TSceneFeature mSceneFeature;
        TObjectFeature mObjectFeature;
    public:
        void InitConveyor() override;
    };
}
