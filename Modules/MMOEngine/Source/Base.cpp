/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Base.h"
#include <boost/foreach.hpp>

#include "Logger.h"
#include "ManagerSession.h"
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

using namespace std;
using namespace nsMMOEngine;

//-------------------------------------------------------------------------
TBase::TBase():
mManagerSession(new TManagerSession),
mControlSc(new TControlScenario),
mContainerUp(new TContainerContextSc),
mMngMngContextSc(new TManagerManagerContextSc)
{
  TDelegateManagerContextSc::SetBase(this);
  mLoadProcent     = 0;

  flgConnectUp  = false;
  mID_SessionUp = INVALID_HANDLE_SESSION;

  SetupScForContext(mContainerUp.get());
  // задать контекст по-умолчанию
  SetDefualtContextForScenario();
  // регистрация на события сценариев
  RegisterOnScenarioEvent();
}
//-------------------------------------------------------------------------
TBase::~TBase()
{
  mManagerSession->GetCallbackRecv()->Unregister(this);
  mManagerSession->GetCallbackDisconnect()->Unregister(this);
}
//-------------------------------------------------------------------------
void TBase::Init(IMakerTransport* pMakerTransport)
{
  if(pMakerTransport==NULL)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->WriteF_time("TBase::Init() pMakerTransport==NULL.\n");
    BL_FIX_BUG();
    return;
  }
  mManagerSession->SetMakerTransport(pMakerTransport);
  mManagerSession->GetCallbackRecv()->Register(&TBase::Recv, this);
  mManagerSession->GetCallbackDisconnect()->Register(&TBase::Disconnect, this);
}
//-------------------------------------------------------------------------
bool TBase::Open(TDescOpen* pDesc, int count)
{
  return mManagerSession->Start(pDesc, count);
}
//-------------------------------------------------------------------------
void TBase::SetLoad(int procent)
{
  mLoadProcent = procent;
}
//-------------------------------------------------------------------------
void TBase::DisconnectUp()
{
	if(mID_SessionUp==INVALID_HANDLE_SESSION)
		return;
	
	mManagerSession->CloseSession(mID_SessionUp);
	
	mID_SessionUp = INVALID_HANDLE_SESSION;
  // событие НЕ создавать, т.к. процесс синхронный
}
//-------------------------------------------------------------------------
void TBase::SendUp(TBreakPacket bp, bool check)
{
  // устанавливать для сценария контекст не требуется
  mControlSc->mFlow->SendUp(bp, check);
}
//-------------------------------------------------------------------------
bool TBase::IsConnectUp()
{
	return mManagerSession->IsExist(mID_SessionUp);
}
//-------------------------------------------------------------------------
bool TBase::IsConnect(unsigned int id)
{
  return mManagerSession->IsExist(id);
}
//-------------------------------------------------------------------------
void TBase::Recv( TDescRecvSession* pDesc )
{
  TDescRecvSession* pNewDesc = new TDescRecvSession;
  pNewDesc->Assign(pDesc);
  mRecvPacket.Add(pNewDesc);
}
//-------------------------------------------------------------------------
void TBase::Disconnect(unsigned int id)
{
  unsigned int* pID = new unsigned int(id);
  mIDSessionDisconnect.Add(pID);
}
//-------------------------------------------------------------------------
void TBase::Work()
{
  //пробежка по ожидающим разъединения и удаление сессий
  mManagerSession->Work();
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
void TBase::SetTimeLiveSession(unsigned int time_ms)
{
  mManagerSession->SetTimeLiveSession(time_ms);
}
//-------------------------------------------------------------------------
void TBase::HandleListDisconnect()
{
  unsigned int** ppFirst = mIDSessionDisconnect.GetFirst();
  while(ppFirst)
  {
    unsigned int ID = *(*ppFirst);
    // сообщить о разрыве связи для различных реализаций
    DisconnectInherit(ID);
    // закрыть сессию
    mManagerSession->CloseSession(ID);
    // следующий ID
    mIDSessionDisconnect.Remove(ppFirst);
    ppFirst = mIDSessionDisconnect.GetFirst();
  }
}
//-------------------------------------------------------------------------
void TBase::HandleListRecv()
{
  TDescRecvSession** ppFirst = mRecvPacket.GetFirst();
  while(ppFirst)
  {
    TDescRecvSession* pDesc = *ppFirst;
    // обработать через сценарий
    mControlSc->Work(pDesc);
    mRecvPacket.Remove(ppFirst);
    ppFirst = mRecvPacket.GetFirst();
  }
}
//-------------------------------------------------------------------------
TManagerContextSc* TBase::AddManagerContextSc()
{
  return mMngMngContextSc->Add();
}
//-------------------------------------------------------------------------
void TBase::RemoveManagerContextSc(TManagerContextSc* pMСSc)
{
  return mMngMngContextSc->Remove(pMСSc);
}
//-------------------------------------------------------------------------
void TBase::SetupScForContext(TContainerContextSc* pCCSc)
{
  pCCSc->SetMCSc(AddManagerContextSc());
  pCCSc->SetMS(mManagerSession.get());
  pCCSc->SetSE(this);

  pCCSc->mDisClient.   SetSc(mControlSc->mDisClient);
  pCCSc->mFlow.        SetSc(mControlSc->mFlow);
  pCCSc->mLoginClient. SetSc(mControlSc->mLoginClient);
  pCCSc->mLoginSlave.  SetSc(mControlSc->mLoginSlave);
  pCCSc->mLoginMaster. SetSc(mControlSc->mLoginMaster);
  pCCSc->mRcm.         SetSc(mControlSc->mRcm);
  pCCSc->mSendToClient.SetSc(mControlSc->mSendToClient);
  pCCSc->mSynchroSlave.SetSc(mControlSc->mSynchroSlave);
}
//-------------------------------------------------------------------------
void TBase::DelayDeleteContainerScenario(TContainerContextSc* pCCSc)
{
  // добавить в список на удаление
  mListDelayDeleteContainerSc.push_back(pCCSc);
}
//-------------------------------------------------------------------------
bool TBase::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
{
  return mManagerSession->GetInfo(id_session, ip_port);
}
//-------------------------------------------------------------------------
void TBase::RegisterNeedForLoginClient()
{
  mControlSc->mLoginClient->Register<unsigned int>(
                            IScenario::eContextBySession, 
                            &TBase::NeedContextLoginClientBySession, this);
  mControlSc->mLoginClient->Register<unsigned int>(
                            TScenarioLoginClient::eContextByClientKey, 
                            &TBase::NeedContextLoginClientByClientKey, this);
  mControlSc->mLoginClient->Register<unsigned int>(
                            TScenarioLoginClient::eNumInQueueByClientKey,
                            &TBase::NeedNumInQueueLoginClient,this);
  mControlSc->mLoginClient->Register<unsigned int,unsigned int>(
                            TScenarioLoginClient::eContextByMasterSessionByClientKey,
                            &TBase::NeedContextByMasterSessionByClientKey,this);
  mControlSc->mLoginClient->Register<unsigned int>(
                            TScenarioLoginClient::eSetClientKey,
                            &TBase::EventSetClientKeyLoginClient,this);
  mControlSc->mLoginClient->Register<unsigned int,unsigned int>(
                            TScenarioLoginClient::eContextByClientSessionByClientKey,
                            &TBase::NeedContextLoginClientByClientSessionByKeyClient, this);
  mControlSc->mLoginClient->Register<unsigned int>(
                            TScenarioLoginClient::eContextByClientSessionAfterAuthorised,
                            &TBase::NeedContextLoginClientBySessionAfterAuthorised, this);
}
//-------------------------------------------------------------------------
void TBase::DeleteContainerScenario()
{
  BOOST_FOREACH(TContainerContextSc* pCCSc, mListDelayDeleteContainerSc)
  {
    RemoveManagerContextSc(pCCSc->GetMCSc());
    delete pCCSc;
  }
  mListDelayDeleteContainerSc.clear();
}
//-------------------------------------------------------------------------
void TBase::SetDefualtContextForScenario()
{
  mControlSc->mDisClient   ->SetContext(&mContainerUp->mDisClient);
  mControlSc->mFlow        ->SetContext(&mContainerUp->mFlow);        
  mControlSc->mLoginClient ->SetContext(&mContainerUp->mLoginClient); // client
  mControlSc->mLoginSlave  ->SetContext(&mContainerUp->mLoginSlave);  // slave
  mControlSc->mLoginMaster ->SetContext(&mContainerUp->mLoginMaster); // master
  mControlSc->mRcm         ->SetContext(&mContainerUp->mRcm);         // client
  mControlSc->mSynchroSlave->SetContext(&mContainerUp->mSynchroSlave);// slave
  mControlSc->mSendToClient->SetContext(&mContainerUp->mSendToClient);// 
}
//-------------------------------------------------------------------------
void TBase::RegisterNeedForRcmClient()
{
  mControlSc->mRcm->Register<unsigned int>(
                              IScenario::eContextByClientKey, 
                              &TBase::NeedContextByClientKeyRcm, this);
  mControlSc->mRcm->Register<unsigned int,bool>(
                              TScenarioRecommutationClient::eNeedContextByClientKeyForSlave,
                              &TBase::NeedContextByClientForSlaveKeyRcm, this);
  mControlSc->mRcm->Register<IScenario*>(
                              TScenarioRecommutationClient::eNeedSessionDonor, 
                              &TBase::NeedSlaveSessionDonorRcm, this);
  mControlSc->mRcm->Register<IScenario*>(
                              TScenarioRecommutationClient::eEventActivate,
                              &TBase::EventActivateRcm, this);
  mControlSc->mRcm->Register<unsigned int>(
                              TScenarioRecommutationClient::eEventDisconnectClient,
                              &TBase::EventDisconnectClientRcm, this);
  mControlSc->mRcm->Register<unsigned int,bool>(
                              TScenarioRecommutationClient::eNeedContextByClientSessionForSlave,
                              &TBase::NeedContextByClientSessionForSlaveRcm, this);
  mControlSc->mRcm->Register<TDescRequestConnectForRecipient*>(
                              TScenarioRecommutationClient::eNeedContextByRequestForRecipient,
                              &TBase::NeedContextByRequestForRecipient, this);
  mControlSc->mRcm->Register<unsigned int>(
                              TScenarioRecommutationClient::eEventTimeClientElapsed,
                              &TBase::EventTimeClientElapsedRcm, this);
}
//-------------------------------------------------------------------------
void TBase::RegisterOnScenarioEvent()
{
  mControlSc->mDisClient->Register<unsigned int>(IScenario::eContextByClientKey,
                                                 &TBase::NeedContextDisconnectClient, this);
  RegisterNeedForLoginClient();
  RegisterNeedForRcmClient();
  mControlSc->mLoginSlave  ->Register<unsigned int>(IScenario::eContextBySession,  &TBase::NeedContextLoginSlave,  this);
  mControlSc->mLoginMaster ->Register<unsigned int>(IScenario::eContextBySession,  &TBase::NeedContextLoginMaster, this);
  mControlSc->mSendToClient->Register<unsigned int>(IScenario::eContextByClientKey,&TBase::NeedContextSendToClient,this);
  mControlSc->mSynchroSlave->Register<unsigned int>(IScenario::eContextBySession,  &TBase::NeedContextSynchroSlave,this);

  mControlSc->mDisClient   ->Register<IScenario*>(IScenario::eEnd,&TBase::EndDisconnectClient,this);
  mControlSc->mLoginClient ->Register<IScenario*>(IScenario::eEnd,&TBase::EndLoginClient, this);
  mControlSc->mLoginSlave  ->Register<IScenario*>(IScenario::eEnd,&TBase::EndLoginSlave,  this);
  mControlSc->mLoginMaster ->Register<IScenario*>(IScenario::eEnd,&TBase::EndLoginMaster, this);
  mControlSc->mRcm         ->Register<IScenario*>(IScenario::eEnd,&TBase::EndRcm,         this);
  mControlSc->mSynchroSlave->Register<IScenario*>(IScenario::eEnd,&TBase::EndSynchroSlave,this);
}
//-------------------------------------------------------------------------
