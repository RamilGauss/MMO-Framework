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

#include "ECS/Include/ExecuteSystem.h"
#include "ECS/Include/Helper.h"

#include "Config.h"
#include "Base/Common/LoadFromFile.h"
#include "Base/Common/TextFile.h"
#include "Base/Common/PathOperations.h"

#include "GeneratedFiles/JsonSerializer.h"

#include "Components/FilePathComponent.h"
#include "Components/PathsComponent.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsCommon
{
    void TResolveJsonPathSystem::Execute()
    {
        namespace fs = std::filesystem;

        auto filePathComponent = nsECSFramework::SingleComponent<TFilePathComponent>(mEntMng);
        auto pathsComponent = nsECSFramework::SingleComponent<TPathsComponent>(mEntMng);

        std::string configName = filePathComponent->value;

        auto configFileName = fs::path(configName).filename();
        if (configFileName == configName) {
            // This is a name
            configName = "./" + configName;
        }

        auto pathToJsonFile = fs::path(configName).parent_path().string();
        auto currentPath = fs::current_path().string();
        pathsComponent->absPathDirJson = nsBase::nsCommon::TPathOperations::CalculatePathBy(currentPath, pathToJsonFile);
        pathsComponent->absPathDirJson += "\\";

        pathsComponent->absPathJsonFile = nsBase::nsCommon::TPathOperations::CalculatePathBy(pathsComponent->absPathDirJson, configFileName.string());
    }
}