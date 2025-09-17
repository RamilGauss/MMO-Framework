/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <filesystem>

#include <fmt/core.h>

#include "Base/Common/PathOperations.h"
#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"
#include "ContainerCodeGeneratorLib/Sources/MessageException.h"
#include "ContainerCodeGeneratorLib/Sources/PathValidator.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/SetupConfig/Project/ValidateConfigSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Components/ProjectConfigComponent.h"

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
        if (rootPath.wstring() != std::wstring(1, std::filesystem::path::preferred_separator)) {

            auto root = rootPath.string();
            std::string upperRoot = root;

            std::transform(root.begin(), root.end(), upperRoot.begin(), ::toupper);

            if (root != upperRoot) {
                auto msg = fmt::format("Incorrect path, need a upper case for the disk label: \"{}\"\n", 
                    configComponent->value.projectConfig.relPathToSources);
                throw TMessageException(msg);
            }
        }
    }
}