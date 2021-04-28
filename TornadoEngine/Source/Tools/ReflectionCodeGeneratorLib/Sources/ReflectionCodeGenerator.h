/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <filesystem>

#include "Config.h"
#include "SetupConfig.h"
#include "ProgramInfo.h"

#include "OutDumper.h"
#include "Dumper.h"

#include "ITargetCodeGenerator.h"
#include "IIncludeListGenerator.h"

#include "TypeDef.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TReflectionCodeGenerator
    {
    public:
        enum class Result
        {
            OK,
            NOT_FOUND_CONFIG,
            INNER_ERROR,
            PARSER_ERROR,
        };

        TReflectionCodeGenerator();

        void AddGenerator(ITargetCodeGenerator* generator);
        void SetIncludeListGenerator(IIncludeListGenerator* includeList);

        void SetDumper(IDumper* dumper);
        void SetOutDumper(IOutDumper* outDumper);

        void Init(int argc, char** argv);
        Result Work();

    private:
        IDumper* mDumper = nullptr;
        IOutDumper* mOutDumper = nullptr;

        using TStringList = std::list<std::string>;
        using TStrSet = std::set<std::string>;
        using TTypeInfoPtrList = std::list<nsCppParser::TTypeInfo*>;
        using TTypeInfoPtrSet = std::set<nsCppParser::TTypeInfo*>;

        std::list<std::shared_ptr<nsCppParser::TTypeInfo>> mAllTypeList;

        TDumper mDumperImpl;
        TOutDumper mOutDumperImpl;

        TStringList mFileList;
        TTypeInfoPtrList mTypeList;
        TTypeInfoPtrSet mFilteredTypeList;

        IGenerator::TPairList mDump;

        TSetupConfig mSetupConfig;

        TTypeManager* mTypeManager = nullptr;
        TConfig* mConfig = nullptr;

        std::list<ITargetCodeGenerator*> mAddedGenerators;

        struct TGeneratorInfo
        {
            ITargetCodeGenerator* generator;

            std::vector<TExternalSource> extSrcVector;
            std::map<std::string, TExternalSource*> typeNameExtSrcMap;

            std::set<std::string> dependenciesTypeNameSet;
            std::set<nsCppParser::TTypeInfo*> dependenciesTypeSet;// Filtered by availability in type manager

            std::set<nsCppParser::TTypeInfo*> depAndFilterSet;
        };

        std::list<TGeneratorInfo> mGenerators;

        IIncludeListGenerator* mIncludeList = nullptr;

        void ShowTitle();

        template <typename DirectoryIterator>
        void CollectAbsPaths(TStringList& fileList);
        void GetFileAbsPathList(TSetupConfig* mSetupConfig, TStringList& fileList);
        bool GetTypeList(TSetupConfig* mSetupConfig, TStringList& fileList, TTypeInfoPtrList& typeList);
        void FilterTypeList(TSetupConfig* mSetupConfig, TTypeInfoPtrList& typeList, TTypeInfoPtrSet& filteredTypeList);
        void CollectDumpFromGenerators();
        void FillIncludeList();
        void CollectDumpFromIncludeList();
        void SaveDumpToFiles();
        void SaveOut();
        void AddToGeneratorList();

        void LoadExternalSources();
        void SolveTypeNameExternalSources();
        void SolveDependencies();
        void FilterDependenciesByTypeManager();
        void MergeDependeciesWithFiltered();

        void FillTypeNameDataBase();

        void AddDependencies(ITargetCodeGenerator* generator, 
            nsCppParser::TTypeInfo* type, std::set<std::string> dependenciesTypeNameSetOut);
    };
    //---------------------------------------------------------------------------------------
    template <typename DirectoryIterator>
    void TReflectionCodeGenerator::CollectAbsPaths(TStringList& fileList)
    {
        TStrSet extSet(mConfig->filter.extensions.begin(), mConfig->filter.extensions.end());

        for (auto& dir : mConfig->targetForParsing.directories) {
            DirectoryIterator dirIt((char*) dir.data());

            for (auto& p : dirIt) {
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
}