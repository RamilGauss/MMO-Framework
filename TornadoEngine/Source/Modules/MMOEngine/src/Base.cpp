/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Base.h"

#include "Logger.h"
#include "SessionManager.h"
#include "DescRecvSession.h"
#include "ManagerManagerContextSc.h"
#include "ControlScenario.h"
#include "ContainerContextSc.h"

#include "ScenarioDisconnectClient.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioLoginMaster.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSendToClient.h"
#include "ScenarioSynchroSlave.h"

#include "DelegateManagerContextSc.h"
#include "Events.h"

#include "EntityManager.h"

using namespace nsMMOEngine;

//-------------------------------------------------------------------------
TBase::TBase() :
  mEntMng( new nsECSFramework::TEntityManager() ),
  mSessionManager( new TSessionManager ),
  mControlSc( new TControlScenario ),
  mContainerUp( new TContainerContextSc ),
  mMngMngContextSc( new TManagerManagerContextSc )
{
  mEntMng->Setup();// magic reflection

  GetLogger()->Register( STR_NAME_MMO_ENGINE );

  SetupScForContext( mContainerUp.get() );
  // задать контекст по-умолчанию
  SetDefualtContextForScenario();
  // регистрация на события сценариев
  RegisterOnScenarioEvent();
}
//-------------------------------------------------------------------------
TBase::~TBase()
{
  mSessionManager->GetCallbackRecv()->Unregister( this );
  mSessionManager->GetCallbackDisconnect()->Unregister( this );
  mSessionManager->GetCallbackTryConnectDown()->Unregister( this );
}
//-------------------------------------------------------------------------
void TBase::Init( IMakerTransport* pMakerTransport )
{
  if( pMakerTransport == nullptr )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->WriteF_time( "TBase::Init() pMakerTransport==NULL.\n" );
    BL_FIX_BUG();
    return;
  }
  mSessionManager->SetMakerTransport( pMakerTransport );

  mSessionManager->GetCallbackRecv()->Register( &TBase::Recv, this );
  mSessionManager->GetCallbackDisconnect()->Register( &TBase::Disconnect, this );
  mSessionManager->GetCallbackTryConnectDown()->Register( &TBase::TryConnectDown, this );
}
//-------------------------------------------------------------------------
bool TBase::Open( TDescOpen* pDesc, int count )
{
  return mSessionManager->Start( pDesc, count );
}
//-------------------------------------------------------------------------
void TBase::SetLoad( float procent )
{
  mLoadProcent = procent;
}
//-------------------------------------------------------------------------
float TBase::GetLoad()
{
  return mLoadProcent;
}
//-------------------------------------------------------------------------
void TBase::DisconnectUp()
{
  if( mSessionUpID == INVALID_HANDLE_SESSION )
    return;

  mSessionManager->CloseSession( mSessionUpID );

  mSessionUpID = INVALID_HANDLE_SESSION;
  // событие НЕ создавать, т.к. процесс синхронный
}
//-------------------------------------------------------------------------
void TBase::SendUp( char* p, int size, bool check )
{
  SetupBP( p, size );
  // устанавливать для сценария контекст не требуется
  mControlSc->mFlow->SetContext( &mContainerUp->mFlow );
  mControlSc->mFlow->SendUp( mBP, check );
}
//-------------------------------------------------------------------------
bool TBase::IsConnectUp()
{
  return mSessionManager->IsExist( mSessionUpID );
}
//-------------------------------------------------------------------------
bool TBase::IsConnect( unsigned int id )
{
  return mSessionManager->IsExist( id );
}
//-------------------------------------------------------------------------
void TBase::Recv( TDescRecvSession* pDesc )
{
  TDescRecvSession* pNewDesc = new TDescRecvSession;
  pNewDesc->Assign( pDesc );
  mRecvPacket.Add( pNewDesc );
}
//-------------------------------------------------------------------------
void TBase::Disconnect( unsigned int id )
{
  unsigned int* pID = new unsigned int( id );
  mDisconnectSessionID.Add( pID );
}
//-------------------------------------------------------------------------
void TBase::TryConnectDown( TTryConnectDown* pTryConnectDown )
{
  auto pNewTryConnectDown = new TTryConnectDown;
  pNewTryConnectDown->Assign( pTryConnectDown );
  mTryConnectDown.Add( pNewTryConnectDown );
}
//-------------------------------------------------------------------------
void TBase::HandleTryConnectDownList()
{
  TTryConnectDown** ppFirst = mTryConnectDown.GetFirst();
  while( ppFirst )
  {
    TTryConnectDown* pTryConnectDown = *ppFirst;
    // обработать через сценарий
    TTryConnectDownEvent* pEvent = new TTryConnectDownEvent();
    pEvent->sessionID = pTryConnectDown->sessionID;
    pEvent->c = pTryConnectDown->loginHash;
    pEvent->hashLogin = pEvent->c.GetPtr();
    pEvent->hashLoginSize = pEvent->c.GetSize();
    AddEventWithoutCopy<TTryConnectDownEvent>( pEvent );

    mTryConnectDown.RemoveFirst();
    ppFirst = mTryConnectDown.GetFirst();
  }
}
//-------------------------------------------------------------------------
void TBase::Work()
{
  //пробежка по ожидающим разъединения и удаление сессий
  mSessionManager->Work();
  // обработка попыток соединиться
  HandleTryConnectDownList();
  // обработать полученные данные соответствующим сценарием
  HandleListRecv();
  // отреагировать на событие дисконнект сессий
  HandleListDisconnect();
  // дать отработать всем сценариям по своим задачам 
  // порядок вызовов здесь не случаен, сначала должен быть вызов HandleListRecv
  mMngMngContextSc->Work();
  // те сценарии которые должны были быть удалены, но были активны (нельзя было явно удалять)
  DeleteContainerScenario();
  // например, Slave должен отсылать отчет по своей нагрузке CPU на Master
  WorkInherit();
}
//-------------------------------------------------------------------------
void TBase::SetTimeLiveSession( unsigned int time_ms )
{
  mSessionManager->SetTimeLiveSession( time_ms );
}
//-------------------------------------------------------------------------
void TBase::HandleListDisconnect()
{
  unsigned int** ppFirst = mDisconnectSessionID.GetFirst();
  while( ppFirst )
  {
    unsigned int ID = *(*ppFirst);
    // сообщить о разрыве связи для различных реализаций
    DisconnectInherit( ID );
    // закрыть сессию
    mSessionManager->CloseSession( ID );
    // следующий ID
    mDisconnectSessionID.RemoveFirst();
    ppFirst = mDisconnectSessionID.GetFirst();
  }
}
//-------------------------------------------------------------------------
void TBase::HandleListRecv()
{
  TDescRecvSession** ppFirst = mRecvPacket.GetFirst();
  while( ppFirst )
  {
    TDescRecvSession* pDesc = *ppFirst;
    // обработать через сценарий
    mControlSc->Recv( pDesc );
    mRecvPacket.RemoveFirst();
    ppFirst = mRecvPacket.GetFirst();
  }
}
//-------------------------------------------------------------------------
TScContextManager* TBase::AddManagerContextSc()
{
  return mMngMngContextSc->Add();
}
//-------------------------------------------------------------------------
void TBase::RemoveManagerContextSc( TScContextManager* pMCSc )
{
  mMngMngContextSc->Remove( pMCSc );
}
//-------------------------------------------------------------------------
void TBase::SetupScForContext( TContainerContextSc* pCCSc )
{
  pCCSc->SetMCSc( AddManagerContextSc() );
  pCCSc->SetMS( mSessionManager.get() );
  pCCSc->SetSE( this );

  pCCSc->mDisClient.SetSc( mControlSc->mDisClient );
  pCCSc->mFlow.SetSc( mControlSc->mFlow );
  pCCSc->mLoginClient.SetSc( mControlSc->mLoginClient );
  pCCSc->mLoginSlave.SetSc( mControlSc->mLoginSlave );
  pCCSc->mLoginMaster.SetSc( mControlSc->mLoginMaster );
  pCCSc->mRcm.SetSc( mControlSc->mRcm );
  pCCSc->mSendToClient.SetSc( mControlSc->mSendToClient );
  pCCSc->mSynchroSlave.SetSc( mControlSc->mSynchroSlave );
}
//-------------------------------------------------------------------------
void TBase::DelayDeleteContainerScenario( TContainerContextSc* pCCSc )
{
  // добавить в список на удаление
  mListDelayDeleteContainerSc.push_back( pCCSc );
}
//-------------------------------------------------------------------------
bool TBase::GetInfoSession( unsigned int sessionID, TIP_Port& ip_port )
{
  return mSessionManager->GetInfo( sessionID, ip_port );
}
//-------------------------------------------------------------------------
void TBase::RegisterNeedForLoginClient()
{
  auto p = mControlSc->mLoginClient;
  p->Register( IScenario::eContextBySession,                                 &TBase::NeedContextLoginClientBySession, this );
  p->Register( TScenarioLoginClient::eContextByClientKey,                    &TBase::NeedContextLoginClientByClientKey, this );
  p->Register( TScenarioLoginClient::eContextByClientKey_SecondCallSlave,    &TBase::NeedContextLoginClientByClientKey_SecondCallSlave, this );
  p->Register( TScenarioLoginClient::eNumInQueueByClientKey,                 &TBase::NeedNumInQueueLoginClient, this );
  p->Register( TScenarioLoginClient::eContextByMasterSessionByClientKey,     &TBase::NeedContextByMasterSessionByClientKey, this );
  p->Register( TScenarioLoginClient::eSetClientKey,                          &TBase::EventSetClientKeyLoginClient, this );
  p->Register( TScenarioLoginClient::eContextByClientSessionByClientKey,     &TBase::NeedContextLoginClientByClientSessionByKeyClient, this );
  p->Register( TScenarioLoginClient::eContextByClientSessionAfterAuthorised, &TBase::NeedContextLoginClientBySessionAfterAuthorised, this );
  p->Register( TScenarioLoginClient::eContextByClientSessionLeaveQueue,      &TBase::NeedContextLoginClientBySessionLeaveQueue, this );
}
//-------------------------------------------------------------------------
void TBase::DeleteContainerScenario()
{
  for( TContainerContextSc* pCCSc : mListDelayDeleteContainerSc )
  {
    RemoveManagerContextSc( pCCSc->GetMCSc() );
    delete pCCSc;
  }
  mListDelayDeleteContainerSc.clear();
}
//-------------------------------------------------------------------------
void TBase::SetDefualtContextForScenario()
{
  mControlSc->mDisClient->SetContext( &mContainerUp->mDisClient );
  mControlSc->mFlow->SetContext( &mContainerUp->mFlow );
  mControlSc->mLoginClient->SetContext( &mContainerUp->mLoginClient ); // client
  mControlSc->mLoginSlave->SetContext( &mContainerUp->mLoginSlave );  // slave
  mControlSc->mLoginMaster->SetContext( &mContainerUp->mLoginMaster ); // master
  mControlSc->mRcm->SetContext( &mContainerUp->mRcm );         // client
  mControlSc->mSynchroSlave->SetContext( &mContainerUp->mSynchroSlave );// slave
  mControlSc->mSendToClient->SetContext( &mContainerUp->mSendToClient );// 
}
//-------------------------------------------------------------------------
void TBase::RegisterNeedForRcmClient()
{
  auto p = mControlSc->mRcm;
  p->Register( IScenario::eContextByClientKey,                                   &TBase::NeedContextByClientKeyRcm, this );
  p->Register( TScenarioRecommutationClient::eNeedContextByClientKeyForSlave,    &TBase::NeedContextByClientForSlaveKeyRcm, this );
  p->Register( TScenarioRecommutationClient::eNeedSessionDonor,                  &TBase::NeedSlaveSessionDonorRcm, this );
  p->Register( TScenarioRecommutationClient::eEventActivate,                     &TBase::EventActivateRcm, this );
  p->Register( TScenarioRecommutationClient::eEventDisconnectClient,             &TBase::EventDisconnectClientRcm, this );
  p->Register( TScenarioRecommutationClient::eNeedContextByClientSessionForSlave,&TBase::NeedContextByClientSessionForSlaveRcm, this );
  p->Register( TScenarioRecommutationClient::eNeedContextByRequestForRecipient,  &TBase::NeedContextByRequestForRecipient, this );
  p->Register( TScenarioRecommutationClient::eEventTimeClientElapsed,            &TBase::EventTimeClientElapsedRcm, this );
}
//-------------------------------------------------------------------------
void TBase::RegisterOnScenarioEvent()
{
  mControlSc->mDisClient->Register( IScenario::eContextByClientKey,   &TBase::NeedContextDisconnectClient, this );
  RegisterNeedForLoginClient();
  RegisterNeedForRcmClient();
  mControlSc->mLoginSlave->Register(   IScenario::eContextBySession,  &TBase::NeedContextLoginSlave, this );
  mControlSc->mLoginMaster->Register(  IScenario::eContextBySession,  &TBase::NeedContextLoginMaster, this );
  mControlSc->mSendToClient->Register( IScenario::eContextByClientKey,&TBase::NeedContextSendToClient, this );
  mControlSc->mSynchroSlave->Register( IScenario::eContextBySession,  &TBase::NeedContextSynchroSlave, this );

  mControlSc->mDisClient->Register(    IScenario::eEnd, &TBase::EndDisconnectClient, this );
  mControlSc->mLoginClient->Register(  IScenario::eEnd, &TBase::EndLoginClient, this );
  mControlSc->mLoginSlave->Register(   IScenario::eEnd, &TBase::EndLoginSlave, this );
  mControlSc->mLoginMaster->Register(  IScenario::eEnd, &TBase::EndLoginMaster, this );
  mControlSc->mRcm->Register(          IScenario::eEnd, &TBase::EndRcm, this );
  mControlSc->mSynchroSlave->Register( IScenario::eEnd, &TBase::EndSynchroSlave, this );
}
//-------------------------------------------------------------------------
void TBase::SetupBP( char* p, int size )
{
  mBP.Reset();
  mBP.PushBack( p, size );
}
//-------------------------------------------------------------------------
