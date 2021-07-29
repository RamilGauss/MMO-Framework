/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_29 08:27:54.091
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "IncludeList.h"

namespace nsTypeFactory
{
    class DllExport TTypeFactorySerializer
    {
    public:
        static void* New(int rtti);
        static void Delete(void* p, int rtti);
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
