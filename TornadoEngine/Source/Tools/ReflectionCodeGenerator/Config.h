/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ReflectionMacro.h"
#include <vector>
#include <list>
#include <string>
#include <map>

namespace nsReflectionCodeGenerator
{
  REFLECTION_ATTRIBUTE struct TTargetForParsing
  {
    std::vector<std::string> directories;
    bool recursive;
  };

  REFLECTION_ATTRIBUTE struct TFilter
  {
    std::string attribute;
    std::vector<std::string> extensions;
  };

  REFLECTION_ATTRIBUTE struct TClassDesc
  {
    std::string nameSpaceName;
    std::string className;
    std::string fileName;
  };

  REFLECTION_ATTRIBUTE struct TDeserializationHandler : TClassDesc
  {
    std::string method;
  };

  REFLECTION_ATTRIBUTE struct TBinaryMarshallerGeneratorConfig : TClassDesc
  {
    TDeserializationHandler deserializationHandler;
  };

  REFLECTION_ATTRIBUTE struct TJsonSerializerGeneratorConfig : TClassDesc
  {

  };

  REFLECTION_ATTRIBUTE struct TImplementation
  {
    std::shared_ptr<TJsonSerializerGeneratorConfig> jsonSerializer;
    std::shared_ptr<TBinaryMarshallerGeneratorConfig> binaryMarshaller;
  };

  REFLECTION_ATTRIBUTE struct TTargetForCodeGeneration
  {
    std::string directory;
    std::string includeListFileName;
    TImplementation implementation;
  };

  REFLECTION_ATTRIBUTE struct TConfig
  {
    TTargetForParsing targetForParsing;
    TFilter filter;
    TTargetForCodeGeneration targetForCodeGeneration;
  };
}
