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
      TVectorRise<TEntity> mReactionEntities;
    public:
      TReactiveForOneEventSystem();
      virtual void Update() final;
    protected:
      virtual void Reaction(THugeRegistry& registry, const TEntity entity) final;
    };
  }
}