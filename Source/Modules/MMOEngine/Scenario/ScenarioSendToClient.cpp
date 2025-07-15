/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SrcEvent_ex.h"

#include "MMOEngine/Include/Events.h"

#include "MMOEngine/Scenario/ScenarioSendToClient.h"
#include "MMOEngine/SubSystem/SessionManager.h"

using namespace nsMMOEngine;

TScenarioSendToClient::TScenarioSendToClient()
{

}
//-------------------------------------------------------------------
TScenarioSendToClient::~TScenarioSendToClient()
{

}
//-------------------------------------------------------------------
void TScenarioSendToClient::Recv(TDescRecvSession* pDesc)
{
    THeader* pPacket = (THeader*)pDesc->data;
    switch (pPacket->subType) {
    case eSuperServer:
        RecvFromSuperServer(pDesc);
        break;
    case eMaster:
        RecvFromMaster(pDesc);
        break;
    case eSlave:
        RecvFromSlave(pDesc);
        break;
    }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromSuperServer(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
    SendAll<THeaderSuperServer>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromMaster(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
    SendAll<THeaderMaster>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromSlave(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
    SendAll<THeaderSlave>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromSuperServer(TDescRecvSession* pDesc)
{
    THeaderSuperServer* pH = (THeaderSuperServer*)pDesc->data;
    NeedContextByClientKey(pH->clientKey);
    if (Context()) {
        mBP.Reset();
        mBP.PushFront(pDesc->data + sizeof(THeaderSuperServer),
            pDesc->dataSize - sizeof(THeaderSuperServer));

        Send<THeaderMaster>(pH->clientKey, mBP);
    }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromMaster(TDescRecvSession* pDesc)
{
    THeaderMaster* pH = (THeaderMaster*)pDesc->data;
    NeedContextByClientKey(pH->clientKey);
    if (Context()) {
        mBP.Reset();
        mBP.PushFront(pDesc->data + sizeof(THeaderMaster),
            pDesc->dataSize - sizeof(THeaderMaster));

        Send<THeaderSlave>(pH->clientKey, mBP);
    }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromSlave(TDescRecvSession* pDesc)
{
    THeaderSlave* pH = (THeaderSlave*)pDesc->data;

    TRecvFromUpEvent* pEvent = new TRecvFromUpEvent;
    // отцепиться от памяти, в которой содержится пакет
    // отдать память под контроль события
    pEvent->c = pDesc->c;
    pEvent->SetShift(sizeof(THeaderSlave));
    // откуда пришел пакет - сессия
    pEvent->sessionID = pDesc->sessionID;
    // добавить событие без копирования и указать истинное время создания события в транспорте
    Context()->GetSE()->AddEventWithoutCopy<TRecvFromUpEvent>(pEvent, pDesc->time_ms);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::DelayBegin()
{
    Context()->SendAndRemoveFirst();
    End();
}
//-------------------------------------------------------------------
