/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_29 08:27:54.093
	
#pragma once

#include <string>
#include <map>
#include <list>
#include <vector>

#include "TypeDef.h"
#include "IncludeList.h"

namespace nsTypeInformation
{
    class DllExport TTypeInformationSerializer
    {
        static std::list<std::string> mTypeNameList;
    
        static std::vector<std::string> mNameVector;
        static std::map<std::string, int> mNameRttiMap;
    
        static void Init();
    
    public:
        static const std::list<std::string>* GetTypeNameList();
    
        static const std::string* ConvertRttiToName(int rtti);
        static bool ConvertNameToRtti(const std::string& typeName, int& rtti);
    };
}
