/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScRecommutationClient_SlaveImpl.h"
#include "Logger.h"
#include "SessionManager.h"
#include "BaseScRecommutationClient_Struct.h"
#include "ContextScRecommutationClient.h"
#include "Events.h"
#include "SrcEvent_ex.h"
#include "DescRequestConnectForRecipient.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;


TScRecommutationClient_SlaveImpl::TScRecommutationClient_SlaveImpl(IScenario* pSc) :
    TBaseScRecommutationClient(pSc)
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::Work(unsigned int time_ms)
{
    unsigned int time_wait_ms = Context()->GetTimeWait() + eTimeWait;
    if (time_wait_ms < time_ms) {
        if (Context()->IsDonor()) {
            TDisconnectDownEvent event;
            event.sessionID = Context()->GetID_SessionClientSlave();
            Context()->GetSE()->AddEventCopy(&event, sizeof(event));
        }

        EventTimeClientElapsed(Context()->GetClientKey());
        Context()->GetMS()->CloseSession(Context()->GetID_SessionClientSlave());
    }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvInherit(TDescRecvSession* pDesc)
{
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
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
    THeader* pHeader = (THeader*)pDesc->data;
    switch (pHeader->subType) {
    case eBeginDonor:
        BeginDonor(pDesc);
        break;
    case eInfoRecipientToDonor:
        InfoRecipientToDonor(pDesc);
        break;
    case eBeginRecipient:
        BeginRecipient(pDesc);
        break;
    case eDisconnectClient:
        DisconnectClientToSlave(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvFromClient(TDescRecvSession* pDesc)
{
    // защита от хака
    if (pDesc->dataSize < sizeof(THeader)) {
        return;
    }
    //=======================================
    THeader* pHeader = (THeader*)pDesc->data;
    switch (pHeader->subType) {
    case eCheckBeginClient:
        CheckBeginClient(pDesc);
        break;
    case eCheckInfoRecipient:
        CheckInfoRecipient(pDesc);
        break;
    case eRequestConnect:
        RequestConnect(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::BeginDonor(TDescRecvSession* pDesc)
{
    THeaderBeginDonor* pHeader = (THeaderBeginDonor*)pDesc->data;
    NeedContextByClientKeyForSlave(pHeader->clientKey, true);
    if (Context() == nullptr) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::BeginDonor() Context()==NULL.\n");
        BL_FIX_BUG();
        return;
    }
    //--------------------------------------------
    Context()->SetClientKey(pHeader->clientKey);
    Context()->SetRoleAsDonor();// роль Донора
    // начало сценария
    if (Begin() == false) {
        // генерация ошибки
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::BeginDonor() scenario is not active.\n");
        BL_FIX_BUG();
        return;
    }
    // сформировать пакет далее для Клиента
    mBP.Reset();
    THeaderBeginClient h;
    h.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionClientSlave(), mBP);

    SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::InfoRecipientToDonor(TDescRecvSession* pDesc)
{
    THeaderInfoRecipientToDonor* pHeader = (THeaderInfoRecipientToDonor*)pDesc->data;
    NeedContextByClientKeyForSlave(pHeader->clientKey, true);
    if (Context() == nullptr) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::InfoRecipientToDonor() Context()==NULL.\n");
        BL_FIX_BUG();
        return;
    }
    //--------------------------------------------
    mBP.Reset();
    THeaderInfoRecipientToClient h;
    h.clientKey = pHeader->clientKey;
    h.ip_port_recipient = pHeader->ip_port_recipient;
    h.random_num = pHeader->random_num;
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionClientSlave(), mBP);

    SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::BeginRecipient(TDescRecvSession* pDesc)
{
    THeaderBeginRecipient* pHeader = (THeaderBeginRecipient*)pDesc->data;
    NeedContextByClientKeyForSlave(pHeader->clientKey, false);
    if (Context() == nullptr) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::BeginRecipient() Context()==NULL.\n");
        BL_FIX_BUG();
        return;
    }
    //--------------------------------------------
    Context()->SetRandomNum(pHeader->random_num);
    Context()->SetClientKey(pHeader->clientKey);
    Context()->SetRoleAsRecipient();// роль Реципиента
    Context()->SetID_SessionMasterSlave(pDesc->sessionID);
    // начало сценария
    if (Begin() == false) {
        // генерация ошибки
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::BeginRecipient() scenario is not active.\n");
        BL_FIX_BUG();
        return;
    }
    // сохранить Контекст в контекст (извините за каламбур)
    // Slave еще рано отдавать Контекст
    Context()->SaveContextData(pDesc->data + sizeof(THeaderBeginRecipient),
        pDesc->dataSize - sizeof(THeaderBeginRecipient));
    // сформировать пакет далее для Мастера
    mBP.Reset();
    THeaderCheckBeginRecipient h;
    h.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);

    SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::DisconnectClientToSlave(TDescRecvSession* pDesc)
{
    THeaderDisconnectClient* pHeader = (THeaderDisconnectClient*)pDesc->data;
    EventDisconnectClient(pHeader->clientKey);
    // вызывать End(); нельзя, потому что тогда в Slave отработает по окончанию сценария 
    // добавлением Клиента
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::CheckBeginClient(TDescRecvSession* pDesc)
{
    NeedContextByClientSessionForSlave(pDesc->sessionID, true);
    if (Context() == nullptr) {
        // за то время что ждали ответа от Клиента, Клиент отвалился
        // смысла вызывать End нет, Контекста нет
        return;
    }
    //--------------------------------------------
    // Сохранить контекст по данному Клиенту
    TSaveContextEvent event;
    event.sessionID = pDesc->sessionID;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));

    SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::CheckInfoRecipient(TDescRecvSession* pDesc)
{
    NeedContextByClientSessionForSlave(pDesc->sessionID, true);
    if (Context() == nullptr) {
        // за то время что ждали ответа от Клиента, Клиент отвалился
        // смысла вызывать End нет, Контекста нет
        return;
    }
    //--------------------------------------------
    // Клиент готов к дисконнекту, рвем связь
    Context()->GetMS()->CloseSession(pDesc->sessionID);

    // все, Клиента у нас больше нет
    End();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RequestConnect(TDescRecvSession* pDesc)
{
    THeaderRequestConnect* pHeader = (THeaderRequestConnect*)pDesc->data;
    TDescRequestConnectForRecipient desc;
    desc.sessionID = pDesc->sessionID;
    desc.key = pHeader->clientKey;
    desc.random_num = pHeader->random_num;
    NeedContextByRequestForRecipient(&desc);

    if (Context() == nullptr) {
        auto clientKey = pHeader->clientKey;

        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScRecommutationClient_SlaveImpl::RequestConnect not found session=0x%X, key=%u",
                pDesc->sessionID, clientKey);
        return;
    }
    // запомнить сессию
    SetID_SessionClientSlave(pDesc->sessionID);
    // Клиенту
    mBP.Reset();
    THeaderCheckRequestConnect hClient;
    hClient.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&hClient, sizeof(hClient));

    Context()->GetMS()->Send(GetID_SessionClientSlave(), mBP);

    // Мастеру
    mBP.Reset();
    THeaderClientConnect hMaster;
    hMaster.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&hMaster, sizeof(hMaster));

    Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);
    // разработчику
    TRestoreContextEvent* pEvent = new TRestoreContextEvent;
    pEvent->sessionID = pDesc->sessionID;
    pEvent->c.SetDataByCount(Context()->GetContextDataPtr(), Context()->GetContextDataSize());
    Context()->GetSE()->AddEventWithoutCopy<TRestoreContextEvent>(pEvent);
    // завершить сценарий
    End();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::SaveContext(void* data, int size)
{
    mBP.Reset();
    if (data && size) {
        mBP.PushFront((char*)data, size);
    }

    THeaderCheckBeginDonor h;
    h.clientKey = Context()->GetClientKey();
    mBP.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);
}
//--------------------------------------------------------------
