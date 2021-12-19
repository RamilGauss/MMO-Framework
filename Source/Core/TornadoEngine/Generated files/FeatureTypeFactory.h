/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_19 11:41:21.716
	
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
