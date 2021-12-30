/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OpenProjectOkButtonClickHandler.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "SceneManager.h"
#include "PrefabManager.h"

#include "SceneInstanceGuidComponent.h"

#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"

#include "HierarchyHelper.h"
#include "EditorInfoTagComponent.h"

#include "InputTextValueComponent.h"
#include "AbsoluteFilePathComponent.h"

#include <ECS/include/Helper.h>

#include "ProjectConfigComponent.h"
#include "TextFile.h"
#include "TornadoEngineJsonSerializer.h"
#include "PrefabObjectConstructor.h"
#include "TitleComponent.h"
#include "LabelValueComponent.h"

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
    auto sceneMng = nsTornadoEngine::Modules()->SceneMng();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
    auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto prefabObjConstructor = nsTornadoEngine::Modules()->PrefabObjConstructor();

    prefabObjConstructor->EntMng()->Clear();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;

    auto hierarchy = nsTornadoEngine::Modules()->HierarchyHelper();

    auto textInputEid = hierarchy->GetBrotherByName(eid, "Project path");
    auto absPath =
        entMng->ViewComponent<nsGuiWrapper::TInputTextValueComponent>(textInputEid)->value;

    TProjectConfigComponent projectConfigComponent;
    std::string err;
    auto loadResult = LoadProjectConfig(absPath, projectConfigComponent.value, err);

    if (!loadResult) {

        if (err.empty()) {
            err = "File not found";
        }

        auto warningDialogEid = prefabObjConstructor->InstatiateByGuid("2");

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

    prefabMng->InstantiateByGuid("0", sceneInstanceGuid);
}
//---------------------------------------------------------------------------------------------------------------------