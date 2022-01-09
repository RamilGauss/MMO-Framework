/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnFileHierarchyClickHandler.h"

#include "Modules.h"
#include "PrefabManager.h"

#include <ECS/include/Helper.h>
#include "FileHierarchyWindowTagComponent.h"
#include "SceneInstanceGuidComponent.h"
#include "HierarchyHelper.h"

using namespace nsTornadoEditor;

void TOnFileHierarchyClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

    auto fileHierarchyWindowEid = nsECSFramework::SingleEntity<TFileHierarchyWindowTagComponent>(entMng);

    if (fileHierarchyWindowEid == nsECSFramework::NONE) {
        prefabMng->InstantiateByGuid("0", sceneInstanceGuid);
    } else {
        prefabMng->Destroy(fileHierarchyWindowEid);
    }

}
