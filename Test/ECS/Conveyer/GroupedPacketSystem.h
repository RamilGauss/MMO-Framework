/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ECS/include/ExecuteSystem.h"
#include "ECS/include/DataMemoryPoolComponent.h"
#include "SpeedCalculationSystem.h"
#include "FreshPacket.h"
#include <iostream>

#define GROUP_TEST_COUNT 1

class TGroupedPacketSystem : public nsECSFramework::TExecuteSystem, public TSpeedCalculationSystem
{
public:
  virtual void Execute() override
  {
    auto registry = GetRegistry();

    //Start();

    ////entt::View<nsECSFramework::TEntity, TDataMemoryPoolComponent> packetGroup();
    //for( int i = 0; i < GROUP_TEST_COUNT; i++ )
    //{
    //  auto packetGroup = registry->view<TFreshPacket>();
    //  packetGroup.size();
    //}

    //Stop();
    //auto speed = SpeedToStr( GROUP_TEST_COUNT );
    //std::cout << "Make grouped speed = " << speed << " us/1" << std::endl;

    Start();

    auto packetGroup = registry->view<TFreshPacket>();
    auto count = packetGroup.size();
    auto entities = packetGroup.data();
    float sum = 0;
    for( auto i = 0; i < count; i++ )
    {
      auto entity = entities[i];
      GetRegistry()->destroy( entity );
    }

    Stop();
    auto speed = SpeedToStr( count );
    std::cout << "GroupedPacketSystem speed = " << speed << " us/1" << std::endl;
  }

};