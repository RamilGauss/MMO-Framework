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

        TGeneratedClass typeInfo;
        TGeneratedClass dynamicCaster;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSystemConfig : TIncludeListFileName
    {
        std::list<std::string> inheritances;

        TGeneratedClass typeInfo;
        TGeneratedClass typeFactory;
        TGeneratedClass dynamicCaster;
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
        bool isNeedGenerate;

        std::string exportDeclaration;
        std::string targetDirectory;
        std::string nameSpace;
        std::string parseDirectory;

        TComponentConfig componentConfig;
        TEcsSystemConfig ecsSystemConfig;
        TSystemConfig systemConfig;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig
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
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TConfig
    {
        std::string reflectionCodeGeneratorFileName;

        std::string entityManagerHeaderPath;

        std::string baseHandlerTypeName;

        TCoreConfig coreConfig;
        TProjectConfig projectConfig;
        TAggregator aggregator;
    };
}