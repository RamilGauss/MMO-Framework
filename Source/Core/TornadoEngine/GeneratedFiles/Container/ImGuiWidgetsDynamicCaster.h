/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.1, build 60 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>

#include "Base/Common/TypeDef.h"
#include "TornadoEngine/GeneratedFiles/Container/ImGuiWidgetsIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TImGuiWidgetsDynamicCaster
    {
    public:
        static void Init();
        static const std::map<int, std::set<int>>& GetRttiCombinations();// rtti <---> rtti-es
        static void* Cast(int srcRtti, void* p, int dstRtti);
    private:
        struct Data
        {
            int rtti = 0;
            std::function<void*(void*)> castFunc = nullptr;
        };
    
        static std::vector<std::vector<Data>> mDataVector;
        static std::map<int, std::set<int>> mRttiCombinations;
    
    };
}
