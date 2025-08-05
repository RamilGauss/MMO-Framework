/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <string>

#include "Base/Common/TypeDef.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TConstants
    {
        // Core configs
        constexpr static char CORE_COMPONENT_CONFIG [] = "CoreComponentConfig.json";

        // Core configs out
        constexpr static char CORE_COMPONENT_JSON_OUT[]           = "CoreComponentJsonOut.json";
        constexpr static char CORE_COMPONENT_RTTI_OUT[]           = "CoreComponentRttiOut.json";
        constexpr static char CORE_COMPONENT_ECS_OUT[]            = "CoreComponentEcsOut.json";
        constexpr static char CORE_COMPONENT_BINARY_OUT[]         = "CoreComponentBinaryOut.json";
        constexpr static char CORE_COMPONENT_IMGUI_OUT[]          = "CoreComponentImGuiOut.json";
        constexpr static char CORE_COMPONENT_DYNAMIC_CASTER_OUT[] = "CoreComponentDynamicCasterOut.json";
        constexpr static char CORE_COMPONENT_TYPE_FACTORY_OUT[]   = "CoreComponentTypeFactoryOut.json";

        constexpr static char CORE_IMGUI_WIDGETS_CONFIG[] = "CoreImGuiWidgetsConfig.json";

        constexpr static char CORE_IMGUI_WIDGETS_RTTI_OUT[] = "CoreImGuiWidgetsRttiOut.json";
        constexpr static char CORE_IMGUI_WIDGETS_DYNAMIC_CASTER_OUT[] = "CoreImGuiWidgetsDynamicCasterOut.json";

        //-----------------------------------------------------------------------------------------------------
        // Project configs
        constexpr static char PROJECT_COMPONENT_CONFIG[]  = "ProjectComponentConfig.json";
        constexpr static char PROJECT_HANDLER_CONFIG[]    = "ProjectHandlerConfig.json";
        constexpr static char PROJECT_ECS_SYSTEM_CONFIG[] = "ProjectEcsSystemConfig.json";
        constexpr static char PROJECT_SYSTEM_CONFIG[]     = "ProjectSystemConfig.json";

        //-----------------------------------------------------------------------------------------------------
        constexpr static char IGNORE_ATTRIBUTE[] = "IGNORE_ATTRIBUTE";

        static const std::set<std::string> GetHeaderExtensions();

        static const std::set<std::string> GetSystemInheritances();

        static const std::string GetHeader();

        static const std::string GetProgramDescription();

        static const int GetProgramMajorVersion();
        static const int GetProgramMinorVersion();
        static const int GetProgramJuniorVersion();

        static const std::string GetProgramName();
    };
}
