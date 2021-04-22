/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <memory>

#include "Parser/Sources/Types.h"

namespace nsReflectionCodeGenerator
{
#pragma REFLECTION_ATTRIBUTE
    struct TTargetForParsing
    {
        std::vector<std::string> directories;
        bool recursive;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TFilter
    {
        std::vector<std::string> extensions;
        
        // Filter by pragma or parent
        std::string attribute;// #pragma ATTRIBUTE
        // or
        std::string inheritance;// "ns::TypeA"
    };

#pragma REFLECTION_ATTRIBUTE 
    struct TClassDesc
    {
        std::string exportDeclaration;// DllExport
        std::string nameSpaceName;
        std::string className;
        std::string fileName;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TUnpackHandler : TClassDesc
    {
        std::string method;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TExternalSource
    {
        std::string fileName;
        std::string nameSpaceName;
        std::string typeName;

        std::set<std::string> customizedTypes;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TExternalSources
    {
        std::list<std::string> inFileList;
        std::string outFile;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TSerializer : TClassDesc
    {
        std::shared_ptr<TExternalSources> externalSources;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TBinaryMarshallerGeneratorConfig : TSerializer
    {
        std::shared_ptr<TUnpackHandler> unpackHandler;
        unsigned short beginID;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TJsonSerializerGeneratorConfig : TSerializer
    {

    };

#pragma REFLECTION_ATTRIBUTE
    struct TMyGuiGeneratorConfig : TSerializer
    {

    };

#pragma REFLECTION_ATTRIBUTE
    struct TReflectionGeneratorConfig : TSerializer
    {

    };

#pragma REFLECTION_ATTRIBUTE
    struct TEntityManagerGeneratorConfig : TSerializer
    {

    };

#pragma REFLECTION_ATTRIBUTE
    struct TTypeInformationGeneratorConfig : TSerializer
    {

    };

#pragma REFLECTION_ATTRIBUTE
    struct TImplementation
    {
        std::shared_ptr<TJsonSerializerGeneratorConfig> jsonSerializer;
        std::shared_ptr<TBinaryMarshallerGeneratorConfig> binaryMarshaller;
        std::shared_ptr<TMyGuiGeneratorConfig> mygui;

        std::shared_ptr<TReflectionGeneratorConfig> reflection;
        std::shared_ptr<TEntityManagerGeneratorConfig> entMngExt;
        std::shared_ptr<TTypeInformationGeneratorConfig> typeInformation;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TTargetForCodeGeneration
    {
        std::string directory;
        std::string includeListFileName;
        std::string header;
        std::map<std::string, nsCppParser::TypeCategory> typeCustomizerMap;
        TImplementation implementation;
    };

#pragma REFLECTION_ATTRIBUTE
    struct TConfig
    {
        TTargetForParsing targetForParsing;
        TFilter filter;
        TTargetForCodeGeneration targetForCodeGeneration;
    };
}
