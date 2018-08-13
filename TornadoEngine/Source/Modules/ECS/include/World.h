#pragma once
#include <entt/entt.hpp>
#include <vector>
#include "ECSconfig.h"
#include "ConveyerPartMaster.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TWorld : public TConveyerPartMaster
    {
    public:
      TWorld();
    };
  }
}