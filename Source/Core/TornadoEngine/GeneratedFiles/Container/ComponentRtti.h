/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2025_08_05 13:10:21.477
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
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
