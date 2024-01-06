/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HandlerMMO_SuperServer.h"
#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Events.h"
#include "MMOEngine/include/SuperServer.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "Base/Common/ResolverSelf_IP_v4.h"
#include "Base/Common/Logger.h"

using namespace std;

THandlerMMO_SuperServer::THandlerMMO_SuperServer(nsMMOEngine::TBase* pBase) : THandlerMMO(pBase, eSuperServer)
{

}
//-----------------------------------------------------------------------------------
void THandlerMMO_SuperServer::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
    nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
    nsMMOEngine::TSuperServer* pSuperServer = (nsMMOEngine::TSuperServer*)pEvent->pSrc;

    string sEvent;
    switch (pBE->mType) {
        case nsMMOEngine::eTryConnectDown:
        {
            sEvent = "TryConnectDown";
            auto pTryConnectDown = (nsMMOEngine::TTryConnectDownEvent*)pBE;
            auto sessionID = pTryConnectDown->sessionID;
            std::string password = MASTER_PASSWORD;
            pSuperServer->Accept(sessionID, password);
        }
        break;
        case nsMMOEngine::eConnectDown:
            sEvent = "ConnectDown";
            AddConnection(((nsMMOEngine::TConnectDownEvent*)pBE)->sessionID);
            break;
        case nsMMOEngine::eDisconnectDown:
            sEvent = "DisconnectDown";
            RemoveConnection(((nsMMOEngine::TDisconnectDownEvent*)pBE)->sessionID);
            break;
        case nsMMOEngine::eError:
        {
            nsMMOEngine::TErrorEvent* pEr = (nsMMOEngine::TErrorEvent*)pBE;
            sEvent = nsMMOEngine::GetStrError(pEr->code);
        }
        break;
        case nsMMOEngine::eRecvFromDown:
        {
            sEvent = "RecvFromDown";
            nsMMOEngine::TRecvFromDownEvent* pR = (nsMMOEngine::TRecvFromDownEvent*)pBE;
            char s[200];
            memcpy(s, pR->GetData(), pR->GetSize());
            s[pR->GetSize()] = '\0';
            sEvent += " msg: ";
            sEvent += s;
        }
        break;
        default:BL_FIX_BUG();
    }

    if (pBE->mType == nsMMOEngine::eError) {
        nsBase::nsCommon::GetLogger(ServerLog)->WriteF("MMOEngine SS(0x%p): %s.\t", pSuperServer, sEvent.data());
        PrintCC(ServerLog);
    }
}
//---------------------------------------------------------------------------------------------
