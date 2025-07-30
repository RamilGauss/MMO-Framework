/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OpenProjectOkButtonClickHandler.h"

#include "ECS/Include/Helper.h"

#include "Base/Common/TextFile.h"

#include "Modules/Common/Modules.h"
#include "StopAccessor.h"
#include "Modules/Resources/Scene/SceneManager.h"
#include "Modules/Resources/Prefab/PrefabManager.h"
#include "Modules/Resources/Common/GameObject.h"

#include "Components/Meta/SceneInstanceGuidComponent.h"
#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"
#include "EditorInfoTagComponent.h"
#include "InputTextValueComponent.h"
#include "AbsoluteFilePathComponent.h"
#include "ProjectConfigComponent.h"

#include "GeneratedFiles/TornadoEngineJsonSerializer.h"
#include "Components/Gui/Properties/TitleComponent.h"
#include "LabelValueComponent.h"
#include "FileHierarchyWindowTagComponent.h"
#include "FileHierarchyWindowRefreshTagComponent.h"

using namespace nsTornadoEditor;
using namespace nsTornadoEngine;


bool TOpenProjectOkButtonClickHandler::LoadProjectConfig(const std::string& absPath, 
    nsTornadoEngine::TProjectConfig& projectConfig, std::string& err)
{
    std::string jsonContent;
    nsBase::nsCommon::TTextFile::Load(absPath, jsonContent);
    if (jsonContent.length() == 0) {
        return false;
    }
    auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&projectConfig, jsonContent, err);
    if (!deserResult) {
        return false;
    }
    return deserResult;
}
//---------------------------------------------------------------------------------------------------------------------
void TOpenProjectOkButtonClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC)
{
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
    auto entMng = nsTornadoEngine::Modules()->EntMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

    TGameObject go(eid);

    auto textInput = go.GetBrotherByName("Project path");
    auto absPath = textInput.GetComponent<nsGuiWrapper::TInputTextValueComponent>().value;

    TProjectConfigComponent projectConfigComponent;
    std::string err;
    auto loadResult = LoadProjectConfig(absPath, projectConfigComponent.value, err);

    if (!loadResult) {

        if (err.empty()) {
            err = "File not found";
        }

        auto warningDialogObject = nsTornadoEngine::Modules()->PrefabMng()->Instantiate({ "2", sceneInstanceGuid });
        auto warningDialogEid = warningDialogObject.GetEid();

        nsGuiWrapper::TTitleComponent titleComponent;
        titleComponent.value = "Tornado editor";
        warningDialogObject.SetComponent(titleComponent);

        auto labelObject = warningDialogObject.GetChildByName("Label");

        nsGuiWrapper::TLabelValueComponent labelValueComponent;
        labelValueComponent.value = "\"" + absPath + "\" - " + err;
        labelObject.SetComponent(labelValueComponent);
        return;
    }

    auto editorInfoEid = nsECSFramework::SingleEntity<TEditorInfoTagComponent>(entMng);

    TAbsoluteFilePathComponent absoluteFilePathComponent;
    absoluteFilePathComponent.value = absPath;

    entMng->SetComponent(editorInfoEid, absoluteFilePathComponent);
    entMng->SetComponent(editorInfoEid, projectConfigComponent);

    prefabMng->Destroy(eid);

    auto fileHierarchyWindowEid = nsECSFramework::SingleEntity<TFileHierarchyWindowTagComponent>(entMng);

    if (fileHierarchyWindowEid == nsECSFramework::NONE) {
        prefabMng->Instantiate({ "0", sceneInstanceGuid });
    } else {

        // Destroy file hierarchy
        TGameObject go(fileHierarchyWindowEid);
        
        auto treeViewGo = go.GetChildByName("TreeView");

        nsECSFramework::TEntityList treeNodeEids;
        treeViewGo.GetChilds(treeNodeEids);
        for (auto& treeNodeEid : treeNodeEids) {
            prefabMng->Destroy(treeNodeEid);
        }

        entMng->SetComponent(fileHierarchyWindowEid, TFileHierarchyWindowRefreshTagComponent());
    }
}
//---------------------------------------------------------------------------------------------------------------------