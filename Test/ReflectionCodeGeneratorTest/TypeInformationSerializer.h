/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_29 15:33:35.864
	
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "TypeDef.h"
#include "IncludeList.h"

namespace nsTypeInformation
{
    class DllExport TTypeInformationSerializer
    {
        static std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> mTypeNameVector;
    
    public:
        static void Init();
    
        static const std::list<std::string>* Get();
    };
}
