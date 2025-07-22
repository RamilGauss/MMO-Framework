/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/BL_Debug.h"
#include "Base/Common/Logger.h"

#include "ECS/Include/EntityManager.h"

#include "MMOEngine/Include/Master.h"
#include "MMOEngine/Include/Events.h"
#include "MMOEngine/Include/EnumMMO.h"

#include "MMOEngine/SubSystem/ControlScenario.h"
#include "MMOEngine/SubSystem/SessionManager.h"

#include "MMOEngine/Scenario/ScenarioLoginClient.h"
#include "MMOEngine/Scenario/ScenarioLoginSlave.h"
#include "MMOEngine/Scenario/ScenarioLoginMaster.h"
#include "MMOEngine/Scenario/ScenarioFlow.h"
#include "MMOEngine/Scenario/ScenarioRecommutationClient.h"
#include "MMOEngine/Scenario/ScenarioSynchroSlave.h"
#include "MMOEngine/Scenario/ScenarioDisconnectClient.h"
#include "MMOEngine/Scenario/ScenarioSendToClient.h"

#include "MMOEngine/SubSystem/ContainerContextSc.h"

#include "MMOEngine/SubSystem/RCMLogic.h"
#include "MMOEngine/SubSystem/GroupLogic.h"
#include "MMOEngine/SubSystem/SlaveOnMasterLogic.h"
#include "MMOEngine/SubSystem/ClientOnMasterLogic.h"

using namespace nsMMOEngine;

