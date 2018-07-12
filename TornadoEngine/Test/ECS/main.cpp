#include <entt/entt.hpp>
#include <cstdint>
#ifdef WIN32
#include <conio.h>
#endif
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <entt/entt.hpp>

#include "World.h"
#include "ECSconfig.h"
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
#include "MappedGroup.h"
#include "HiTimer.h"


int main()
{
#if 0
  TSpeedCalculationSystem speedCalc;

  const int memSize = 100;
  int countI = 5000;
  const int countJ = 10000;
  TMemoryPool::Type* arr[countJ];
  // пустой прогон
  for( auto j = 0; j < countJ; j++ )
    arr[j] = g_MemoryPool.Pop( memSize );
  for( auto j = 0; j < countJ; j++ )
    g_MemoryPool.Push( arr[j], memSize );

  speedCalc.Start();
  for( int i = 0; i < countI; i++ )
  {
    for( auto j = 0; j < countJ; j++ )
      arr[j] = g_MemoryPool.Pop( memSize );
    for( auto j = 0; j < countJ; j++ )
      g_MemoryPool.Push( arr[j], memSize );
  }
  speedCalc.Stop();
  auto speed = speedCalc.Speed( countI*countJ );
  printf( "POOL speed = %f us/1\n", speed );

  speedCalc.Start();
  countI = 50000000;
  for( int i = 0; i < countI; i++ )
  {
    std::shared_ptr<unsigned char []> sp( new unsigned char[memSize] );
    sp.reset();
  }
  speedCalc.Stop();
  speed = speedCalc.Speed( countI );
  printf( "Pure speed = %f us/1\n", speed );
  return 0;
#endif

#if 0
  const int mappedGroupTestCount = 50000000;
  {
    MWorks::ECS::THugeRegistry registry;
    TMappedGroup<ShuffledComponents::A> aMappedGroup( &registry );

    auto start = ht_GetMSCount();

    for( int i = 0; i < mappedGroupTestCount; i++ )
    {
      auto entity = registry.create();
      registry.assign<ShuffledComponents::A>( entity, i );
    }

    auto stop = ht_GetMSCount();
    auto delta = stop - start;
    auto createSpeed = delta * 1000.0f / mappedGroupTestCount;

    start = ht_GetMSCount();

    MWorks::ECS::TEntity entity;
    ShuffledComponents::A a;
    for( int i = 0; i < mappedGroupTestCount; i++ )
    {
      a.a = i;
      entity = aMappedGroup.Get( a );
    }

    stop = ht_GetMSCount();
    delta = stop - start;
    auto searchSpeed = delta * 1000.0f / mappedGroupTestCount;

    printf( "Entity = %u, createSpeed = %f us, searchSpeed = %f us \n", entity, createSpeed, searchSpeed );
  }
#ifdef WIN32 
  _getch();
#endif
#endif

  auto world = new MWorks::ECS::TWorld();
  world->AddToConveyer<TProducerFeature>();
  //world->AddToConveyer<TPacketObserverSystem>();
  world->AddToConveyer<TConsumerSystem>();
  //world->AddToConveyer<TGroupedPacketSystem>();
  //world->AddToConveyer<TInitSettingsSystem>();

  //world->AddToConveyer<TMakeShuffleEntitiesSystem>();
  //world->AddToConveyer<TViewShuffleEntitiesSystem>();

  world->Init();
  int testCount = 20;
  while( testCount-- > 0 )
  {
    world->Update();
    printf( "----------------------------------------------------------------\n" );
    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  printf( "Conveyer is stopped, press any key...\n" );
#ifdef WIN32 
  _getch();
#endif
  return 0;
}
