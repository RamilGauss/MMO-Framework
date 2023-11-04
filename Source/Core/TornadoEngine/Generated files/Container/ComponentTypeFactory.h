/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_04 19:35:23.600
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentTypeFactory
    {
    public:
        static void* New(int rtti);
        static void Delete(void* p, int rtti);
        static bool Has(int rtti);
    
        static void Init();
    private:
        struct Data
        {
            int rtti = 0;
            std::function<void* ()> newFunc;
            std::function<void (void*)> deleteFunc;
        };
    
        static std::vector<Data> mDataVector;
    };
}
