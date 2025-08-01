/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ControlScenario.h"
#include "Base/Common/BL_Debug.h"
#include "DescRecvSession.h"

#include "MMOEngine/Scenario/ScenarioDisconnectClient.h"
#include "MMOEngine/Scenario/ScenarioFlow.h"
#include "MMOEngine/Scenario/ScenarioLoginClient.h"
#include "MMOEngine/Scenario/ScenarioLoginSlave.h"
#include "MMOEngine/Scenario/ScenarioLoginMaster.h"
#include "MMOEngine/Scenario/ScenarioRecommutationClient.h"
#include "MMOEngine/Scenario/ScenarioSendToClient.h"
#include "MMOEngine/Scenario/ScenarioSynchroSlave.h"
#include "MMOEngine/SubSystem/SessionManager.h"

using namespace nsMMOEngine;

TControlScenario::TControlScenario()
{
    mDisClient = (TScenarioDisconnectClient*)mMakerScenario.New(TMakerScenario::eDisconnectClient);
    mFlow = (TScenarioFlow*)mMakerScenario.New(TMakerScenario::eFlow);
    mLoginClient = (TScenarioLoginClient*)mMakerScenario.New(TMakerScenario::eLoginClient);
    mLoginSlave = (TScenarioLoginSlave*)mMakerScenario.New(TMakerScenario::eLoginSlave);
    mLoginMaster = (TScenarioLoginMaster*)mMakerScenario.New(TMakerScenario::eLoginMaster);
    mRcm = (TScenarioRecommutationClient*)mMakerScenario.New(TMakerScenario::eRecommutationClient);
    mSendToClient = (TScenarioSendToClient*)mMakerScenario.New(TMakerScenario::eSendToClient);
    mSynchroSlave = (TScenarioSynchroSlave*)mMakerScenario.New(TMakerScenario::eSynchroSlave);

    Add(mDisClient);
    Add(mFlow);
    Add(mLoginClient);
    Add(mLoginSlave);
    Add(mLoginMaster);
    Add(mRcm);
    Add(mSendToClient);
    Add(mSynchroSlave);
}
//----------------------------------------------------------------------
TControlScenario::~TControlScenario()
{

}
//----------------------------------------------------------------------
void TControlScenario::Add(IScenario* pSc)
{
    mMapTypeSc.insert({ pSc->GetType(), pSc });
}
//----------------------------------------------------------------------
void TControlScenario::Recv(TDescRecvSession* pDesc)
{
    TScenarioBaseHeader* pPacket = (TScenarioBaseHeader*)pDesc->data;
    TMapIntPtrIt fit = mMapTypeSc.find(pPacket->type);
    if (fit != mMapTypeSc.end()) {
        auto scenario = fit->second;
        // защита от получения незащищенных UDP пакетов
        if (pDesc->type == INetTransport::eTypeRecv::eUdp)
            if (scenario != mFlow)// только Flow использует UDP, остальным нельзя
                return;
        scenario->Recv(pDesc);
    } else {
        BL_FIX_BUG();
    }
}
//----------------------------------------------------------------------
