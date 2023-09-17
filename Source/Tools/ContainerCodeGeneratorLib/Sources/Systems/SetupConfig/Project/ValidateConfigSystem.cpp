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
#include "PathValidator.h"

#include "Components/ProjectConfigComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TValidateConfigSystem::Execute()
    {
        // Editor had to create folders 
        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        TPathValidator::ValidateAndThrow("projectConfig.parseDirectory", configComponent->value.projectConfig.parseDirectory);
        TPathValidator::ValidateAndThrow("projectConfig.targetDirectory", configComponent->value.projectConfig.targetDirectory);

        TPathValidator::ValidateAndThrow("projectConfig.relPathToSources", configComponent->value.projectConfig.relPathToSources);

        auto rootPath = std::filesystem::path(configComponent->value.projectConfig.relPathToSources).root_name();
        if (rootPath.wstring() != std::wstring(&std::filesystem::path::preferred_separator)) {

            auto root = rootPath.string();
            std::string upperRoot = root;

            std::transform(root.begin(), root.end(), upperRoot.begin(), ::toupper);

            if (root != upperRoot) {
                auto msg = fmt::format("Incorrect path, need a upper case for the disk label: \"{}\"\n", 
                    configComponent->value.projectConfig.relPathToSources);
                throw MSG_EXCEPTION(msg);
            }
        }
    }
}