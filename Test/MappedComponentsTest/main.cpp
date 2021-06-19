#include <cstdlib>
#include <iostream>
#include <ctime>

#include "EntityManager.h"
#include "fmt/core.h"
#include "HiTimer.h"
#include "SortedVector.h"
#include <unordered_set>

using namespace nsMappedComponents;

struct TIdentityComponent : IUniqueComponent
{
  unsigned int id;
  bool operator< ( const TIdentityComponent& other ) const
  {
    return other.id > this->id;
  }
};

struct TGroupIDComponent : IMultiComponent
{
  unsigned int id;
  bool operator< ( const TGroupIDComponent& other ) const
  {
    return other.id > this->id;
  }
};

struct TStateComponent : IMultiComponent, IGroupedComponent
{
  typedef enum
  {
    InQueue,
    Logining,
    RCM,
    OnSlave,
    Count,
  }State;

  State v = InQueue;

  bool operator< ( const TStateComponent& other ) const
  {
    return other.v > this->v;
  }
  virtual int GetGroupCount()
  {
    return State::Count;
  }
  virtual int GetGroupNumber()
  {
    return v;
  }
};

#ifdef _DEBUG
const int CLIENT_COUNT = 4;
const int TEST_COUNT = 1;//500;
const int sizeGroup = 2;
#else
const int CLIENT_COUNT = 200000;// 200000;
const int TEST_COUNT = 1000000;
const int sizeGroup = 30;
#endif

const int inGroupPercent = 80;
const int inQueuePercent = 20;

