/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.0, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_09_10 14:38:50.352
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "HandlerIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport THandlerTypeFactory
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
