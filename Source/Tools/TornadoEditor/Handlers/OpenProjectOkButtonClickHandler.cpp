/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OpenProjectOkButtonClickHandler.h"

#include <ECS/include/Helper.h>

#include "TextFile.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "SceneManager.h"
#include "PrefabManager.h"
#include "GameObject.h"
#include "PrefabObjectConstructor.h"

#include "SceneInstanceGuidComponent.h"
#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"
#include "EditorInfoTagComponent.h"
#include "InputTextValueComponent.h"
#include "AbsoluteFilePathComponent.h"
#include "ProjectConfigComponent.h"

#include "TornadoEngineJsonSerializer.h"
#include "TitleComponent.h"
#include "LabelValueComponent.h"
#include "FileHierarchyWindowTagComponent.h"
#include "FileHierarchyWindowRefreshTagComponent.h"

using namespace nsTornadoEditor;
using namespace nsTornadoEngine;


bool TOpenProjectOkButtonClickHandler::LoadProjectConfig(const std::string& absPath, 
    nsTornadoEngine::TProjectConfig& projectConfig, std::string& err)
{
    std::string jsonContent;
    TTextFile::Load(absPath, jsonContent);
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

        auto prefabObjConstructor = nsTornadoEngine::Modules()->PrefabObjConstructor();
        prefabObjConstructor->EntMng()->Clear();
        auto warningDialogEid = prefabObjConstructor->InstantiateByGuid("2");

        nsGuiWrapper::TTitleComponent titleComponent;
        titleComponent.value = "Tornado editor";
        prefabObjConstructor->EntMng()->SetComponent(warningDialogEid, titleComponent);

        auto labelEid = prefabObjConstructor->GetChildByName(warningDialogEid, "Label");

        nsGuiWrapper::TLabelValueComponent labelValueComponent;
        labelValueComponent.value = "\"" + absPath + "\" - " + err;
        prefabObjConstructor->EntMng()->SetComponent(labelEid, labelValueComponent);
        prefabMng->InstantiateByObjectInMemory(prefabObjConstructor, warningDialogEid, sceneInstanceGuid);
        return;
    }

    auto editorInfoEid = nsECSFramework::SingleEntity<TEditorInfoTagComponent>(entMng);

    TAbsoluteFilePathComponent absoluteFilePathComponent;
    absoluteFilePathComponent.value = absPath;

    entMng->SetComponent(editorInfoEid, absoluteFilePathComponent);
    entMng->SetComponent(editorInfoEid, projectConfigComponent);

    prefabMng->Destroy(eid);

    //auto fileHierarchyWindowEid = nsECSFramework::SingleEntity<TFileHierarchyWindowTagComponent>(entMng);

    //if (fileHierarchyWindowEid == nsECSFramework::NONE) {
    //    prefabMng->InstantiateByGuid("0", sceneInstanceGuid);
    //} else {

    //    // Destroy file hierarchy
    //    TGameObject go(fileHierarchyWindowEid);
    //    
    //    auto treeViewGo = go.GetChildByName("TreeView");

    //    nsECSFramework::TEntityList treeNodeEids;
    //    treeViewGo.GetChilds(treeNodeEids);
    //    for (auto& treeNodeEid : treeNodeEids) {
    //        prefabMng->Destroy(treeNodeEid);
    //    }

    //    entMng->SetComponent(fileHierarchyWindowEid, TFileHierarchyWindowRefreshTagComponent());
    //}
}
//---------------------------------------------------------------------------------------------------------------------