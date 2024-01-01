/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenarioLoginSlave.h"
#include "Base/Common/BL_Debug.h"
#include "SessionManager.h"
#include "Base/Common/Logger.h"
#include "Base/Common/HiTimer.h"
#include "Events.h"
#include "EnumMMO.h"

#include "Base/Common/SrcEvent_ex.h"

using namespace nsMMOEngine;

TScenarioLoginSlave::TScenarioLoginSlave()
{

}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::ConnectToMaster(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet)
{
    if (Begin() == false) {
        // верхнее соединение занято выполнением другого сценария - такого не должно быть
        // генерация ошибки
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScenarioLoginSlave::ConnectToMaster() scenario is not active.\n");
        BL_FIX_BUG();
        return;
    }
    // закрыть соединение
    Context()->GetMS()->CloseSession(Context()->GetSessionID());
    Context()->SetSessionID(INVALID_HANDLE_SESSION);// пока нет сессии
    auto scenario = this;
    auto context = Context();
    Context()->GetMS()->ConnectAsync(ip_port, login, password, subNet, [scenario, context](int sessionID)
        {
            scenario->SetContext(context);
            scenario->ConnectToMasterAfterConnect(sessionID);
        });
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::ConnectToMasterAfterConnect(int sessionID)
{
    Context()->SetSessionID(sessionID);
    mBP.Reset();
    THeaderFromSlave h;
    mBP.PushFront((char*)&h, sizeof(h));
    if (sessionID == INVALID_HANDLE_SESSION) {
        // Генерация ошибки
        TErrorEvent event;
        event.code = LoginSlave_MasterNotReady;
        Context()->GetSE()->AddEventCopy(&event, sizeof(event));
        End();
    } else {
        Context()->GetMS()->Send(sessionID, mBP, true);
        Context()->SetTimeWait(ht_GetMSCount() + eTimeoutWait_ms);
    }
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::Work()
{
    // если нет связи с верхним соединением, ждем соединения, если не дождемся нам об этом сообщит SessionManager
    if (Context()->GetSessionID() == INVALID_HANDLE_SESSION) {
        return;
    }

    unsigned int now = ht_GetMSCount();
    if (Context()->GetTimeWait() < now) {
        // Генерация ошибки
        TErrorEvent event;
        event.code = LoginSlave_NoAnswerFromMaster;
        Context()->GetSE()->AddEventCopy(&event, sizeof(event));
        End();
    }
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::RecvFromMaster(TDescRecvSession* pDesc)
{
    End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::RecvFromSlave(TDescRecvSession* pDesc)
{
    if (Begin() == false) {
        End();
        // верхнее соединение занято выполнением другого сценария - такого не должно быть
        // внутренняя ошибка
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TScenarioLoginSlave::RecvFromSlave() scenario is not active.\n");
        BL_FIX_BUG();
        return;
    }
    Context()->SetSessionID(pDesc->sessionID);

    // событие наружу
    TConnectDownEvent* pEvent = new TConnectDownEvent;
    pEvent->sessionID = pDesc->sessionID;
    // сохранить информацию о логине и пароле клиента
    char* data = pDesc->data + sizeof(THeaderFromSlave);
    int dataSize = pDesc->dataSize - sizeof(THeaderFromSlave);
    pEvent->c.SetData(data, dataSize);
    Context()->GetSE()->AddEventWithoutCopy<TConnectDownEvent>(pEvent);

    mBP.Reset();
    THeaderAnswerMaster h;
    mBP.PushFront((char*)&h, sizeof(h));
    Context()->GetMS()->Send(Context()->GetSessionID(), mBP);

    End();
}
//--------------------------------------------------------------------------
void TScenarioLoginSlave::Recv(TDescRecvSession* pDesc)
{
    NeedContextBySession(pDesc->sessionID);
    THeaderLoginSlave* pPacket = (THeaderLoginSlave*)pDesc->data;
    switch (pPacket->subType) {
    case eFromSlave:
        RecvFromSlave(pDesc);
        break;
    case eAnswerMaster:
        RecvFromMaster(pDesc);
        break;
    default:BL_FIX_BUG();
    }
}
//--------------------------------------------------------------------------  
