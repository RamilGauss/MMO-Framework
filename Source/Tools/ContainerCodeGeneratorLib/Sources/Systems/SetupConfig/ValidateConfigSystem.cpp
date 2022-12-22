/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ValidateConfigSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <ECS/include/Helper.h>

#include "Constants.h"
#include "MessageException.h"

#include "Components/ConfigComponent.h"

namespace nsContainerCodeGenerator
{
    void TValidateConfigSystem::Execute()
    {
        // Editor had to create folders 
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        ValidateAndThrow("coreConfig.parseDirectory", configComponent->value.coreConfig.parseDirectory);
        ValidateAndThrow("coreConfig.targetDirectory", configComponent->value.coreConfig.targetDirectory);

        ValidateAndThrow("projectConfig.parseDirectory", configComponent->value.projectConfig.parseDirectory);
        ValidateAndThrow("projectConfig.targetDirectory", configComponent->value.projectConfig.targetDirectory);
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