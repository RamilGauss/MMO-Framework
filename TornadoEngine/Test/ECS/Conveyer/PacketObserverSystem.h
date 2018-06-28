#pragma once
#include <iostream>

#include "ReactiveForManyEventsSystem.h"
#include "DataMemoryPoolComponent.h"
#include "ECSconfig.h"
#include "FreshPacket.h"
#include "SpeedCalculationSystem.h"

class TPacketObserverSystem : 
  public MWorks::ECS::TReactiveForManyEventsSystem,
  public TSpeedCalculationSystem
{
public:
  virtual void Init()
  {
    Add<TFreshPacket>();
  }

  virtual void Reactive(std::vector<MWorks::ECS::TEntity>& entities, size_t count)
  {
    
  }

  virtual bool Filter(MWorks::ECS::TEntity& entity)
  {
    return GetRegistry()->has<TFreshPacket, PooledComponents::TUchar>(entity);
  }
};
