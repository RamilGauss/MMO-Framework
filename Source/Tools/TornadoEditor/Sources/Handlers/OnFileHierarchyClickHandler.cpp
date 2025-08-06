/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ECS/Include/Helper.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"

#include "TornadoEditor/Sources/Handlers/OnFileHierarchyClickHandler.h"
#include "TornadoEditor/Sources/Components/FileHierarchyWindowTagComponent.h"

using namespace nsTornadoEditor;

void TOnFileHierarchyClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

    auto fileHierarchyWindowEid = nsECSFramework::SingleEntity<TFileHierarchyWindowTagComponent>(entMng);

    if (fileHierarchyWindowEid == nsECSFramework::NONE) {

        nsTornadoEngine::TInstantiatePrefabParams instantiatePrefabParams;
        instantiatePrefabParams.guid = "0";
        instantiatePrefabParams.sceneInstanceGuid = sceneInstanceGuid;

        prefabMng->Instantiate(std::move(instantiatePrefabParams));
    } else {
        prefabMng->Destroy(fileHierarchyWindowEid);
    }

}
