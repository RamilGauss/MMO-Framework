/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientOnMasterLogic.h"

#include "ScenarioLoginClient.h"
#include "Base.h"
#include "ControlScenario.h"
#include "Components.h"
#include "Logger.h"
#include "SaveToFile.h"

using namespace nsMMOEngine;
using namespace nsMappedComponents;

TClientOnMasterLogic::TClientOnMasterLogic( TBase* p ) : TBaseMasterLogic( p )
{

}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::SetResultLogin( bool res, unsigned int clientSessionID,
  unsigned int clientKey, void* resForClient, int sizeResClient )
{
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = clientSessionID;
  auto clientEntity = mEntMng->GetUnique( clientSessionIdentityComponent );
  if ( clientEntity == TEntityManager::None )
    return;

  TContextContainerComponent contextContainerComponent;
  mEntMng->GetComponent( clientEntity, contextContainerComponent );
  auto pC = contextContainerComponent.v;

  mBase->mControlSc->mLoginClient->SetContext( &( pC->mLoginClient ) );
  if ( res == false )
  {
    // отказ
    mBase->mControlSc->mLoginClient->Reject( resForClient, sizeResClient );
    return;
  }
  // проверка на существование ключа в кластере
  TClientIdentityComponent clientIdentityComponent;
  clientIdentityComponent.v = clientKey;
  clientEntity = mEntMng->GetUnique( clientIdentityComponent );
  if ( clientEntity != TEntityManager::None )
  {
    AddError( LoginClient_MasterKeyBusy );
    // отказ
    std::string sReject = "Reject login. Client was been authorized.";
    mBase->mControlSc->mLoginClient->Reject( (void*) sReject.data(), sReject.length() );
    return;
  }

  mEntMng->AddComponent( clientEntity, clientIdentityComponent );

  // клиент в группе?
  TGroupIDComponent groupIDComponent;
  mEntMng->GetComponent( clientEntity, groupIDComponent );
  if ( groupIDComponent.v == 0 )
    TryAddClient( clientKey );
  else
    TryAddClientByGroup( clientKey );
  //if ( resAdd )
  //  AddClientBySlaveSession( clientKey, slaveSessionID, resForClient, sizeResClient );
  //else
  //  AddInQueue( clientKey, resForClient, sizeResClient );


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

}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::EndLoginClient( IScenario* pSc )
{

}
//-------------------------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID )
{

}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextLoginClientBySession( unsigned int sessionID )
{
  // если это повторная авторизация, то Begin по данному контексту клиента
  // вернет false и в сценарии обработка пакета не продолжится
  TClientSessionIdentityComponent clientSessionIdentityComponent;
  clientSessionIdentityComponent.v = sessionID;
  auto clientEntity = mEntMng->GetUnique( clientSessionIdentityComponent );
  if ( clientEntity != TEntityManager::None )
  {
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TMaster::NeedContextLoginClientBySession() against try authorized.\n" );
    mBase->mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }

  //  создать clientEntity
  clientEntity = mEntMng->CreateEntity();
  mEntMng->AddComponent( clientEntity, clientSessionIdentityComponent );

  auto pC = AddContainer();
  TContextContainerComponent contextContainerComponent;
  contextContainerComponent.v = pC;
  mEntMng->AddComponent( clientEntity, contextContainerComponent );
  // назначить контекст
  mBase->mControlSc->mLoginClient->SetContext( &pC->mLoginClient );

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

}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedNumInQueueLoginClient( unsigned int sessionID )
{

}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextDisconnectClient( unsigned int clientKey )
{

}
//-------------------------------------------------------------------------
void TClientOnMasterLogic::NeedContextSendToClient( unsigned int clientKey )
{

}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::DisconnectClientWait( unsigned int sessionID )
{
  return false;
}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::TryAddClient( unsigned int clientKey )
{
  //unsigned char load_procent;
  //if ( mMngContextSlave->FindMinimumLoad( slaveSessionID, load_procent ) == false )
  //{
  //  // генерация ошибки
  //  GetLogger( STR_NAME_MMO_ENGINE )->
  //    WriteF_time( "TMaster::SetResultLogin() count slave = 0.\n" );
  //  BL_FIX_BUG();
  //  return false;
  //}
  //unsigned char limitLoadProcent = GetLimitLoadProcentByKey( clientKey );
  //if ( load_procent < limitLoadProcent )
  //  return true;
  return false;
}
//-------------------------------------------------------------------------
bool TClientOnMasterLogic::TryAddClientByGroup( unsigned int clientKey )
{
  //if ( mMngGroup->FindSessionByID( groupID, slaveSessionID ) == false )
  //{
  //  BL_FIX_BUG();
  //  return false;
  //}
  //unsigned char load_procent;
  //if ( mMngContextSlave->FindLoadBySession( slaveSessionID, load_procent ) == false )
  //{
  //  BL_FIX_BUG();
  //  return false;
  //}
  //if ( load_procent < GetLimitLoadProcentByKey( clientKey ) )
  //  return true;
  return false;
}
//-------------------------------------------------------------------------
