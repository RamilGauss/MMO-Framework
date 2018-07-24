#pragma once
#include <iostream>

#include "ExecuteSystem.h"
#include "SpeedCalculationSystem.h"
#include "PacketData.h"
#include "FreshPacket.h"
#include "DataMemoryPoolComponent.h"
#include "ShuffledComponents.h"
#include "MappedGroup.h"

#ifdef _DEBUG
#define PACKET_COUNT 10
#else
#define PACKET_COUNT 20000000
#endif

#define SIZE_PACKET 100

class TProducerSystem : public MWorks::ECS::TExecuteSystem, public TSpeedCalculationSystem
{
  typedef TMappedSingleEntityGroup<ShuffledComponents::A> SA_Group;
  SA_Group* mSA_group;

  typedef TMappedMultiEntityGroup<ShuffledComponents::A> MA_Group;
  MA_Group* mMA_group;
public:
  virtual void Init()
  {
    mSA_group = new SA_Group( GetRegistry() );// пример как использовать группу для поиска по значению
    mMA_group = new MA_Group( GetRegistry() );// пример как использовать группу для поиска по значению
  }

  virtual void Execute()
  {
    ShuffledComponents::A a;
    a.a = 1;
    std::list<MWorks::ECS::TEntity> entList;
    mMA_group->Get( a, entList );
    if( entList.size() > 0 )
    {
      int asd = 0;
    }
    auto ent = mSA_group->Get( a );
    if( ent != entt::null )
    {
      int asd = 0;
    }

    Start();
    auto registry = GetRegistry();

    for( auto i = 0; i < PACKET_COUNT; i++ )
    {
      auto ent = registry->create();
      registry->assign<PooledComponents::TUchar>( ent, SIZE_PACKET );
      auto& c = registry->get<PooledComponents::TUchar>( ent );
      registry->assign<TFreshPacket>( ent );
    }

    Stop();
    auto speed = SpeedToStr( PACKET_COUNT );
    std::cout << "Producer speed = " << speed << " us/1" << std::endl;
  }
};
