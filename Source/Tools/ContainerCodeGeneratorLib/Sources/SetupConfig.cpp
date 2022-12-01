/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SetupConfig.h"

#include <fstream>
#include <filesystem>
#include <fmt/core.h>

#include "SingletonManager.h"
#include "Config.h"
#include "Generated files/JsonSerializer.h"
#include "LoadFromFile.h"
#include "TextFile.h"
#include "PathOperations.h"

namespace fs = std::filesystem;
using namespace nsBase;

namespace nsContainerCodeGenerator
{
    void TSetupConfig::Init(int argc, char** argv)
    {
        mArgc = argc;
        mArgv = argv;
    }
    //---------------------------------------------------------------------------------------------
    bool TSetupConfig::Work()
    {
        if (mArgc == 1) {
            return false;
        }

        ResolveJsonPath();

        auto loadResult = TryLoadConfig();
        // debug only
        if (loadResult == false) {
            return false;
        }

        ResolvePathes();
        return true;
    }
    //---------------------------------------------------------------------------------------------
    bool TSetupConfig::TryLoadConfig()
    {
        std::string str;
        TTextFile::Load(mAbsPathJsonFile, str);
        if (str.length() == 0) {
            return false;
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(&mConfig, str, err);
        if (!fillRes) {
            fmt::print("Deserilaize error in \"{}\", {}.\n", mAbsPathJsonFile, err);
        }

        return fillRes;
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfig::ResolvePathes()
    {
        ResolvePath(mConfig.reflectionCodeGeneratorFileName);

        ResolvePath(mConfig.coreConfig.parseDirectory);
        ResolvePath(mConfig.coreConfig.targetDirectory);
        ResolvePath(mConfig.coreConfig.ecsSystemConfig.ecsDirectory);

        ResolvePath(mConfig.projectConfig.parseDirectory);
        ResolvePath(mConfig.projectConfig.targetDirectory);
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfig::ResolvePath(std::string& path)
    {
        path = TPathOperations::CalculatePathBy(mAbsPathDirJson, path);
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfig::ResolveJsonPath()
    {
        std::string configName = mArgv[1];

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
    TConfig TSetupConfig::GetConfig() const
    {
        return mConfig;
    }
    //---------------------------------------------------------------------------------------
}