/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReflectionCodeGenerator.h"

#include <fmt/core.h>
#include <fmt/color.h>

#include "Base/Common/SingletonManager.h"
#include "Base/Common/PathOperations.h"
#include "Base/Common/LoadFromFile.h"
#include "Base/Common/SaveToFile.h"

#include "JsonSerializer.h"

namespace fs = std::filesystem;

using namespace nsReflectionCodeGenerator;
using namespace nsCppParser;
using namespace nsBase;

TReflectionCodeGenerator::TReflectionCodeGenerator()
{
    mTypeManager = SingletonManager()->Get<TTypeManager>();
    mConfig = SingletonManager()->Get<TConfigContainer>()->Config();

    mDumper = &mDumperImpl;
    mOutDumper = &mOutDumperImpl;
}
//--------------------------------------------------------------------------------------------------------
void TReflectionCodeGenerator::Init(int argc, char** argv)
{
    mSetupConfig.Init(argc, argv);
}
//--------------------------------------------------------------------------------------------------------
TReflectionCodeGenerator::Result TReflectionCodeGenerator::Work()
{
    try {
        ShowTitle();

        auto setupConfigResult = mSetupConfig.Work();
        if (setupConfigResult == false) {
            return Result::NOT_FOUND_CONFIG;
        }

        // Take all filtered files => get FileList.
        GetFileAbsPathList(mFileList);

        // Add to generator list
        AddToGeneratorList();

        // Parse FileList => get TypeList.
        auto parserResult = GetTypeList(mFileList, mTypeList);
        if (!parserResult) {
            return Result::PARSER_ERROR;
        }

        // Add to TypeManager
        for (auto& type : mTypeList) {
            mTypeManager->Add(type);
        }

        // Solve Filtered.
        FilterTypeList(mTypeList, mFilteredTypeList);

        CorrectMemberInfoInAllTypes();

        // For each generator
        LoadExternalSources();

        SolveTypeNameExternalSources();

        // Solve Dependencies. D = ...
        SolveDependencies();
        UnionDependencies();
        FilterDependenciesByTypeManager();

        // DFT = (D U F) П T;
        MergeDependeciesWithFiltered();

        // DFT U Customized = Reference.
        // DFT \ Customized = Generate.
        FillTypeNameDataBase();

        // Generate by each of Generator implementations (by Generate)
        CollectDumpFromGenerators();

        // Add all header file name in includes
        FillIncludeList();

        // Collect from include list generator
        CollectDumpFromIncludeList();

        SaveDumpToFiles();

        // Save generated (Out) list in files for each of generators (by Generate)
        SaveOut();

    } catch (std::exception& ex) {
        fmt::print(fg(fmt::color::red), "exception: {}\n", ex.what());
        return Result::INNER_ERROR;
    }
    return Result::OK;
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::AddGenerator(ITargetCodeGenerator* generator)
{
    mAddedGenerators.push_back(generator);
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SetIncludeListGenerator(IIncludeListGenerator* includeList)
{
    mIncludeList = includeList;
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SetDumper(IDumper* dumper)
{
    mDumper = dumper;
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SetOutDumper(IOutDumper* outDumper)
{
    mOutDumper = outDumper;
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::ShowTitle()
{
    fmt::print(fg(fmt::color::green), "{}\n", TProgramInfo::Get());
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::GetFileAbsPathList(TStringList& fileList)
{
    fileList.clear();

    TStrSet extSet(mConfig->filter.extensions.begin(), mConfig->filter.extensions.end());

    for (auto& dir : mConfig->targetForParsing.directories) {
        nsBase::TPathOperations::AddAbsPathsByDirectory(dir, extSet, fileList, mConfig->targetForParsing.recursive);
    }
}
//---------------------------------------------------------------------------------------
bool TReflectionCodeGenerator::GetTypeList(TStringList& fileList, TTypeInfoPtrList& typeList)
{
    typeList.clear();

    TParser parser;
    TLoadFromFile lff;
    TContainer data;

    parser.SetupTypes(mConfig->targetForCodeGeneration.typeCustomizerMap,
        mConfig->targetForCodeGeneration.appendTypeCustomizerMap);

    for (auto& fileAbsPath : fileList) {
        fs::path filePath(fileAbsPath);
        auto filename = filePath.filename().string();

        auto isOpen = lff.ReOpen((char*)fileAbsPath.c_str());
        if (isOpen == false) {
            continue;
        }
        lff.ReadSmall(data);

        std::string content;
        content.append(data.GetPtr(), data.GetSize());

        parser.Parse(content, filename, fileAbsPath);

        auto lastError = parser.GetLastError();
        if (!lastError.empty()) {
            fmt::print("Parser error {}\n", lastError);
            return false;
        }

        auto parseResult = parser.GetResult();
        for (auto& type : parseResult->mTypeList) {
            mAllTypeList.push_back(type);

            typeList.push_back(type.get());
        }
    }
    return true;
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::FilterTypeList(TTypeInfoPtrList& typeList, TTypeInfoPtrSet& filteredTypeList)
{
    filteredTypeList.clear();

    const auto& filterInheritances = mConfig->filter.inheritances;
    auto attribute = mConfig->filter.attribute;

    for (auto& type : typeList) {

        bool passedByAttribute = false;
        if (!attribute.empty()) {
            auto fit = type->mPragmaTextSet.find(attribute);
            if (fit != type->mPragmaTextSet.end()) {
                passedByAttribute = true;
            }
        }

        std::set<std::string> typeInheritances;
        for (auto& typeInheritance : type->mInheritanceVec) {
            for (auto& parent : type->mInheritanceVec) {
                typeInheritances.insert(parent.mLongTypeName);
                typeInheritances.insert(parent.mOriginalTypeName);
            }
        }

        bool passedByInheritance = false;
        for (auto& inheritanceList : filterInheritances) {
            passedByInheritance = true;
            for (auto& inheritance : inheritanceList) {
                if (inheritance.empty()) {
                    continue;
                }
                auto isInType = (typeInheritances.find(inheritance) != typeInheritances.end());
                if (!isInType) {
                    passedByInheritance = false;
                    break;
                }
            }
            if (passedByInheritance) {
                break;
            }
        }

        bool isAllEmpty = attribute.empty() && filterInheritances.size() == 0;

        if (isAllEmpty || passedByAttribute || passedByInheritance) {
            filteredTypeList.insert(type);
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::LoadExternalSources()
{
    TContainer data;
    TLoadFromFile lff;

    for (auto& genInfo : mGenerators) {

        auto externalSources = genInfo.generator->GetSerializer()->externalSources.get();
        if (externalSources == nullptr) {
            continue;
        }

        for (auto& inFile : externalSources->inFileList) {

            auto absPath = TPathOperations::CalculatePathBy(mSetupConfig.mAbsPathDirJson, inFile);

            auto isOpen = lff.ReOpen((char*)absPath.c_str());
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

            genInfo.extSrcVector.push_back(extSrc);
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SolveTypeNameExternalSources()
{
    for (auto& genInfo : mGenerators) {
        for (auto& extSrc : genInfo.extSrcVector) {
            for (auto& typeName : extSrc.customizedTypes) {
                genInfo.typeNameExtSrcMap.insert({ typeName, &extSrc });
            }
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::AddDependencies(ITargetCodeGenerator* generator, TTypeInfo* type, std::set<std::string>& dependenciesTypeNameSetOut)
{
    // Get deps
    std::set<std::string> dependenciesTypeNameSet;
    generator->GetDependencies(type, dependenciesTypeNameSet);

    // Filter by new
    std::set<std::string> newDependenciesTypeNameSet;
    for (auto& dep : dependenciesTypeNameSet) {
        if (dependenciesTypeNameSetOut.contains(dep) == false) {
            dependenciesTypeNameSetOut.insert(dep);
            newDependenciesTypeNameSet.insert(dep);
        }
    }

    // Continue searching of new deps
    for (auto& dep : newDependenciesTypeNameSet) {

        auto depType = mTypeManager->Get(dep);
        if (depType != nullptr) {
            AddDependencies(generator, depType, dependenciesTypeNameSetOut);
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SolveDependencies()
{
    for (auto& type : mFilteredTypeList) {
        for (auto& genInfo : mGenerators) {
            AddDependencies(genInfo.generator, type, genInfo.dependenciesTypeNameSet);
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::UnionDependencies()
{
    for (auto& genInfo : mGenerators) {
        genInfo.unionedDependenciesTypeNameSet.insert(genInfo.dependenciesTypeNameSet.begin(), genInfo.dependenciesTypeNameSet.end());
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::FilterDependenciesByTypeManager()
{
    for (auto& genInfo : mGenerators) {
        for (auto& dep : genInfo.unionedDependenciesTypeNameSet) {
            auto type = mTypeManager->Get(dep);
            if (type != nullptr) {
                genInfo.unionedDependenciesTypeSet.insert(type);
            }
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::MergeDependeciesWithFiltered()
{
    for (auto& genInfo : mGenerators) {
        genInfo.depAndFilterSet.insert(mFilteredTypeList.begin(), mFilteredTypeList.end());
        genInfo.depAndFilterSet.insert(genInfo.unionedDependenciesTypeSet.begin(), genInfo.unionedDependenciesTypeSet.end());
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::FillTypeNameDataBase()
{
    for (auto& genInfo : mGenerators) {

        auto typeNameDB = genInfo.generator->GetTypeNameDB();
        for (auto& depAndFilter : genInfo.depAndFilterSet) {

            auto inCustomized = genInfo.typeNameExtSrcMap.find(depAndFilter->GetTypeNameWithNameSpace());
            if (inCustomized == genInfo.typeNameExtSrcMap.end()) {
                // Generated 
                TTypeNameDataBase::TTypeInfo typeInfo;
                typeInfo.nameSpace = depAndFilter->GetNameSpace();
                typeInfo.typeName = depAndFilter->mName;
                typeNameDB->AddForGenerate(typeInfo);

                // Reference
                TTypeNameDataBase::TReferenceInfo referenceInfo;
                referenceInfo.typeInfo.nameSpace = depAndFilter->GetNameSpace();
                referenceInfo.typeInfo.typeName = depAndFilter->mName;

                referenceInfo.refType = TTypeNameDataBase::ReferenceType::GENERATED;

                typeNameDB->AddReference(referenceInfo);

            } else {
                // Reference
                auto extSrc = inCustomized->second;
                TTypeNameDataBase::TReferenceInfo referenceInfo;
                referenceInfo.typeInfo.nameSpace = depAndFilter->GetNameSpace();
                referenceInfo.typeInfo.typeName = depAndFilter->mName;

                referenceInfo.refType = TTypeNameDataBase::ReferenceType::CUSTOMIZED;
                referenceInfo.reflectionInfo.reset(new TTypeNameDataBase::TReflectionInfo());
                referenceInfo.reflectionInfo->fileName = extSrc->fileName;
                referenceInfo.reflectionInfo->className = extSrc->typeName;
                referenceInfo.reflectionInfo->nameSpace = extSrc->nameSpaceName;

                typeNameDB->AddReference(referenceInfo);
            }
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::CollectDumpFromGenerators()
{
    for (auto& genInfo : mGenerators) {
        genInfo.generator->Init(mDump);
        genInfo.generator->Work();
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::FillIncludeList()
{
    for (auto& genInfo : mGenerators) {

        auto& addForGenerate = genInfo.generator->GetTypeNameDB()->GetForGenerate();
        for (auto& forGenerate : addForGenerate) {
            auto type = mTypeManager->Get(forGenerate.GetFullType());
            if (type == nullptr) {
                continue;
            }
            mIncludeList->AddInclude(type->mAbsFileName);
        }
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::CollectDumpFromIncludeList()
{
    mIncludeList->Init(mDump);
    mIncludeList->Work();
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SaveDumpToFiles()
{
    for (auto& absFilenameContent : mDump) {
        mDumper->Save(absFilenameContent.first, absFilenameContent.second);
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::SaveOut()
{
    for (auto& genInfo : mGenerators) {

        auto ser = genInfo.generator->GetSerializer();
        auto externalSources = ser->externalSources;
        if (externalSources == nullptr) {
            continue;
        }

        auto absFilePath = TPathOperations::CalculatePathBy(mSetupConfig.mAbsPathDirJson, externalSources->outFile);
        if (externalSources->outFile.size() == 0) {
            continue;
        }

        TExternalSource extSrc;
        extSrc.fileName = ser->fileName;
        extSrc.nameSpaceName = ser->nameSpaceName;
        extSrc.typeName = ser->className;

        auto& forGen = genInfo.generator->GetTypeNameDB()->GetForGenerate();
        for (auto& gen : forGen) {
            extSrc.customizedTypes.insert(gen.GetFullType());
        }

        mOutDumper->Save(extSrc, absFilePath);
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::AddToGeneratorList()
{
    for (auto& generator : mAddedGenerators) {
        if (!generator->HasSerializer()) {
            continue;
        }

        TGeneratorInfo generatorInfo;
        generatorInfo.generator = generator;
        mGenerators.push_back(generatorInfo);
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::ConvertStringToTypeCategory(std::map<std::string, std::string>& strTypeCustomizerMap,
    std::map<std::string, TypeCategory>& typeCustomizerMap)
{
    static std::map<std::string, TypeCategory> nameToTypeCategoryMap;

    if (nameToTypeCategoryMap.size() == 0) {
        constexpr auto& typeCategories = magic_enum::enum_values<TypeCategory>();
        for (auto& typeCategory : typeCategories) {

            std::string name(magic_enum::enum_name<TypeCategory>(typeCategory));
            nameToTypeCategoryMap.insert({ name, typeCategory });
        }
    }

    typeCustomizerMap.clear();
    for (auto& typeCustomizer : strTypeCustomizerMap) {
        auto& type = nameToTypeCategoryMap[typeCustomizer.second];
        typeCustomizerMap.insert({ typeCustomizer.first, type });
    }
}
//---------------------------------------------------------------------------------------
void TReflectionCodeGenerator::CorrectMemberInfoInAllTypes()
{
    for (auto& type : mTypeList) {

        std::list<std::string> withinClassTypeNameList;

        withinClassTypeNameList.push_back("");
        withinClassTypeNameList.push_back(type->GetNameSpace());
        withinClassTypeNameList.push_back(type->GetTypeNameWithNameSpace());

        auto& pubMem = type->mMembers[(int)AccessLevel::PUBLIC];
        for (auto& member : pubMem) {
            TMemberExtendedTypeInfo* pMemberExtendedInfo = nullptr;
            if (member->mPragmaTextSet.find(mConfig->filter.memberIgnore) != member->mPragmaTextSet.end()) {
                continue;
            }

            switch (member->mExtendedInfo.mCategory) {
                case TypeCategory::REFLECTION:
                    pMemberExtendedInfo = &(member->mExtendedInfo);
                    break;
                case TypeCategory::SMART_POINTER:
                case TypeCategory::VECTOR:
                case TypeCategory::LIST:
                case TypeCategory::SET:
                case TypeCategory::MAP:
                {
                    TMemberExtendedTypeInfo* pExt = &(member->mExtendedInfo);
                    while (true) {
                        auto* templArr = &(pExt->mTemplateChildArr);
                        if (!templArr->empty()) {
                            pExt = &(templArr->at(templArr->size() - 1));
                        } else {
                            if (pExt->mCategory == TypeCategory::REFLECTION) {
                                pMemberExtendedInfo = pExt;
                            }
                            break;
                        }
                    }
                }
                break;
                default:;
            }

            if (pMemberExtendedInfo == nullptr) {
                continue;
            }

            auto foundType = Find(pMemberExtendedInfo, withinClassTypeNameList);
            if (foundType == nullptr) {
                continue;
            }

            pMemberExtendedInfo->mNameSpace = foundType->GetNameSpace();
            pMemberExtendedInfo->mLongType = foundType->GetTypeNameWithNameSpace();
        }
    }
}
//---------------------------------------------------------------------------------------
TTypeInfo* TReflectionCodeGenerator::Find(TMemberExtendedTypeInfo* pMemberExtendedInfo,
    const std::list<std::string>& withinClassTypeNameList)
{
    for (auto& withinClassTypeName : withinClassTypeNameList) {

        std::string fullType;
        if (!withinClassTypeName.empty()) {
            fullType = withinClassTypeName + "::" + pMemberExtendedInfo->mLongType;
        } else {
            fullType = pMemberExtendedInfo->mLongType;
        }

        auto type = mTypeManager->Get(fullType);
        if (type != nullptr) {
            return type;
        }
    }

    return nullptr;
}
//-----------------------------------------------------------------------------------------------------------
