/*
Core System
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_12_24 21:59:44.778
	
#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>

#include "TypeDef.h"
#include "SystemIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TSystemDynamicCaster
    {
    public:
        static const std::map<int, std::set<int>>& GetRttiCombinations();// rtti <---> rtti-es
        static void* Cast(int srcRtti, void* p, int dstRtti);
    private:
        struct Data
        {
            std::function<void*(void*)> castFunc = nullptr;
        };
    
        static std::vector<std::vector<Data>> mDataVector;
        static std::map<int, std::set<int>> mRttiCombinations;
    
        static void Init();
    };
}
