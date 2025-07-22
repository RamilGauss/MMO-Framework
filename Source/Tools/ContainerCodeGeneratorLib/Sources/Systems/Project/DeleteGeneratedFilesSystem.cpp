/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DeleteGeneratedFilesSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include "ECS/Include/Helper.h"

#include "Components/ProjectConfigComponent.h"

namespace nsContainerCodeGenerator::nsProject
{
    void TDeleteGeneratedFilesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TProjectConfigComponent>(mEntMng);

        auto targetDir = std::filesystem::path(configComponent->value.projectConfig.targetDirectory);

        for (const auto& entry : std::filesystem::directory_iterator(targetDir)) {
            std::filesystem::remove_all(entry.path());
        }
    }
}