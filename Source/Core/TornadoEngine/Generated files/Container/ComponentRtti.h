/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_05 17:20:05.361
	
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "TypeDef.h"
#include "Parser/Sources/TypeInfo.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentRtti
    {
        static std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> mTypeInoVector;
    
    public:
        static void Init();
    
        static const nsCppParser::TTypeInfo* Get(int rtti);
    };
}
