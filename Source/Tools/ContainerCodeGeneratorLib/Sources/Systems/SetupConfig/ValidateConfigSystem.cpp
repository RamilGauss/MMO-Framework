/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ValidateConfigSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <PathOperations.h>
#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ConfigComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig
{
    void TValidateConfigSystem::Execute()
    {
        // Editor had to create folders 
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        ValidateAndThrow("coreConfig.parseDirectory", configComponent->value.coreConfig.parseDirectory);
        ValidateAndThrow("coreConfig.targetDirectory", configComponent->value.coreConfig.targetDirectory);

        ValidateAndThrow("projectConfig.parseDirectory", configComponent->value.projectConfig.parseDirectory);
        ValidateAndThrow("projectConfig.targetDirectory", configComponent->value.projectConfig.targetDirectory);


        ValidateAndThrow("projectConfig.absPathToProject", configComponent->value.projectConfig.absPathToProject);

        std::list<std::string> fileList;
        nsBase::TPathOperations::AddAbsPathsByDirectory(configComponent->value.projectConfig.absPathToProject, 
            {".project"}, fileList, false);

        if (fileList.size() == 0) {
            auto msg = fmt::format("Not found project: \"{}\"\n", configComponent->value.projectConfig.absPathToProject);
            throw TMessageException(msg);
        }

        auto rootPath = std::filesystem::path(configComponent->value.projectConfig.absPathToProject).root_name();
        if (rootPath.wstring() != std::wstring(&std::filesystem::path::preferred_separator)) {

            auto root = rootPath.string();
            std::string upperRoot = root;

            std::transform(root.begin(), root.end(), upperRoot.begin(), ::toupper);

            if (root != upperRoot) {
                auto msg = fmt::format("Incorrect path, need a upper case for the disk label: \"{}\"\n", configComponent->value.projectConfig.absPathToProject);
                throw TMessageException(msg);
            }
        }
    }

    void TValidateConfigSystem::ValidateAndThrow(const std::string& tagName, const std::string& path)
    {
        auto isExist = std::filesystem::exists(path);

        if (!isExist) {
            auto msg = fmt::format("Not valid {}: \"{}\"\n", tagName, path);
            throw TMessageException(msg);
        }
    }
}