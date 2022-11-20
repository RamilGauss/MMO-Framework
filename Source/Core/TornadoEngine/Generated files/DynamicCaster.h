/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_16 11:21:05.204
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "FeatureIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TDynamicCaster
    {
    public:
        static void* Cast(int srcRtti, void* p, int dstRtti);
    private:
        struct Data
        {
            std::function<void*(void*)> castFunc;
        };
    
        static std::vector<std::vector<Data>> mDataVector;
    
        static void Init();
    };
}
