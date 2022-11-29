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
        mConfigContainer = SingletonManager()->Get<TConfigContainer>();
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
        auto mConfig = mConfigContainer->Config();
        std::string str;
        TTextFile::Load(mAbsPathJsonFile, str);
        if (str.length() == 0) {
            return false;
        }

        std::string err;
        auto fillRes = TJsonSerializer::Deserialize(mConfig, str, err);
        return fillRes;
    }
    //---------------------------------------------------------------------------------------
    void TSetupConfig::ResolvePathes()
    {
        auto pConfig = mConfigContainer->Config();

        // input
        for (auto& dir : pConfig->coreConfig.componentConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }
        for (auto& dir : pConfig->coreConfig.handlerConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }
        for (auto& dir : pConfig->coreConfig.systemConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }

        for (auto& dir : pConfig->projectConfig.componentConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }
        for (auto& dir : pConfig->projectConfig.handlerConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }
        for (auto& dir : pConfig->projectConfig.systemConfig.directories) {
            dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        }

        // output
        ResolvePath(pConfig->coreConfig.componentConfig.directoryPath);
        ResolvePath(pConfig->coreConfig.handlerConfig.directoryPath);
        ResolvePath(pConfig->coreConfig.systemConfig.directoryPath);
        ResolvePath(pConfig->projectConfig.componentConfig.directoryPath);
        ResolvePath(pConfig->projectConfig.handlerConfig.directoryPath);
        ResolvePath(pConfig->projectConfig.systemConfig.directoryPath);
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
}