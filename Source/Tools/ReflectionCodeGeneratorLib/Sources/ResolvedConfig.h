/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <memory>
#include <string>
#include <set>
#include <unordered_set>

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/Types.h"

namespace nsReflectionCodeGenerator
{
    struct DllExport TFilterExt
    {
        std::vector<std::string> extensions;
        
        // Filter by pragma or parent
        std::string attribute;// #pragma ATTRIBUTE
        // or
        std::list<std::list<std::string>> inheritances;// ["ns::TypeA" and "ns::TypeC"] or ["ns::TypeB"]

        std::string memberIgnore;// #pragma IGNORE_ATTRIBUTE
    };

    struct DllExport TSourceRoot
    {
        std::string original;
        std::string absOriginalPath;

        std::unordered_set<std::string> absPathAllFilesInDir;
    };

    struct DllExport TClassDescExt
    {
        std::string exportDeclaration;
        std::string nameSpaceName;
        std::string className;
        std::string fileName;

        std::string absFilePath;
        std::string filePathForInclude;
    };

    struct DllExport TExternalSourceExt
    {
        std::string fileName;
        std::string nameSpaceName;
        std::string typeName;

        std::string absFilePath;
        std::string filePathForInclude;

        std::set<std::string> customizedTypes;
    };

    struct DllExport TExternalSourcesExt
    {
        std::list<TExternalSourceExt> loadedExternalSources;

        std::list<std::string> inAbsFilePathList;
        std::string outAbsFilePath;
    };

    struct DllExport TSerializerExt : TClassDescExt
    {
        std::shared_ptr<TExternalSourcesExt> externalSources;
        std::map<std::string, std::string> keyValueMap;
    };

    struct DllExport TResolvedConfig
    {
        bool addTimeStamp = false;
        std::string header;
        TFilterExt filter;

        std::list<std::string> targetForParsingAbsPaths;
        bool targetParsingRecursive;

        std::map<std::string, nsCppParser::TypeCategory> typeCustomizerMap;
        bool appendTypeCustomizerMap;
        
        std::string targetForCodeGenerationAbsPath;
        std::string includeAbsFilePath;
        std::string includeFileForInclude;

        std::map<std::string, TSerializerExt> implementations;

        std::list<TSourceRoot> sourceRoots;

        std::list<std::string> absSourceRootPaths;
    };
}
