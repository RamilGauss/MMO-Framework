/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SetupConfigSystem.h"

#include <fstream>
#include <filesystem>
#include <fmt/core.h>

#include <ECS/include/Helper.h>

#include "SingletonManager.h"
#include "Config.h"
#include "LoadFromFile.h"
#include "TextFile.h"
#include "PathOperations.h"

#include "Generated files/JsonSerializer.h"

#include "Components/ArgumentComponent.h"
#include "Components/ConfigComponent.h"
#include "Components/ResultComponent.h"

namespace fs = std::filesystem;
using namespace nsBase;

namespace nsContainerCodeGenerator
{
    void TSetupConfigSystem::Execute()
    {
        auto argumentComponent = nsECSFramework::SingleComponent<TArgumentComponent>(mEntMng);
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(mEntMng);

        if (argumentComponent->argc == 1) {
            resultComponent->value = "Not found argument";
            throw std::exception();
        }

        ResolveJsonPath();

        TryLoadConfig();

        ResolvePathes();
    }
    //---------------------------------------------------------------------------------------------
    void TSetupConfigSystem::TryLoadConfig()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(mEntMng);

        std::string str;
        TTextFile::Load(mAbsPathJsonFile, str);
        if (str.length() == 0) {
            resultComponent->value = fmt::format("Not loaded file \"{}\"\n", mAbsPathJsonFile);
            throw std::exception();
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&configComponent->value, str, err);
        if (!fillRes) {
            resultComponent->value = fmt::format("Deserilaize error in \"{}\", {}\n", mAbsPathJsonFile, err);
            throw std::exception();
        }
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfigSystem::ResolvePathes()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto& config = configComponent->value;

        ResolvePath(config.reflectionCodeGeneratorFileName);

        ResolvePath(config.coreConfig.parseDirectory);
        ResolvePath(config.coreConfig.targetDirectory);
        ResolvePath(config.coreConfig.ecsSystemConfig.ecsDirectory);

        ResolvePath(config.projectConfig.parseDirectory);
        ResolvePath(config.projectConfig.targetDirectory);
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfigSystem::ResolvePath(std::string& path)
    {
        path = TPathOperations::CalculatePathBy(mAbsPathDirJson, path);
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfigSystem::ResolveJsonPath()
    {
        auto argumentComponent = nsECSFramework::SingleComponent<TArgumentComponent>(mEntMng);

        std::string configName = argumentComponent->argv[1];

        auto configFileName = fs::path(configName).filename();
        if (configFileName == configName) {
            // This is a name
            configName = "./" + configName;
        }

        auto pathToJsonFile = fs::path(configName).parent_path().string();
        auto currentPath = fs::current_path().string();
        mAbsPathDirJson = TPathOperations::CalculatePathBy(currentPath, pathToJsonFile);
        mAbsPathDirJson += "\\";

        mAbsPathJsonFile = TPathOperations::CalculatePathBy(mAbsPathDirJson, configFileName.string());
    }
    //---------------------------------------------------------------------------------------
}