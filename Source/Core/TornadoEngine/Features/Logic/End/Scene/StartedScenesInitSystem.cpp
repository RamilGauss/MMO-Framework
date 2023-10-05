/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "StartedScenesInitSystem.h"
#include "ProjectConfigContainer.h"
#include "Modules.h"

#include "SceneManager.h"

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