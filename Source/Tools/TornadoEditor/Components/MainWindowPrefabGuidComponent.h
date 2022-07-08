#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>

#include "GuidReference.h"

namespace nsTornadoEditor
{
    struct DllExport TMainWindowPrefabGuidComponent : nsECSFramework::IComponent
    {
        nsTornadoEngine::TPrefabGuid fileHierarchyGuid;
        nsTornadoEngine::TPrefabGuid objectHierarchyGuid;
    };
}