/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Slave.h"

#include "Logger.h"
#include "ControlScenario.h"
#include "SessionManager.h"
#include "Events.h"

#include "ManagerContextClient_slave.h"
#include "ContainerContextSc.h"

#include "ScenarioDisconnectClient.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSendToClient.h"
#include "ScenarioSynchroSlave.h"
#include "DescRequestConnectForRecipient.h"

using namespace nsMMOEngine;
using namespace std;

TSlave::TSlave()
{
  mMngContextClient.reset( new TManagerContextClient_slave( this ) );
  mMngContextClientSlaveRecipient.reset( new TManagerContextClient_slave( this ) );

  mTimeNeedSendSynchro = 0;
  mControlSc->mLoginClient->SetBehavior( TScenarioLoginClient::eSlave );
  mControlSc->mRcm->SetBehavior( TScenarioRecommutationClient::eSlave );
}
//-------------------------------------------------------------------------
TSlave::~TSlave()
{

}
//-------------------------------------------------------------------------
void TSlave::SaveContext( unsigned int sessionID, void* data, int size )
{
  TContainerContextSc* pC = mMngContextClient->FindContextBySession( sessionID );
  if( pC && pC->IsRcmActive() ) // передать контекст в сценарий
  {
    mControlSc->mRcm->SetContext( &pC->mRcm );
    mControlSc->mRcm->SaveContext( data, size );// это уже вызов функции сценария
  }
}
//-------------------------------------------------------------------------
bool TSlave::FindClientKeyBySession( unsigned int sessionID, unsigned int &id )
{
  return mMngContextClient->FindKeyBySession( sessionID, id );
}
//-------------------------------------------------------------------------
bool TSlave::FindSessionByClientKey( unsigned int id, unsigned int& sessionID )
{
  return mMngContextClient->FindSessionByKey( id, sessionID );
}
//-------------------------------------------------------------------------
void TSlave::DisconnectInherit( unsigned int sessionID )
{
  // либо обрыв связи с верхним соединением - тогда мы одни, нерабочее состояние
  if( sessionID == mSessionUpID )
  {
    DisconnectAllClient();// распустить всех клиентов
    mSessionUpID = INVALID_HANDLE_SESSION;

    TDisconnectUpEvent event;
    event.sessionID = sessionID;
    AddEventCopy( &event, sizeof( event ) );
    return;
  }
  // либо обрыв с одним из клиентов - уничтожить клиента
  // физический обрыв или сценарий сам оборвал
  unsigned int clientKey;
  if( mMngContextClient->FindKeyBySession( sessionID, clientKey ) == false )
    return;

  TContainerContextSc* pC = mMngContextClient->FindContextBySession( sessionID );
  if( pC == nullptr )
  {
    BL_FIX_BUG();
    return;
  }
  // если есть активный сценарий, то завершить и начать сценарий дисконнекта
  mControlSc->mDisClient->SetContext( &pC->mDisClient );
  pC->mDisClient.SetSessionID( mSessionUpID );
  mControlSc->mDisClient->DisconnectFromSlave( clientKey );// отправка Мастеру информации о потере связи с Клиентом

  mMngContextClient->DeleteByKey( clientKey );

  if( pC->IsLoginClientActive() == false )
  {
    TDisconnectDownEvent event;
    event.sessionID = sessionID;
    AddEventCopy( &event, sizeof( event ) );
  }
}
//-------------------------------------------------------------------------
void TSlave::GetDescDown( std::list<unsigned int>& sessionID_List )
{
  sessionID_List.clear();
  auto count = mMngContextClient->GetCountSession();
  for( int index = 0 ; index < count ; index++ )
  {
    unsigned int sessionID;
    if ( mMngContextClient->GetSessionByIndex( index, sessionID ) == false )
      continue;
    sessionID_List.push_back( sessionID );
  }
}
//-------------------------------------------------------------------------
void TSlave::ConnectUp( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet )
{
  // если сессия жива, то значит либо соединились, либо соединяемся
  if( mSessionUpID != INVALID_HANDLE_SESSION )
    return;

  mControlSc->mLoginSlave->ConnectToMaster( ip_port, login, password, subNet );
}
//-------------------------------------------------------------------------
void TSlave::WorkInherit()
{
  // пока нет связи с Мастером - синхронизацию не проводить
  if( IsConnectUp() == false )
    return;
  //-------------------------------------------------------
  unsigned int now_ms = ht_GetMSCount();
  if( mTimeNeedSendSynchro < now_ms )
  {
    mControlSc->mSynchroSlave->SendSynchro( mLoadProcent );
    mTimeNeedSendSynchro = now_ms + eDeltaSynchro;
  }
}
//-------------------------------------------------------------------------
void TSlave::DisconnectAllClient()
{
  unsigned int id;
  // перечисляем всех клиентов и узнаем их ключи
  while( mMngContextClient->GetFirstKey( id ) )
  {
    // по ключу ищем сессию
    unsigned int sessionID;
    if( mMngContextClient->FindSessionByKey( id, sessionID ) )
    {
      // закрываем сессию
      mSessionManager->CloseSession( sessionID );
      // удаляем по ключу
      mMngContextClient->DeleteByKey( id );
      // генерация события о дисконнекте
      TDisconnectDownEvent event;
      event.sessionID = sessionID;
      AddEventCopy( &event, sizeof( event ) );
    }
  }
}
//-------------------------------------------------------------------------
void TSlave::SendDown( unsigned int sessionID, char* p, int size, bool check )
{
  TContainerContextSc* pC = mMngContextClient->FindContextBySession( sessionID );
  if( pC )
  {
    mControlSc->mFlow->SetContext( &pC->mFlow );

    SetupBP( p, size );
    mControlSc->mFlow->SendDown( mBP, check );
  }
}
//-------------------------------------------------------------------------
void TSlave::EndLoginClient( IScenario* pSc )
{
  TContextScLoginClient* pContext = (TContextScLoginClient*) pSc->GetContext();
  if( pContext->IsAccept() )
  {
    // сохранить сессию Клиента
    TContainerContextSc* pC = mMngContextClient->FindContextByKey( pContext->GetClientKey() );
    BL_ASSERT( pC );
    pC->SetSessionID( pContext->GetID_SessionClientSlave() );
    return;
  }

  mMngContextClient->DeleteByKey( pContext->GetClientKey() );
}
//-------------------------------------------------------------------------
void TSlave::EndLoginSlave( IScenario* pSc )
{
  // взять по этому контексту, задать всем контекстам
  mSessionUpID = pSc->GetContext()->GetSessionID();
  mContainerUp->SetSessionID( mSessionUpID );

  if( IsConnectUp() )
  {
    // вход в кластер закончен
    TConnectUpEvent event;
    event.sessionID = mSessionUpID;
    AddEventCopy( &event, sizeof( event ) );
  }
}
//-------------------------------------------------------------------------
void TSlave::EndRcm( IScenario* pSc )
{
  TContextScRecommutationClient* pContext = (TContextScRecommutationClient*) pSc->GetContext();
  unsigned int key = pContext->GetClientKey();
  if( pContext->IsDonor() )
  {
    // просто удалить  
    mMngContextClient->DeleteByKey( key );
    return;
  }
  if( pContext->IsRecipient() == false )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TSlave::EndRcm() Undef state.\n" );
    BL_FIX_BUG();
    return;
  }
  // переместить из временного хранилища в постоянное
  mMngContextClientSlaveRecipient->DeleteByKey( key );

  unsigned int sessionID = pContext->GetID_SessionClientSlave();
  TContainerContextSc* pC = mMngContextClient->AddContextByKey( key );
  mMngContextClient->AddSessionByKey( key, sessionID );
  // для всех контекстов назначить связь вниз
  pC->SetSessionID( sessionID );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextSendToClient( unsigned int clientKey )
{
  // запрос на отправку какому-то клиенту
  TContainerContextSc* pContext = mMngContextClient->FindContextByKey( clientKey );
  if( pContext )
    mControlSc->mSendToClient->SetContext( &pContext->mSendToClient );
  else
    mControlSc->mSendToClient->SetContext( nullptr );
}
//-------------------------------------------------------------------------
void TSlave::SendByClientKey( list<unsigned int>& lKey, char* p, int size )
{
  SetupBP( p, size );
  mControlSc->mSendToClient->SendFromSlave( lKey, mBP );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextLoginClientByClientSessionByKeyClient( unsigned int id_session_client, unsigned int clientKey )
{
  TContainerContextSc* pC = mMngContextClient->FindContextByKey( clientKey );
  if( pC == nullptr )
  {
    mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }
  // надо проверить, вдруг клиент решил взять не свой ключ и ключ совпал
  unsigned int id_session_exist;
  if( mMngContextClient->FindSessionByKey( clientKey, id_session_exist ) == false )
  {
    mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }
  // сессии не должно быть, он ведь впервые соединяется
  if( id_session_exist != INVALID_HANDLE_SESSION )
  {
    mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }

  mMngContextClient->AddSessionByKey( clientKey, id_session_client );
  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextLoginClientByClientKey( unsigned int clientKey )
{
  TContainerContextSc* pC = mMngContextClient->FindContextByKey( clientKey );
  if( pC == nullptr )
    pC = mMngContextClient->AddContextByKey( clientKey );

  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextLoginClientByClientKey_SecondCallSlave( unsigned int clientKey )
{
  TContainerContextSc* pC = mMngContextClient->FindContextByKey( clientKey );
  if( pC == nullptr )
  {
    mControlSc->mLoginClient->SetContext( nullptr );
    return;
  }
  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByClientForSlaveKeyRcm( unsigned int key, bool donor )
{
  if( donor )
  {
    TContainerContextSc* pC = mMngContextClient->FindContextByKey( key );
    if( pC )
    {
      // настроить сессии наверх и вниз
      pC->mRcm.SetID_SessionClientSlave( pC->GetSessionID() );
      pC->mRcm.SetID_SessionMasterSlave( mSessionUpID );

      mControlSc->mRcm->SetContext( &pC->mRcm );
    }
    else
      mControlSc->mRcm->SetContext( nullptr );
  }
  else
  {
    TContainerContextSc* pC = mMngContextClientSlaveRecipient->FindContextByKey( key );
    if( pC == nullptr )
      pC = mMngContextClientSlaveRecipient->AddContextByKey( key );

    // верх и низ сессия назначит сам сценарий
    mControlSc->mRcm->SetContext( &pC->mRcm );
  }
}
//-------------------------------------------------------------------------
void TSlave::EventDisconnectClientRcm( unsigned int key )
{
  // для подстраховки и там и там удалить
  TContainerContextSc* pC = mMngContextClientSlaveRecipient->FindContextByKey( key );
  if( pC )
    mMngContextClientSlaveRecipient->DeleteByKey( key );
  else
  {
    // если Клиент исхитрился и вместо отсылки "CheckInfoRecipient, ready to disconnect"
    // просто разорвал соединение - удалить из системы
    pC = mMngContextClient->FindContextByKey( key );
    if( pC == nullptr )
      return;
    mMngContextClient->DeleteByKey( key );
  }
  unsigned int sessionID = pC->mRcm.GetID_SessionClientSlave();
  mSessionManager->CloseSession( sessionID );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByClientSessionForSlaveRcm( unsigned sessionID, bool donor )
{
  TContainerContextSc* pC = nullptr;
  if( donor )
    pC = mMngContextClient->FindContextBySession( sessionID );
  else
    pC = mMngContextClientSlaveRecipient->FindContextBySession( sessionID );
  //----------
  if( pC )
    mControlSc->mRcm->SetContext( &pC->mRcm );
  else
    mControlSc->mRcm->SetContext( nullptr );
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByRequestForRecipient( TDescRequestConnectForRecipient* pDescRequest )
{
  TContainerContextSc*pC = mMngContextClientSlaveRecipient->FindContextByKey( pDescRequest->key );
  if( pC )
  {
    // проверка числа
    if( pC->mRcm.GetRandomNum() == pDescRequest->random_num )
    {
      mControlSc->mRcm->SetContext( &pC->mRcm );
      // сохранить сессию
      mMngContextClientSlaveRecipient->
        AddSessionByKey( pDescRequest->key, pDescRequest->sessionID );
      // запомнить откуда Клиент вообще
      pC->SetSessionID( pDescRequest->sessionID );
      return;
    }
  }
  mControlSc->mRcm->SetContext( nullptr );
}
//-------------------------------------------------------------------------
void TSlave::EventTimeClientElapsedRcm( unsigned int clientKey )
{
  // Донор или Реципиент
  TContainerContextSc* pC = mMngContextClient->FindContextByKey( clientKey );
  if( pC )
  {
    // Донор
    mMngContextClient->DeleteByKey( clientKey );
  }
  else
  {
    pC = mMngContextClientSlaveRecipient->FindContextByKey( clientKey );
    if( pC == nullptr )
      return;
    // реципиент
    mMngContextClientSlaveRecipient->DeleteByKey( clientKey );
  }
  // если есть активный сценарий, то завершить и начать сценарий дисконнекта
  mControlSc->mDisClient->SetContext( &pC->mDisClient );
  pC->mDisClient.SetSessionID( mSessionUpID );
  mControlSc->mDisClient->DisconnectFromSlave( clientKey );
}
//-------------------------------------------------------------------------
