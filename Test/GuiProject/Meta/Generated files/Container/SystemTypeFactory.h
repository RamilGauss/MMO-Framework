/*
Project System
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:17:14.810
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "SystemIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport TSystemTypeFactory
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