TEntityManager entMng;
//----------------------------------------------------------------------------------
void AddRemoveTest()
{
  auto ent = entMng.CreateEntity();
  TStateComponent state;
  state.v = TStateComponent::InQueue;
  entMng.AddComponent( ent, state );

  TGroupIDComponent groupID;
  groupID.id = 0;
  entMng.AddComponent( ent, groupID );

  TIdentityComponent identity;
  identity.id = 1;
  entMng.AddComponent( ent, identity );

  entMng.DestroyEntity( ent );

  entMng.RemoveComponent<TStateComponent>( ent );
}
//----------------------------------------------------------------------------------
void AddClients()
{
  int clientsInGroup = 0;
  unsigned int lasGroupID = 1;
  for ( int i = 0; i < CLIENT_COUNT; i++ )
  {
    auto ent = entMng.CreateEntity();

    TStateComponent state;
    int inQueueRand = std::rand() % 100;
    if ( inQueueRand < inQueuePercent )
      state.v = TStateComponent::InQueue;
    else
      state.v = TStateComponent::OnSlave;
    entMng.AddComponent( ent, state );

    int inGroupRand = std::rand() % 100;
    TGroupIDComponent groupID;
    groupID.id = 0;
    if ( inGroupRand < inGroupPercent )
    {
      if ( clientsInGroup >= sizeGroup )
      {
        clientsInGroup = 0;
        lasGroupID++;
      }
      groupID.id = lasGroupID;
      entMng.AddComponent( ent, groupID );
      clientsInGroup++;
    }
    else
      entMng.AddComponent( ent, groupID );

    TIdentityComponent identity;
    identity.id = i + 1;
    entMng.AddComponent( ent, identity );
  }
}
//----------------------------------------------------------------------------------
void UpdateStateClient( int count )
{
  TIdentityComponent identity;
  identity.id = 1;
  auto ent = entMng.GetUnique( identity );
  TStateComponent stateForUpdate;
  stateForUpdate.v = TStateComponent::OnSlave;

  for ( int i = 0; i < TEST_COUNT; i++ )
    entMng.UpdateComponent( ent, stateForUpdate );
}
//----------------------------------------------------------------------------------
void UpdateIdentityClient( int count )
{
  TIdentityComponent identity;
  identity.id = 1;
  auto ent = entMng.GetUnique( identity );
  for ( int i = 0; i < count; i++ )
    entMng.UpdateComponent( ent, identity );
}
//----------------------------------------------------------------------------------
void UpdateGroupID_Client( int count )
{
  TIdentityComponent identity;
  identity.id = 1;
  auto ent = entMng.GetUnique( identity );
  TGroupIDComponent groupIDForUpdate;
  groupIDForUpdate.id = 1;

  for ( int i = 0; i < count; i++ )
    entMng.UpdateComponent( ent, groupIDForUpdate );
}
//----------------------------------------------------------------------------------
void DestroyClients()
{
  for ( int i = 0; i < CLIENT_COUNT; i++ )
  {
    TIdentityComponent identity;
    identity.id = i + 1;
    auto ent = entMng.GetUnique( identity );
    entMng.DestroyEntity( ent );
  }
}
//----------------------------------------------------------------------------------
int GetInQueueCount()
{
  TStateComponent state;
  state.v = TStateComponent::InQueue;
  auto mid = entMng.GetMultiID( state );
  return entMng.GetMultiCount( mid );
}
//----------------------------------------------------------------------------------
int GetOnSlaveCount()
{
  TStateComponent state;
  state.v = TStateComponent::OnSlave;
  auto mid = entMng.GetMultiID( state );
  return entMng.GetMultiCount( mid );
}
//----------------------------------------------------------------------------------
int GetInQueueWithoutGroupCount()
{
  TStateComponent state;
  state.v = TStateComponent::InQueue;
  TGroupIDComponent groupID;
  groupID.id = 0;
  auto mid = entMng.GetMultiID( groupID, state );
  return entMng.GetMultiCount( mid );
}
//----------------------------------------------------------------------------------
int GetOnSlaveWithoutGroupCount()
{
  TStateComponent state;
  state.v = TStateComponent::OnSlave;
  TGroupIDComponent groupID;
  groupID.id = 0;
  auto mid = entMng.GetMultiID( groupID, state );
  return entMng.GetMultiCount( mid );
}
//----------------------------------------------------------------------------------
int GetWithoutGroupCount()
{
  TGroupIDComponent groupID;
  groupID.id = 0;
  auto mid = entMng.GetMultiID( groupID );
  return entMng.GetMultiCount( mid );
}
//----------------------------------------------------------------------------------
float GetPercent( int clients )
{
  return ( 100.0f * clients ) / CLIENT_COUNT;
}
//----------------------------------------------------------------------------------
void Test( std::string testName, std::function<void( int )> func )
{
  auto start = ht_GetMSCount();

  func( TEST_COUNT );

  auto stop = ht_GetMSCount();
  auto delta = stop - start;

  auto timePerCycle = ( ( 1000.0*delta ) / ( TEST_COUNT ) );
  fmt::print( "{} : {} us\n", testName, timePerCycle );
}
//---------------------------------------------------------------------------------------
struct TDestroyHandler
{
  void Destroy( TEntityManager::EntityID id )
  {
    fmt::print( "destroy entity with id = {}\n", id );
  }
};
//---------------------------------------------------------------------------------------
int main( int argc, char* argv )
{
  std::srand( std::time( nullptr ) );

  entMng.JoinMultiToGroup<TGroupIDComponent, TStateComponent>();

#ifdef _DEBUG
  TDestroyHandler destroyHandler;
  entMng.GetCBOnDestroy()->Register( &TDestroyHandler::Destroy,&destroyHandler);
#endif

  auto start = ht_GetMSCount();
  AddClients();
  auto stop = ht_GetMSCount();
  float timePerTest = ( stop - start ) * 1000.0f / CLIENT_COUNT;
  fmt::print( "time per client creation  = {} us\n", timePerTest );

  //###
  //TGroupIDComponent groupID;
  //groupID.id = 1;
  //auto mid = entMng.GetMultiID( groupID );
  //auto entID_1 = *(entMng.GetBegin( mid ));
  //groupID.id = 2;
  //mid = entMng.GetMultiID( groupID );
  //auto entID_2 = *( entMng.GetBegin( mid ) );

  //TStateComponent stateForUpdate;
  //stateForUpdate.v = TStateComponent::OnSlave;

  //entMng.UpdateComponent( entID_1, stateForUpdate );
  //entMng.UpdateComponent( entID_2, stateForUpdate );
  //###

  Test( "Update unique", UpdateIdentityClient );
  Test( "Update group", UpdateStateClient );
  Test( "Update multi", UpdateGroupID_Client );

  auto clientCount = entMng.GetUniqueCount<TIdentityComponent>();

  auto lowGroupID = entMng.GetLow<TGroupIDComponent>();

  auto inQueueCount = GetInQueueCount();
  auto onSlaveCount = GetOnSlaveCount();

  auto inQueueWithoutGroupCount = GetInQueueWithoutGroupCount();
  auto onSlaveWithoutGroupCount = GetOnSlaveWithoutGroupCount();

  auto withoutGroupCount = GetWithoutGroupCount();

  fmt::print( "\ninQueue: all {} % / without {} %,\n\nonSlave: all {} % / without {} %,\n\n without group {} %\n", 
    GetPercent( inQueueCount ), GetPercent( inQueueWithoutGroupCount ), 
    GetPercent( onSlaveCount ), GetPercent( onSlaveWithoutGroupCount ),
    GetPercent( withoutGroupCount ) );

  start = ht_GetMSCount();
  DestroyClients();
  stop = ht_GetMSCount();
  timePerTest = ( stop - start ) * 1000.0f / CLIENT_COUNT;
  fmt::print( "time per client destroy  = {} us\n", timePerTest );

  getchar();
  return 0;
}
