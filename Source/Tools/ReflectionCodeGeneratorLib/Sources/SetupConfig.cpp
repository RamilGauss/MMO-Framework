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
#include "ReflectionCodeGeneratorLib/Sources/ResolvedConfig.h"
#include "ReflectionCodeGeneratorLib/Sources/JsonSerializer.h"
#include "ReflectionCodeGeneratorLib/Sources/Requirements.h"
#include "ReflectionCodeGeneratorLib/Sources/SetupConfig.h"

namespace fs = std::filesystem;
using namespace nsReflectionCodeGenerator;
using namespace nsBase::nsCommon;

void TSetupConfig::Init(TResolvedConfig* resolvedConfig, int argc, char** argv)
{
    mArgc = argc;
    mArgv = argv;
    mResolvedConfig = resolvedConfig;
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
    ResolveConfig();
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
    mConfig.targetForParsing.recursive = true;
    mConfig.targetForParsing.directories.push_back("./Sources");
    mConfig.targetForParsing.directories.push_back("../Parser/Sources");

    mConfig.filter.attribute = "REFLECTION_ATTRIBUTE";
    mConfig.filter.extensions.push_back(".h");
    mConfig.filter.extensions.push_back(".hh");
    mConfig.filter.extensions.push_back(".hpp");

    mConfig.targetForCodeGeneration.sourceRootPaths = {".."};

    mConfig.targetForCodeGeneration.directory = "./Sources";
    mConfig.targetForCodeGeneration.header = "\tReflectionCodeGenerator";

    mConfig.targetForCodeGeneration.appendTypeCustomizerMap = true;
    mConfig.targetForCodeGeneration.includeListParams.includeListFileName = "IncludeList";

    TSerializer jsonSerializer;
    jsonSerializer.exportDeclaration = "DllExport";
    jsonSerializer.className = "TJsonSerializer";
    jsonSerializer.fileName = "JsonSerializer";
    jsonSerializer.nameSpaceName = "nsJson";

    jsonSerializer.externalSources.reset(new TExternalSources());
    jsonSerializer.externalSources->inFileList = { "../Parser/Sources/GeneratedFiles/JsonOutFile.json" };
    jsonSerializer.externalSources->outFile = "./Sources/JsonOutFile.json";

    mConfig.targetForCodeGeneration.implementations.insert({"JsonSerializerGenerator", jsonSerializer});
}
//---------------------------------------------------------------------------------------
bool TSetupConfig::TryLoadConfig()
{
    std::string str;
    nsBase::nsCommon::TTextFile::Load(mAbsPathJsonFile, str);
    if (str.length() == 0) {
        return false;
    }

    std::string err;
    auto fillRes = nsJson::TJsonSerializer::Deserialize(&mConfig, str, err);
    return fillRes;
}
//---------------------------------------------------------------------------------------
void TSetupConfig::ResolveConfig()
{
    mResolvedConfig->header = mConfig.targetForCodeGeneration.header;
    mResolvedConfig->filter.attribute = mConfig.filter.attribute;
    mResolvedConfig->filter.extensions = mConfig.filter.extensions;
    mResolvedConfig->filter.inheritances = mConfig.filter.inheritances;
    mResolvedConfig->filter.memberIgnore = mConfig.filter.memberIgnore;

    mResolvedConfig->targetParsingRecursive = mConfig.targetForParsing.recursive;

    for (auto& dir : mConfig.targetForParsing.directories) {
        auto absPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, dir);
        mResolvedConfig->targetForParsingAbsPaths.push_back(absPath);
    }

    mResolvedConfig->typeCustomizerMap = mConfig.targetForCodeGeneration.typeCustomizerMap;
    mResolvedConfig->appendTypeCustomizerMap = mConfig.targetForCodeGeneration.appendTypeCustomizerMap;

    mResolvedConfig->targetForCodeGenerationAbsPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, mConfig.targetForCodeGeneration.directory);

    std::unordered_set<std::string> extSet(mResolvedConfig->filter.extensions.begin(), mResolvedConfig->filter.extensions.end());

    for (auto& sourceRootPath : mConfig.targetForCodeGeneration.sourceRootPaths) {
        TSourceRoot sourceRoot;
        sourceRoot.original = sourceRootPath;
        sourceRoot.absOriginalPath = TPathOperations::CalculatePathBy(mAbsPathDirJson, sourceRootPath);

        CollectAbsPaths(sourceRoot.absOriginalPath, extSet, sourceRoot.absPathAllFilesInDir);

        mResolvedConfig->sourceRoots.push_back(sourceRoot);
        mResolvedConfig->absSourceRootPaths.push_back(sourceRoot.absOriginalPath);
    }

    for (auto& impl : mConfig.targetForCodeGeneration.implementations) {
        TSerializerExt ser;

        if (impl.second.externalSources) {
            ser.externalSources = std::make_shared<TExternalSourcesExt>();

            for (auto& inFile : impl.second.externalSources->inFileList) {
                auto absInFilePath = TPathOperations::CalculatePathBy(mAbsPathDirJson, inFile);
                ser.externalSources->inAbsFilePathList.push_back(absInFilePath);
            }
            ser.externalSources->outAbsFilePath = TPathOperations::CalculatePathBy(mAbsPathDirJson, impl.second.externalSources->outFile);

            for (auto& inAbsFilePath : ser.externalSources->inAbsFilePathList) {
                TContainer data;
                nsBase::nsCommon::TLoadFromFile lff;

                auto isOpen = lff.ReOpen((char*)inAbsFilePath.c_str());
                if (isOpen == false) {
                    continue;
                }
                lff.ReadSmall(data);

                std::string content;
                content.append(data.GetPtr(), data.GetSize());

                std::string err;
                TExternalSource extSrc;
                auto deserResult = nsJson::TJsonSerializer::Deserialize(&extSrc, content, err);
                if (deserResult == false) {
                    continue;
                }

                auto pathToJsonFile = fs::path(inAbsFilePath).parent_path().string();

                TExternalSourceExt externalSourceExt;

                externalSourceExt.fileName = extSrc.fileName;
                externalSourceExt.customizedTypes = extSrc.customizedTypes;
                externalSourceExt.nameSpaceName = extSrc.nameSpaceName;
                externalSourceExt.typeName = extSrc.typeName;

                externalSourceExt.absFilePath = TPathOperations::CalculatePathBy(pathToJsonFile, externalSourceExt.fileName);
                externalSourceExt.filePathForInclude = TPathOperations::ResolveInclude(mResolvedConfig->absSourceRootPaths, externalSourceExt.absFilePath);

                ser.externalSources->loadedExternalSources.emplace_back(std::move(externalSourceExt));
            }
        }

        ser.keyValueMap = impl.second.keyValueMap;
        ser.className = impl.second.className;
        ser.exportDeclaration = impl.second.exportDeclaration;
        ser.nameSpaceName = impl.second.nameSpaceName;
        ser.fileName = impl.second.fileName;
        ser.absFilePath = TPathOperations::CalculatePathBy(mResolvedConfig->targetForCodeGenerationAbsPath, impl.second.fileName);
        ser.filePathForInclude = TPathOperations::ResolveInclude(mResolvedConfig->absSourceRootPaths, ser.absFilePath);
        mResolvedConfig->implementations.emplace(impl.first, std::move(ser));
    }
    mResolvedConfig->includeAbsFilePath = TPathOperations::CalculatePathBy(mResolvedConfig->targetForCodeGenerationAbsPath, mConfig.targetForCodeGeneration.includeListParams.includeListFileName);
    mResolvedConfig->includeFileForInclude = TPathOperations::ResolveInclude(mResolvedConfig->absSourceRootPaths, mResolvedConfig->includeAbsFilePath);
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
void TSetupConfig::CollectAbsPaths(const std::string& dir, 
    const std::unordered_set<std::string>& extSet, std::unordered_set<std::string>& fileList)
{
    fs::recursive_directory_iterator dirIt((char*)dir.data());

    for (auto& p : dirIt) {
        auto path = p.path();
        std::string ext = path.extension().string();
        if (extSet.find(ext) == extSet.end()) {
            continue;
        }
        auto str = std::filesystem::canonical(path).string();
        fileList.insert(str);
    }
}
//---------------------------------------------------------------------------------------
