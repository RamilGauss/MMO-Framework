/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <iostream>

#include "ECS/include/ReactiveForOneEventSystem.h"
#include "ECS/include/DataMemoryPoolComponent.h"
#include "ECS/include/ECSconfig.h"
#include "FreshPacket.h"
#include "SpeedCalculationSystem.h"

class TConsumerSystem : public nsECSFramework::TReactiveForOneEventSystem, public TSpeedCalculationSystem
{
public:
  virtual void Init()
  {
    Add<TFreshPacket>();
  }

  void Reactive( std::vector<nsECSFramework::TEntity>& entities, size_t count )
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
    std::cout << "Consumer speed = " << speed << " us/1" << std::endl;
  }

  bool Filter( nsECSFramework::TEntity& entity )
  {
    return GetRegistry()->has<TFreshPacket>( entity );
  }
};

