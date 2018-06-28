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
      // после сортировки и прореживания от повторов
      TVectorRise<TEntity> mSortedUniqueEntities;
      // после фильтрации наследуемым классом
      TVectorRise<TEntity> mFilteredEntities;

      // статистика по встречаемости
      TVectorRise<unsigned short> mStatistics;
    public:
      TReactiveForManyEventsSystem();
      virtual void Update() final;

    protected:
      virtual void Reaction(THugeRegistry& registry, const TEntity entity) final;
    };
  }
}