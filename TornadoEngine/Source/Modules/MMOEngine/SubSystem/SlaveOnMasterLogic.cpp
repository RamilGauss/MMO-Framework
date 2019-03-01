/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SlaveOnMasterLogic.h"
#include "IScenario.h"
#include "Components.h"
#include "Base.h"
#include "ControlScenario.h"
#include "ContainerContextSc.h"

#include "EntityManager.h"
#include "Logger.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioSynchroSlave.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioDisconnectClient.h"
#include "Events.h"

using namespace nsMMOEngine;
using namespace nsMappedComponents;

TSlaveOnMasterLogic::TSlaveOnMasterLogic( TBase* p ) : TBaseMasterLogic( p )
{

}
//---------------------------------------------------------------------------------------
void TSlaveOnMasterLogic::GetDescDown( std::list<unsigned int>& sessionIDList )
{
  sessionIDList.clear();
  for ( auto sessionIDentityPair : mEntMng->GetUniqueEntities<TSlaveSessionIdentityComponent>() )
    sessionIDList.push_back( sessionIDentityPair.first.v );
}
//---------------------------------------------------------------------------------------
void TSlaveOnMasterLogic::EndLoginSlave( IScenario* pSc )
{
  auto pContext = (TContextScLoginSlave*) pSc->GetContext();
  auto sessionID = pContext->GetSessionID();

  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = sessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );
  TContextContainerComponent contextComponent;
  mEntMng->GetComponent( slaveEntity, contextComponent );

  contextComponent.v->SetSessionID( sessionID );

  //auto pContext = (TContextScLoginSlave*) pSc->GetContext();
  //// сохранить сессию Slave
  //auto sessionID = pContext->GetSessionID();
  //TContainerContextSc* pC = mMngContextSlave->FindContextBySession( sessionID );
  //pC->SetSessionID( sessionID );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::SendDown( unsigned int sessionID, char* p, int size, bool check )
{
  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = sessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );

  TContextContainerComponent contextComponent;
  mEntMng->GetComponent( slaveEntity, contextComponent );

  if ( contextComponent.v == nullptr )
    return;

  auto pFlow = &( contextComponent.v->mFlow );
  mBase->mControlSc->mFlow->SetContext( pFlow );

  mBase->SetupBP( p, size );
  mBase->mControlSc->mFlow->SendDown( mBase->mBP, check );

  //TContainerContextSc* pC = mMngContextSlave->FindContextBySession( sessionID );
  //if ( pC == nullptr )
  //  return;
  //mControlSc->mFlow->SetContext( &pC->mFlow );

  //SetupBP( p, size );
  //mControlSc->mFlow->SendDown( mBP, check );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::NeedContextLoginSlave( unsigned int sessionID )
{
  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = sessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );

  if ( slaveEntity != TEntityManager::None )
  {
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TSlaveOnMasterLogic::NeedContextLoginSlave() against try authorized.\n" );
    return;
  }
  auto pC = AddContainer();
  mBase->mControlSc->mLoginSlave->SetContext( &pC->mLoginSlave );

  slaveEntity = mEntMng->CreateEntity();
  mEntMng->AddComponent( slaveEntity, slaveSessionIdentityComponent );

  TContextContainerComponent contextComponent;
  contextComponent.v = pC;
  mEntMng->AddComponent( slaveEntity, contextComponent );

  TSlaveLoadInfoComponent loadInfoComponent;
  mEntMng->AddComponent( slaveEntity, loadInfoComponent );

  //TContainerContextSc* pC = mMngContextSlave->FindContextBySession( sessionID );
  //if ( pC )
  //{
  //  // внутренняя ошибка
  //  GetLogger( STR_NAME_MMO_ENGINE )->
  //    WriteF_time( "TMaster::NeedContextLoginSlave() against try authorized.\n" );
  //  return;
  //}
  //pC = mMngContextSlave->AddContext( sessionID );
  //mControlSc->mLoginSlave->SetContext( &pC->mLoginSlave );

  //mStatisticaClientInGroup->AddSlave( sessionID );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::NeedContextSynchroSlave( unsigned int sessionID )
{
  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = sessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );
  if ( slaveEntity == TEntityManager::None )
    return;// нет такого Slave

  TContextContainerComponent contextComponent;
  if ( mEntMng->GetComponent( slaveEntity, contextComponent ) == false )
    return;// нет контекста

  mBase->mControlSc->mSynchroSlave->SetContext( &( contextComponent.v->mSynchroSlave ) );

  //TContainerContextSc* pC = mMngContextSlave->FindContextBySession( sessionID );
  //if ( pC == nullptr )
  //  return;
  //mControlSc->mSynchroSlave->SetContext( &pC->mSynchroSlave );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::EndSynchroSlave( IScenario* pSc )
{
  auto pContextSynchroSlave = (TContextScSynchroSlave*) pSc->GetContext();
  auto slaveSessionID = pContextSynchroSlave->GetSessionID();

  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = slaveSessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );
  if ( slaveEntity == TEntityManager::None )
    return;

  TSlaveLoadInfoComponent loadComponent;
  loadComponent.v = pContextSynchroSlave->GetLoadProcent();
  mEntMng->UpdateComponent( slaveEntity, loadComponent );

  TryAddClientFromQueue( slaveEntity );

  //TContextScSynchroSlave* pContextSynchroSlave = (TContextScSynchroSlave*) pSc->GetContext();
  //auto slaveSessionID = pContextSynchroSlave->GetSessionID();
  //mMngContextSlave->SetLoadBySession( slaveSessionID, pContextSynchroSlave->GetLoadProcent() );

  //// проанализировать: если есть клиенты в очереди - проверить появилось ли место для добавления
  //// место есть если при добавлении нагрузка не станет выше предела
  //TryAddClientFromQueue( slaveSessionID );
}
//-------------------------------------------------------------------------
bool TSlaveOnMasterLogic::DisconnectSlave( unsigned int sessionID )
{
  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = sessionID;
  auto slaveEntity = mEntMng->GetUnique( slaveSessionIdentityComponent );
  if ( slaveEntity == TEntityManager::None )
    return false;// нет такого Slave

  // исключить из всего набора клиентов потерявших связь ( т.к. находятся в группах и их нельзя было удалять )
  DestroyAllLostClientsBySlaveSession( sessionID );

  std::vector<unsigned int> clientKeyVector;
  GetAllClientsBySlaveSession( sessionID, clientKeyVector );

  // отправить SuperServer список клиентов
  SendSuperServer( clientKeyVector );

  SendRecipient( sessionID );

  DestroyAllClientsBySlaveSession( sessionID );
  DestroyAllGroupsBySlaveSession( sessionID );

  // уничтожить Slave
  mEntMng->DestroyEntity( slaveEntity );

  TDisconnectDownEvent event;
  event.sessionID = sessionID;
  mBase->AddEventCopy( &event, sizeof( event ) );
  return true;

  //if ( mMngContextSlave->FindContextBySession( sessionID ) == nullptr )
  //  return false;
  //// составить список клиентов, которые сидели на Slave
  //int countClient;
  //if ( mMngContextSlave->GetCountClientKey( sessionID, countClient ) == false )
  //  return false;

  //std::vector<unsigned int> vID_client;
  //for ( int i = 0; i < countClient; i++ )
  //{
  //  unsigned int clientKey;
  //  if ( mMngContextSlave->GetClientKeyByIndex( sessionID, i, clientKey ) )
  //    vID_client.push_back( clientKey );
  //}
  //// отправить SuperServer список клиентов
  //if ( ( mSessionUpID != INVALID_HANDLE_SESSION ) && // если есть связь с SuperServer
  //  ( vID_client.size() ) )
  //{
  //  // задать какой-то контекст
  //  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey( vID_client[0] );
  //  if ( pC )
  //  {
  //    mControlSc->mDisClient->SetContext( &pC->mDisClient );
  //    pC->mDisClient.SetSessionID( mSessionUpID );
  //    mControlSc->mDisClient->DisconnectFromMaster( vID_client );
  //  }
  //}
  //for ( unsigned int clientKey : vID_client )
  //{
  //  // если это Реципиент, то уведомить о потере Клиента
  //  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey( clientKey );
  //  NotifyRecipientAboutDisconnectClient( clientKey, pC, sessionID );

  //  mMngContextClient->DeleteByKey( clientKey );
  //}
  //// !!! из групп нельзя удалять clientKey, удалять нужно группы с sessionID
  //int countGroup = mMngGroup->GetCountID();
  //for ( int i = 0; i < countGroup; i++ )
  //{
  //  // перебираем все группы и ищем с sessionID
  //  unsigned int groupID;
  //  if ( mMngGroup->GetIDByIndex( i, groupID ) )
  //  {
  //    unsigned int id_session_in_group;
  //    if ( mMngGroup->FindSessionByID( groupID, id_session_in_group ) )
  //      if ( id_session_in_group == sessionID )
  //      {
  //        mMngGroup->DeleteByID( groupID );
  //        // 
  //        TDestroyGroupEvent eventDestroyGroup;
  //        eventDestroyGroup.groupID = groupID;
  //        AddEventCopy( &eventDestroyGroup, sizeof( eventDestroyGroup ) );
  //      }
  //  }
  //}
  //// удалить Slave
  //mMngContextSlave->DeleteContextBySession( sessionID );
  //mStatisticaClientInGroup->DeleteBySlaveSession( sessionID );
  //// уведомить о разрыве
  //TDisconnectDownEvent event;
  //event.sessionID = sessionID;
  //AddEventCopy( &event, sizeof( event ) );
  //return true;
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::TryAddClientFromQueue( TEntityManager::EntityID slaveEntity )
{
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::InQueue;
  auto inQueueClientsMID = mEntMng->GetMultiID( clientStateComponent );
  if ( mEntMng->GetMultiCount( inQueueClientsMID ) == 0 )
    return;// очередь пуста

  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  mEntMng->GetComponent( slaveEntity, slaveSessionIdentityComponent );
  auto sessionID = slaveSessionIdentityComponent.v;
  // нужны все клиент из очереди
  // приоритет у клиентов из групп ( группы данного Slave )

  TryAddFromQueueGroupClients( slaveEntity, sessionID );
  TryAddFromQueue( slaveEntity, sessionID );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::DestroyAllLostClientsBySlaveSession( unsigned int sessionID )
{
  std::list<TEntityManager::EntityID> clientForDestroy;

  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::Lost;

  // найти все группы slave удалить всех потерянных клиентов
  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = sessionID;
  auto groupMID = mEntMng->GetMultiID( slaveSessionByGroupComponent );
  for ( auto groupEntity : mEntMng->GetEntities( groupMID ) )
  {
    TGroupIdentityComponent groupIdentityComponent;
    mEntMng->GetComponent( groupEntity, groupIdentityComponent );
    // найти всех потерянных клиентов по группе
    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupIdentityComponent.v;

    auto lostClientMID = mEntMng->GetMultiID( groupIDComponent, clientStateComponent );

    for ( auto clientEntity : mEntMng->GetEntities( lostClientMID ) )
      clientForDestroy.push_back( clientEntity );
  }

  for ( auto clientEntity : clientForDestroy )
    mEntMng->DestroyEntity( clientEntity );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::GetAllClientsBySlaveSession( unsigned int sessionID, std::vector<unsigned int>& clientKeyVector )
{
  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = sessionID;
  auto clientMID = mEntMng->GetMultiID( slaveSessionByClientComponent );
  for ( auto clientEntity : mEntMng->GetEntities( clientMID ) )
  {
    TClientIdentityComponent clientIdentityComponent;
    mEntMng->GetComponent( clientEntity, clientIdentityComponent );
    clientKeyVector.push_back( clientIdentityComponent.v );
  }
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::SendSuperServer( std::vector<unsigned int>& clientKeyVector )
{
  if ( mBase->mSessionUpID == INVALID_HANDLE_SESSION ) // если есть связь с SuperServer
    return;
  if ( clientKeyVector.size() == 0 )
    return;

  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKeyVector[0];
  auto clientEntity = mEntMng->GetUnique( clientIdentityComponent );
  TContextContainerComponent contextContainerComponent;
  mEntMng->GetComponent( clientEntity, contextContainerComponent );
  // задать какой-то контекст, любой кроме мастера
  TContainerContextSc* pC = contextContainerComponent.v;
  if ( pC )
  {
    mBase->mControlSc->mDisClient->SetContext( &pC->mDisClient );
    pC->mDisClient.SetSessionID( mBase->mSessionUpID );
    mBase->mControlSc->mDisClient->DisconnectFromMaster( clientKeyVector );
  }
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::DestroyAllClientsBySlaveSession( unsigned int sessionID )
{
  std::list<TEntityManager::EntityID> clientForDestroy;

  // найти все группы slave удалить всех потерянных клиентов
  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = sessionID;
  auto groupMID = mEntMng->GetMultiID( slaveSessionByGroupComponent );
  for ( auto groupEntity : mEntMng->GetEntities( groupMID ) )
  {
    TGroupIdentityComponent groupIdentityComponent;
    mEntMng->GetComponent( groupEntity, groupIdentityComponent );
    // найти всех потерянных клиентов по группе
    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupIdentityComponent.v;

    auto clientMID = mEntMng->GetMultiID( groupIDComponent );
    for ( auto clientEntity : mEntMng->GetEntities( clientMID ) )
      clientForDestroy.push_back( clientEntity );
  }

  for ( auto clientEntity : clientForDestroy )
    mEntMng->DestroyEntity( clientEntity );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::DestroyAllGroupsBySlaveSession( unsigned int sessionID )
{
  std::list<TEntityManager::EntityID> groupEntitiesForDestroyList;// for delay destroy

  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = sessionID;
  auto groupMID = mEntMng->GetMultiID( slaveSessionByGroupComponent );
  for ( auto groupEntity : mEntMng->GetEntities( groupMID ) )
  {
    TGroupIdentityComponent groupIdentityComponent;
    if ( mEntMng->GetComponent( groupEntity, groupIdentityComponent ) == false )
    {
      BL_FIX_BUG();
      continue;
    }
    groupEntitiesForDestroyList.push_back( groupEntity );
    // event
    TDestroyGroupEvent eventDestroyGroup;
    eventDestroyGroup.groupID = groupIdentityComponent.v;
    mBase->AddEventCopy( &eventDestroyGroup, sizeof( eventDestroyGroup ) );
  }

  for ( auto groupEntity : groupEntitiesForDestroyList )
    mEntMng->DestroyEntity( groupEntity );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::SendRecipient( unsigned int sessionID )
{
  // ищем всех клиентов, находящихся в состоянии перекоммутации и донором является наш Slave
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::RCM;

  TDonorSessionComponent donorSessionComponent;
  donorSessionComponent.v = sessionID;

  auto clientMID = mEntMng->GetMultiID( donorSessionComponent, clientStateComponent );
  for ( auto clientEntity : mEntMng->GetEntities( clientMID ) )
  {
    TContextContainerComponent contextContainerComponent;
    mEntMng->GetComponent( clientEntity, contextContainerComponent );

    auto pC = contextContainerComponent.v;

    mBase->mControlSc->mRcm->SetContext( &pC->mRcm );
    mBase->mControlSc->mRcm->DisconnectClient();
  }
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::TryAddFromQueueGroupClients( TEntityManager::EntityID slaveEntity, unsigned int sessionID )
{
  // логика здесь такая:
  // если клиент в очереди и находится в группе, значит он должен иметь информацию о Slave
  // иначе он только зашел и информации о Slave у него нет (SlaveSessionID == 0) или же
  // его выкинули из группы, но в таком случае информацию о Slave затёрли!
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::InQueue;
  TSlaveSessionByClientComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = sessionID;
  auto inQueueClientsMID = mEntMng->GetMultiID( slaveSessionByGroupComponent, clientStateComponent );
  if ( mEntMng->GetMultiCount( inQueueClientsMID ) == 0 )
    return;// очередь пуста

  auto& clientEntitySet = mEntMng->GetEntities( inQueueClientsMID );
  AddClientBySlave( clientEntitySet, sessionID, slaveEntity, LimitLoadPercentOnSlaveForAdd_ClientInGroup );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::TryAddFromQueue( TEntityManager::EntityID slaveEntity, unsigned int sessionID )
{
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::InQueue;
  TGroupIDComponent groupIDComponent;
  groupIDComponent.v = 0;

  auto inQueueClientsMID = mEntMng->GetMultiID( groupIDComponent, clientStateComponent );
  if ( mEntMng->GetMultiCount( inQueueClientsMID ) == 0 )
    return;// очередь пуста

  auto& clientEntitySet = mEntMng->GetEntities( inQueueClientsMID );
  AddClientBySlave( clientEntitySet, sessionID, slaveEntity, LimitLoadPercentOnSlaveForAdd );
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::AddClientBySlave( TEntityManager::TSortedEntity& clientEntitySet, unsigned int slaveSessionID,
  TEntityManager::EntityID slaveEntity, float limit )
{
  auto bit = clientEntitySet.begin();
  auto eit = clientEntitySet.end();
  while ( bit != eit )
  {
    auto futureLoad = CalculateFutureLoadOnSlave( slaveEntity, 1 );// + 1 client
    if ( futureLoad >= limit )
      return;// места нет
    auto clientEntity = *bit;
    bit++;
    AddClientBySlaveSession( clientEntity, slaveSessionID );
  }
}
//-------------------------------------------------------------------------
void TSlaveOnMasterLogic::AddClientBySlaveSession( TEntityManager::EntityID clientEntity, unsigned int slaveSessionID )
{
  TContextContainerComponent contextContainerComponent;
  mEntMng->GetComponent( clientEntity, contextContainerComponent );
  auto pC = contextContainerComponent.v;

  void* resForClient = pC->mLoginClient.GetSaveQueueDataPtr();
  int sizeResClient = pC->mLoginClient.GetSaveQueueDataSize();

  TClientStateComponent сlientStateComponent;
  сlientStateComponent.v = TClientStateComponent::Logining;
  mEntMng->UpdateComponent( clientEntity, сlientStateComponent );

  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = slaveSessionID;
  mEntMng->UpdateComponent( clientEntity, slaveSessionByClientComponent );

  TClientIdentityComponent clientIdentityComponent;
  mEntMng->GetComponent( clientEntity, clientIdentityComponent );

  auto clientKey = clientIdentityComponent.v;

  mBase->mControlSc->mLoginClient->Accept( clientKey, resForClient, sizeResClient,
      slaveSessionID, mBase->mSessionUpID );

  //// добавить для статистики
  //mMngLoginingClientsOnSlave->AddClient( slaveSessionID, clientKey );

  //// начали процесс авторизации
  //mMngContextSlave->AddClientKey( slaveSessionID, clientKey );
  //mControlSc->mLoginClient->Accept( clientKey, resForClient, sizeResClient,
  //  slaveSessionID, mSessionUpID );
}
//-------------------------------------------------------------------------
