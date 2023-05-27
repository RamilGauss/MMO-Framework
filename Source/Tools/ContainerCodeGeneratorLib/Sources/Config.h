/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

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
    struct DllExport TParentClass
    {
        std::string fileName;
        std::string typeName;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TIncludeListFileName
    {
        std::string includeListFileName;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentConfig : TIncludeListFileName
    {
        std::string inheritanceFilter;

        TGeneratedClass typeInfo;
        TGeneratedClass json;
        TGeneratedClass binary;
        TGeneratedClass imGui;
        TGeneratedClass entMng;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TImGuiWidgetsConfig : TIncludeListFileName
    {
        std::string imGuiWidgetsDirectory;

        TGeneratedClass typeInfo;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport THandlerConfig : TIncludeListFileName
    {
        TGeneratedClass typeInfo;
        TGeneratedClass typeFactory;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TEcsSystemConfig : TIncludeListFileName
    {
        std::string ecsDirectory;

        std::list<std::string> inheritances;

        TGeneratedClass typeInfo;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSystemConfig : TIncludeListFileName
    {
        std::list<std::string> inheritances;

        TGeneratedClass typeFactory;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TAggregatorClass
    {
        TGeneratedClass impl;
        TParentClass parent;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentAggregator : TAggregatorClass
    {
        TAggregatorClass typeInfoImpl;
        TAggregatorClass jsonImpl;
        TAggregatorClass binaryImpl;
        TAggregatorClass imGuiImpl;
        TAggregatorClass entMngImpl;
        TAggregatorClass dynamicCasterImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TImGuiWidgetsAggregator : TAggregatorClass
    {
        TAggregatorClass typeInfoImpl;
        TAggregatorClass dynamicCasterImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport THandlerAggregator : TAggregatorClass
    {
        TAggregatorClass typeInfoImpl;
        TAggregatorClass typeFactoryImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSystemAggregator : TAggregatorClass
    {
        TAggregatorClass typeInfoImpl;
        TAggregatorClass typeFactoryImpl;
        TAggregatorClass dynamicCasterImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCoreConfig
    {
        std::string exportDeclaration;
        std::string targetDirectory;
        std::string nameSpace;
        std::string parseDirectory;

        TComponentConfig componentConfig;
        TImGuiWidgetsConfig imGuiWidgetsConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig
    {
        std::string relPathToSources;

        std::string exportDeclaration;
        std::string targetDirectory;
        std::string nameSpace;
        std::string parseDirectory;

        TComponentConfig componentConfig;
        THandlerConfig handlerConfig;
        TSystemConfig systemConfig;
        TEcsSystemConfig ecsSystemConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TAggregator : TAggregatorClass
    {
        std::string targetDirectory;

        std::string exportDeclaration;
        std::string cExportDeclaration;

        std::string dllHeaderFileName;
        std::string dllCppFileName;
        std::string getFuncName;
        std::string freeFuncName;

        TComponentAggregator componentImpl;
        THandlerAggregator handlerImpl;
        TSystemAggregator systemImpl;
        TImGuiWidgetsAggregator imGuiWidgetsImpl;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TCoreContainerConfig
    {
        std::string reflectionCodeGeneratorFileName;

        std::string entityManagerHeaderPath;

        TCoreConfig coreConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectContainerConfig
    {
        std::string baseHandlerTypeName;

        std::string absCorePath;
        std::string relCoreConfigPath;

        TProjectConfig projectConfig;
        TAggregator aggregator;
    };
}