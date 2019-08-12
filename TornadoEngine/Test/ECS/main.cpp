/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"

#ifdef _DEBUG
#define COUNT 5000000
#else
#define COUNT 100000000
#endif

using namespace nsECSFramework;

class A : public IComponent
{
public:
  int id;

  // Inherited via IComponent
  virtual bool IsEqual( IComponent* pOther ) override
  {
    return false;
  }
  virtual bool IsLess( IComponent* pOther ) override
  {
    return false;
  }
  virtual bool IsMore( IComponent* pOther ) override
  {
    return false;
  }
};

int main()
{
  TEntityManager entMng;
  TComplexType complexType;

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
