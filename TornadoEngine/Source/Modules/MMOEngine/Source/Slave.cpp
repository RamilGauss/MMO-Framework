/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Slave.h"

#include <boost/foreach.hpp>

#include "Logger.h"
#include "ControlScenario.h"
#include "ManagerSession.h"
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

using namespace nsMMOEngine;
using namespace std;

TSlave::TSlave()
{
  mMngContextClient.reset(new TManagerContextClient_slave(this));
  mMngContextClientSlaveRecipient.reset(new TManagerContextClient_slave(this));

  mTimeNeedSendSynchro = 0;
  mControlSc->mLoginClient->SetBehavior(TScenarioLoginClient::eSlave);
	mControlSc->mRcm->SetBehavior(TScenarioRecommutationClient::eSlave);
}
//-------------------------------------------------------------------------
TSlave::~TSlave()
{

}
//-------------------------------------------------------------------------
void TSlave::SaveContext(unsigned int id_session, void* data, int size)
{
  TContainerContextSc* pC = mMngContextClient->FindContextBySession(id_session);
  if(pC && pC->IsRcmActive()) // передать контекст в сценарий
  {
    mControlSc->mRcm->SetContext(&pC->mRcm);
    mControlSc->mRcm->SaveContext(data, size);// это уже вызов функции сценария
  }
}
//-------------------------------------------------------------------------
bool TSlave::FindClientKeyBySession(unsigned int id_session, unsigned int &id)
{
  return mMngContextClient->FindKeyBySession(id_session, id);
}
//-------------------------------------------------------------------------
bool TSlave::FindSessionByClientKey(unsigned int id, unsigned int& id_session)
{
  return mMngContextClient->FindSessionByKey(id, id_session);
}
//-------------------------------------------------------------------------
void TSlave::DisconnectInherit(unsigned int id_session)
{
  // либо обрыв связи с верхним соединением - тогда мы одни, нерабочее состояние
  if(id_session==mID_SessionUp)
  {
    flgConnectUp = false;
    DisconnectAllClient();// распустить всех клиентов
    mID_SessionUp = INVALID_HANDLE_SESSION;
    
    TEventDisconnectUp event;
    event.id_session = id_session;
    AddEventCopy(&event, sizeof(event));
    return;
  }
  // либо обрыв с одним из клиентов - уничтожить клиента
  // физический обрыв или сценарий сам оборвал
  unsigned int id_client;
  if(mMngContextClient->FindKeyBySession(id_session,id_client)==false)
    return;

  TContainerContextSc* pC = mMngContextClient->FindContextBySession(id_session);
  // если есть активный сценарий, то завершить и начать сценарий дисконнекта
  mControlSc->mDisClient->SetContext(&pC->mDisClient);
  pC->mDisClient.SetID_Session(mID_SessionUp);
  mControlSc->mDisClient->DisconnectFromSlave(id_client);

  mMngContextClient->DeleteByKey(id_client);
  
  TEventDisconnectDown event;
  event.id_session = id_session;
  AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------
int TSlave::GetCountDown()
{
	return mMngContextClient->GetCountSession();
}
//-------------------------------------------------------------------------
bool TSlave::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  if(sizeDesc<sizeof(TDescDownSlave))
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TSlave::GetDescDown() size of buffer less then size of structure.\n");
    return false;
  }

  unsigned int id_session;
  if(mMngContextClient->GetSessionByIndex(index, id_session)==false)
    return false;

  TDescDownSlave* pDescDownSlave = (TDescDownSlave*)pDesc;
  pDescDownSlave->id_session = id_session;
  sizeDesc = sizeof(TDescDownSlave);
	return true;
}
//-------------------------------------------------------------------------
void TSlave::ConnectUp(unsigned int ip, unsigned short port, 
                       void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                       unsigned char subNet )
{
  // если сессия жива, то значит либо соединились, либо соединяемся
  if(mID_SessionUp!=INVALID_HANDLE_SESSION)
    return;

  mControlSc->mLoginSlave->ConnectToMaster(ip, port, 
    pLogin, sizeLogin, pPassword, sizePassword, subNet);
  // тут же опросить на созданную сессию
  mID_SessionUp = mContainerUp->mLoginSlave.GetID_Session();
}
//-------------------------------------------------------------------------
void TSlave::WorkInherit()
{
  // пока нет связи с Мастером - синхронизацию не проводить
  if(flgConnectUp==false)
    return;
  //-------------------------------------------------------
  unsigned int now_ms = ht_GetMSCount();
  if(mTimeNeedSendSynchro<now_ms)
  {
    mControlSc->mSynchroSlave->SendSynchro(mLoadProcent);
    mTimeNeedSendSynchro = now_ms + eDeltaSynchro;
  }
}
//-------------------------------------------------------------------------
void TSlave::DisconnectAllClient()
{
  unsigned int id;
  // перечисляем всех клиентов и узнаем их ключи
  while(mMngContextClient->GetFirstKey(id))
  {
    // по ключу ищем сессию
    unsigned int id_session;
    if(mMngContextClient->FindSessionByKey(id, id_session))
    {
      // закрываем сессию
      mManagerSession->CloseSession(id_session);
      // удаляем по ключу
      mMngContextClient->DeleteByKey(id);
      // генерация события о дисконнекте
      TEventDisconnectDown event;
      event.id_session = id_session;
      AddEventCopy(&event, sizeof(event));
    }
  }
}
//-------------------------------------------------------------------------
void TSlave::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  TContainerContextSc* pC = mMngContextClient->FindContextBySession(id_session);
  if(pC)
  {
    mControlSc->mFlow->SetContext(&pC->mFlow);
    mControlSc->mFlow->SendDown(bp, check);
  }
}
//-------------------------------------------------------------------------
void TSlave::EndLoginClient(IScenario* pSc)
{
  TContextScLoginClient* pContext = (TContextScLoginClient*)pSc->GetContext();
  if(pContext->IsAccept())
  {
    // сохранить сессию Клиента
    TContainerContextSc* pC = mMngContextClient->FindContextByKey(pContext->GetClientKey());
    BL_ASSERT(pC);
    pC->SetID_Session(pContext->GetID_SessionClientSlave());
    return;
  }

  mMngContextClient->DeleteByKey(pContext->GetClientKey());
}
//-------------------------------------------------------------------------
void TSlave::EndLoginSlave(IScenario* pSc)
{
  // взять по этому контексту, задать всем контекстам
  mID_SessionUp = pSc->GetContext()->GetID_Session();
  mContainerUp->SetID_Session(mID_SessionUp);

  flgConnectUp = mContainerUp->mLoginSlave.IsConnect();
  if(flgConnectUp)
  {
    // вход в кластер закончен
    TEventConnectUp event;
    event.id_session = mID_SessionUp;
    AddEventCopy(&event, sizeof(event));
  }
}
//-------------------------------------------------------------------------
void TSlave::EndRcm(IScenario* pSc)
{
  TContextScRecommutationClient* pContext = (TContextScRecommutationClient*)pSc->GetContext();
  unsigned int key = pContext->GetClientKey();
  if(pContext->IsDonor())
  {
    // просто удалить  
    mMngContextClient->DeleteByKey(key);
    return;
  }
  if(pContext->IsRecipient()==false)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TSlave::EndRcm() Undef state.\n");
    BL_FIX_BUG();
    return;
  }
  // переместить из временного хранилища в постоянное
  mMngContextClientSlaveRecipient->DeleteByKey(key);

  unsigned int id_session = pContext->GetID_SessionClientSlave();
  TContainerContextSc* pC = mMngContextClient->AddContextByKey(key);
  mMngContextClient->AddSessionByKey(key,id_session);
  // для всех контекстов назначить связь вниз
  pC->SetID_Session(id_session);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextSendToClient(unsigned int id_client)
{
  // запрос на отправку какому-то клиенту
  TContainerContextSc* pContext = mMngContextClient->FindContextByKey(id_client);
	if(pContext)
		mControlSc->mSendToClient->SetContext(&pContext->mSendToClient);
	else
		mControlSc->mSendToClient->SetContext(NULL);
}
//-------------------------------------------------------------------------
void TSlave::SendByClientKey(list<unsigned int>& lKey, TBreakPacket bp)
{
	mControlSc->mSendToClient->SendFromSlave(lKey, bp);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextLoginClientByClientSessionByKeyClient(unsigned int id_session_client,
                                                              unsigned int id_client)
{
  TContainerContextSc* pC = mMngContextClient->FindContextByKey(id_client);
  if(pC==NULL)
  {
    mControlSc->mLoginClient->SetContext(NULL);
    return;
  }
  // надо проверить, вдруг клиент решил взять не свой ключ и ключ совпал
  unsigned int id_session_exist;
  if(mMngContextClient->FindSessionByKey(id_client,id_session_exist)==false)
  {
    mControlSc->mLoginClient->SetContext(NULL);
    return;
  }
  // сессии не должно быть, он ведь впервые соединяется
  if(id_session_exist!=INVALID_HANDLE_SESSION)
  {
    mControlSc->mLoginClient->SetContext(NULL);
    return;
  }

  mMngContextClient->AddSessionByKey(id_client, id_session_client);
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextLoginClientByClientKey(unsigned int id_client)
{
  TContainerContextSc* pC = mMngContextClient->FindContextByKey(id_client);  
  if(pC==NULL)
    pC = mMngContextClient->AddContextByKey(id_client);

  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByClientForSlaveKeyRcm(unsigned int key, bool donor)
{
  if(donor)
  {
    TContainerContextSc* pC = mMngContextClient->FindContextByKey(key);
    if(pC)
    {
      // настроить сессии наверх и вниз
      pC->mRcm.SetID_SessionClientSlave(pC->GetID_Session());
      pC->mRcm.SetID_SessionMasterSlave(mID_SessionUp);

      mControlSc->mRcm->SetContext(&pC->mRcm);
    }
    else
      mControlSc->mRcm->SetContext(NULL);
  }
  else
  {
    TContainerContextSc* pC = mMngContextClientSlaveRecipient->FindContextByKey(key);
    if(pC==NULL)
      pC = mMngContextClientSlaveRecipient->AddContextByKey(key);
    
    // верх и низ сессия назначит сам сценарий
    mControlSc->mRcm->SetContext(&pC->mRcm);
  }
}
//-------------------------------------------------------------------------
void TSlave::EventDisconnectClientRcm(unsigned int key)
{
  // для подстраховки и там и там удалить
  TContainerContextSc* pC = mMngContextClientSlaveRecipient->FindContextByKey(key);
  if(pC)
    mMngContextClientSlaveRecipient->DeleteByKey(key);
  else
  {
    // если Клиент исхитрился и вместо отсылки "CheckInfoRecipient, ready to disconnect"
    // просто разорвал соединение - удалить из системы
    pC = mMngContextClient->FindContextByKey(key);
    if(pC==NULL)
      return;
    mMngContextClient->DeleteByKey(key);
  }
  unsigned int id_session = pC->mRcm.GetID_SessionClientSlave();
  mManagerSession->CloseSession(id_session);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByClientSessionForSlaveRcm(unsigned id_session, bool donor)
{
  TContainerContextSc* pC = NULL;
  if(donor)
    pC = mMngContextClient->FindContextBySession(id_session);
  else
    pC = mMngContextClientSlaveRecipient->FindContextBySession(id_session);
  //----------
  if(pC)
    mControlSc->mRcm->SetContext(&pC->mRcm);
  else
    mControlSc->mRcm->SetContext(NULL);
}
//-------------------------------------------------------------------------
void TSlave::NeedContextByRequestForRecipient(TDescRequestConnectForRecipient* pDescRequest)
{
  TContainerContextSc*pC = mMngContextClientSlaveRecipient->FindContextByKey(pDescRequest->key);
  if(pC)
  {
    // проверка числа
    if(pC->mRcm.GetRandomNum()==pDescRequest->random_num)
    {
      mControlSc->mRcm->SetContext(&pC->mRcm);
      // сохранить сессию
      mMngContextClientSlaveRecipient->
        AddSessionByKey(pDescRequest->key, pDescRequest->id_session);
      // запомнить откуда Клиент вообще
      pC->SetID_Session(pDescRequest->id_session);
      return;
    }
  }
  mControlSc->mRcm->SetContext(NULL);
}
//-------------------------------------------------------------------------
void TSlave::EventTimeClientElapsedRcm(unsigned int id_client)
{
  // Донор или Реципиент
  TContainerContextSc* pC = mMngContextClient->FindContextByKey(id_client);
  if(pC)
  {
    // Донор
    mMngContextClient->DeleteByKey(id_client);
  }
  else
  {
    pC = mMngContextClientSlaveRecipient->FindContextByKey(id_client);
    if(pC==NULL)
      return;
    // реципиент
    mMngContextClientSlaveRecipient->DeleteByKey(id_client);
  }
  // если есть активный сценарий, то завершить и начать сценарий дисконнекта
  mControlSc->mDisClient->SetContext(&pC->mDisClient);
  pC->mDisClient.SetID_Session(mID_SessionUp);
  mControlSc->mDisClient->DisconnectFromSlave(id_client);
}
//-------------------------------------------------------------------------
