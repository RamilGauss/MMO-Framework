/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>

#include <fmt/core.h>

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Core/DeleteGeneratedFilesSystem.h"

namespace nsContainerCodeGenerator::nsCore
{
    void TDeleteGeneratedFilesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);

        auto targetDir = std::filesystem::path(configComponent->value.coreConfig.targetDirectory);

        for (const auto& entry : std::filesystem::directory_iterator(targetDir)) {
            std::filesystem::remove_all(entry.path());
        }
    }
}