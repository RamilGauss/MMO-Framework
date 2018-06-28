#pragma once
#include <entt/entt.hpp>
#include "ECSconfig.h"
#include "ConveyerPartWithGlobalAccess.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TSystem : public TConveyerPartWithGlobalAccess {};
  }
}