/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Client.h"
#include "SessionManager.h"
#include "ControlScenario.h"
#include "IScenarioContext.h"
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
    if (count != 1) {
        TErrorEvent event;
        event.code = OpenClient_MoreThenOneSubNet;
        AddEventCopy(&event, sizeof(event));
        BL_FIX_BUG();
        return false;
    }
    mSubNet = pDesc[0].subNet;
    return mSessionManager->Start(pDesc, 1);
}
//-------------------------------------------------------------------------
void TClient::Login(TIP_Port& ip_port, std::string& login, std::string& password)
{
    if (IsConnectUp()) {
        TErrorEvent event;
        event.code = LoginClient_ClientSecondEnter;
        AddEventCopy(&event, sizeof(event));
        return;
    }
    if (login.size() == 0 || password.size() == 0) {
        TErrorEvent event;
        event.code = LoginClient_EmptyLoginPassword;
        AddEventCopy(&event, sizeof(event));
        return;
    }

    mControlSc->mLoginClient->TryLogin(ip_port, login, password, mSubNet);

    mControlSc->mRcm->SetClientLoginPassword(login, password);
}
//-------------------------------------------------------------------------
void TClient::DisconnectInherit(unsigned int sessionID)
{
    // тут проблема в том, что бы различить дисконнект со стороны Мастера при 
    // отработке сценария LoginClient от других
    if (mContainerUp->IsLoginClientActive())// активен сценарий LoginClient
    {
        // возможно это продолжение сценария
        mControlSc->mLoginClient->DisconnectFromClient();
        return;
    }
    // Rcm
    if (mContainerUp->IsRcmActive())// активен сценарий перекоммутации
    {
        // возможно это продолжение сценария
        mControlSc->mRcm->DisconnectFromClient(mSubNet);
        return;
    }
    // в остальных случаях это действительно потеря связи
    mSessionUpID = INVALID_HANDLE_SESSION;
    TDisconnectUpEvent event;
    event.sessionID = sessionID;
    AddEventCopy(&event, sizeof(event));
}
//-------------------------------------------------------------------------
void TClient::EndLoginClient(IScenario* pSc)
{
    // взять по этому контексту, задать всем контекстам
    mSessionUpID = pSc->GetContext()->GetSessionID();
    mContainerUp->SetSessionID(mSessionUpID);
}
//-------------------------------------------------------------------------
void TClient::EndRcm(IScenario* pSc)
{
    // взять по этому контексту, задать всем контекстам
    mSessionUpID = pSc->GetContext()->GetSessionID();
    mContainerUp->SetSessionID(mSessionUpID);
}
//-------------------------------------------------------------------------
void TClient::LeaveQueue()
{
    if (mContainerUp->IsLoginClientActive())
        mControlSc->mLoginClient->LeaveQueue();
}
//-------------------------------------------------------------------------
void TClient::EventSetClientKeyLoginClient(unsigned int clientKey)
{
    mID = clientKey;
}
//-------------------------------------------------------------------------
