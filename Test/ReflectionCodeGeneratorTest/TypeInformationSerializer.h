/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_30 17:47:51.208
	
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "Parser/Sources/TypeInfo.h"
#include "IncludeList.h"

namespace nsTypeInformation
{
    class DllExport TTypeInformationSerializer
    {
        static std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> mTypeInoVector;
    
    public:
        static void Init();
    
        static const nsCppParser::TTypeInfo* Get(int rtti);
    };
}
