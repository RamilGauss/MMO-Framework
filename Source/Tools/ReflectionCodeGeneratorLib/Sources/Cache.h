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

namespace nsReflectionCodeGenerator
{
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
        std::list<std::string> inAbsFilePathList;
        std::string outAbsFilePath;
    };

    struct DllExport TSerializerExt : TClassDescExt
    {
        TExternalSourcesExt externalSources;
    };

    struct DllExport TCache
    {
        std::list<std::string> targetForParsingAbsPaths;
        
        std::string targetForCodeGenerationAbsPath;
        std::string includeAbsFilePath;
        std::string includeFileForInclude;

        std::map<std::string, TSerializerExt> implementations;

        std::list<TSourceRoot> sourceRoots;
    };
}
