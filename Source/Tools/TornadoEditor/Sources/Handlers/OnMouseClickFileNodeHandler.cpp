/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <filesystem>

#include "ECS/Include/Helper.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneManager.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/Modules/Resources/Common/GameObject.h"

#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Gui/Properties/SelectedTreeNodeGuidComponent.h"

#include "TornadoEditor/Sources/Components/FilePathNodeComponent.h"
#include "TornadoEditor/Sources/Components/ObjectHierarchyWindowTagComponent.h"
#include "TornadoEditor/Sources/Components/ObjectHierarchyWindowRefreshTagComponent.h"
#include "TornadoEditor/Sources/Components/EditorInfoTagComponent.h"
#include "TornadoEditor/Sources/Components/AssetAbsoluteFilePathComponent.h"

#include "TornadoEditor/Sources/Handlers/OnMouseClickFileNodeHandler.h"

using namespace nsTornadoEditor;
using namespace nsTornadoEngine;

namespace fs = std::filesystem;

void TOnMouseClickFileNodeHandler::Handle(nsECSFramework::TEntityID eid, const nsGraphicEngine::TMouseButtonEvent event)
{
    if (event.clicks != 2) {
        return;
    }

    if (event.button != nsGraphicEngine::MouseButton::LEFT) {
        return;
    }

    //TODO: open scene or prefab editing window
    auto sceneMng = nsTornadoEngine::Modules()->SceneMng();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
    auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
    auto entMng = nsTornadoEngine::Modules()->EntMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

    auto selectedTreeNodeGuidComponent = entMng->ViewComponent<nsGuiWrapper::TSelectedTreeNodeGuidComponent>(eid);

    if (selectedTreeNodeGuidComponent == nullptr ||
        selectedTreeNodeGuidComponent->value == nsTornadoEngine::TGuidConstants::NONE) {
        return;
    }

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = selectedTreeNodeGuidComponent->value;
    auto selectedTreeNodeEid = entMng->GetByUnique(guidComponent);

    if (selectedTreeNodeEid == nsECSFramework::NONE) {
        return;
    }

    auto absPath =
        entMng->ViewComponent<TFilePathNodeComponent>(selectedTreeNodeEid)->value;

    auto path = fs::path(absPath);

    auto ext = path.extension();

    if (ext.string() != ".prefab" && ext.string() != ".scene") {
        return;
    }

    auto fileHierarchyWindowEid = nsECSFramework::SingleEntity<TObjectHierarchyWindowTagComponent>(entMng);

    auto editorInfoTagEid = nsECSFramework::SingleEntity<TEditorInfoTagComponent>(entMng);
    TAssetAbsoluteFilePathComponent assetAbsoluteFilePathComponent;
    assetAbsoluteFilePathComponent.value = absPath;

    entMng->SetComponent(editorInfoTagEid, assetAbsoluteFilePathComponent);

    if (fileHierarchyWindowEid == nsECSFramework::NONE) {
        nsTornadoEngine::TInstantiatePrefabParams instantiatePrefabParams;
        instantiatePrefabParams.guid = "4";
        instantiatePrefabParams.sceneInstanceGuid = sceneInstanceGuid;

        prefabMng->Instantiate(std::move(instantiatePrefabParams));
    } else {

        // Destroy file hierarchy
        TGameObject go(fileHierarchyWindowEid);
        auto treeViewGo = go.GetChildByName("TreeView");

        nsECSFramework::TEntityList treeNodeEids;
        treeViewGo.GetChilds(treeNodeEids);
        for (auto& treeNodeEid : treeNodeEids) {
            prefabMng->Destroy(treeNodeEid);
        }

        entMng->SetComponent(fileHierarchyWindowEid, TObjectHierarchyWindowRefreshTagComponent());
    }
}