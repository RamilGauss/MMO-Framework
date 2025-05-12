/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <boost/asio/ip/impl/address_v4.ipp>

#include "Base/Common/ResolverSelf_IP_v4.h"
#include "Base/Common/BL_Debug.h"

#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Events.h"
#include "MMOEngine/include/Client.h"

#include "CommonParam.h"
#include "HandlerMMO_Client.h"

using namespace std;

THandlerMMO_Client::THandlerMMO_Client(nsMMOEngine::TBase* pBase) : 
    THandlerMMO(pBase, eClient)
{
}
//-----------------------------------------------------------------------------------
void THandlerMMO_Client::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
    nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
    nsMMOEngine::TClient* pClient = (nsMMOEngine::TClient*)pEvent->pSrc;

    string sEvent;
    switch (pBE->mType) {
        case nsMMOEngine::eConnectUp:
            //sEvent = "ConnectUp";
            //IncreaseConnectUpCount();
            break;
        case nsMMOEngine::eDisconnectUp:
            //sEvent = "DisconnectUp";
            //IncreaseDisconnectUpCount();
            break;
        case nsMMOEngine::eError:
        {
            nsMMOEngine::TErrorEvent* pEr = (nsMMOEngine::TErrorEvent*)pBE;
            sEvent = GetStrError(pEr->code);
        }
        break;
        case nsMMOEngine::eRecvFromUp:
        {
            //sEvent = "RecvFromUp";
            //nsMMOEngine::TRecvFromUpEvent* pR = (nsMMOEngine::TRecvFromUpEvent*)pBE;
            //char s[200];
            //memcpy(s, pR->data, pR->dataSize);
            //s[pR->dataSize] = '\0';
            //sEvent += " msg: ";
            //sEvent += s;
        }
        break;
        case nsMMOEngine::eResultLogin:
        {
            //sEvent = "ResultLogin";
            //nsMMOEngine::TResultLoginEvent* pRes = (nsMMOEngine::TResultLoginEvent*)pBE;
            //if(pRes->res==nsMMOEngine::TMaster::eAccept)
            //{
            //  sEvent += " Accept ";
            //  IncreaseCountConnection();
            //}
            //else
            //  sEvent += " Reject ";
            //sEvent.append(pRes->c.GetPtr(), pRes->c.GetSize());
        }
        break;
        case nsMMOEngine::eEnterInQueue:
        {
            //sEvent = "InQueueLoginClient";
        }
        break;
        case nsMMOEngine::eLeaveQueue:
            //sEvent = "LeaveQueue";
            break;
        default:BL_FIX_BUG();
    }
    if (sEvent.length()) {
        printf("MMOEngine: %s.\t\t", sEvent.data());
        //printf("CC=%d\n", GetCountConnection());
    }
}
//---------------------------------------------------------------------------------------------
