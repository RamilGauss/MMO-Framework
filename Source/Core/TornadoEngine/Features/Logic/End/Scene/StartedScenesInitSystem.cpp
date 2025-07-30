/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneManager.h"

#include "TornadoEngine/Features/Logic/End/Scene/StartedScenesInitSystem.h"

using namespace nsLogicWrapper;
using namespace nsTornadoEngine;

void TStartedScenesInitSystem::Init()
{
    auto& startedScenes = Project()->mProjectConfig.startScenesGuid;

    TInstantiateSceneParams instantiateSceneParams;
    for (auto& sceneGuid : startedScenes) {
        instantiateSceneParams.guid = sceneGuid;
        Modules()->SceneMng()->Instantiate(instantiateSceneParams);
    }
}