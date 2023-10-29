/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:16:50.217
	
#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <vector>

#include "TypeDef.h"
#include "HandlerIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport THandlerTypeInfo
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
