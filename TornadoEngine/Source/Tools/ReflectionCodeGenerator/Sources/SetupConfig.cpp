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

TSetupConfig::TSetupConfig()
{
    // dirty, but simple
    mArgc = __argc;
    mArgv = __argv;
    mConfigContainer = SingletonManager()->Get<TConfigContainer>();
}
//---------------------------------------------------------------------------------------------
bool TSetupConfig::Work()
{
    if (mArgc == 1) {
        ShowManual();
        getchar();
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
    for (auto key : nsReflectionCodeGenerator::nsManual::g_Manual) {
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

    config->filter.attribute = "REFLECTION_ATTRIBUTE";
    config->filter.extensions.push_back(".h");
    config->filter.extensions.push_back(".hpp");

    config->targetForCodeGeneration.directory = "./Sources";
    config->targetForCodeGeneration.includeListFileName = "IncludeList";

    config->targetForCodeGeneration.implementation.jsonSerializer.reset(new nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig());
    auto jsonSerializer = config->targetForCodeGeneration.implementation.jsonSerializer.get();
    jsonSerializer->className = "TJsonSerializer";
    jsonSerializer->fileName = "JsonSerializer";
    jsonSerializer->nameSpaceName = "nsJson";

    config->targetForCodeGeneration.implementation.binaryMarshaller.reset(new nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig());
    auto binaryMarshaller = config->targetForCodeGeneration.implementation.binaryMarshaller.get();
    binaryMarshaller->className = "TBinaryMarshaller";
    binaryMarshaller->fileName = "BinaryMarshaller";
    binaryMarshaller->nameSpaceName = "nsBinary";

    binaryMarshaller->unpackHandler.reset(new nsReflectionCodeGenerator::TUnpackHandler());
    binaryMarshaller->unpackHandler->className = "TUnpackHandler";
    binaryMarshaller->unpackHandler->fileName = "UnpackHandler";
    binaryMarshaller->unpackHandler->method = "Handle";
    binaryMarshaller->unpackHandler->nameSpaceName = "nsBinary";
}
//---------------------------------------------------------------------------------------
bool TSetupConfig::TryLoadConfig()
{
    auto config = mConfigContainer->Config();
    std::string str;
    TTextFile::Load(mAbsPathJsonFile, str);
    if (str.length() == 0)
        return false;

    std::string err;
    auto fillRes = nsJson::TJsonSerializer::Fill(config, str, err);
    //LoadExternalSources(config);
    return fillRes;
}
//---------------------------------------------------------------------------------------
std::string TSetupConfig::ResolvePathRelativeConfig(const std::string& path)
{
    // save
    auto oldCurrentPath = fs::current_path().string();

    fs::current_path(mAbsPathDirJson);
    auto result = fs::absolute(path).string();

    // restore
    fs::current_path(oldCurrentPath);
    return result;
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
//void TSetupConfig::LoadExternalSources(nsReflectionCodeGenerator::TConfig* config)
//{
//    LoadExternalSources(config->targetForCodeGeneration.implementation.binaryMarshaller.get());
//    LoadExternalSources(config->targetForCodeGeneration.implementation.jsonSerializer.get());
//}
//---------------------------------------------------------------------------------------
//void TSetupConfig::LoadExternalSources(nsReflectionCodeGenerator::TSerializer* serializer)
//{
//    if (serializer == nullptr) {
//        return;
//    }
//    auto extSrc = serializer->externalSources.get();
//    if (extSrc == nullptr) {
//        return;
//    }
//
//    if (extSrc->outFile.size() > 0) {
//        extSrc->outExtSrc.reset(new nsReflectionCodeGenerator::TExternalSource());
//    }
//
//    if (extSrc->inFileList.size() > 0) {
//        extSrc->inExtSrcList.reset(new nsReflectionCodeGenerator::TExternalSourceList());
//        for (auto& inFile : extSrc->inFileList) {
//
//            //inFile
//            auto absPath = ResolvePathRelativeConfig(inFile);
//
//            std::string str;
//            TTextFile::Load(absPath, str);
//            if (str.length() == 0) {
//                continue;
//            }
//
//            std::string err;
//            nsReflectionCodeGenerator::TExternalSource extSrcFromJson;
//            auto fillRes = nsJson::TJsonSerializer::Fill(&extSrcFromJson, str, err);
//
//            extSrc->inExtSrcList->val.push_back(extSrcFromJson);
//        }
//    }
//}
//---------------------------------------------------------------------------------------
