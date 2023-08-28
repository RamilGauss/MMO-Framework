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
#include "MainWindowPrefabGuidComponent.h"

#include "SceneInstanceGuidComponent.h"

#include "PositionComponent.h"
#include "SizeComponent.h"

namespace nsTornadoEditor
{
    void TObjectHierarchyWindowInitSystem::Init()
    {
        auto pGE = nsTornadoEngine::Modules()->G()->GetGE();
        auto displayWidth = pGE->GetWidth();
        auto displayHeight = pGE->GetHeight();

        auto entMng = nsTornadoEngine::Modules()->EntMng();
        auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

        auto mainWindowEid = nsECSFramework::SingleEntity<TMainWindowTagComponent>(entMng);
        auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(mainWindowEid)->value;

        auto mainWindowPrefabGuidComponent = entMng->ViewComponent<TMainWindowPrefabGuidComponent>(mainWindowEid);

        auto go = prefabMng->InstantiateByGuid({ mainWindowPrefabGuidComponent->objectHierarchyGuid, sceneInstanceGuid });

        nsGuiWrapper::TPositionComponent posComponent;
        posComponent.x = 0;
        posComponent.y = displayHeight / 2;
        go.SetComponent(posComponent);

        nsGuiWrapper::TSizeComponent sizeComponent;
        sizeComponent.x = displayWidth / 3;
        sizeComponent.y = displayHeight / 2;
        go.SetComponent(sizeComponent);
    }
}