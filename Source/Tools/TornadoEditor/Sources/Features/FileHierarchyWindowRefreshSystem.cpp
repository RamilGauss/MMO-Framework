/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>
#include <iostream>

#include "ECS/Include/Helper.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Gui/Properties/NodeIconComponent.h"
#include "TornadoEngine/Components/Gui/Properties/InputTextValueComponent.h"
#include "TornadoEngine/Components/Graphic/TextureFromFileComponent.h"

#include "TornadoEditor/Sources/Components/AbsoluteFilePathComponent.h"
#include "TornadoEditor/Sources/Components/EditorInfoTagComponent.h"
#include "TornadoEditor/Sources/Components/FilePathNodeComponent.h"
#include "TornadoEditor/Sources/Features/FileHierarchyWindowRefreshSystem.h"

namespace fs = std::filesystem;

using namespace nsTornadoEditor;

void TFileHierarchyWindowRefreshSystem::Reactive(nsECSFramework::TEntityID eid, const TFileHierarchyWindowRefreshTagComponent* pC)
{
    auto entMng = GetEntMng();

    entMng->RemoveComponent<TFileHierarchyWindowRefreshTagComponent>(eid);

    nsTornadoEngine::TGameObject go(eid);
    auto treeViewEid = go.GetChildByName("TreeView").GetEid();

    Handle(treeViewEid);
}
//--------------------------------------------------------------------------------------------
void TFileHierarchyWindowRefreshSystem::Handle(nsECSFramework::TEntityID treeViewEid)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
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

    auto directory = fs::path(absoluteFilePath).parent_path();
    AddFileNodes({}, directory.string(), sceneInstanceGuid, parentGuid);
}
//--------------------------------------------------------------------------------------------
void TFileHierarchyWindowRefreshSystem::AddFileNodes(const nsTornadoEngine::TGameObject& parentGo,
    const std::string& absoluteFilePath, const std::string& sceneInstanceGuid, const std::string& parentGuid)
{
    auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();

    std::list<std::filesystem::path> paths;
    GetFiles(absoluteFilePath, paths, true);
    GetFiles(absoluteFilePath, paths, false);

    for (const auto& path : paths) {

        auto go = prefabMng->Instantiate({ "3", sceneInstanceGuid, parentGuid});

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
        go.SetComponent(titleComponent);

        TFilePathNodeComponent filePathNodeComponent;
        filePathNodeComponent.value = absFilePathStr;
        go.SetComponent(filePathNodeComponent);

        nsGraphicWrapper::TTextureFromFileComponent textureComponent;
        textureComponent.resourceGuid = icon;
        go.SetComponent(textureComponent);

        nsGuiWrapper::TNodeIconComponent nodeIconComponent;
        nodeIconComponent.width = 16;
        nodeIconComponent.height = 16;
        go.SetComponent(nodeIconComponent);

        if (isDir) {
            auto parentGoGuid = go.GetComponent<nsCommonWrapper::TGuidComponent>().value;
            AddFileNodes(go, absFilePathStr, sceneInstanceGuid, parentGoGuid);
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
        {".cpp",    "cpp.png"},
        {".h",      "cpp.png"},
        {".json",   "json.png"},
        {".png",    "image.png"},
        {".jpg",    "image.png"},
        {".jpeg",   "image.png"},
        {".scene",  "scene.png"},
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
