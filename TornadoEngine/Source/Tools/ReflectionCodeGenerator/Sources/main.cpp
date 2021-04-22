/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <fmt/core.h>

#include "SingletonManager.h"
#include "Config.h"
#include "Parser/Sources/Parser.h"
#include "CodeGeneratorAggregator.h"
#include "SetupConfig.h"
#include "ProgramInfo.h"
#include "JsonSerializer.h"
#include "BL_Debug.h"
#include "PathOperations.h"
#include "LoadFromFile.h"

using namespace nsReflectionCodeGenerator;
namespace fs = std::filesystem;

using TStringList = std::list<std::string>;
using TStrSet = std::set<std::string>;
using TTypeInfoPtrList = std::list<nsCppParser::TTypeInfo*>;
using TTypeInfoPtrSet = std::set<nsCppParser::TTypeInfo*>;

std::list<std::shared_ptr<nsCppParser::TTypeInfo>> g_AllTypeList;

TStringList g_FileList;
TTypeInfoPtrList g_TypeList;
TTypeInfoPtrSet g_FilteredTypeList;

TCodeGeneratorAggregator g_Cga;

// TODO: transfer to separate dll for access to ContainerCodeGenerator
//---------------------------------------------------------------------------------------
void ShowTitle()
{
    fmt::print("{} version {}, build {}, info {},\n",
        nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD, nsProgramInfo::INFO);
}
//---------------------------------------------------------------------------------------
template <typename DirectoryIterator>
void CollectAbsPaths(TStringList& fileList)
{
    auto config = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();
    TStrSet extSet(config->filter.extensions.begin(), config->filter.extensions.end());

    for (auto& dir : config->targetForParsing.directories) {
        for (auto& p : DirectoryIterator((char*) dir.data())) {
            auto path = p.path();
            std::string ext = path.extension().string();
            if (extSet.find(ext) == extSet.end()) {
                continue;
            }
            auto str = std::filesystem::canonical(path).string();
            fileList.push_back(str);
        }
    }
}
//---------------------------------------------------------------------------------------
void GetFileAbsPathList(TSetupConfig* setupConfig, TStringList& fileList)
{
    fileList.clear();
    auto pConfig = SingletonManager()->Get<TConfigContainer>()->Config();
    if (pConfig->targetForParsing.recursive) {
        CollectAbsPaths<fs::recursive_directory_iterator>(fileList);
    } else {
        CollectAbsPaths<fs::directory_iterator>(fileList);
    }
}
//---------------------------------------------------------------------------------------
bool GetTypeList(TSetupConfig* setupConfig, TStringList& fileList, TTypeInfoPtrList& typeList)
{
    typeList.clear();

    auto config = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();

    nsCppParser::TParser parser;
    TLoadFromFile lff;
    TContainer data;

    parser.SetupTypes(config->targetForCodeGeneration.typeCustomizerMap);

    for (auto& fileAbsPath : fileList) {
        fs::path filePath(fileAbsPath);
        auto filename = filePath.filename().string();

        lff.ReOpen((char*) fileAbsPath.c_str());
        lff.ReadSmall(data);

        std::string content;
        content.append(data.GetPtr(), data.GetSize());

        parser.Parse(content, filename);

        auto lastError = parser.GetLastError();
        if (!lastError.empty()) {
            fmt::print("Parser error {}\n", lastError);
            return false;
        }

        auto parseResult = parser.GetResult();
        for (auto& type : parseResult->mTypeList) {
            g_AllTypeList.push_back(type);

            typeList.push_back(type.get());
        }
    }
    return true;
}
//---------------------------------------------------------------------------------------
void FilterTypeList(TSetupConfig* setupConfig, TTypeInfoPtrList& typeList, TTypeInfoPtrSet& filteredTypeList)
{
    filteredTypeList.clear();
    auto config = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();

    auto inheritance = config->filter.inheritance;
    auto attribute = config->filter.attribute;

    for (auto& type : typeList) {

        bool passedByAttribute = false;
        if (!attribute.empty()) {
            auto fit = type->mPragmaTextSet.find(attribute);
            if (fit != type->mPragmaTextSet.end()) {
                passedByAttribute = true;
            }
        }

        bool passedByInheritance = false;
        if (!attribute.empty()) {
            for (auto& parent : type->mInheritanceVec) {
                if (inheritance == parent.mLongTypeName) {
                    passedByInheritance = true;
                    break;
                }
                if (inheritance == parent.mOriginalName) {
                    passedByInheritance = true;
                    break;
                }
            }
        }

        if (passedByAttribute || passedByInheritance) {
            filteredTypeList.insert(type);
        }
    }
}
//---------------------------------------------------------------------------------------
void FindDFT()
{
    auto typeManager = SingletonManager()->Get<TTypeManager>();
    auto config = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();

    TTypeInfoPtrSet customizedSet;
    TTypeInfoPtrSet depSet;
    TTypeInfoPtrSet filteredSet;

    TTypeNameDataBase::TTypeInfo typeInfo;
    TTypeNameDataBase::TReferenceInfo referenceInfo;

    std::list<std::string> dependencies;

    for (auto& type : g_FilteredTypeList) {
        for (auto& genInfo : g_Cga.mGenerators) {

            if (!genInfo.generator->IsWork()) {
                continue;
            }

            auto externalSources = genInfo.generator->GetSerializer()->externalSources.get();
            if (externalSources == nullptr) {
                continue;
            }
            
            for (auto& inFile : externalSources->inFileList) {

            }

            typeInfo.nameSpace = type->GetNameSpace();
            typeInfo.typeName = type->mName;
            genInfo.generator->GetTypeNameDB()->AddForGenerate(typeInfo);

            referenceInfo.typeInfo = typeInfo;
            referenceInfo.refType = TTypeNameDataBase::ReferenceType::GENERATED;
            referenceInfo.reflectionInfo.reset();

            genInfo.generator->GetTypeNameDB()->AddReference(referenceInfo);

            genInfo.generator->GetDependencies(type, dependencies);
            for (auto& dep : dependencies) {
                auto refType = typeManager->Get(dep);
                if (refType == nullptr) {
                    continue;
                }

                referenceInfo.typeInfo = typeInfo;
                referenceInfo.refType = TTypeNameDataBase::ReferenceType::GENERATED;
                referenceInfo.reflectionInfo.reset();

            }
        }
    }
}
//---------------------------------------------------------------------------------------
enum ReturnedValue : int
{
    OK = 0,
    NOT_FOUND_CONFIG,
    INNER_ERROR,
    PARSER_ERROR,
};
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
    }

    try {
        ShowTitle();

        TSetupConfig setupConfig;
        if (setupConfig.Work() == false) {
            return ReturnedValue::NOT_FOUND_CONFIG;
        }

        // 1. Take all filtered files => get FileList.
        GetFileAbsPathList(&setupConfig, g_FileList);

        // 2a. Parse FileList => get TypeList.
        auto parserResult = GetTypeList(&setupConfig, g_FileList, g_TypeList);
        if (!parserResult) {
            return ReturnedValue::PARSER_ERROR;
        }
        // 2b. Add to TypeManager
        auto typeManager = SingletonManager()->Get<TTypeManager>();
        for (auto& type : g_TypeList) {
            typeManager->Add(type);
        }

        // 3. Solve Filtered.
        FilterTypeList(&setupConfig, g_TypeList, g_FilteredTypeList);

        // Для каждого генератора
        // 4. Solve Dependencies. D = ...
        // 5. DFT = (D U F) П T;
        FindDFT();

        // 6. DFT U Customized = Reference.
        // 7. DFT \ Customized = Generate.


        // 8. Generate by each of Generator implementations (by Generate).
        IGenerator::TPairList dump;
        for (auto& genInfo : g_Cga.mGenerators) {
            genInfo.generator->Init(dump);
            genInfo.generator->Work();
        }

        for (auto& genInfo : g_Cga.mGenerators) {
            auto addForGenerate = genInfo.generator->GetTypeNameDB()->GetForGenerate();
            for (auto& forGenerate : *addForGenerate) {
                auto type = typeManager->Get(forGenerate.GetFullType());
                if (type == nullptr) {
                    continue;
                }
                g_Cga.GetIncludeList()->AddInclude(type->mFileName);
            }
        }

        g_Cga.GetIncludeList()->Init(dump);
        g_Cga.GetIncludeList()->Work();

        // get string and save
        // dump
        for (auto& filenameContent : dump) {
            //filenameContent.first
        }


        // 9. Save generated (Out) list in files for each of generators (by Generate).
        for (auto& genInfo : g_Cga.mGenerators) {
            auto typeNameDB = genInfo.generator->GetTypeNameDB();
            auto forGenerate = typeNameDB->GetForGenerate();
            for (auto& type : *forGenerate) {
                //type.typeName;
            }
        }

    } catch (std::exception& ex) {
        printf("exception: %s\n", ex.what());
        return ReturnedValue::INNER_ERROR;
    }
    return ReturnedValue::OK;
}