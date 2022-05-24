/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FileHierarchyWindowRefreshSystem.h"

#include "Modules.h"
#include "HierarchyHelper.h"
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
#include "NodeIconComponent.h"
#include "TextureComponent.h"

#include <iostream>

namespace fs = std::filesystem;

using namespace nsTornadoEditor;

void TFileHierarchyWindowRefreshSystem::Reactive(nsECSFramework::TEntityID eid, const TFileHierarchyWindowRefreshTagComponent* pC)
{
    auto entMng = GetEntMng();

    entMng->RemoveComponent<TFileHierarchyWindowRefreshTagComponent>(eid);

    auto treeViewEid = nsTornadoEngine::Modules()->HierarchyHelper()->GetChildByName(eid, "TreeView");

    Handle(treeViewEid);
}
//--------------------------------------------------------------------------------------------
void TFileHierarchyWindowRefreshSystem::Handle(nsECSFramework::TEntityID treeViewEid)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto prefabObjConstructor = nsTornadoEngine::Modules()->PrefabObjConstructor();
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

    auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(treeViewEid)->value;
    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(treeViewEid)->value;

    auto editorInfoEid = nsECSFramework::SingleEntity<TEditorInfoTagComponent>(entMng);

    auto absoluteFilePathComponent = entMng->ViewComponent<TAbsoluteFilePathComponent>(editorInfoEid);
    if (absoluteFilePathComponent == nullptr) {
        return;
    }

    auto absoluteFilePath = absoluteFilePathComponent->value;
    if (!fs::exists(absoluteFilePath)) {
        return;
    }

    prefabObjConstructor->EntMng()->Clear();

    auto directory = fs::path(absoluteFilePath).parent_path();
    AddFileNodes(nsECSFramework::NONE, directory.string(), sceneInstanceGuid, parentGuid);
}
//--------------------------------------------------------------------------------------------
void TFileHierarchyWindowRefreshSystem::AddFileNodes(nsECSFramework::TEntityID parentNodeEid,
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

        std::string icon;

        auto isDir = std::filesystem::is_directory(path);
        if (isDir) {
            fileName = "[" + fileName + "]";

            icon = "folder.png";
        } else {
            icon = GetIcon(path);
        }

        nsGuiWrapper::TTitleComponent titleComponent;
        titleComponent.value = fileName;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, titleComponent);

        TFilePathNodeComponent filePathNodeComponent;
        filePathNodeComponent.value = absFilePathStr;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, filePathNodeComponent);

        nsGraphicWrapper::TTextureComponent textureComponent;
        textureComponent.resourceGuid = icon;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, textureComponent);

        nsGuiWrapper::TNodeIconComponent nodeIconComponent;
        nodeIconComponent.width = 16;
        nodeIconComponent.height = 16;
        prefabObjConstructor->EntMng()->SetComponent(fileNodeEid, nodeIconComponent);

        if (isDir) {
            AddFileNodes(fileNodeEid, absFilePathStr, sceneInstanceGuid, parentGuid);
        }

        if (parentNodeEid == nsECSFramework::NONE) {
            prefabMng->InstantiateByObjectInMemory(prefabObjConstructor, fileNodeEid, sceneInstanceGuid, parentGuid);
        }
    }
}
//--------------------------------------------------------------------------------------------
void TFileHierarchyWindowRefreshSystem::GetFiles(const std::filesystem::path& directory,
    std::list<std::filesystem::path>& paths, bool isDir)
{
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_directory() == isDir) {
            paths.push_back(entry.path());
        }
    }
}
//--------------------------------------------------------------------------------------------
std::string TFileHierarchyWindowRefreshSystem::GetIcon(const std::filesystem::path& fileNamePath)
{
    std::map<std::string, std::string> extIconMap = 
    {
        {".cpp", "cpp.png"},
        {".h", "cpp.png"},
        {".json", "json.png"},
        {".png", "image.png"},
        {".jpg", "image.png"},
        {".jpeg", "image.png"},
        {".scene", "scene.png"},
        {".prefab", "prefab.png"},
    };

    auto ext = fileNamePath.extension();

    auto fit = extIconMap.find(ext.string());
    if (fit == extIconMap.end()) {
        return "undefined.jpg";
    }

    return fit->second;
}
//--------------------------------------------------------------------------------------------