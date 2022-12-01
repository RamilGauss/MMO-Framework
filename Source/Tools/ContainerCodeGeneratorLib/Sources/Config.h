#pragma once

#include <list>
#include <string>

#include "TypeDef.h"

namespace nsContainerCodeGenerator
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TGeneratedClass
    {
        std::string fileName;
        std::string typeName;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentConfig
    {
        std::string inheritanceFilter;

        TGeneratedClass typeInfo;
        TGeneratedClass json;
        TGeneratedClass binary;
        TGeneratedClass imGui;
        TGeneratedClass entMng;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport THandlerConfig
    {
        std::string baseHandlerTypeName;

        TGeneratedClass typeInfo;
        TGeneratedClass typeFactory;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TEcsSystemConfig
    {
        std::string ecsDirectory;

        TGeneratedClass typeInfo;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSystemConfig
    {
        std::list<std::string> inheritances;

        TGeneratedClass typeInfo;
        TGeneratedClass typeFactory;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCommonConfig
    {
        std::string exportDeclaration;
        std::string targetDirectory;
        std::string nameSpace;
        std::string parseDirectory;

        TComponentConfig componentConfig;
        THandlerConfig handlerConfig;
        TSystemConfig systemConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentAggregator : TGeneratedClass
    {
        TGeneratedClass typeInfoImpl;
        TGeneratedClass jsonImpl;
        TGeneratedClass binaryImpl;
        TGeneratedClass imGuiImpl;
        TGeneratedClass entMngImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport THandlerAggregator : TGeneratedClass
    {
        TGeneratedClass typeInfoImpl;
        TGeneratedClass typeFactoryImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSystemAggregator : TGeneratedClass
    {
        TGeneratedClass typeInfoImpl;
        TGeneratedClass typeFactoryImpl;
        TGeneratedClass dynamicCasterImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TAggregator : TGeneratedClass
    {
        TComponentAggregator componentImpl;
        THandlerAggregator handlerImpl;
        TSystemAggregator systemImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCoreConfig : TCommonConfig
    {
        bool isNeedGenerate;
        TEcsSystemConfig ecsSystemConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig : TCommonConfig
    {
        TAggregator aggregator;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TConfig
    {
        std::string reflectionCodeGeneratorFileName;

        TCoreConfig coreConfig;
        TProjectConfig projectConfig;
    };
}