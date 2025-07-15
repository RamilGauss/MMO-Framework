/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <stddef.h>

#include "Base/Common/BL_Debug.h"

#include "MMOEngine/SubSystem/MakerScenario.h"
#include "MMOEngine/SubSystem/IScenario.h"

#include "MMOEngine/Scenario/ScenarioDisconnectClient.h"
#include "MMOEngine/Scenario/ScenarioFlow.h"
#include "MMOEngine/Scenario/ScenarioLoginClient.h"
#include "MMOEngine/Scenario/ScenarioLoginMaster.h"
#include "MMOEngine/Scenario/ScenarioLoginSlave.h"
#include "MMOEngine/Scenario/ScenarioSendToClient.h"
#include "MMOEngine/Scenario/ScenarioSynchroSlave.h"
#include "MMOEngine/Scenario/ScenarioRecommutationClient.h"

using namespace nsMMOEngine;

TMakerScenario::TMakerScenario()
{

}
//----------------------------------------------------------------------
TMakerScenario::~TMakerScenario()
{
    for (IScenario* p : mSetMakeSc) {
        delete p;
    }
}
//----------------------------------------------------------------------
IScenario* TMakerScenario::New(unsigned int ID_Implementation)
{
    IScenario* pSc = nullptr;
    switch (ID_Implementation) {
    case eDisconnectClient:
        pSc = new TScenarioDisconnectClient;
        break;
    case eFlow:
        pSc = new TScenarioFlow;
        break;
    case eLoginClient:
        pSc = new TScenarioLoginClient;
        break;
    case eLoginMaster:
        pSc = new TScenarioLoginMaster;
        break;
    case eLoginSlave:
        pSc = new TScenarioLoginSlave;
        break;
    case eRecommutationClient:
        pSc = new TScenarioRecommutationClient;
        break;
    case eSendToClient:
        pSc = new TScenarioSendToClient;
        break;
    case eSynchroSlave:
        pSc = new TScenarioSynchroSlave;
        break;
    default:BL_FIX_BUG();
    }
    if (pSc) {
        pSc->SetType(ID_Implementation);
        mSetMakeSc.insert(pSc);
    }
    return pSc;
}
//----------------------------------------------------------------------
void TMakerScenario::Delete(IScenario* p)
{
    mSetMakeSc.erase(p);
    delete p;
}
//----------------------------------------------------------------------
