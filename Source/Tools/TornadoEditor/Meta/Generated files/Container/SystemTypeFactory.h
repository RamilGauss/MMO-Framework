/*
Project System
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_25 11:43:22.521
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "Base/Common/TypeDef.h"
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
