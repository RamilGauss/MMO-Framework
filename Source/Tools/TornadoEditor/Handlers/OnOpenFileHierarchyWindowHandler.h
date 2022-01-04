/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include "IObjectInstanceEndHandler.h"
#include <string>
#include <filesystem>

namespace nsTornadoEditor
{
    class DllExport TOnOpenFileHierarchyWindowHandler : public nsLogicWrapper::IObjectInstanceEndHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid) override;

    private:
        void AddFileNodes(nsECSFramework::TEntityID parentNodeEid, 
            const std::string& absoluteFilePath, const std::string& sceneInstanceGuid, const std::string& parentGuid);

        void GetFiles(const std::filesystem::path& directory,
            std::list<std::filesystem::path>& paths, bool isDir);

        std::string GetIcon(const std::filesystem::path& fileNamePath);
    };
}