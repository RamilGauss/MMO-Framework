/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnOpenFileHierarchyWindowHandler.h"

#include <filesystem>
#include "Modules.h"
#include "StopAccessor.h"
#include "PrefabManager.h"
#include "PrefabObjectConstructor.h"

#include "GuidComponent.h"
#include "InputTextValueComponent.h"
#include "TitleComponent.h"
#include "SceneInstanceGuidComponent.h"
#include <ECS/include/Helper.h>
#include "AbsoluteFilePathComponent.h"
#include "EditorInfoTagComponent.h"
#include "FilePathNodeComponent.h"

#include <iostream>

namespace fs = std::filesystem;

using namespace nsTornadoEditor;
using namespace nsTornadoEngine;

void TOnOpenFileHierarchyWindowHandler::Handle(nsECSFramework::TEntityID eid)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto prefabObjConstructor = nsTornadoEngine::Modules()->PrefabObjConstructor();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid)->value;
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid)->value;

    auto editorInfoEid = nsECSFramework::SingleEntity<TEditorInfoTagComponent>(entMng);
    auto absoluteFilePath = entMng->ViewComponent<TAbsoluteFilePathComponent>(editorInfoEid)->value;

    prefabObjConstructor->EntMng()->Clear();

    auto directory = fs::path(absoluteFilePath).parent_path();
    AddFileNodes(nsECSFramework::NONE, directory.string(), sceneInstanceGuid, parentGuid);
}
//--------------------------------------------------------------------------------------------
void TOnOpenFileHierarchyWindowHandler::AddFileNodes(nsECSFramework::TEntityID parentNodeEid, 
    const std::string& absoluteFilePath, const std::string& sceneInstanceGuid, const std::string& parentGuid)
{
    nsECSFramework::TEntityID fileNodeEid;

    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
    auto prefabObjConstructor = nsTornadoEngine::Modules()->PrefabObjConstructor();

    std::list<std::filesystem::path> paths;
    GetFiles(absoluteFilePath, paths, true);
    GetFiles(absoluteFilePath, paths, false);

    for (const auto& path : paths) {
        fileNodeEid = prefabObjConstructor->InstatiateByGuid("3");
        if (parentNodeEid != nsECSFramework::NONE) {
            prefabObjConstructor->Attach(parentNodeEid, fileNodeEid);
        }

        auto absFilePathStr = path.string();

        auto fileName = path.filename().string();

        auto isDir = std::filesystem::is_directory(path);
        if (isDir) {
            fileName = "[" + fileName + "]";
        }

        nsGuiWrapper::TTitleComponent titleComponent;
        titleComponent.value = fileName;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, titleComponent);

        TFilePathNodeComponent filePathNodeComponent;
        filePathNodeComponent.value = absFilePathStr;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, filePathNodeComponent);

        if (isDir) {
            AddFileNodes(fileNodeEid, absFilePathStr, sceneInstanceGuid, parentGuid);
        }

        if (parentNodeEid == nsECSFramework::NONE) {
            prefabMng->InstantiateByObjectInMemory(prefabObjConstructor, fileNodeEid, sceneInstanceGuid, parentGuid);
        }
    }
}
//--------------------------------------------------------------------------------------------
void TOnOpenFileHierarchyWindowHandler::GetFiles(const std::filesystem::path& directory,
    std::list<std::filesystem::path>& paths, bool isDir)
{
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_directory() == isDir) {
            paths.push_back(entry.path());
        }
    }
}
//--------------------------------------------------------------------------------------------
