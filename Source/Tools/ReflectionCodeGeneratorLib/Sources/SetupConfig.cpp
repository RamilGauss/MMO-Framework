/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <fstream>
#include <filesystem>
#include <fmt/core.h>

#include "Base/Common/SingletonManager.h"
#include "Base/Common/LoadFromFile.h"
#include "Base/Common/TextFile.h"
#include "Base/Common/PathOperations.h"

#include "ReflectionCodeGeneratorLib/Sources/Config.h"
#include "ReflectionCodeGeneratorLib/Sources/Cache.h"
#include "ReflectionCodeGeneratorLib/Sources/JsonSerializer.h"
#include "ReflectionCodeGeneratorLib/Sources/Requirements.h"
#include "ReflectionCodeGeneratorLib/Sources/SetupConfig.h"

namespace fs = std::filesystem;
using namespace nsReflectionCodeGenerator;
using namespace nsBase::nsCommon;

void TSetupConfig::Init(TConfigContainer* configContainer, TCache* cache, int argc, char** argv)
{
    mArgc = argc;
    mArgv = argv;
    mConfigContainer = configContainer;
    mCache = cache;
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
    ConvertConfigToCache();
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
    auto config = mConfigContainer->Config();
    config->targetForParsing.recursive = true;
    config->targetForParsing.directories.push_back("./Sources");
    config->targetForParsing.directories.push_back("../Parser/Sources");

    config->filter.attribute = "REFLECTION_ATTRIBUTE";
    config->filter.extensions.push_back(".h");
    config->filter.extensions.push_back(".hh");
    config->filter.extensions.push_back(".hpp");

    config->targetForCodeGeneration.directory = "./Sources";
    config->targetForCodeGeneration.header = "\tReflectionCodeGenerator";

    config->targetForCodeGeneration.appendTypeCustomizerMap = true;
    config->targetForCodeGeneration.includeListParams.includeListFileName = "IncludeList";

    TSerializer jsonSerializer;
    jsonSerializer.exportDeclaration = "DllExport";
    jsonSerializer.className = "TJsonSerializer";
    jsonSerializer.fileName = "JsonSerializer";
    jsonSerializer.nameSpaceName = "nsJson";

    jsonSerializer.externalSources.reset(new TExternalSources());
    jsonSerializer.externalSources->outFile = "./Sources/JsonOutFile.json";

    config->targetForCodeGeneration.implementations.insert({"JsonSerializerGenerator", jsonSerializer});

    TSerializer binaryMarshaller;
    binaryMarshaller.exportDeclaration = "DllExport";
    binaryMarshaller.className = "TBinaryMarshaller";
    binaryMarshaller.fileName = "BinaryMarshaller";
    binaryMarshaller.nameSpaceName = "nsBinary";
    binaryMarshaller.keyValueMap.insert({"beginId", "666"});

    binaryMarshaller.externalSources.reset(new TExternalSources());
    binaryMarshaller.externalSources->outFile = "./Sources/BinaryOutFile.json";

    config->targetForCodeGeneration.implementations.insert({"BinaryMarshallerGenerator", binaryMarshaller});
}
//---------------------------------------------------------------------------------------
bool TSetupConfig::TryLoadConfig()
{
    auto mConfig = mConfigContainer->Config();
    std::string str;
    nsBase::nsCommon::TTextFile::Load(mAbsPathJsonFile, str);
    if (str.length() == 0) {
        return false;
    }

    std::string err;
    auto fillRes = nsJson::TJsonSerializer::Deserialize(mConfig, str, err);
    return fillRes;
}
//---------------------------------------------------------------------------------------
void TSetupConfig::ConvertConfigToCache()
{
    auto config = mConfigContainer->Config();

    // input
    for (auto& dir : config->targetForParsing.directories) {
        auto absPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        mCache->targetForParsingAbsPaths.push_back(absPath);
    }

    mCache->targetForCodeGenerationAbsPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, config->targetForCodeGeneration.directory);
    mCache->includeAbsFilePath = TPathOperations::CalculatePathBy(mAbsPathDirJson, config->targetForCodeGeneration.includeListParams.includeListFileName);

    for (auto& impl : config->targetForCodeGeneration.implementations) {
        TSerializerExt ser;
        ser.className = impl.second.className;
        ser.exportDeclaration = impl.second.exportDeclaration;
        ser.nameSpaceName = impl.second.nameSpaceName;
        ser.fileName = impl.second.fileName;
        ser.absFilePath = TPathOperations::CalculatePathBy(mAbsPathDirJson, impl.second.fileName);
        //ser.filePathForInclude = TPathOperations::GetRelativePath(mAbsPathDirJson, impl.second.fileName);
        mCache->implementations.emplace(impl.first, std::move(ser));
    }

    // auto& sourceRootPaths = config->targetForCodeGeneration.sourceRootPaths;
    // if (sourceRootPaths.empty()) {
        // sourceRootPaths = ".";
    // }
    // sourceRootPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, sourceRootPath);
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
