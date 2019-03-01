/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseMasterLogic.h"
#include "Master.h"
#include "Components.h"
#include "EntityManager.h"
#include "Events.h"

using namespace nsMMOEngine;
using namespace nsMappedComponents;

TBaseMasterLogic::TBaseMasterLogic( TBase* p ) : TBaseLogic( p )
{
  // Client:
  /*
    TContextContainerComponent      C
    TClientIdentityComponent        U
    TClientSessionIdentityComponent U
    TClientStateComponent           G, M
    TGroupIDComponent               M      Join to State
    TSlaveSessionByClientComponent  M      Join to State
    TDonorSessionComponent          M      only for RCM state
  */
  // Slave
  /*
    TContextContainerComponent     C
    TSlaveSessionIdentityComponent U
    TSlaveLoadInfoComponent        С
  */
  // Group
  /*
    TGroupIdentityComponent       U
    TSlaveSessionByGroupComponent M
  */

  mEntMng->JoinMultiToGroup<TGroupIDComponent, TClientStateComponent>();
  mEntMng->JoinMultiToGroup<TClientSessionIdentityComponent, TClientStateComponent>();

  mEntMng->GetCBOnDestroy()->Register( &TBaseMasterLogic::OnDestroy, this );
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::OnDestroy( TEntityManager::EntityID entity )
{
  // уничтожить контекст 
  TContextContainerComponent contextContainerComponent;
  if ( mEntMng->GetComponent( entity, contextContainerComponent ) )
    DeleteContainer( contextContainerComponent.v );
}
//-----------------------------------------------------------------------------------
float TBaseMasterLogic::CalculateFutureLoadOnSlave( TEntityManager::EntityID slaveEntity, int addedClientCount )
{
  TSlaveLoadInfoComponent slaveLoadInfoComponent;
  mEntMng->GetComponent( slaveEntity, slaveLoadInfoComponent );

  auto load = slaveLoadInfoComponent.v;

  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  mEntMng->GetComponent( slaveEntity, slaveSessionIdentityComponent );

  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = slaveSessionIdentityComponent.v;

  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::OnSlave;

  auto onSlaveClientMID = mEntMng->GetMultiID( slaveSessionByClientComponent, clientStateComponent );
  auto onSlaveCount = mEntMng->GetMultiCount( onSlaveClientMID );

  if ( onSlaveCount == 0 )
  {
    onSlaveCount = 1;
    load = DefaultLoadPerClientIfClientCountZero;
  }

  clientStateComponent.v = TClientStateComponent::RCM;
  // все, для кого мы - реципиент
  auto rcmClientMID = mEntMng->GetMultiID( slaveSessionByClientComponent, clientStateComponent );
  auto rcmCount = mEntMng->GetMultiCount( onSlaveClientMID );

  clientStateComponent.v = TClientStateComponent::Logining;

  auto loginingClientMID = mEntMng->GetMultiID( slaveSessionByClientComponent, clientStateComponent );
  auto loginingCount = mEntMng->GetMultiCount( onSlaveClientMID );

  auto futureLoad = ( load * ( onSlaveCount + rcmCount + loginingCount + addedClientCount ) ) / onSlaveCount;
  return futureLoad;
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::GetClientWithoutGroup( unsigned int slaveSession,
  std::list<TEntityManager::EntityID>& clientEntityList )
{
  clientEntityList.clear();

  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = slaveSession;
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::OnSlave;
  auto clientOnSlaveMID = mEntMng->GetMultiID( slaveSessionByClientComponent, clientStateComponent );
  for ( auto clientEntity : mEntMng->GetEntities( clientOnSlaveMID ) )
  {
    TGroupIDComponent groupIDComponent;
    mEntMng->GetComponent( clientEntity, groupIDComponent );
    if ( groupIDComponent.v != 0 )
      continue;// не в группе
    clientEntityList.push_back( clientEntity );
  }
}
//-----------------------------------------------------------------------------------
void TBaseMasterLogic::AddError( nsMMOEngine::ErrorCode err )
{
  TErrorEvent event;
  event.code = err;
  mBase->AddEventCopy( &event, sizeof( event ) );
}
//-------------------------------------------------------------------------------------------