TMaster::TMaster()
{
    mRCMLogic.reset(new TRCMLogic(this));
    mGroupLogic.reset(new TGroupLogic(this));
    mSlaveLogic.reset(new TSlaveOnMasterLogic(this));
    mClientLogic.reset(new TClientOnMasterLogic(this));

    mControlSc->mLoginClient->SetBehavior(TScenarioLoginClient::eMaster);
    mControlSc->mRcm->SetBehavior(TScenarioRecommutationClient::eMaster);
}
//-------------------------------------------------------------------------
bool TMaster::TryCreateGroup(std::list<unsigned int>& clientKeyList, unsigned int& groupID)
{
    return mGroupLogic->TryCreateGroup(clientKeyList, groupID);
}
//-------------------------------------------------------------------------
void TMaster::DestroyGroup(unsigned int groupID)
{
    mGroupLogic->DestroyGroup(groupID);
}
//-------------------------------------------------------------------------
void TMaster::LeaveGroup(unsigned int clientKey)
{
    mGroupLogic->LeaveGroup(clientKey);
}
//-------------------------------------------------------------------------
void TMaster::GetListForGroup(unsigned int groupID, std::list<unsigned int>& clientKeyList)
{
    mGroupLogic->GetListForGroup(groupID, clientKeyList);
}
//-------------------------------------------------------------------------
void TMaster::SetResultLogin(bool res, unsigned int clientSessionID,
    unsigned int clientKey, void* resForClient, int sizeResClient)
{
    mClientLogic->SetResultLogin(res, clientSessionID, clientKey, resForClient, sizeResClient);
}
//-------------------------------------------------------------------------
bool TMaster::FindSlaveSessionByGroup(unsigned int groupID, unsigned int& sessionID)
{
    return mGroupLogic->FindSlaveSessionByGroup(groupID, sessionID);
}
//-------------------------------------------------------------------------
void TMaster::DisconnectInherit(unsigned int sessionID)
{
    if (DisconnectSuperServer(sessionID)) {
        return;
    }
    if (DisconnectClientWait(sessionID)) {
        return;
    }
    if (DisconnectSlave(sessionID)) {
        return;
    }
}
//-------------------------------------------------------------------------
void TMaster::GetDescDown(std::list<unsigned int>& sessionIDList)
{
    mSlaveLogic->GetDescDown(sessionIDList);
}
//-------------------------------------------------------------------------
void TMaster::ConnectUp(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet)
{
    mControlSc->mLoginMaster->ConnectToSuperServer(ip_port, login, password, subNet);
}
//-------------------------------------------------------------------------
void TMaster::EndLoginMaster(IScenario* pSc)
{
    // взять по этому контексту, задать всем контекстам
    mSessionUpID = pSc->GetContext()->GetSessionID();
    mContainerUp->SetSessionID(mSessionUpID);

    if (IsConnectUp()) {
        // вход в кластер закончен
        TConnectUpEvent event;
        event.sessionID = mSessionUpID;
        AddEventCopy(&event, sizeof(event));
    }
}
//-------------------------------------------------------------------------
void TMaster::EndLoginSlave(IScenario* pSc)
{
    mSlaveLogic->EndLoginSlave(pSc);
}
//-------------------------------------------------------------------------
void TMaster::SendDown(unsigned int sessionID, char* p, int size, bool check)
{
    mSlaveLogic->SendDown(sessionID, p, size, check);
}
//-------------------------------------------------------------------------
void TMaster::EndLoginClient(IScenario* pSc)
{
    mClientLogic->EndLoginClient(pSc);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginSlave(unsigned int sessionID)
{
    mSlaveLogic->NeedContextLoginSlave(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextSynchroSlave(unsigned int sessionID)
{
    mSlaveLogic->NeedContextSynchroSlave(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::EndSynchroSlave(IScenario* pSc)
{
    mSlaveLogic->EndSynchroSlave(pSc);
}
//-------------------------------------------------------------------------
void TMaster::SendByClientKey(std::list<unsigned int>& clientKeyList, char* p, int size)
{
    SetupBP(p, size);
    mControlSc->mSendToClient->SendFromMaster(clientKeyList, mBP);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionAfterAuthorised(unsigned int sessionID)
{
    mClientLogic->NeedContextLoginClientBySessionAfterAuthorised(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionLeaveQueue(unsigned int sessionID)
{
    mClientLogic->NeedContextLoginClientBySessionLeaveQueue(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySession(unsigned int sessionID)
{
    mClientLogic->NeedContextLoginClientBySession(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientByClientKey(unsigned int clientKey)
{
    mClientLogic->NeedContextLoginClientByClientKey(clientKey);
}
//-------------------------------------------------------------------------
void TMaster::NeedNumInQueueLoginClient(unsigned int sessionID)
{
    mClientLogic->NeedNumInQueueLoginClient(sessionID);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextDisconnectClient(unsigned int clientKey)
{
    mClientLogic->NeedContextDisconnectClient(clientKey);
}
//-------------------------------------------------------------------------
void TMaster::EndDisconnectClient(IScenario* pSc)
{
    // empty
}
//-------------------------------------------------------------------------
void TMaster::NeedContextSendToClient(unsigned int clientKey)
{
    mClientLogic->NeedContextSendToClient(clientKey);
}
//-------------------------------------------------------------------------
void TMaster::EndRcm(IScenario* pSc)
{
    mRCMLogic->EndRcm(pSc);
}
//-------------------------------------------------------------------------
void TMaster::NeedContextByClientKeyRcm(unsigned int clientKey)
{
    mRCMLogic->NeedContextByClientKeyRcm(clientKey);
}
//-------------------------------------------------------------------------
void TMaster::NeedSlaveSessionDonorRcm(IScenario* pSc)
{
    mRCMLogic->NeedSlaveSessionDonorRcm(pSc);
}
//-------------------------------------------------------------------------
void TMaster::EventActivateRcm(IScenario* pSc)
{
    mRCMLogic->EventActivateRcm(pSc);
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectSuperServer(unsigned int sessionID)
{
    if (sessionID != mSessionUpID) {
        return false;
    }

    mSessionUpID = INVALID_HANDLE_SESSION;

    TDisconnectUpEvent event;
    event.sessionID = mSessionUpID;
    AddEventCopy(&event, sizeof(event));
    return true;
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectClientWait(unsigned int sessionID)
{
    return mClientLogic->DisconnectClientWait(sessionID);
}
//-------------------------------------------------------------------------
bool TMaster::DisconnectSlave(unsigned int sessionID)
{
    return mSlaveLogic->DisconnectSlave(sessionID);
}
//-------------------------------------------------------------------------
