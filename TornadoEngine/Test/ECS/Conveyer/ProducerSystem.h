/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <iostream>

#include "ECS/include/ExecuteSystem.h"
#include "ECS/include/MappedGroup.h"
#include "ECS/include/DataMemoryPoolComponent.h"
#include "SpeedCalculationSystem.h"
#include "PacketData.h"
#include "FreshPacket.h"
#include "ShuffledComponents.h"
#include "include/Helper.h"

#ifdef _DEBUG
#define PACKET_COUNT 2
#else
#define PACKET_COUNT 20000000
#endif

#define SIZE_PACKET 100

class TProducerSystem : public nsECSFramework::TExecuteSystem, public TSpeedCalculationSystem
{
  typedef TMappedSingleEntityGroup<ShuffledComponents::A> SA_Group;
  SA_Group* mSA_group;
  SA_Group* mSA_group2;

  typedef TMappedMultiEntityGroup<ShuffledComponents::A> MA_Group;
  MA_Group* mMA_group;
public:
  virtual void Init()
  {
    // пример как использовать группу для поиска по значению
    mSA_group = new SA_Group( GetRegistry() );
    mSA_group2 = new SA_Group( GetRegistry() );
    mMA_group = new MA_Group( GetRegistry() );
  }

  virtual void Execute()
  {
    ShuffledComponents::A a;
    a.a = 1;
    std::list<nsECSFramework::TEntity> entList;
    mMA_group->Get( a, entList );
    if ( entList.size() > 0 )
    {
      int asd = 0;
    }
    auto ent = mSA_group->Get( a );
    auto ent2 = mSA_group2->Get( a );
    if ( ent != entt::null )
    {
      int asd = 0;
    }

    Start();
    auto registry = GetRegistry();

    for ( auto i = 0; i < PACKET_COUNT; i++ )
    {
      auto ent = registry->create();
      registry->assign<PooledComponents::TUchar>( ent, registry, SIZE_PACKET );
      auto& c = registry->get<PooledComponents::TUchar>( ent );
      registry->assign<TFreshPacket>( ent );
    }
    //###
    struct A
    {
    };
    struct B
    {
    };
    for ( int i = 0; i < 1; i++ )
    {
      auto e = registry->create();
      registry->assign<A>( e );
    }
    for ( int i = 0; i < 1; i++ )
    {
      auto e = registry->create();
      registry->assign<B>( e );
    }
    for ( int i = 0; i < 2; i++ )
    {
      auto e = registry->create();
      registry->assign<A>( e );
      registry->assign<B>( e );
    }

    auto fu = registry->view<A,B>();
    auto sfu = fu.size();
    for ( auto e : fu )
    {
      int a = 0;
    }
    //###

    Stop();
    auto speed = SpeedToStr( PACKET_COUNT );
    std::cout << "Producer speed = " << speed << " us/1" << std::endl;
  }
};
