/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_01_01 18:53:40.112
	
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport TComponentRtti
    {
        static std::list<std::string> mTypeNameList;
        static std::list<int> mRttiList;
    
        static std::vector<std::string> mNameVector;
        static std::unordered_map<std::string, int> mNameRttiMap;
    
    public:
        static void Init();
    
        static const std::list<std::string>* GetTypeNameList();
        static const std::list<int>* GetRttiList();
    
        static const std::string* ConvertRttiToName(int rtti);
        static bool ConvertNameToRtti(const std::string& typeName, int& rtti);
    };
}
