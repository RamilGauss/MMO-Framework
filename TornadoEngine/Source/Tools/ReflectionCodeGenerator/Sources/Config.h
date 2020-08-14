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
#include <memory>

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
    std::string attribute;
    std::vector<std::string> extensions;
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
  struct TBinaryMarshallerGeneratorConfig : TClassDesc
  {
    TUnpackHandler unpackHandler;
    unsigned short beginID;
  };

#pragma REFLECTION_ATTRIBUTE
  struct TJsonSerializerGeneratorConfig : TClassDesc
  {

  };

#pragma REFLECTION_ATTRIBUTE
  struct TSqlGeneratorConfig : TClassDesc
  {

  };

#pragma REFLECTION_ATTRIBUTE
  struct TImplementation
  {
    std::shared_ptr<TJsonSerializerGeneratorConfig> jsonSerializer;
    std::shared_ptr<TBinaryMarshallerGeneratorConfig> binaryMarshaller;
    std::shared_ptr<TSqlGeneratorConfig> sql;
  };

#pragma REFLECTION_ATTRIBUTE
  struct TTargetForCodeGeneration
  {
    std::string directory;
    std::string includeListFileName;
    std::string header;
    TImplementation implementation;
    
    std::map<std::string, std::string> typeCustomizerMap;
  };

#pragma REFLECTION_ATTRIBUTE
  struct TConfig
  {
    TTargetForParsing targetForParsing;
    TFilter filter;
    TTargetForCodeGeneration targetForCodeGeneration;
  };

}
