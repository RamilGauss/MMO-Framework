/*
	DynamicCasterTest
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_20 21:27:14.738
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "DynamicCast_1_IncludeList.h"

namespace nsDynamicCasterTest
{
    class DllExport TDynamicCaster_1
    {
    public:
        //### static bool CanCast(int srcRtti, int dstRtti);//!!!

        static void* Cast(int srcRtti, void* p, int dstRtti);
    private:
        struct Data
        {
            std::function<void*(void*)> castFunc = nullptr;//### !!!
        };
    
        static std::vector<std::vector<Data>> mDataVector;
    
        static void Init();
    };
}
