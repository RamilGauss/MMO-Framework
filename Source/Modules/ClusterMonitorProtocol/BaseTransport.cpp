/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseTransport.h"
#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Events.h"
#include "MonitorEvents.h"

#include "Base/Common/SrcEvent_ex.h"

using namespace nsClusterMonitorProtocol;

TBaseTransport::TBaseTransport(nsMMOEngine::TBase* pBase)
{
    mBase = pBase;
}
//---------------------------------------------------------------------------------------
TBaseTransport::~TBaseTransport()
{

}
//---------------------------------------------------------------------------------------
void TBaseTransport::Open(unsigned short port, unsigned char subNet)
{
    mSubNet = subNet;

    nsMMOEngine::TDescOpen descOpen;
    descOpen.subNet = subNet;
    descOpen.port = port;
    mBase->Init(&mMakerNetTransport);
    mBase->Open(&descOpen);
    mBase->SetLoad(0);// всегда в начале нет нагрузки
    mBase->SetDstObject(this);
    mBase->SetSelfID(descOpen.port);
}
//---------------------------------------------------------------------------------------
void TBaseTransport::Work()
{
    mBase->Work();

    auto pEvent = GetEvent();
    while (pEvent) {
        // обработать событие
        auto pBase = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
        switch (pBase->mType) {
            case nsMMOEngine::eTryConnectDown:
            {
                auto pTryConnectDown = (nsMMOEngine::TTryConnectDownEvent*)pBase;

                auto pTryConnectEvent = new nsEvents::TTryConnectEvent();
                pTryConnectEvent->clientKey = pTryConnectDown->sessionID;
                pTryConnectEvent->loginHash = pTryConnectDown->c;
                AddEventWithoutCopy(pTryConnectEvent);
            }
            break;
            case nsMMOEngine::eConnectDown:
            {
                auto pConnectDown = (nsMMOEngine::TConnectDownEvent*)pBase;

                auto pConnectEvent = new nsEvents::TConnectEvent();
                pConnectEvent->clientKey = pConnectDown->sessionID;
                AddEventWithoutCopy(pConnectEvent);
            }
            break;
            case nsMMOEngine::eDisconnectDown:
                break;
            case nsMMOEngine::eConnectUp:
            {
                auto pConnectEvent = new nsEvents::TConnectEvent();
                AddEventWithoutCopy(pConnectEvent);
            }
            break;
            case nsMMOEngine::eDisconnectUp:
                break;
            case nsMMOEngine::eError:
                break;
            case nsMMOEngine::eRecvFromDown:
            case nsMMOEngine::eRecvFromUp:
            {
                auto pRecvEvent = (nsMMOEngine::TRecvFromDownEvent*)pBase;

                auto pPacketEvent = new nsEvents::TPacketEvent();
                pPacketEvent->clientKey = pRecvEvent->sessionID;
                pPacketEvent->packet = pRecvEvent->c;
                pPacketEvent->pHeader = (nsPackets::THeader*)(pPacketEvent->packet.GetPtr() + pRecvEvent->GetShift());
                AddEventWithoutCopy(pPacketEvent);
            }
            break;
            case nsMMOEngine::eSaveContext:
            case nsMMOEngine::eRestoreContext:
            case nsMMOEngine::eTryLogin:
            case nsMMOEngine::eLogin:
            case nsMMOEngine::eLogoff:
            case nsMMOEngine::eDestroyGroup:
            case nsMMOEngine::eEnterInQueue:
            case nsMMOEngine::eLeaveQueue:
                throw new std::exception();
                break;
        }

        pEvent = GetEvent();
    }
}
//---------------------------------------------------------------------------------------
