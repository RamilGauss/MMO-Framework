#pragma once
#include <entt/entt.hpp>

#include "System.h"
#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TReactiveForOneEventSystem : public TBaseReactiveSystem
    {
    public:
      TReactiveForOneEventSystem();
      virtual void Update() final;
    };
  }
}