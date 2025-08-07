/*
Project Handler
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "Parser/Sources/TypeInfo.h"
#include "HandlerIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport THandlerTypeInfo
    {
        static std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> mTypeInoVector;
    
    public:
        static void Init();
    
        static const nsCppParser::TTypeInfo* Get(int rtti);
    };
}
