#pragma once
#include <iostream>

#include "ExecuteSystem.h"
#include "SpeedCalculationSystem.h"
#include "PacketData.h"
#include "FreshPacket.h"
#include "DataMemoryPoolComponent.h"


#ifdef _DEBUG
#define PACKET_COUNT 10
#else
#define PACKET_COUNT 20000000
#endif

#define SIZE_PACKET 100

class TProducerSystem : public MWorks::ECS::TExecuteSystem, public TSpeedCalculationSystem
{
public:
  virtual void Init()
  {
    int a = 0;
  }

  virtual void Execute()
  {
    Start();
    auto registry = GetRegistry();

    for (auto i = 0; i < PACKET_COUNT; i++)
    {
      auto ent = registry->create();
      registry->assign<PooledComponents::TUchar>(ent, SIZE_PACKET);
      auto& c = registry->get<PooledComponents::TUchar>( ent );
      registry->assign<TFreshPacket>(ent);
    }

    Stop();
    auto speed = SpeedToStr(PACKET_COUNT);
    std::cout << "Producer speed = " << speed << " us/1" << std::endl;
  }
};
