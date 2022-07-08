/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectHierarchyWindowInitSystem.h"

#include <ECS/include/Helper.h>

#include "FileHierarchyWindowTagComponent.h"
#include "Modules.h"
#include "PrefabManager.h"
#include "IGraphicEngineModule.h"
#include "MainWindowTagComponent.h"

#include "SceneInstanceGuidComponent.h"

namespace nsTornadoEditor
{
    void TObjectHierarchyWindowInitSystem::Init()
    {
        auto pGE = nsTornadoEngine::Modules()->G()->GetGE();
        auto displayWidth = pGE->GetWidth();
        auto displayHeight = pGE->GetHeight();


        //auto entMng = nsTornadoEngine::Modules()->EntMng();
        //auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

        //auto mainWindowEid = nsECSFramework::SingleEntity<TMainWindowTagComponent>(entMng);
        //auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(mainWindowEid)->value;

        //prefabMng->InstantiateByGuid("0", sceneInstanceGuid);
    }
}