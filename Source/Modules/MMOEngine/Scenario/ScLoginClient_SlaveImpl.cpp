/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScLoginClient_SlaveImpl.h"
#include "ContextScLoginClient.h"
#include "SessionManager.h"
#include "Base.h"
#include "Base/Common/Logger.h"
#include "Events.h"
#include "EnumMMO.h"

#include "Base/Common/SrcEvent_ex.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_SlaveImpl::TScLoginClient_SlaveImpl(IScenario* pSc) :
    TBaseScLoginClient(pSc)
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvInherit(TDescRecvSession* pDesc)
{
    // защита от хака
    if (pDesc->dataSize < sizeof(THeader)) {
        return;
    }
    //=======================================
    THeader* pHeader = (THeader*)pDesc->data;
    switch (pHeader->from) {
    case eClient:
        RecvFromClient(pDesc);
        break;
    case eMaster:
        RecvFromMaster(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::Work(unsigned int time_ms)
{
    if (Context()->IsStateTimeExpired(time_ms) == false)
        return;

    auto errorType = Context()->GetCurrentStateErrorCode();

    // ошибка на той стороне
    // непонятно в чем дело, но клиент сдох
    TErrorEvent event;
    event.code = (nsMMOEngine::ErrorCode)errorType;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvFromClient(TDescRecvSession* pDesc)
{
    THeader* pHeader = (THeader*)pDesc->data;
    switch (pHeader->subType) {
    case eConnectToSlaveC2S:
        ConnectToSlaveC2S(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
    THeader* pHeader = (THeader*)pDesc->data;
    switch (pHeader->subType) {
    case eInfoClientM2S:
        InfoClientM2S(pDesc);
        break;
    case eCheckClientConnectM2S:
        CheckClientConnectM2S(pDesc);
        break;
    case eDisconnectClientM2S:
        DisconnectClientM2S(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::ConnectToSlaveC2S(TDescRecvSession* pDesc)
{
    // защита от хака
    if (pDesc->dataSize < sizeof(THeaderConnectToSlaveC2S))
        return;

    THeaderConnectToSlaveC2S* pHeader = (THeaderConnectToSlaveC2S*)pDesc->data;
    // существует ли вообще клиент с данным ключом,
    // то есть был ли добавлен на ожидание от Мастера данный Клиент
    // загрузить контекст для работы
    NeedContextByClientSessionByClientKey(pDesc->sessionID, pHeader->clientKey);

    if (Context() == nullptr) {
        // генерация ошибки
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScLoginClient_SlaveImpl::SetIsExistClientID() id client is not exist.\n");
        BL_FIX_BUG();
        return;
    }
    // запомнить сессию Клиента
    SetID_SessionClientSlave(pDesc->sessionID);

    // уведомить Мастера о запросе от клиента
    THeaderClientConnectS2M h;
    h.clientKey = Context()->GetClientKey();// указать какой клиент захотел соединиться
    mBP.Reset();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);

    Context()->SetCurrentStateWait(TContextScLoginClient::SlaveWaitMaster);
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::InfoClientM2S(TDescRecvSession* pDesc)
{
    THeaderInfoClientM2S* pHeader = (THeaderInfoClientM2S*)pDesc->data;
    NeedContextByClientKey(pHeader->clientKey);
    if (Context() == nullptr) {
        BL_FIX_BUG();
        return;
    }
    //--------------------------------------------
    // начало сценария
    if (Context()->WasBegin() == false) {
        // стартовали впервые
        Context()->SetWasBegin();
        if (Begin() == false) {
            // генерация ошибки
            GetLogger(STR_NAME_MMO_ENGINE)->
                WriteF_time("TScLoginClient_SlaveImpl::InfoClientM2S() scenario is not active.\n");
            BL_FIX_BUG();
            return;
        }
    }
    // Если WasBegin==true - старт уже был, Мастер не дождался, Клиент остановил у себя сценарий
    // потом Клиент еще раз попытался авторизоваться, а Slave еще его ждет, т.е. это уже
    // вторая попытка войти. Что ж продолжим авторизацию.

    // запомнить сессию
    SetID_SessionMasterSlave(pDesc->sessionID);

    Context()->SetClientKey(pHeader->clientKey);
    // сформировать квитанцию
    mBP.Reset();
    THeaderCheckInfoClientS2M h;
    h.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);

    Context()->SetCurrentStateWait(TContextScLoginClient::SlaveWaitClient);
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::CheckClientConnectM2S(TDescRecvSession* pDesc)
{
    THeaderCheckClientConnectM2S* pHeader = (THeaderCheckClientConnectM2S*)pDesc->data;
    NeedContextByClientKey_SecondCallSlave(pHeader->clientKey);
    if (Context() == nullptr)
        return;
    //--------------------------------------------
    // отсылка уведомления Developer Slave события Connect
    TConnectDownEvent* pEvent = new TConnectDownEvent;
    pEvent->sessionID = GetID_SessionClientSlave();

    Context()->GetSE()->AddEventWithoutCopy<TConnectDownEvent>(pEvent);
    // отослать клиенту уведомление
    THeaderCheckConnectToSlaveS2C h;
    mBP.Reset();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionClientSlave(), mBP);
    Context()->Accept();

    Context()->SetCurrentStateWait(TContextScLoginClient::NoWait);
    End();
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::DisconnectClientM2S(TDescRecvSession* pDesc)
{
    THeaderDisconnectClientM2S* pH = (THeaderDisconnectClientM2S*)pDesc->data;
    NeedContextByClientKey(pH->clientKey);

    if (Context() == nullptr) {
        BL_FIX_BUG();
        return;
    }
    Context()->Reject();
    Context()->GetMS()->CloseSession(Context()->GetID_SessionClientSlave());
    End();
}
//--------------------------------------------------------------
