/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SuperServer.h"
#include "ManagerContextMoreDownClientConnection.h"
#include "ManagerContextDownConnection.h"

#include "Logger.h"
#include "IScenario.h"
#include "ContainerContextSc.h"
#include "ControlScenario.h"
#include "Events.h"

#include "ScenarioLoginMaster.h"
#include "ScenarioFlow.h"
#include "ScenarioSendToClient.h"
#include "ScenarioLoginClient.h"
#include "ScenarioDisconnectClient.h"

using namespace nsMMOEngine;

TSuperServer::TSuperServer():
mMngContextClient(new TManagerContextMoreDownClientConnection),
mMngContextMaster(new TManagerContextDownConnection),
mContainer_SecondLogin(new TContainerContextSc)
{
  mControlSc->mLoginClient->SetBehavior(TScenarioLoginClient::eSuperServer);

  SetupScForContext(mContainer_SecondLogin.get());
}
//-------------------------------------------------------------------------
TSuperServer::~TSuperServer()
{

}
//-------------------------------------------------------------------------
void TSuperServer::SendByClientKey(std::list<unsigned int>& lKey, TBreakPacket bp)
{
	mControlSc->mSendToClient->SendFromSuperServer(lKey, bp);
}
//-------------------------------------------------------------------------
void TSuperServer::DisconnectInherit(unsigned int id_session)
{
  if(mMngContextMaster->FindContextBySession(id_session)==NULL)
    return;
  
  // перечислить всех клиентов, которые сид€т на этом мастере и их удаление
  int cClient ;
  if(mMngContextMaster->GetCountClientKey(id_session, cClient)==false)
    return;
  for( int i = 0 ; i < cClient ; i++)
  {
    unsigned int id_client;
    if(mMngContextMaster->GetClientKeyByIndex(id_session, i, id_client))
      mMngContextClient->DeleteByKey(id_client);
  }

  mMngContextMaster->DeleteContextBySession(id_session);

  TEventDisconnectDown event;
  event.id_session = id_session;
  AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------
int TSuperServer::GetCountDown()
{
	return mMngContextMaster->GetCountSession();
}
//-------------------------------------------------------------------------
bool TSuperServer::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  if(sizeDesc<sizeof(TDescDownSuperServer))
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TSuperServer::GetDescDown() size of buffer less then size of structure.\n");
    return false;
  }

  unsigned int id_session;
  if(mMngContextMaster->GetSessionByIndex(index, id_session)==false)
    return false;
  // кол-во клиентов на дднном мастере
  int countClient;
  if(mMngContextMaster->GetCountClientKey(id_session, countClient)==false)
    return false;

  TDescDownSuperServer* pD = (TDescDownSuperServer*)pDesc;
  pD->id_session  = id_session;
  pD->countClient = countClient;
  sizeDesc = sizeof(TDescDownSuperServer);
  return true;
}
//-------------------------------------------------------------------------
void TSuperServer::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  TContainerContextSc* pC = mMngContextMaster->FindContextBySession(id_session);
  if(pC==NULL)
    return;
  mControlSc->mFlow->SetContext(&pC->mFlow);
  mControlSc->mFlow->SendDown(bp,check);
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextLoginMaster(unsigned int id_session)
{
  TContainerContextSc* pC = mMngContextMaster->FindContextBySession(id_session);
  if(pC)
  {
    // внутренн€€ ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TSuperServer::LoginMaster() against try authorized.\n");
    return;
  }
  pC = mMngContextMaster->AddContext(id_session);
  // назначить контекст дл€ сценари€
  mControlSc->mLoginMaster->SetContext(&pC->mLoginMaster);
  // событие наружу
  TEventConnectDown event;
  event.id_session = id_session;
  AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextByMasterSessionByClientKey(unsigned int id_session,
                                                         unsigned int id_client)
{
  // проверка на существование мастера
  if(mMngContextMaster->FindContextBySession(id_session)==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey(id_client);
  bool fakeClient = false;
  if(pC==NULL)
  {
    // первый заход
    mMngContextMaster->AddClientKey(id_session,id_client);
    pC = mMngContextClient->AddContext(id_client,id_session);
    fakeClient = false;
  }
  else
  {
    // повторна€ авторизаци€
    pC = mContainer_SecondLogin.get();
    fakeClient = true;
  }
  mControlSc->mLoginClient->SetContext(&pC->mLoginClient);
  mControlSc->mLoginClient->SetFakeClient(fakeClient);
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextDisconnectClient(unsigned int id_client)
{
  unsigned int id_session_master;
  // удалить запись в ћастере
  if(mMngContextClient->FindSessionByClientKey(id_client,id_session_master))
    mMngContextMaster->DeleteByClientKey(id_session_master, id_client);
  // и сам клиент
  mMngContextClient->DeleteByKey(id_client);
}
//-------------------------------------------------------------------------
void TSuperServer::EndDisconnectClient(IScenario* pSc)
{

}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextSendToClient(unsigned int id_client)
{
	TContainerContextSc* pContext = mMngContextClient->FindContextByClientKey(id_client);
	if(pContext)
		mControlSc->mSendToClient->SetContext(&pContext->mSendToClient);
	else
		mControlSc->mSendToClient->SetContext(NULL);
}
//-------------------------------------------------------------------------
