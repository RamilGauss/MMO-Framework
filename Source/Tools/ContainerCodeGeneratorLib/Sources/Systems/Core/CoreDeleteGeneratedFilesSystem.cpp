/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CoreDeleteGeneratedFilesSystem.h"

#include <filesystem>

#include <fmt/core.h>

#include <ECS/include/Helper.h>

#include "Components/ConfigComponent.h"

namespace nsContainerCodeGenerator
{
    void TCoreDeleteGeneratedFilesSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);

        auto targetDir = std::filesystem::path(configComponent->value.coreConfig.targetDirectory);

        for (const auto& entry : std::filesystem::directory_iterator(targetDir)) {
            std::filesystem::remove_all(entry.path());
        }
    }
}