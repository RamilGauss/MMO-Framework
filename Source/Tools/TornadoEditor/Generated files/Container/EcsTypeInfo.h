/*
Project Ecs System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_29 17:47:00.792
	
#pragma once

#include <string>
#include <map>
#include <list>
#include <vector>

#include "TypeDef.h"
#include "EcsSystemIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport TEcsTypeInfo
    {
        static std::list<std::string> mTypeNameList;
        static std::list<int> mRttiList;
    
        static std::vector<std::string> mNameVector;
        static std::map<std::string, int> mNameRttiMap;
    
        static void Init();
    
    public:
        static const std::list<std::string>* GetTypeNameList();
        static const std::list<int>* GetRttiList();
    
        static const std::string* ConvertRttiToName(int rtti);
        static bool ConvertNameToRtti(const std::string& typeName, int& rtti);
    };
}
