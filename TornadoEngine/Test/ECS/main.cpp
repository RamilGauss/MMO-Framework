/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <conio.h>

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"
#include "ExecuteSystem.h"

#ifdef _DEBUG
#define COUNT 10000
#else
#define COUNT 2000000
#endif

using namespace nsECSFramework;

class Tag : public IComponent
{
};

class A : public IComponent
{
public:
  int mID;
  A()
  {
  }
  A( int id )
  {
    mID = id;
  }

  virtual bool IsLess( const IComponent* pOther ) const override
  {
    auto p = (A*)pOther;
    return mID < p->mID;
  }
  virtual bool IsEqual( const IComponent* pOther ) const override
  {
    auto p = (A*)pOther;
    return mID == p->mID;
  }
};

class B : public IComponent
{
public:
  int mID;
  B()
  {
  }
  B( int id )
  {
    mID = id;
  }

  virtual bool IsLess( const IComponent* pOther ) const override
  {
    auto p = (B*)pOther;
    return mID < p->mID;
  }
  virtual bool IsEqual( const IComponent* pOther ) const override
  {
    auto p = (B*)pOther;
    return mID == p->mID;
  }
};

class C : public IComponent
{
public:
  std::string mName;
  C()
  {
  }
  C( std::string name )
  {
    mName = name;
  }

  virtual bool IsLess( const IComponent* pOther ) const override
  {
    auto p = (C*)pOther;
    return mName < p->mName;
  }
  virtual bool IsEqual( const IComponent* pOther ) const override
  {
    auto p = (C*)pOther;
    return mName == p->mName;
  }
};

class TASystem// : public TExecuteSystem
{
public:
  void Handle( TEntityID id, A* pA )
  {
    printf( "" );
  }
};

class TKey
{
public:
  int v;
  bool operator < ( const TKey& other ) const
  {
    return v < other.v;
  }
};

TEntityManager g_EntMng;
std::list<TEntityID> g_Entities;
const int g_EntityCount = COUNT;
const int testCount = 100;


void CreateEntities()
{
  for ( int i = 0; i < g_EntityCount; i++ )
  {
    auto eid = g_EntMng.CreateEntity();
    g_Entities.push_back( eid );
  }
}

void DestroyEntities()
{
  for ( auto eid : g_Entities )
    g_EntMng.DestroyEntity( eid );
  g_Entities.clear();
}

void CreateComplexEntities()
{
  Tag tag;
  A a( 777 );
  B b;
  C c( "123" );
  for ( size_t i = 0; i < g_EntityCount; i++ )
  {
    auto entity = g_EntMng.CreateEntity();
    g_EntMng.SetComponent( entity, tag );// tag on search all entities
    //g_EntMng.SetComponent( entity, a );
    //g_EntMng.SetComponent( entity, b );
    //g_EntMng.SetComponent( entity, c );
    g_Entities.push_back( entity );

    // 4 - create = 0.717000, destroy = 0.632000
    // 3 - create = 0.583500, destroy = 0.531500
    // 2 - create = 0.447500, destroy = 0.435000
    // 1 - create = 0.248000, destroy = 0.275000
    // 1(has) - create = 0.346000, destroy = 0.343500
    // create = 0.207500, destroy = 0.260000
    // 0 - create = 0.089000, destroy = 0.151500
  }
}

void DestroyEntitiesByTag()
{
  //auto entities = g_EntMng.GetByHas<Tag>();
  //TLoopList<TEntityID> loopListEntities( entities );
  //while ( true )
  //{
  //  TEntityID entity;
  //  if ( loopListEntities.Next( entity ) == false )
  //    break;
  //  g_EntMng.DestroyEntity( entity );
  //}
}

float GetSpeedByTest( std::function<void()> testFunc, int count )
{
  auto start = ht_GetMSCount();

  testFunc();

  auto delta = ht_GetMSCount() - start;
  auto speed = ( 1000.0f * delta ) / count;
  return speed;
}

int main()
{
  g_EntMng.Setup();

  for ( int iTest = 0; iTest < testCount; iTest++ )
  {
    //auto createSpeed = GetSpeedByTest( CreateEntities, g_EntityCount );
    //auto destroySpeed = GetSpeedByTest( DestroyEntities, g_EntityCount );

    auto createComplexSpeed = GetSpeedByTest( CreateComplexEntities, g_EntityCount );
    auto destroyByTagSpeed = GetSpeedByTest( DestroyEntities/*DestroyEntitiesByTag*/, g_EntityCount );

    std::string testName = iTest == 0 ? "Cold" : "Hot";
    //printf( "Speed in %s test us/entity: create = %f, destroy = %f,        COMPLEX create = %f, destroy = %f \n",
    //  testName.data(), createSpeed, destroySpeed, createComplexSpeed, destroyByTagSpeed );
    printf( "Speed in %s test us/entity: create = %f, destroy = %f \n",
      testName.data(), createComplexSpeed, destroyByTagSpeed );
  }
  _getch();

  //A a( 777 );
  //B b;
  //C c( "123" );
  //  for ( size_t i = 0; i < entityCount; i++ )
  //  {
  //    b.mID = i;
  //    auto entity = entMng.CreateEntity();
  //    if ( i < entityCount / 2 )
  //      entMng.SetComponent( entity, a );
  //    else
  //      entMng.SetComponent( entity, b );
  //    if ( i > entityCount / 3 - 1 && i < ( entityCount * 2 ) / 3 )
  //      entMng.SetComponent( entity, c );
  //  }

  //auto hasAList = g_EntMng.GetByHas<A>();
  //auto hasABList = g_EntMng.GetByHas<A, B>();
  //auto hasBList = g_EntMng.GetByHas<B>();
  //auto hasACList = g_EntMng.GetByHas<A, C>();
  //auto hasBCList = g_EntMng.GetByHas<B, C>();
  //auto hasCList = g_EntMng.GetByHas<C>();

  //auto valueAList = g_EntMng.GetByValue( a );
  //auto valueCList = g_EntMng.GetByValue( c );

  //b.mID = 500;
  //auto entByUnique = g_EntMng.GetByUnique( b );

  //  auto pASystem = new TASystem();
  //
  //  entMng.OnAdd<A>( [pASystem]( TEntityManager::CallBackPtr<A>* pCB )
  //  {
  //    pCB->Register( &TASystem::Handle, pASystem );
  //  } );
  //
  //  entMng.OnAdd<A>( [pASystem]( TEntityManager::CallBackPtr<A>* pCB )
  //  {
  //    pCB->Unregister( pASystem );
  //  } );
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
