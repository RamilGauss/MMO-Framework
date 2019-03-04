/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#if 0
#include <entt/entt.hpp>
#include <cstdint>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "ECS/include/World.h"
#include "ECS/include/ECSconfig.h"
#include "ProducerFeature.h"
#include "PacketObserverSystem.h"
#include "ConsumerSystem.h"
#include "InitSettingsSystem.h"
#include "GroupedPacketSystem.h"
#include "MemoryPool.h"
#include "MakeShuffleEntitiesSystem.h"
#include "ViewShuffleEntitiesSystem.h"
#include "BL_Debug.h"
#include <map>
#include "HiTimer.h"
#include "BreakPacket.h"
#endif

#include "ECS/include/ECSconfig.h"
#include <entt/entt.hpp>

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"

#ifdef _DEBUG
#define COUNT 10
#else
#define COUNT 50000000
#endif

nsECSFramework::TEntityManager entMng( 1 );

nsECSFramework::THugeRegistry registry;
TVectorRise<nsECSFramework::TEntity> entities;

void testEntityManager()
{
  auto start = ht_GetMSCount();

  for ( int i = 0; i < COUNT; i++ )
  {
    entMng.CreateEntity();
  }

  auto stop = ht_GetMSCount();
  auto delta = stop - start;
  auto timePerCycle = delta * 1000000.0f / COUNT;
  printf( "create time %f ns\n", timePerCycle );

  start = ht_GetMSCount();

  for ( int i = 0; i < COUNT; i++ )
  {
    entMng.DestroyEntity( 0 );
  }

  stop = ht_GetMSCount();
  delta = stop - start;
  timePerCycle = delta * 1000000.0f / COUNT;
  printf( "destroy time %f ns\n", timePerCycle );
}

void testEntt()
{
  entities.Clear();
  auto start = ht_GetMSCount();

  for ( int i = 0; i < COUNT; i++ )
  {
    entities.Append( registry.create() );
  }

  auto stop = ht_GetMSCount();
  auto delta = stop - start;
  auto timePerCycle = delta * 1000000.0f / COUNT;
  printf( "create time %f ns\n", timePerCycle );

  start = ht_GetMSCount();

  for ( int i = 0; i < COUNT; i++ )
  {
    registry.destroy( entities.mVec[i] );
  }

  stop = ht_GetMSCount();
  delta = stop - start;
  timePerCycle = delta * 1000000.0f / COUNT;
  printf( "destroy time %f ns\n", timePerCycle );
}

int main()
{
  for ( int i = 0; i < 10; i++ )
    testEntityManager();
  printf( "-------------------------------------------------------------------------------\n" );
  for ( int i = 0; i < 10; i++ )
    testEntt();
#if 0
  auto world = new nsECSFramework::TWorld();
  world->AddToConveyer<TProducerFeature>();
  //world->AddToConveyer<TConsumerSystem>();// 1
       //world->AddToConveyer<TProducerFeature>();
  //world->AddToConveyer<TConsumerSystem>();// 2
       //world->AddToConveyer<TPacketObserverSystem>();
  world->AddToConveyer<TGroupedPacketSystem>();
  //world->AddToConveyer<TInitSettingsSystem>();

  //world->AddToConveyer<TMakeShuffleEntitiesSystem>();
  //world->AddToConveyer<TViewShuffleEntitiesSystem>();

  world->Init();
  int testCount = 20;
  while ( testCount-- > 0 )
  {
    world->Update();
    printf( "----------------------------------------------------------------\n" );
  }

  printf( "Conveyer is stopped, press any key...\n" );
#endif
  getchar();
  return 0;
}
