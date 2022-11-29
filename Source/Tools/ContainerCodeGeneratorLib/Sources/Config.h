#pragma once

#include <list>
#include <string>

#include "TypeDef.h"

namespace nsContainerCodeGenerator
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TGeneratedClass
    {
        std::string directoryPath;

        std::string exportDeclaration;
        std::string fileName;
        std::string typeName;
        std::string nameSpace;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TTargetForParsing
    {
        std::list<std::string> directories;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TInheritances
    {
        std::list<std::string> inheritances;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCategoryConfig : TInheritances, TGeneratedClass, TTargetForParsing
    {
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPartConfig
    {
        TCategoryConfig componentConfig;
        TCategoryConfig handlerConfig;
        TCategoryConfig systemConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TConfig
    {
        bool isNeedCoreGenerate;
        TPartConfig coreConfig;

        TPartConfig projectConfig;

        TGeneratedClass targetClass;
    };
}