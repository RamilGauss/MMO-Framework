/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ClientOnMasterLogic.h"

#include "ScenarioLoginClient.h"
#include "Base.h"
#include "Events.h"
#include "ControlScenario.h"
#include "Components.h"
#include "Logger.h"
#include "SaveToFile.h"

#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSendToClient.h"
#include "ScenarioDisconnectClient.h"

using namespace nsMMOEngine;

TClientOnMasterLogic::TClientOnMasterLogic( TBase* p ) : TBaseMasterLogic( p )
{

}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::SetResultLogin( bool res, unsigned int clientSessionID,
  unsigned int clientKey, void* resForClient, int sizeResClient )
{
  // если состоит в группе, то обязан быть в кластере
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = clientSessionID;
  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
  {
    // пока ждали ответа от разработчика - клиент успел отвалиться
    return;
  }

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  mBase->mControlSc->mLoginClient->SetContext( &( pC->mLoginClient ) );
  if ( res == false )
  {
    // отказ
    mBase->mControlSc->mLoginClient->Reject( resForClient, sizeResClient );
    return;
  }

  // если такой клиент уже есть, то проверить состоит ли в группе и считается ли он потерянным
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto mayGrouppedClientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  if ( mayGrouppedClientEntity != nsECSFramework::None )
  {
    auto state = mEntMng->ViewComponent<TClientStateComponent>( mayGrouppedClientEntity )->v;
    auto groupId = mEntMng->ViewComponent<TGroupIDComponent>( mayGrouppedClientEntity )->v;
    if ( groupId == 0 || state != TClientStateComponent::LostFromGroup )
    {
      AddError( LoginClient_MasterKeyBusy );
      // отказ
      std::string sReject = "Reject login. Client was been authorized.";
      mBase->mControlSc->mLoginClient->Reject( (void*)sReject.data(), sReject.length() );
      mEntMng->DestroyEntity( clientEntity );
      return;
    }

    // слияние информации о двух клиентах
    // старого удалить, для нового обновить
    mEntMng->DestroyEntity( mayGrouppedClientEntity );// удалить первым, потому что будет коллизия по clientKey

    TGroupIDComponent groupIdComponent;
    groupIdComponent.v = groupId;
    mEntMng->SetComponent( clientEntity, groupIdComponent );
  }
  mEntMng->SetComponent( clientEntity, clientIdentityComponent );

  // клиент в группе?
  auto inGroup = mEntMng->ViewComponent<TGroupIDComponent>( clientEntity )->v != 0;
  bool resultAdd = false;
  unsigned int slaveSessionId;
  if ( inGroup )
    resultAdd = TryAddClientByGroup( clientKey, slaveSessionId );
  else
    resultAdd = TryAddClient( clientKey, slaveSessionId );
  if ( resultAdd )
    AddClientBySlaveSession( clientKey, slaveSessionId, resForClient, sizeResClient );
  else
    AddInQueue( clientKey, resForClient, sizeResClient, inGroup );


  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( clientSessionID );
  //if ( pC == nullptr )
  //  return;
  //mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
  //if ( res == false )
  //{
  //  // отказ
  //  mControlSc->mLoginClient->Reject( resForClient, sizeResClient );
  //  return;
  //}
  //// проверка на существование ключа в кластере
  //unsigned int id_session_temp;
  //if ( ( mMngContextClient->FindContextByClientKey( clientKey ) ) ||
  //  ( mMngContextClientLogining->FindSessionByClientKey( clientKey, id_session_temp ) ) )
  //{
  //  TErrorEvent event;
  //  event.code = LoginClient_MasterKeyBusy;
  //  AddEventCopy( &event, sizeof( event ) );

  //  // отказ
  //  std::string sReject = "Reject login. Client was been authorized.";
  //  mControlSc->mLoginClient->Reject( (void*) sReject.data(), sReject.length() );
  //  return;
  //}
  //// связка сессии и ключа клиента
  //mMngContextClientLogining->AddKeyBySession( clientSessionID, clientKey );
  //// решить на какой Slave закинуть клиента
  //// для Группы задан Slave, значит на него и перекидывать, но возможно он перегружен
  //// навряд ли он перегружен, иначе, он самый не нагруженный, потому как только бы на него и пихали клиентов
  //// а это противоречие, значит пихаем в него

  //// клиент в группе?
  //bool resAdd = false;
  //unsigned int slaveSessionID;
  //unsigned int groupID;
  //bool inGroup = mMngGroup->FindIDByClientKey( clientKey, groupID );
  //if ( inGroup )
  //  resAdd = TryAddClientByGroup( clientKey, groupID, slaveSessionID );
  //else
  //  resAdd = TryAddClient( clientKey, slaveSessionID );
  //if ( resAdd )
  //  AddClientBySlaveSession( clientKey, slaveSessionID, resForClient, sizeResClient );
  //else
  //  AddInQueue( clientKey, resForClient, sizeResClient, inGroup );
}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID )
{
  // после авторизации Клиент получил информацию о Slave. Далее он пришлет Мастеру
  // квитанцию об этом. Значит сессию Мастер должен найти.
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;
  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
  {
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TMaster::NeedContextLoginClientBySessionAfterAuthorised() context not found.\n" );
    mBase->mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }
  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  // назначить контекст
  mBase->mControlSc->mLoginClient->SetContext( &pC->mLoginClient );

  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( sessionID );
  //if ( pC == nullptr )
  //{
  //  // внутренняя ошибка
  //  GetLogger( STR_NAME_MMO_ENGINE )->
  //    WriteF_time( "TMaster::NeedContextLoginClientBySessionAfterAuthorised() context not found.\n" );
  //  mControlSc->mLoginClient->SetContext( nullptr );
  //  return;
  //}
  //// назначить контекст
  //mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::EndLoginClient( IScenario* pSc )
{
  // получить контекст
  TContextScLoginClient* pContextLoginClient = (TContextScLoginClient*)pSc->GetContext();
  // переместить информацию из mMngContextClientLogining в mMngContextClient
  // либо по сессии 
  unsigned int clientSessionID = pContextLoginClient->GetID_SessionClientMaster();
  // ID Клиента
  unsigned int clientKey = pContextLoginClient->GetClientKey();
  // найти сессию Slave
  unsigned int slaveSessionID = pContextLoginClient->GetID_SessionMasterSlave();

  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );

  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::OnSlave;
  mEntMng->SetComponent( clientEntity, clientStateComponent );

  auto groupId = mEntMng->ViewComponent<TGroupIDComponent>( clientEntity )->v;
  auto pContainer = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;

  // либо время вышло, либо отказали в авторизации
  if ( pContextLoginClient->IsReject() )
  {
    std::vector<unsigned int> vecID_Client;
    vecID_Client.push_back( pContextLoginClient->GetClientKey() );
    mBase->mControlSc->mDisClient->SetContext( &pContainer->mDisClient );
    pContainer->mDisClient.SetSessionID( mBase->mSessionUpID );
    mBase->mControlSc->mDisClient->DisconnectFromMaster( vecID_Client );

    // удалить из списка авторизующихся
    if ( groupId == 0 )
      mEntMng->DestroyEntity( clientEntity );
    else
    {
      clientStateComponent.v = TClientStateComponent::LostFromGroup;
      mEntMng->SetComponent( clientEntity, clientStateComponent );
    }
    return;
  }
  // тут если авторизация закончилась удачно
  if ( pContextLoginClient->IsAccept() )
  {
    auto pLoginEvent = new TLoginEvent();
    pLoginEvent->clientKey = clientKey;
    mBase->AddEventWithoutCopy( pLoginEvent );
  }


  //// получить контекст
  //TContextScLoginClient* pContextLoginClient = (TContextScLoginClient*)pSc->GetContext();
  //// переместить информацию из mMngContextClientLogining в mMngContextClient
  //// либо по сессии 
  //unsigned int clientSessionID = pContextLoginClient->GetID_SessionClientMaster();
  //// ID Клиента
  //unsigned int clientKey = pContextLoginClient->GetClientKey();
  //// найти сессию Slave
  //unsigned int slaveSessionID = pContextLoginClient->GetID_SessionMasterSlave();
  //mMngLoginingClientsOnSlave->RemoveClient( clientKey );

  //TContainerContextSc* pContainer =
  //  mMngContextClientLogining->FindContextBySession( clientSessionID );
  //// либо время вышло, либо отказали в авторизации
  //if ( pContextLoginClient->IsReject() )
  //{
  //  // удалить из списка авторизующихся
  //  mMngContextClientLogining->DeleteBySession( clientSessionID );
  //  if ( pContainer )
  //  {
  //    std::vector<unsigned int> vecID_Client;
  //    vecID_Client.push_back( pContextLoginClient->GetClientKey() );
  //    mControlSc->mDisClient->SetContext( &pContainer->mDisClient );
  //    pContainer->mDisClient.SetSessionID( mSessionUpID );
  //    mControlSc->mDisClient->DisconnectFromMaster( vecID_Client );
  //  }
  //  return;
  //}
  //// тут если авторизация закончилась удачно
  //if ( pContextLoginClient->IsAccept() )
  //{
  //  // удалить из списка авторизующихся
  //  mMngContextClientLogining->UnlinkContextBySession( clientSessionID );
  //  mMngContextClient->EntrustContext( clientKey, slaveSessionID, pContainer );

  //  // если Клиент числится в группе, то добавить в статистику
  //  unsigned int fakeGroupID;
  //  if ( mMngGroup->FindIDByClientKey( clientKey, fakeGroupID ) )
  //    mStatisticaClientInGroup->AddBySlaveSessionClientKey( slaveSessionID, clientKey );

  //  auto pLoginEvent = new TLoginEvent();
  //  pLoginEvent->clientKey = clientKey;
  //  AddEventWithoutCopy( pLoginEvent );
  //}
}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID )
{
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;
  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
  {
    mBase->mControlSc->mLoginClient->SetContext( nullptr );// сам вышел из очереди, ну и хер с ним
    return;
  }

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  mBase->mControlSc->mLoginClient->SetContext( &pC->mLoginClient );// назначить контекст

  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( sessionID );
  //if ( pC )
  //  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );// назначить контекст
  //else
  //  mControlSc->mLoginClient->SetContext( nullptr );// сам вышел из очереди, ну и хер с ним
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientBySession( unsigned int sessionID )
{
  // если это повторная авторизация, то Begin по данному контексту клиента
  // вернет false и в сценарии обработка пакета не продолжится
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;
  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity != nsECSFramework::None )
  {
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TMaster::NeedContextLoginClientBySession() against try authorized.\n" );
    mBase->mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }

  //  создать clientEntity
  clientEntity = mEntMng->CreateEntity();
  mEntMng->SetComponent( clientEntity, clientSessionIdentityComponent );

  auto pC = AddContainer();
  TContextContainerComponent contextContainerComponent;
  contextContainerComponent.v = pC;
  mEntMng->SetComponent( clientEntity, contextContainerComponent );
  // назначить контекст
  mBase->mControlSc->mLoginClient->SetContext( &pC->mLoginClient );

  TClientStateComponent clientStateComponent;
  mEntMng->SetComponent( clientEntity, clientStateComponent );

  TGroupIDComponent groupIDComponent;
  mEntMng->SetComponent( clientEntity, groupIDComponent );

  //// если это повторная авторизация, то Begin по данному контексту клиента
  //// вернет false и в сценарии обработка пакета не продолжится
  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( sessionID );
  //if ( pC )
  //{
  //  // внутренняя ошибка
  //  GetLogger( STR_NAME_MMO_ENGINE )->
  //    WriteF_time( "TMaster::NeedContextLoginClientBySession() against try authorized.\n" );
  //  mControlSc->mLoginClient->SetContext( nullptr );
  //  return;
  //}
  //else
  //{
  //  pC = mMngContextClientLogining->AddContext( sessionID );
  //}
  //// назначить контекст
  //mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientByClientKey( unsigned int clientKey )
{
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
    return;

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  mBase->mControlSc->mLoginClient->SetContext( &( pC->mLoginClient ) );
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedNumInQueueLoginClient( unsigned int sessionID )
{
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;

  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
  {
    BL_FIX_BUG();
    return;
  }

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  auto clientKey = mEntMng->ViewComponent<TClientIdentityComponent>( clientEntity )->v;

  int index;
  if ( mSetClientKeyInQueue->GetIndex( clientKey, index ) == false )
  {
    BL_FIX_BUG();
    return;
  }
  pC->mLoginClient.SetNumInQueue( index + 1 );

  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( sessionID );
  //if ( pC == nullptr )
  //{
  //  BL_FIX_BUG();
  //  return;
  //}
  //unsigned int clientKey;
  //if ( mMngContextClientLogining->FindClientKeyBySession( sessionID, clientKey ) == false )
  //{
  //  BL_FIX_BUG();
  //  return;
  //}
  //int index;
  //if ( mSetClientKeyInQueue->GetIndex( clientKey, index ) == false )
  //{
  //  BL_FIX_BUG();
  //  return;
  //}
  //pC->mLoginClient.SetNumInQueue( index + 1 );
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextDisconnectClient( unsigned int clientKey )
{
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
    return;

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  mBase->mControlSc->mDisClient->SetContext( &( pC->mDisClient ) );
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextSendToClient( unsigned int clientKey )
{
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
    return;

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  mBase->mControlSc->mSendToClient->SetContext( &( pC->mSendToClient ) );
}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::DisconnectClientWait( unsigned int sessionID )
{
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;
  auto clientEntity = mEntMng->GetByUnique( clientSessionIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
    return false;

  auto pC = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  auto clientKey = mEntMng->ViewComponent<TClientIdentityComponent>( clientEntity )->v;

  // возможно клиент в очереди, удалим на всякий случай
  mSetClientKeyInQueue->RemoveByKey( clientKey );
  // закончить с Клиентом на Slave
  mBase->mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
  // в EndLoginClient в случае не принятия клиента будет рассылка уведомления выше
  pC->mLoginClient.Reject();
  // в конце авторизации, если не будет принятия, то соединению выше передан пакет о уничтожении клиента
  mBase->mControlSc->mLoginClient->DisconnectFromMaster();

  auto groupId = mEntMng->ViewComponent<TGroupIDComponent>( clientEntity )->v;
  if ( groupId != 0 )
  {
    TClientStateComponent clientStateComponent;
    clientStateComponent.v = TClientStateComponent::LostFromGroup;
    mEntMng->SetComponent( clientEntity, clientStateComponent );
  }
  else
    mEntMng->DestroyEntity( clientEntity );
  return true;

  //TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession( sessionID );
  //if ( pC == nullptr )
  //  return false;

  //unsigned int clientKey;
  //if ( mMngContextClientLogining->FindClientKeyBySession( sessionID, clientKey ) )
  //{
  //  // возможно клиент в очереди, удалим на всякий случай
  //  mSetClientKeyInQueue->RemoveByKey( clientKey );
  //  // закончить с Клиентом на Slave
  //  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
  //  // в EndLoginClient в случае не принятия клиента будет рассылка уведомления выше
  //  pC->mLoginClient.Reject();
  //  // в конце авторизации, если не будет принятия, то соединению выше передан пакет о уничтожении клиента
  //  mControlSc->mLoginClient->DisconnectFromMaster();
  //}

  //mMngContextClientLogining->DeleteBySession( sessionID );
  //return true;
}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::TryAddClient( unsigned int clientKey, unsigned int& slaveSessionId )
{
  unsigned char load_procent = 0;
  if ( FindMinimumLoad( slaveSessionId, load_procent ) == false )
  {
    // генерация ошибки
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TMaster::SetResultLogin() count slave = 0.\n" );
    BL_FIX_BUG();
    return false;
  }
  unsigned char limitLoadProcent = GetLimitLoadProcentByKey( clientKey );
  if ( load_procent < limitLoadProcent )
    return true;
  return false;
}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::TryAddClientByGroup( unsigned int clientKey, unsigned int& slaveSessionId )
{
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  auto groupId = mEntMng->ViewComponent<TGroupIDComponent>( clientEntity )->v;

  TGroupIdentityComponent groupIdentityComponent;
  groupIdentityComponent.v = groupId;
  auto groupEntity = mEntMng->GetByUnique( groupIdentityComponent );
  slaveSessionId = mEntMng->ViewComponent<TSlaveSessionByGroupComponent>( groupEntity )->v;

  TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
  slaveSessionIdentityComponent.v = slaveSessionId;
  auto slaveEntity = mEntMng->GetByUnique( slaveSessionIdentityComponent );
  auto load_procent = mEntMng->ViewComponent<TSlaveLoadInfoComponent>( slaveEntity )->v;

  unsigned char limitLoadProcent = GetLimitLoadProcentByKey( clientKey );
  if ( load_procent < limitLoadProcent )
    return true;
  return false;
}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::AddClientBySlaveSession( unsigned int clientKey, unsigned int slaveSessionID,
  void* resForClient, int sizeResClient )
{
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );

  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = slaveSessionID;
  mEntMng->SetComponent( clientEntity, slaveSessionByClientComponent );

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
void TClientOnMasterLogic::AddInQueue( unsigned int clientKey, void* resForClient, int sizeResClient, bool inGroup )
{
  auto type = inGroup ? TSetOrderElement::InGroup : TSetOrderElement::Simple;
  // в очередь на ожидание свободного места
  mSetClientKeyInQueue->PushBack( clientKey, type );
  int index;
  if ( mSetClientKeyInQueue->GetIndex( clientKey, index ) )
    mBase->mControlSc->mLoginClient->Queue( index + 1, resForClient, sizeResClient );
}
//-------------------------------------------------------------------------
