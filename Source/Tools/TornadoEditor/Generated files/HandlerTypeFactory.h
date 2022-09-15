/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_09_14 08:06:50.593
	
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
