/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenarioFlow.h"
#include "Events.h"
#include "SessionManager.h"

using namespace nsMMOEngine;

TScenarioFlow::TScenarioFlow()
{

}
//-------------------------------------------------------------------------
TScenarioFlow::~TScenarioFlow()
{

}
//-------------------------------------------------------------------------
void TScenarioFlow::SendUp(TBreakPacket& bp, bool check)
{
    THeaderSendUp h;
    bp.PushFront((char*)&h, sizeof(h));
    HandlePacket(bp, check);
}
//-------------------------------------------------------------------------
void TScenarioFlow::SendDown(TBreakPacket& bp, bool check)
{
    THeaderSendDown h;
    bp.PushFront((char*)&h, sizeof(h));
    HandlePacket(bp, check);
}
//-------------------------------------------------------------------------
void TScenarioFlow::Recv(TDescRecvSession* pDesc)
{
    NeedContextBySession(pDesc->sessionID);

    THeaderFlow* pPacket = (THeaderFlow*)pDesc->data;
    switch (pPacket->subType) {
    case eUp:
        Recv<TRecvFromDownEvent>(pDesc);
        break;
    case eDown:
        Recv<TRecvFromUpEvent>(pDesc);
        break;
    }
}
//-------------------------------------------------------------------------
void TScenarioFlow::DelayBegin()
{
    Context()->SendAndRemoveFirst();
    End();
}
//-------------------------------------------------------------------------
void TScenarioFlow::HandlePacket(TBreakPacket& bp, bool check)
{
    // попытаться активизироваться
    if (Begin()) {
        // отсылка сразу
        Context()->Send(bp, check);
        // сценарий закончен
        End();
    } else {
        // пока отослать нельзя, сохранить пакет до момента возможности
        Context()->SaveBreakPacket(bp, check);
    }
}
//-------------------------------------------------------------------------
