/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Client.h"
#include "ManagerSession.h"
#include "ControlScenario.h"
#include "IContextScenario.h"
#include "ContainerContextSc.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioRecommutationClient.h"
#include "Events.h"
#include "EnumMMO.h"

using namespace std;
using namespace nsMMOEngine;

TClient::TClient()
{
	mSubNet = 0;
  mControlSc->mLoginClient->SetBehavior(TScenarioLoginClient::eClient);
	mControlSc->mRcm->SetBehavior(TScenarioRecommutationClient::eClient);
}
//-------------------------------------------------------------------------
TClient::~TClient()
{

}
//-------------------------------------------------------------------------
bool TClient::Open(TDescOpen* pDesc, int count)
{
	if(count!=1)
	{
		TEventError event;
		event.code = OpenClient_MoreThenOneSubNet;
		AddEventCopy(&event, sizeof(event));
		BL_FIX_BUG();
		return false;
	}
	mSubNet = pDesc[0].subNet;
	return mManagerSession->Start(pDesc, 1);
}
//-------------------------------------------------------------------------
void TClient::Login(unsigned int ip, unsigned short port, void* data, int size)
{
  if(IsConnectUp())
  {
    TEventError event;
    event.code = LoginClient_ClientSecondEnter;
    AddEventCopy(&event, sizeof(event));
    return;
  }

  mControlSc->mLoginClient->TryLogin(ip, port, data, size, mSubNet);
}
//-------------------------------------------------------------------------
void TClient::DisconnectInherit(unsigned int id_session)
{
  // тут проблема в том, что бы различить дисконнект со стороны ћастера при 
  // отработке сценари€ LoginClient от других
  if(mContainerUp->IsLoginClientActive())// активен сценарий LoginClient
  {
    // возможно это продолжение сценари€
    mControlSc->mLoginClient->DisconnectFromClient();
    return;
  }
  // Rcm
  if(mContainerUp->IsRcmActive())// активен сценарий перекоммутации
  {
    // возможно это продолжение сценари€
    mControlSc->mRcm->DisconnectFromClient(mSubNet);
    return;
  }
  // в остальных случа€х это действительно потер€ св€зи
  mID_SessionUp = INVALID_HANDLE_SESSION;
	TEventDisconnectUp event;
	event.id_session = id_session;
  AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------
void TClient::EndLoginClient(IScenario* pSc)
{
  // вз€ть по этому контексту, задать всем контекстам
  mID_SessionUp = pSc->GetContext()->GetID_Session();
  mContainerUp->SetID_Session(mID_SessionUp);
}
//-------------------------------------------------------------------------
void TClient::EndRcm(IScenario* pSc)
{
  // вз€ть по этому контексту, задать всем контекстам
  mID_SessionUp = pSc->GetContext()->GetID_Session();
  mContainerUp->SetID_Session(mID_SessionUp);
}
//-------------------------------------------------------------------------
void TClient::LeaveQueue()
{
  if(mContainerUp->IsLoginClientActive())
    mControlSc->mLoginClient->LeaveQueue();
}
//-------------------------------------------------------------------------
void TClient::EventSetClientKeyLoginClient(unsigned int id_client)
{
  mID = id_client;
}
//-------------------------------------------------------------------------
