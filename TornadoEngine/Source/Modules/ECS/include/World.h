#pragma once
#include <entt/entt.hpp>
#include <vector>
#include "ECSconfig.h"
#include "ConveyerPartMaster.h"

namespace nsECSFramework
{
  class DllExport TWorld : public TConveyerPartMaster
  {
  public:
    TWorld();
  };
}