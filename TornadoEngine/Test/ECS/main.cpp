/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <entt/entt.hpp>
#include <cstdint>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <entt/entt.hpp>

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

int main()
{
  //auto p = /*TMemoryPool<char>::Singleton();*/ SingletonManager()->Get<TMemoryPool<char>>();
  //int count = 2000000000;
  //auto start = ht_GetMSCount();
  //for( int i = 0; i < count; i++ )
  //  p = /*TMemoryPool<char>::Singleton();*/ SingletonManager()->Get<TMemoryPool<char>>();
  //auto delta = ht_GetMSCount() - start;
  //float cycle_time = delta * 1000.0f / count;
  //printf( "cycle_time = %f\n", cycle_time );
  //getchar();
//#if 0
//  TSpeedCalculationSystem speedCalc;
//
//  const int memSize = 100;
//  int countI = 5000;
//  const int countJ = 10000;
//  TMemoryPool::Type* arr[countJ];
//  // пустой прогон
//  for( auto j = 0; j < countJ; j++ )
//    arr[j] = g_MemoryPool.Pop( memSize );
//  for( auto j = 0; j < countJ; j++ )
//    g_MemoryPool.Push( arr[j], memSize );
//
//  speedCalc.Start();
//  for( int i = 0; i < countI; i++ )
//  {
//    for( auto j = 0; j < countJ; j++ )
//      arr[j] = g_MemoryPool.Pop( memSize );
//    for( auto j = 0; j < countJ; j++ )
//      g_MemoryPool.Push( arr[j], memSize );
//  }
//  speedCalc.Stop();
//  auto speed = speedCalc.Speed( countI*countJ );
//  printf( "POOL speed = %f us/1\n", speed );
//
//  speedCalc.Start();
//  countI = 50000000;
//  for( int i = 0; i < countI; i++ )
//  {
//    std::shared_ptr<unsigned char []> sp( new unsigned char[memSize] );
//    sp.reset();
//  }
//  speedCalc.Stop();
//  speed = speedCalc.Speed( countI );
//  printf( "Pure speed = %f us/1\n", speed );
//  return 0;
//#endif
//
//#if 0
//  const int mappedGroupTestCount = 50000000;
//  {
//    nsECSFramework::THugeRegistry registry;
//    TMappedGroup<ShuffledComponents::A> aMappedGroup( &registry );
//
//    auto start = ht_GetMSCount();
//
//    for( int i = 0; i < mappedGroupTestCount; i++ )
//    {
//      auto entity = registry.create();
//      registry.assign<ShuffledComponents::A>( entity, i );
//    }
//
//    auto stop = ht_GetMSCount();
//    auto delta = stop - start;
//    auto createSpeed = delta * 1000.0f / mappedGroupTestCount;
//
//    start = ht_GetMSCount();
//
//    nsECSFramework::TEntity entity;
//    ShuffledComponents::A a;
//    for( int i = 0; i < mappedGroupTestCount; i++ )
//    {
//      a.a = i;
//      entity = aMappedGroup.Get( a );
//    }
//
//    stop = ht_GetMSCount();
//    delta = stop - start;
//    auto searchSpeed = delta * 1000.0f / mappedGroupTestCount;
//
//    printf( "Entity = %u, createSpeed = %f us, searchSpeed = %f us \n", entity, createSpeed, searchSpeed );
//  }
//#ifdef WIN32 
//  _getch();
//#endif
//#endif
  auto world = new nsECSFramework::TWorld();
  world->AddToConveyer<TProducerFeature>();
  world->AddToConveyer<TConsumerSystem>();// 1
       //world->AddToConveyer<TProducerFeature>();
  //world->AddToConveyer<TConsumerSystem>();// 2
       //world->AddToConveyer<TPacketObserverSystem>();
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
  }

  printf( "Conveyer is stopped, press any key...\n" );

  getchar();
  return 0;
}
