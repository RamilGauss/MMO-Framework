#pragma once
#include <iostream>

#include "ReactiveForOneEventSystem.h"
#include "DataMemoryPoolComponent.h"
#include "ECSconfig.h"
#include "FreshPacket.h"
#include "SpeedCalculationSystem.h"

class TConsumerSystem : public MWorks::ECS::TReactiveForOneEventSystem, public TSpeedCalculationSystem
{
public:
  virtual void Init()
  {
    Add<TFreshPacket>();
  }

  void Reactive(std::vector<MWorks::ECS::TEntity>& entities, size_t count)
  {
    Start();

    auto registry = GetRegistry();
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
      auto entity = entities[i];
      registry->get<PooledComponents::TUchar>(entity).Done();
      registry->destroy(entity);
    }

    Stop();
    auto speed = SpeedToStr(count);
    std::cout << "Consumer speed = " << speed << " us/1" << std::endl;
  }

  bool Filter(MWorks::ECS::TEntity& entity)
  {
    return GetRegistry()->has<TFreshPacket>(entity);
  }
};

