/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Master.h"
#include "ControlScenario.h"
#include "BL_Debug.h"
#include "Logger.h"

#include "ManagerContextMoreDownClientConnection.h"
#include "ManagerContextDownConnection_Slave.h"
#include "ManagerContextClientLogining.h"
#include "ManagerGroupClient.h"
#include "ManagerRecommutation.h"
#include "SetOrderElement.h"
#include "StatisticaClientInGroup.h"

#include "Events.h"

#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioLoginMaster.h"
#include "ScenarioFlow.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSynchroSlave.h"
#include "ScenarioDisconnectClient.h"
#include "ScenarioSendToClient.h"

#include "ContainerContextSc.h"
#include "EnumMMO.h"
#include "ManagerSession.h"

using namespace std;
using namespace nsMMOEngine;

TMaster::TMaster()
{
  mMngContextClient.reset(new TManagerContextMoreDownClientConnection(this));
  mMngContextSlave.reset(new TManagerContextDownConnection_Slave(this));
  mMngContextClientLogining.reset(new TManagerContextClientLogining(this));
  mMngGroup.reset(new TManagerGroupClient);
  mSetClientKeyInQueue.reset(new TSetOrderElement);
  mStatisticaClientInGroup.reset(new TStatisticaClientInGroup);
  mMngRcm.reset(new TManagerRecommutation);

  mControlSc->mLoginClient->SetBehavior(TScenarioLoginClient::eMaster);
	mControlSc->mRcm->SetBehavior(TScenarioRecommutationClient::eMaster);
}
//-------------------------------------------------------------------------
TMaster::~TMaster()
{
  Done();
}
//-------------------------------------------------------------------------
bool TMaster::TryCreateGroup(list<unsigned int>& l_id_client, unsigned int& id_group)
{
  BOOST_FOREACH(unsigned int id_client, l_id_client)
  {
    // Клиент может и не существовать в системе 
    // спросить состоит ли клиент в группе
    if(mMngGroup->FindIDByClientKey(id_client,id_group))
    {
      TEventError event;
      event.code = CreateGroup_ClientNotExist;
      AddEventCopy(&event, sizeof(event));
      return false;
    }
  }
  // оценка ситуации на Slave
  return EvalCreateGroupNow(l_id_client,id_group);
}
//-------------------------------------------------------------------------
void TMaster::DestroyGroup(unsigned int id_group)
{
  unsigned int id_session_slave;
  if(mMngGroup->FindSessionByID(id_group, id_session_slave)==false)
    return;
  mStatisticaClientInGroup->DeleteBySlaveSession(id_session_slave);
  //----------------------------------------------------------------
  mMngGroup->DeleteByID(id_group);
}
//-------------------------------------------------------------------------
void TMaster::LeaveGroup(unsigned int id_client)
{
  unsigned int id_group;
  if(mMngGroup->FindIDByClientKey(id_client,id_group)==false)
    return;

  unsigned int id_session_slave;
  if(mMngGroup->FindSessionByID(id_group, id_session_slave))
    mStatisticaClientInGroup->DeleteByClientKey(id_session_slave,id_client);

  mMngGroup->DeleteClientKey(id_client);
}
//-------------------------------------------------------------------------
void TMaster::GetListForGroup(unsigned int id_group, std::list<unsigned int>& lClientKey)
{
  int countClient = mMngGroup->GetCountClientKey(id_group);

  for( int i = 0 ; i < countClient ; i++)
  {
    unsigned int id_client;
    mMngGroup->GetClientKeyByIndex(id_group, i, id_client);
    lClientKey.push_back(id_client);
  }
}
//-------------------------------------------------------------------------
void TMaster::SetResultLogin(bool res, unsigned int id_session_client, 
                             unsigned int id_client, 
                             void* resForClient, int sizeResClient)
{
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session_client);
  if(pC==NULL)
    return;
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
  if(res==false)
  {
		// отказ
    mControlSc->mLoginClient->Reject(resForClient, sizeResClient);
    return;
  }
  // проверка на существование ключа в кластере
  unsigned int id_session_temp;
  if((mMngContextClient->FindContextByClientKey(id_client))||
     (mMngContextClientLogining->FindSessionByClientKey(id_client,id_session_temp)))
  {
    TEventError event;
    event.code = LoginClient_MasterKeyBusy;
    AddEventCopy(&event,sizeof(event)); 

    // отказ
    string sReject = "Reject login. Client was been authorized.";
    mControlSc->mLoginClient->Reject((void*)sReject.data(), sReject.length());
    return;
  }
  // связка сессии и ключа клиента
  mMngContextClientLogining->AddKeyBySession(id_session_client, id_client);
  // решить на какой Slave закинуть клиента
  // для Группы задан Slave, значит на него и перекидывать, но возможно он перегружен
  // навряд ли он перегружен, иначе, он самый не нагруженный, потому как только бы на него и пихали клиентов
  // а это противоречие, значит пихаем в него

  // клиент в группе?
  bool resAdd = false;
  unsigned int id_session_slave;
  unsigned int id_group;
  if(mMngGroup->FindIDByClientKey(id_client, id_group))
    resAdd = TryAddClientByGroup(id_client, id_group, id_session_slave);
  else
    resAdd = TryAddClient(id_client, id_session_slave);
  if(resAdd)
    AddClientBySlaveSession(id_client,id_session_slave,resForClient,sizeResClient);
  else
    AddInQueue(id_client, resForClient, sizeResClient);
}
//-------------------------------------------------------------------------
bool TMaster::FindSlaveSessionByGroup(unsigned int id_group, 
                                      unsigned int& id_session)
{
  return mMngGroup->FindSessionByID(id_group,id_session);
}
//-------------------------------------------------------------------------
void TMaster::DisconnectInherit(unsigned int id_session)
{
  if(DisconnectSuperServer(id_session))
    return;
  if(DisconnectClientWait(id_session))
    return;
  if(DisconnectSlave(id_session))
    return;
  //GetLogger(STR_NAME_MMO_ENGINE)->
  //  WriteF_time("TMaster::DisconnectInherit() session not exist id=%u.\n",id_session);
  //BL_FIX_BUG();
}
//-------------------------------------------------------------------------
int TMaster::GetCountDown()
{
	return mMngContextSlave->GetCountSession();
}
//-------------------------------------------------------------------------
bool TMaster::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  if(sizeDesc<sizeof(TDescDownMaster))
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TMaster::GetDescDown() size of buffer less then size of structure.\n");
    return false;
  }
  unsigned int id_session;
  if(mMngContextSlave->GetSessionByIndex(index, id_session)==false)
    return false;

  TDescDownMaster* pDescDownSlave = (TDescDownMaster*)pDesc;
  pDescDownSlave->id_session = id_session;
  sizeDesc = sizeof(TDescDownMaster);
  return true;
}
//-------------------------------------------------------------------------
void TMaster::ConnectUp(unsigned int ip, unsigned short port, 
                        void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                        unsigned char subNet)
{
  mControlSc->mLoginMaster->ConnectToSuperServer(ip, port, 
    pLogin, sizeLogin, pPassword, sizePassword, subNet);
  // тут же опросить на созданную сессию
  mID_SessionUp = mControlSc->mLoginMaster->GetContext()->GetID_Session();
}
//-------------------------------------------------------------------------
void TMaster::EndLoginMaster(IScenario* pSc)
{
  // взять по этому контексту, задать всем контекстам
  mID_SessionUp = pSc->GetContext()->GetID_Session();
  mContainerUp->SetID_Session(mID_SessionUp);

  flgConnectUp = mContainerUp->mLoginMaster.IsConnect();
  if(flgConnectUp)
  {
    // вход в кластер закончен
    TEventConnectUp event;
    event.id_session = mID_SessionUp;
    AddEventCopy(&event, sizeof(event));
  }
}
//-------------------------------------------------------------------------
void TMaster::EndLoginSlave(IScenario* pSc)
{
  
}
//-------------------------------------------------------------------------
void TMaster::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  TContainerContextSc* pC = mMngContextSlave->FindContextBySession(id_session);
  if(pC==NULL)
    return;
  mControlSc->mFlow->SetContext(&pC->mFlow);
  mControlSc->mFlow->SendDown(bp,check);
}
//-------------------------------------------------------------------------
void TMaster::WorkInherit()
{
}
//-------------------------------------------------------------------------
void TMaster::EndLoginClient(IScenario* pSc)
{
  // получить контекст
  TContextScLoginClient* pContextLoginClient = (TContextScLoginClient*)pSc->GetContext();
  // переместить информацию из mMngContextClientLogining в mMngContextClient
  // либо по сессии 
  unsigned int id_session_client = pContextLoginClient->GetID_SessionClientMaster();
  TContainerContextSc* pContainer = 
    mMngContextClientLogining->FindContextBySession(id_session_client);
  // удалить из списка авторизующихся
  mMngContextClientLogining->DeleteBySession(id_session_client);
  // либо время вышло, либо отказали в авторизации
  if(pContextLoginClient->IsReject())
  {
    if(pContainer)
    {
      vector<unsigned int> vecID_Client;
      vecID_Client.push_back(pContextLoginClient->GetClientKey());
      mControlSc->mDisClient->SetContext(&pContainer->mDisClient);
      pContainer->mDisClient.SetID_Session(mID_SessionUp);
      mControlSc->mDisClient->DisconnectFromMaster(vecID_Client);
    }
    return;
  }
  // тут если авторизация закончилась удачно
  if(pContextLoginClient->IsAccept())
  {
    // ID Клиента
    unsigned int id_client = pContextLoginClient->GetClientKey();
    // найти сессию Slave
    unsigned int id_session_slave = pContextLoginClient->GetID_SessionMasterSlave();
    mMngContextClient->AddContext(id_client,id_session_slave);

    // если Клиент числится в группе, то добавить в статистику
    unsigned int id_group_fake;
    if(mMngGroup->FindIDByClientKey(id_client, id_group_fake))
      mStatisticaClientInGroup->AddBySlaveSessionClientKey(id_session_slave,id_client);
  }
}
//-------------------------------------------------------------------------
void TMaster::Done()
{
  
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectSuperServer(unsigned int id_session)
{
  if(id_session!=mID_SessionUp)
    return false;

  mID_SessionUp = INVALID_HANDLE_SESSION;
  flgConnectUp  = false;

  TEventDisconnectUp event;
  event.id_session = mID_SessionUp;
  AddEventCopy(&event, sizeof(event));
  return true;
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectClientWait(unsigned int id_session)
{
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session);
  if(pC==NULL)
    return false;
  
  unsigned int id_client;
  if(mMngContextClientLogining->FindClientKeyBySession(id_session,id_client))
  {
		// возможно клиент в очереди, удалим на всякий случай
		mSetClientKeyInQueue->DeleteKey(id_client);
    // закончить с Клиентом на Slave
    mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
    mControlSc->mLoginClient->DisconnectFromMaster();
    // отослать SuperServer информацию о дисконнекте Клиента
    mControlSc->mDisClient->SetContext(&pC->mDisClient);
    vector<unsigned int> vecID;
    vecID.push_back(id_client);
    mControlSc->mDisClient->DisconnectFromMaster(vecID);
  }

  mMngContextClientLogining->DeleteBySession(id_session);
  return true;
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectSlave(unsigned int id_session)
{
  if(mMngContextSlave->FindContextBySession(id_session)==NULL)
    return false;
  // составить список клиентов, которые сидели на Slave
  int countClient;
  if(mMngContextSlave->GetCountClientKey(id_session, countClient)==false)
    return false;

  vector<unsigned int> vID_client;  
  for(int i = 0 ; i < countClient ; i++)
  {
    unsigned int id_client;
    if(mMngContextSlave->GetClientKeyByIndex(id_session, i, id_client))
      vID_client.push_back(id_client);
  }
  // отослать SuperServer список клиентов
  if((mID_SessionUp!=INVALID_HANDLE_SESSION)&& // если есть связь с SuperServer
     (vID_client.size()                    ))
  {
    // задать какой-то контекст
    TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(vID_client[0]);
    if(pC)
    {
      mControlSc->mDisClient->SetContext(&pC->mDisClient);
      pC->mDisClient.SetID_Session(mID_SessionUp);
      mControlSc->mDisClient->DisconnectFromMaster(vID_client);
    }
  }
  BOOST_FOREACH(unsigned int id_client, vID_client)
  {
    // если это Реципиент, то уведомить о потере Клиента
    TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(id_client);
    NotifyRecipientAboutDisconnectClient(id_client, pC, id_session);

    mMngContextClient->DeleteByKey(id_client);
  }
  // !!! из групп нельзя удалять id_client, удалять нужно группы с id_session
  int countGroup = mMngGroup->GetCountID();
  for( int i = 0 ; i < countGroup ; i++ )
  {
    // перебираем все группы и ищем с id_session
    unsigned int id_group;
    if(mMngGroup->GetIDByIndex(i, id_group))
    {
      unsigned int id_session_in_group;
      if(mMngGroup->FindSessionByID(id_group, id_session_in_group))
        if(id_session_in_group==id_session)
        {
          mMngGroup->DeleteByID(id_group);
          // 
          TEventDestroyGroup eventDestroyGroup;
          eventDestroyGroup.id_group = id_group;
          AddEventCopy(&eventDestroyGroup, sizeof(eventDestroyGroup));
        }
    }
  }
  // удалить Slave
  mMngContextSlave->DeleteContextBySession(id_session);
  mStatisticaClientInGroup->DeleteBySlaveSession(id_session);
  // уведомить о разрыве
  TEventDisconnectDown event;
  event.id_session = id_session;
  AddEventCopy(&event, sizeof(event));
  return true;
}
//-------------------------------------------------------------------------
bool TMaster::EvalCreateGroupNow(list<unsigned int>& l_id_client, unsigned int& id_group)
{
  // ищем минимум Slave, который содержит минимум Клиентов, состоящих в группе
  unsigned int id_session_slave;
  if(mStatisticaClientInGroup->FindSlaveSessionByMinimumClient(id_session_slave)==false)
    return false;
  // определить нагрузку, которая будет в будущем на Slave, если будет меньше допустимого значения, то можно создать
  if(LoadInFutureLessLimit(id_session_slave, l_id_client)==false)
    return false;
  // создать группу
  id_group = mMngGroup->AddGroup( id_session_slave);

  // занести в статистику
  mStatisticaClientInGroup->AddSlave(id_session_slave);
  // все те Клиенты, которые активны и стали внутри Группы, поместить в Статистику
  BOOST_FOREACH(unsigned int id_client, l_id_client)
  {
    // если присутствует в системе
    if(mMngContextClient->FindContextByClientKey(id_client))
      mStatisticaClientInGroup->AddBySlaveSessionClientKey(id_session_slave,id_client);
    // заполнить клиентами независимо от того существуют ли они в системе
    mMngGroup->AddClientKey(id_group, id_client);
  }
  //================================================================================
  // определить кто встанет на место этого Клиента на старом Slave
  // и заодно перенаправить этого Клиента на новый Slave
  BOOST_FOREACH(unsigned int id_client, l_id_client)
  {
    TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(id_client);
    if(pC)
      SolveExchangeClient(id_client, pC, id_session_slave);
  }
  return true;
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginSlave(unsigned int id_session)
{
  TContainerContextSc* pC = mMngContextSlave->FindContextBySession(id_session);
  if(pC)
  {
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TMaster::NeedContextLoginSlave() against try authorized.\n");
    return;
  }
  pC = mMngContextSlave->AddContext(id_session);
  mControlSc->mLoginSlave->SetContext(&pC->mLoginSlave);

  mStatisticaClientInGroup->AddSlave(id_session);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextSynchroSlave(unsigned int id_session)
{
	TContainerContextSc* pC = mMngContextSlave->FindContextBySession(id_session);
  if(pC==NULL)
    return;
  mControlSc->mSynchroSlave->SetContext(&pC->mSynchroSlave);
}
//-------------------------------------------------------------------------
void TMaster::EndSynchroSlave(IScenario* pSc)
{
  TContextScSynchroSlave* pContextSynchroSlave = (TContextScSynchroSlave*)pSc->GetContext();
	mMngContextSlave->SetLoadBySession(pContextSynchroSlave->GetID_Session(), 
		                                 pContextSynchroSlave->GetLoadProcent());
}
//-------------------------------------------------------------------------
void TMaster::SendByClientKey(list<unsigned int>& lKey, TBreakPacket bp)
{
	mControlSc->mSendToClient->SendFromMaster(lKey, bp);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionAfterAuthorised(unsigned int id_session)
{
  // после авторизации Клиент получил информацию о Slave. Далее он пришлет Мастеру
  // квитанцию об этом. Значит сессию Мастер должен найти.
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session);
  if(pC==NULL)
  {
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TMaster::NeedContextLoginClientBySessionAfterAuthorised() context not found.\n");
    mControlSc->mLoginClient->SetContext(NULL);
    return;
  }
  // назначить контекст
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionLeaveQueue(unsigned int id_session)
{
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session);
  if(pC)
    mControlSc->mLoginClient->SetContext(&pC->mLoginClient);// назначить контекст
  else
    mControlSc->mLoginClient->SetContext(NULL);// сам вышел из очереди, ну и хер с ним
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySession(unsigned int id_session)
{
  // если это повторная авторизация, то Begin по данному контексту клиента
  // вернет false и в сценарии обработка пакета не продолжится
	TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session);
  if(pC)
  {
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TMaster::NeedContextLoginClientBySession() against try authorized.\n");
    mControlSc->mLoginClient->SetContext(NULL);
    return;
  }
  else
  {
		pC = mMngContextClientLogining->AddContext(id_session);
  }
  // назначить контекст
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientByClientKey(unsigned int id_key_client)
{
  unsigned int id_session_client;
  if(mMngContextClientLogining->FindSessionByClientKey(id_key_client,id_session_client))
  {
    TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session_client);
    if(pC)
      mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
    else
    {
      mControlSc->mLoginClient->SetContext(NULL);
      BL_FIX_BUG();
    }
  }
  else
  {
    mControlSc->mLoginClient->SetContext(NULL);
    //BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------------
void TMaster::NeedNumInQueueLoginClient(unsigned int id_session)
{
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session);
  if(pC==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  unsigned int id_client;
  if(mMngContextClientLogining->FindClientKeyBySession(id_session, id_client)==false)
  {
    BL_FIX_BUG();
    return;
  }
  int index;
  if(mSetClientKeyInQueue->FindIndexByClientKey(id_client,index)==false)
  {
    BL_FIX_BUG();
    return;
  }
  pC->mLoginClient.SetNumInQueue(index + 1);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextDisconnectClient(unsigned int id_client)
{
  bool client_is_logining = false;
  unsigned int id_session_client;
  // проверить есть ли вообще такой клиент
  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(id_client);
  if(pC==NULL)
  {
    if(mMngContextClientLogining->FindSessionByClientKey(id_client,id_session_client)==false)
      return;
    TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session_client);
    if(pC==NULL)
      return;
    client_is_logining = true;
  }
  // переслать дальше SuperServer
  if(mID_SessionUp!=INVALID_HANDLE_SESSION)
  {
    vector<unsigned int> vecID;
    vecID.push_back(id_client);
    mControlSc->mDisClient->SetContext(&pC->mDisClient);
    pC->mDisClient.SetID_Session(mID_SessionUp);
    mControlSc->mDisClient->DisconnectFromMaster(vecID);
  }
  // удалить из кластера
  if(client_is_logining)
    mMngContextClientLogining->DeleteBySession(id_session_client);
  else
  {
    unsigned int id_session_slave;
    if(mMngContextClient->FindSessionByClientKey(id_client, id_session_slave))
    {
      NotifyRecipientAboutDisconnectClient(id_client, pC, id_session_slave);
      // удалять из менеджера Групп нельзя(!), т.к. Клиента может и не быть, но он может быть в Группе
			mMngContextSlave->DeleteByClientKey(id_session_slave, id_client);
      
      // удалить из статистики
      mStatisticaClientInGroup->DeleteByClientKey(id_session_slave, id_client);
    }
    mMngContextClient->DeleteByKey(id_client);
  }

	TryAddClientFromQueue();
}
//-------------------------------------------------------------------------
void TMaster::EndDisconnectClient(IScenario* pSc)
{

}
//-------------------------------------------------------------------------
void TMaster::TryAddClientFromQueue()
{
  unsigned int id_client;
  unsigned int id_session_slave;
  if(TryFindClientForAdd(id_client, id_session_slave)==false)
    return;
  unsigned int id_session_client;// для проверки
  if(mMngContextClientLogining->FindSessionByClientKey(id_client, id_session_client)==false)
  {
    BL_FIX_BUG();
    return;
  }
  TContainerContextSc* pC = mMngContextClientLogining->FindContextBySession(id_session_client);
  if(pC==NULL)
  {
    BL_FIX_BUG();
    return;
  }

  void* resForClient = pC->mLoginClient.GetSaveQueueDataPtr();
	int sizeResClient  = pC->mLoginClient.GetSaveQueueDataSize();
	// начали процесс авторизации
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
  AddClientBySlaveSession(id_client,id_session_slave,resForClient,sizeResClient);
}
//-------------------------------------------------------------------------
unsigned char TMaster::GetLimitLoadProcentByKey(unsigned int id_client)
{
  // Решение проблемы: если клиент состоит в группе и у него произошел
  // дисконнект, то он должен войти в систему по запросу в любом случае,
  // т.е. его приоритет выше чем у других клиентов
  unsigned int id_group;
  if(mMngGroup->FindIDByClientKey(id_client, id_group))
    return eLimitLoadProcentOnSlaveForAdd_ClientInGroup;
  return eLimitLoadProcentOnSlaveForAdd;
}
//-------------------------------------------------------------------------
bool TMaster::TryAddClientByGroup(unsigned int id_client, unsigned int id_group, 
                                  unsigned int& id_session_slave)
{
  if(mMngGroup->FindSessionByID(id_group, id_session_slave)==false)
  {
    BL_FIX_BUG();
    return false;
  }
  unsigned char load_procent;
  if(mMngContextSlave->FindLoadBySession(id_session_slave, load_procent)==false)
  {
    BL_FIX_BUG();
    return false;
  }
  if(load_procent < GetLimitLoadProcentByKey(id_client))
    return true;
  return false;
}
//-------------------------------------------------------------------------
bool TMaster::TryAddClient(unsigned int id_client, 
                           unsigned int& id_session_slave)
{
  unsigned char load_procent;
  if(mMngContextSlave->FindMinimumLoad(id_session_slave,load_procent)==false)
  {
  	// генерация ошибки
  	GetLogger(STR_NAME_MMO_ENGINE)->
  		WriteF_time("TMaster::SetResultLogin() count slave = 0.\n");
  	BL_FIX_BUG();
  	return false;
  }
  unsigned char limitLoadProcent = GetLimitLoadProcentByKey(id_client);
  if(load_procent<limitLoadProcent)
    return true;
  return false;
}
//-------------------------------------------------------------------------
void TMaster::AddClientBySlaveSession(unsigned int id_client,
                                      unsigned int id_session_slave, 
                                      void* resForClient, int sizeResClient)
{
  // начали процесс авторизации
  mMngContextSlave->AddClientKey(id_session_slave, id_client);
  mControlSc->mLoginClient->Accept(id_client,resForClient,sizeResClient,
                                   id_session_slave,mID_SessionUp);
}
//-------------------------------------------------------------------------
void TMaster::AddInQueue(unsigned int id_client, void* resForClient, int sizeResClient)
{
  // в очередь на ожидание свободного места
  mSetClientKeyInQueue->AddKeyAtEnd(id_client);
  int index;
  if(mSetClientKeyInQueue->FindIndexByClientKey(id_client,index))
    mControlSc->mLoginClient->Queue(index + 1,resForClient,sizeResClient);
}
//-------------------------------------------------------------------------
bool TMaster::TryFindClientForAdd(unsigned int& id_client, unsigned int& id_session_slave)
{
  // решить на какой Slave
  // перебор клиентов, которые стоят в очереди
  while(1)
  {
    // ищем до тех пора не закончатся клиенты в очереди или не найдем
    if(mSetClientKeyInQueue->DeleteFirst(id_client)==false)
      return false;// пусто
    unsigned int id_session_client;
    if(mMngContextClientLogining->FindSessionByClientKey(id_client,id_session_client)==false)
      continue;// клиента нет, пропуск хода

    unsigned int id_group;
    if(mMngGroup->FindIDByClientKey(id_client, id_group))
    {
      // находится в группе, теперь найти сессию Slave
      if(mMngGroup->FindSessionByID(id_group, id_session_slave)==false)
      {
        BL_FIX_BUG();
        return false;
      }
      return true;
    }
    else
    {
      unsigned char load_procent;
      if(mMngContextSlave->FindMinimumLoad(id_session_slave,load_procent)==false)
      {
        // генерация ошибки
        GetLogger(STR_NAME_MMO_ENGINE)->
          WriteF_time("TMaster::SetResultLogin() count slave = 0.\n");
        BL_FIX_BUG();
        return false;
      }
      return true;
    }
  }
}
//-------------------------------------------------------------------------
bool TMaster::IsClientRecommutation(unsigned int id_client)
{
  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(id_client);
  if(pC==NULL)
    return false;
  if(pC->IsRcmActive())
    return true;
  return false;
}
//-------------------------------------------------------------------------
bool TMaster::LoadInFutureLessLimit(unsigned int id_session_slave, 
                                    list<unsigned int>& l_id_client)
{
  unsigned char load_procent;// текущая нагрузка
  if(mMngContextSlave->FindLoadBySession(id_session_slave, load_procent)==false)
    return false;
  // если нагрузки нет, то выйти
  if(load_procent==0)
    return true;
  // общее кол-во клиентов на Slave
  int countAllClient;
  if(mMngContextSlave->GetCountClientKey(id_session_slave, countAllClient)==false)
    return false;
  if(countAllClient>0)
  {
    int countClientInGroup;// кол-во Клиентов, состоящих в Группах
    if(mStatisticaClientInGroup->FindCountClientBySlaveSession(id_session_slave, countClientInGroup)==false)
      return false;
    // если кол-во добавляемых в виде Группы больше кол-ву Незанятых в Группах,
    // то значит общее кол-во не изменится, не изменится и нагрузка,
    // не изменится потому что будет произведен обмен (см. SolveExchangeClient)
    int countFreeClient = countAllClient - countClientInGroup;
    if(int(l_id_client.size())>countFreeClient)
      return true;
    int countGroupClientInFuture  = countClientInGroup;
    countGroupClientInFuture     += l_id_client.size() - countFreeClient;
    float load_procent_future = (float(load_procent)*countGroupClientInFuture)/countAllClient;
    if(load_procent_future>eLimitLoadProcentOnSlaveForAdd_ClientInGroup)
      return false;
  }
  return true;
}
//-------------------------------------------------------------------------
void TMaster::SolveExchangeClient(unsigned int id_client, 
                                  TContainerContextSc* pC_ClientInGroup, 
                                  unsigned int id_session_slave_recipient)
{
  // если текущий сценарий Клиента находится в процессе Перекоммутации,
  // то невозможно определить где он был или будет, обменивать нечего
  if(pC_ClientInGroup->IsRcmActive())
  {
    RcmByClientKeyContextSlaveSessionRecipient(id_client,
      &pC_ClientInGroup->mRcm, 
      id_session_slave_recipient);
    return;
  }
  //===========================================
  // если его Slave совпадает с новым, то выйти
  unsigned int id_session_slave_donor;
  if(mMngContextClient->FindSessionByClientKey(id_client, id_session_slave_donor)==false)
  {
    BL_FIX_BUG();
    return;
  }
  if(id_session_slave_donor==id_session_slave_recipient)
    return;
  //===========================================
  RcmByClientKeyContextSlaveSessionRecipient(id_client,
    &pC_ClientInGroup->mRcm, 
    id_session_slave_recipient);
  //===========================================
  // Донору надо отдать от Реципиента Клиента взамен Группового
  // ищем какой именно
  int countClientOnSlaveRecipient;
  if(mMngContextSlave->GetCountClientKey(id_session_slave_recipient, countClientOnSlaveRecipient)==false)
  {
    BL_FIX_BUG();
    return;
  }
  // перебор всех Клиентов Реципиента
  for( int i = 0 ; i < countClientOnSlaveRecipient ; i++ )
  {
    unsigned int id_client_on_recipient;
    if(mMngContextSlave->GetClientKeyByIndex(id_session_slave_recipient, i, id_client_on_recipient)==false)
    {
      BL_FIX_BUG();
      return;
    }
    // он должен быть свободен, без Группы
    unsigned int id_group;
    if(mMngGroup->FindIDByClientKey(id_client_on_recipient,id_group)==false)
    {
      TContainerContextSc* pC_client_on_recipient = mMngContextClient->FindContextByClientKey(id_client_on_recipient);
      if(pC_client_on_recipient==NULL)
      {
        BL_FIX_BUG();
        return;
      }
      // если Клиент находится в процессе Перекоммутации, то он нам не подходит, ищем следующего
      if(pC_client_on_recipient->IsRcmActive())
        continue;
      RcmByClientKeyContextSlaveSessionRecipient(id_client_on_recipient,
        &pC_client_on_recipient->mRcm, 
        id_session_slave_donor);
      return;
    }
  }
}
//-------------------------------------------------------------------------
void TMaster::RcmByClientKeyContextSlaveSessionRecipient(unsigned int id_client,
                                           TContextScRecommutationClient* pCRCM, 
                                           unsigned int id_session_slave_recipient)
{
  mControlSc->mRcm->SetContext(pCRCM);
  mControlSc->mRcm->Start(id_session_slave_recipient, id_client);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextSendToClient(unsigned int id_client)
{
	TContainerContextSc* pContext = mMngContextClient->FindContextByClientKey(id_client);
	if(pContext)
		mControlSc->mSendToClient->SetContext(&pContext->mSendToClient);
	else
		mControlSc->mSendToClient->SetContext(NULL);
}
//-------------------------------------------------------------------------
void TMaster::EndRcm(IScenario* pSc)
{
  TContextScRecommutationClient* pContext = (TContextScRecommutationClient*)pSc->GetContext();
  unsigned int key = pContext->GetClientKey();
  mMngRcm->DeleteByClientKey(key);

  // переместить с одного Slave на другой
  unsigned int id_session_recipient = pContext->GetSessionRecipient();
  bool res = mMngContextClient->SetSessionByClientKey(key,id_session_recipient);
  BL_ASSERT(res);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextByClientKeyRcm(unsigned int key)
{
  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(key);
  if(pC)
    mControlSc->mRcm->SetContext(&pC->mRcm);
  else
    mControlSc->mRcm->SetContext(NULL);
}
//-------------------------------------------------------------------------
void TMaster::NeedSlaveSessionDonorRcm(IScenario* pSc)
{
  TContextScRecommutationClient* pContext = (TContextScRecommutationClient*)pSc->GetContext();
  unsigned int key = pContext->GetClientKey();
  unsigned int id_session_donor;
  if(mMngContextClient->FindSessionByClientKey(key, id_session_donor))
    pContext->SetSessionDonor(id_session_donor);
  else
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TMaster::NeedSlaveSessionDonor() key = %u not found donor.\n", key);
    BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------------
void TMaster::EventActivateRcm(IScenario* pSc)
{
  TContextScRecommutationClient* pContext = (TContextScRecommutationClient*)pSc->GetContext();
  unsigned int key = pContext->GetClientKey();
  unsigned int id_session_donor     = pContext->GetSessionDonor(),
               id_session_recipient = pContext->GetSessionRecipient();

  mMngRcm->AddClientKey(key,id_session_donor, id_session_recipient);
}
//-------------------------------------------------------------------------
void TMaster::NotifyRecipientAboutDisconnectClient(unsigned int id_client,
                                                   TContainerContextSc* pC,
                                                   unsigned int id_session)
{
  unsigned int id_session_donor, id_session_recipient;
  if(mMngRcm->FindSessionByClientKey(id_client,id_session_donor, id_session_recipient)==false)
    return;
  
  mMngRcm->DeleteByClientKey(id_client);

  if(id_session==id_session_recipient)
    return;
  // уведомить Реципиента об удалении Клиента
  mControlSc->mRcm->SetContext(&pC->mRcm);
  mControlSc->mRcm->DisconnectClient();
}
//-------------------------------------------------------------------------

