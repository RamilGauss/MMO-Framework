/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2022_11_23 10:25:56.347
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "FeatureIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TFeatureTypeFactory
    {
    public:
        static void* New(int rtti);
        static void Delete(void* p, int rtti);
        static bool Has(int rtti);
    private:
        struct Data
        {
            std::function<void* ()> newFunc;
            std::function<void (void*)> deleteFunc;
        };
    
        static std::vector<Data> mDataVector;
    
        static void Init();
    };
}
