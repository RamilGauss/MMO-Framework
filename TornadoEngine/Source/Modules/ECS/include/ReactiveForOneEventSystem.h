#pragma once
#include <entt/entt.hpp>

#include "System.h"
#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  class DllExport TReactiveForOneEventSystem : public TBaseReactiveSystem
  {
  public:
    TReactiveForOneEventSystem();
    virtual void Update() final;
  };
}
