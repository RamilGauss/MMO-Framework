/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectHierarchyWindowInitSystem.h"

#include "ECS/Include/Helper.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"

#include "TornadoEngine/Modules/Interfaces/IGraphicEngineModule.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Gui/Properties/PositionComponent.h"
#include "TornadoEngine/Components/Gui/Properties/SizeComponent.h"

#include "TornadoEditor/Sources/Components/FileHierarchyWindowTagComponent.h"
#include "TornadoEditor/Sources/Components/MainWindowTagComponent.h"
#include "TornadoEditor/Sources/Components/MainWindowPrefabGuidComponent.h"

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

        return;//###

        auto go = prefabMng->Instantiate({ mainWindowPrefabGuidComponent->objectHierarchyGuid, sceneInstanceGuid });

        go.SetComponent<nsGuiWrapper::TPositionComponent>({ 0, displayHeight / 2 });
        go.SetComponent<nsGuiWrapper::TSizeComponent>({ displayWidth / 3 , displayHeight / 2 });
    }
}
