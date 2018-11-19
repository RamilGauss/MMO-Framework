#pragma once
#include <entt/entt.hpp>
#include "ECSconfig.h"
#include "TypeDef.h"

// Доступ к данным ECS инфраструктуры

namespace nsECSFramework
{
  class DllExport TGlobalAccess
  {
    THugeRegistry* mRegistry;
  public:
    inline THugeRegistry* GetRegistry()
    {
      return mRegistry;
    }
    inline void SetRegistry( THugeRegistry* registry )
    {
      mRegistry = registry;
    }
  };
}
