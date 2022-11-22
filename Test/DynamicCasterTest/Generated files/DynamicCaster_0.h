/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_21 12:20:32.589
	
#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>

#include "TypeDef.h"
#include "DynamicCast_0_IncludeList.h"

namespace nsDynamicCasterTest
{
    class DllExport TDynamicCaster_0
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
