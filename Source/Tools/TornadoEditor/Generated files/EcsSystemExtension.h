/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_07_07 08:07:53.679
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "FeatureIncludeList.h"

namespace nsTornadoEditor
{
    class DllExport TEcsSystemExtension
    {
    public:
        static nsECSFramework::TSystem* DynamicCast(void* p, int rtti);
    private:
        struct Data
        {
            std::function<nsECSFramework::TSystem* (void*)> castFunc;
        };
    
        static std::vector<Data> mDataVector;
    
        static void Init();
    };
}