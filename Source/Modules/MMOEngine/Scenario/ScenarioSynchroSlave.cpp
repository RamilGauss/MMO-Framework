/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/BL_Debug.h"

#include "MMOEngine/Scenario/ScenarioSynchroSlave.h"
#include "MMOEngine/SubSystem/SessionManager.h"

using namespace nsMMOEngine;

TScenarioSynchroSlave::TScenarioSynchroSlave()
{

}
//---------------------------------------------------------------------
TScenarioSynchroSlave::~TScenarioSynchroSlave()
{

}
//---------------------------------------------------------------------
void TScenarioSynchroSlave::SendSynchro(float loadProcent)
{
    mBP.Reset();
    THeaderSynchroSlave h;
    h.loadProcent = loadProcent;
    mBP.PushFront((char*)&h, sizeof(h));
    Context()->GetMS()->Send(Context()->GetSessionID(), mBP);
}
//---------------------------------------------------------------------
void TScenarioSynchroSlave::Recv(TDescRecvSession* pDesc)
{
    NeedContextBySession(pDesc->sessionID);
    THeaderSynchroSlave* pPacket = (THeaderSynchroSlave*)pDesc->data;
    switch (pPacket->subType) {
    case eFromSlave:
        RecvFromSlave(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//---------------------------------------------------------------------
void TScenarioSynchroSlave::RecvFromSlave(TDescRecvSession* pDesc)
{
    THeaderSynchroSlave* pPacket = (THeaderSynchroSlave*)pDesc->data;
    bool res = Begin();
    BL_ASSERT(res);
    Context()->SetSessionID(pDesc->sessionID);
    Context()->SetLoadProcent(pPacket->loadProcent);
    End();
}
//--------------------------------------------------------------------------
