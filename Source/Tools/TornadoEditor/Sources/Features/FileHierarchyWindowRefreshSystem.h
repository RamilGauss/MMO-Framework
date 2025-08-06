/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <filesystem>

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Modules/Resources/Common/GameObject.h"
#include "TornadoEditor/Sources/Components/FileHierarchyWindowRefreshTagComponent.h"

namespace nsTornadoEditor
{
    class DllExport TFileHierarchyWindowRefreshSystem : 
        public nsECSFramework::TOnAddCollectReactiveSystem<TFileHierarchyWindowRefreshTagComponent, TFileHierarchyWindowRefreshSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const TFileHierarchyWindowRefreshTagComponent* pC);

    private:
        void Handle(nsECSFramework::TEntityID eid);

        void AddFileNodes(const nsTornadoEngine::TGameObject& parentGo,
            const std::string& absoluteFilePath, const std::string& sceneInstanceGuid, const std::string& parentGuid);

        void GetFiles(const std::filesystem::path& directory,
            std::list<std::filesystem::path>& paths, bool isDir);

        std::string GetIcon(const std::filesystem::path& fileNamePath);

    };
}
