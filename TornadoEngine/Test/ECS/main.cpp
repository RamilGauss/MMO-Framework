/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"
#include "Components.h"

#ifdef _DEBUG
#define COUNT 5000000
#else
#define COUNT 100000000
#endif

nsECSFramework::TEntityManager entMng( 1 );

TVectorRise<nsECSFramework::TEntity> entities;

struct A : nsECSFramework::IMultiMixComponent
{
  int v;
};
struct B : nsECSFramework::IMultiMixComponent
{
  int v;
};
struct C : nsECSFramework::IMultiMixComponent
{
  int v;
};

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

int main()
{
  entMng.SetMixCombination<A, B>();
  entMng.SetMixCombination<A, B, C>();

  auto entity = entMng.CreateEntity();
  A a;
  a.v = 1;
  entMng.AddComponent( entity, a );

    for ( int i = 0; i < 20; i++ )
      testEntityManager();
  //printf( "-------------------------------------------------------------------------------\n" );
  //for ( int i = 0; i < 10; i++ )
  //  testEntt();
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
