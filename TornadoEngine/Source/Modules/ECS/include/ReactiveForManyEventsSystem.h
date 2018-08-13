#pragma once
#include <entt/entt.hpp>

#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TReactiveForManyEventsSystem : public TBaseReactiveSystem
    {
      // Важен порядок возникновения событий
      // все изменившиеся
      TVectorRise<TEntity> mReactionEntities;
    public:
      TReactiveForManyEventsSystem();
      virtual void Update() final;
    };
  }
}