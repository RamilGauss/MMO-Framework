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

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/Parser.h"

#include "ReflectionCodeGeneratorLib/Sources/ResolvedConfig.h"
#include "ReflectionCodeGeneratorLib/Sources/Config.h"
#include "ReflectionCodeGeneratorLib/Sources/SetupConfig.h"
#include "ReflectionCodeGeneratorLib/Sources/ProgramInfo.h"
#include "ReflectionCodeGeneratorLib/Sources/TypeManager.h"

#include "ReflectionCodeGeneratorLib/Sources/OutDumper.h"
#include "ReflectionCodeGeneratorLib/Sources/Dumper.h"

#include "ReflectionCodeGeneratorLib/Sources/ITargetCodeGenerator.h"
#include "ReflectionCodeGeneratorLib/Sources/IIncludeListGenerator.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TReflectionCodeGenerator
    {
    public:
        enum class Result
        {
            OK = 0,
            NOT_FOUND_CONFIG = 4,
            INNER_ERROR = 5,
            PARSER_ERROR = 6,
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

        TTypeManager mTypeManager;
        TResolvedConfig mResolvedConfig;

        std::list<ITargetCodeGenerator*> mAddedGenerators;

        struct TGeneratorInfo
        {
            ITargetCodeGenerator* generator;

            std::vector<TExternalSourceExt> extSrcVector;
            std::map<std::string, TExternalSourceExt*> typeNameExtSrcMap;

            std::set<std::string> dependenciesTypeNameSet;
            std::set<nsCppParser::TTypeInfo*> depAndFilterSet;

            std::set<std::string> unionedDependenciesTypeNameSet;
            std::set<nsCppParser::TTypeInfo*> unionedDependenciesTypeSet;// Filtered by availability in type manager
        };

        std::list<TGeneratorInfo> mGenerators;

        IIncludeListGenerator* mIncludeList = nullptr;

        void ShowTitle();

        void GetFileAbsPathList(TStringList& fileList);
        bool GetTypeList(TStringList& fileList, TTypeInfoPtrList& typeList);
        void FilterTypeList(TTypeInfoPtrList& typeList, TTypeInfoPtrSet& filteredTypeList);
        void CollectDumpFromGenerators();
        void FillIncludeList();
        void CollectDumpFromIncludeList();
        void SaveDumpToFiles();
        void SaveOut();
        void AddToGeneratorList();

        void LoadExternalSources();
        void SolveTypeNameExternalSources();
        void SolveDependencies();
        void UnionDependencies();
        void FilterDependenciesByTypeManager();
        void MergeDependeciesWithFiltered();

        void FillTypeNameDataBase();

        void AddDependencies(ITargetCodeGenerator* generator, 
            nsCppParser::TTypeInfo* type, std::set<std::string>& dependenciesTypeNameSetOut);

        void ConvertStringToTypeCategory(std::map<std::string, std::string>& strTypeCustomizerMap,
            std::map<std::string, nsCppParser::TypeCategory>& typeCustomizerMap);

        void ThinningMembersInTypes();
        void CorrectMemberInfoInAllTypes();

        nsCppParser::TTypeInfo* Find(nsCppParser::TMemberExtendedTypeInfo* pMemberExtendedInfo,
            const std::list<std::string>& withinClassTypeNameList);
    };
 }
