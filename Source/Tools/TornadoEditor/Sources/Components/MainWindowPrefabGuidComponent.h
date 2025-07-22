#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"

#include "GuidReference.h"

namespace nsTornadoEditor
{
    struct DllExport TMainWindowPrefabGuidComponent : nsECSFramework::IComponent
    {
        nsTornadoEngine::TPrefabGuid fileHierarchyGuid;
        nsTornadoEngine::TPrefabGuid objectHierarchyGuid;
    };
}