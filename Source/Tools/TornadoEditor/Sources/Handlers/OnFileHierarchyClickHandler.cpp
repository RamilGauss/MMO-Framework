/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnFileHierarchyClickHandler.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Prefab/PrefabManager.h"

#include "ECS/Include/Helper.h"
#include "FileHierarchyWindowTagComponent.h"
#include "Components/Meta/SceneInstanceGuidComponent.h"

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
