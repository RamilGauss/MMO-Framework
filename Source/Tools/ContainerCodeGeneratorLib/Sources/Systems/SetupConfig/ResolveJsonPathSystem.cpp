/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResolveJsonPathSystem.h"

#include <fstream>
#include <filesystem>
#include <fmt/core.h>

#include <ECS/include/ExecuteSystem.h>
#include <ECS/include/Helper.h>

#include "Config.h"
#include "LoadFromFile.h"
#include "TextFile.h"
#include "PathOperations.h"

#include "Generated files/JsonSerializer.h"

#include "Components/ArgumentComponent.h"
#include "Components/ConfigComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator
{
    void TResolveJsonPathSystem::Execute()
    {
        namespace fs = std::filesystem;

        auto argumentComponent = nsECSFramework::SingleComponent<TArgumentComponent>(mEntMng);
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string configName = argumentComponent->argv[1];

        auto configFileName = fs::path(configName).filename();
        if (configFileName == configName) {
            // This is a name
            configName = "./" + configName;
        }

        auto pathToJsonFile = fs::path(configName).parent_path().string();
        auto currentPath = fs::current_path().string();
        pathsComponent->absPathDirJson = nsBase::TPathOperations::CalculatePathBy(currentPath, pathToJsonFile);
        pathsComponent->absPathDirJson += "\\";

        pathsComponent->absPathJsonFile = nsBase::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, configFileName.string());
    }
}