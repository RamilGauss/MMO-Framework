/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <string>

#include "TypeDef.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TConstants
    {
        // Core configs
        constexpr static char CORE_COMPONENT_CONFIG [] = "coreComponentConfig.json";
        constexpr static char CORE_HANDLER_CONFIG[]    = "coreHandlerConfig.json";
        constexpr static char CORE_ECS_SYSTEM_CONFIG[] = "coreEcsSystemConfig.json";
        constexpr static char CORE_SYSTEM_CONFIG[]     = "coreSystemConfig.json";

        // Core configs out
        constexpr static char CORE_COMPONENT_JSON_OUT[]      = "coreComponentJsonOut.json";
        constexpr static char CORE_COMPONENT_TYPE_INFO_OUT[] = "coreComponentTypeInfoOut.json";
        constexpr static char CORE_COMPONENT_ECS_OUT[]       = "coreComponentEcsOut.json";
        constexpr static char CORE_COMPONENT_BINARY_OUT[]    = "coreComponentBinaryOut.json";
        constexpr static char CORE_COMPONENT_IMGUI_OUT[]     = "coreComponentImGuiOut.json";

        constexpr static char CORE_HANDLER_TYPE_INFO_OUT[]    = "coreHandlerTypeInfoOut.json";
        constexpr static char CORE_HANDLER_TYPE_FACTORY_OUT[] = "coreHandlerTypeFactoryOut.json";

        constexpr static char CORE_ECS_SYSTEM_TYPE_INFO_OUT[]      = "coreEcsSystemTypeInfoOut.json";
        constexpr static char CORE_ECS_SYSTEM_DYNAMIC_CASTER_OUT[] = "coreEcsSystemDynamicCasterOut.json";

        constexpr static char CORE_SYSTEM_TYPE_INFO_OUT[]      = "coreSystemTypeInfoOut.json";
        constexpr static char CORE_SYSTEM_DYNAMIC_CASTER_OUT[] = "coreSystemDynamicCasterOut.json";
        constexpr static char CORE_SYSTEM_TYPE_FACTORY_OUT[]   = "coreSystemTypeFactoryOut.json";
        //-----------------------------------------------------------------------------------------------------
        // Project configs
        constexpr static char PROJECT_COMPONENT_CONFIG[]  = "projectComponentConfig.json";
        constexpr static char PROJECT_HANDLER_CONFIG[]    = "projectHandlerConfig.json";
        constexpr static char PROJECT_ECS_SYSTEM_CONFIG[] = "projectEcsSystemConfig.json";
        constexpr static char PROJECT_SYSTEM_CONFIG[]     = "projectSystemConfig.json";
        //-----------------------------------------------------------------------------------------------------
        static const std::set<std::string> GetHeaderExtensions();

        static const std::set<std::string> GetSystemInheritances();
    };
}
