/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <iostream>

#include "ECS/include/ReactiveForManyEventsSystem.h"
#include "ECS/include/DataMemoryPoolComponent.h"
#include "ECS/include/ECSconfig.h"
#include "FreshPacket.h"
#include "SpeedCalculationSystem.h"

class TPacketObserverSystem :
  public nsECSFramework::TReactiveForManyEventsSystem,
  public TSpeedCalculationSystem
{
public:
  virtual void Init()
  {
    Add<TFreshPacket, PooledComponents::TUchar>();
  }

  virtual void Reactive( std::vector<nsECSFramework::TEntity>& entities, size_t count )
  {
    Start();

    auto registry = GetRegistry();
    float sum = 0;
    for( int i = 0; i < count; i++ )
    {
      auto entity = entities[i];
      //registry->get<PooledComponents::TUchar>( entity ).Done();
      registry->destroy( entity );
    }

    Stop();
    auto speed = SpeedToStr( count );
    std::cout << "PacketObserverSystem speed = " << speed << " us/1" << std::endl;
  }

  virtual bool Filter( nsECSFramework::TEntity& entity )
  {
    return GetRegistry()->has<TFreshPacket, PooledComponents::TUchar>( entity );
  }
};
