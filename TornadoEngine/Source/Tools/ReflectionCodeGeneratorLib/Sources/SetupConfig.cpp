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

#include "Requirements.h"
#include "SingletonManager.h"
#include "Config.h"
#include "JsonSerializer.h"
#include "LoadFromFile.h"
#include "TextFile.h"
#include "PathOperations.h"

namespace fs = std::filesystem;
using namespace nsReflectionCodeGenerator;

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
        ShowManual();
        return false;
    }

    ResolveJsonPath();

    auto loadResult = TryLoadConfig();
    // debug only
    if (loadResult == false)
#ifdef _DEBUG
        DefaultConfig();
#else
        return false;
#endif
    ResolvePathes();
    return true;
}
//---------------------------------------------------------------------------------------------
void TSetupConfig::ShowManual()
{
    for (auto key : nsManual::g_Manual) {
        fmt::print("{}:\n", key.first.data());
        for (auto value : key.second) {
            fmt::print("\t {}\n", value.data());
        }
    }

    fmt::print("Press any key for continue...\n");
}
//---------------------------------------------------------------------------------------
void TSetupConfig::DefaultConfig()
{
    auto mConfig = mConfigContainer->Config();
    mConfig->targetForParsing.recursive = true;
    mConfig->targetForParsing.directories.push_back("../ReflectionCodeGeneratorLib/Sources");

    mConfig->filter.attribute = "REFLECTION_ATTRIBUTE";
    mConfig->filter.extensions.push_back(".h");
    mConfig->filter.extensions.push_back(".hpp");

    mConfig->targetForCodeGeneration.directory = "../ReflectionCodeGeneratorLib/Sources";
    mConfig->targetForCodeGeneration.includeListFileName = "IncludeList";

    TSerializer jsonSerializer;
    jsonSerializer.className = "TJsonSerializer";
    jsonSerializer.fileName = "JsonSerializer";
    jsonSerializer.nameSpaceName = "nsJson";
    mConfig->targetForCodeGeneration.implementations.insert({"JsonSerializerGenerator", jsonSerializer});

    TSerializer binaryMarshaller;
    binaryMarshaller.className = "TBinaryMarshaller";
    binaryMarshaller.fileName = "BinaryMarshaller";
    binaryMarshaller.nameSpaceName = "nsBinary";
    binaryMarshaller.keyValueMap.insert({"beginId", "666"});

    mConfig->targetForCodeGeneration.implementations.insert({"BinaryMarshallerGenerator", binaryMarshaller});
}
//---------------------------------------------------------------------------------------
bool TSetupConfig::TryLoadConfig()
{
    auto mConfig = mConfigContainer->Config();
    std::string str;
    TTextFile::Load(mAbsPathJsonFile, str);
    if (str.length() == 0)
        return false;

    std::string err;
    auto fillRes = nsJson::TJsonSerializer::Fill(mConfig, str, err);
    //LoadExternalSources(config);
    return fillRes;
}
//---------------------------------------------------------------------------------------
void TSetupConfig::ResolvePathes()
{
    auto pConfig = mConfigContainer->Config();

    // input
    for (auto& dir : pConfig->targetForParsing.directories) {
        dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
    }

    // output
    auto& dir = pConfig->targetForCodeGeneration.directory;
    dir = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
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
    mAbsPathJsonFile = TPathOperations::CalculatePathBy(currentPath, pathToJsonFile);
}
//---------------------------------------------------------------------------------------
