/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO_SuperServer.h"
#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "NetSystem.h"
#include "SuperServer.h"

using namespace std;

THandlerMMO_SuperServer::THandlerMMO_SuperServer()
{

}
//-----------------------------------------------------------------------------------
void THandlerMMO_SuperServer::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
  nsMMOEngine::TBaseEvent* pBE            = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TSuperServer* pSuperServer = (nsMMOEngine::TSuperServer*)pEvent->ptr_object;

  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      IncreaseCountConnection();
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DecreaseCountConnection();
      break;
    case nsMMOEngine::eError:
    {
      nsMMOEngine::TEventError* pEr = (nsMMOEngine::TEventError*)pBE;
      sEvent = GetStrError(pEr->code);
    }
      break;
    case nsMMOEngine::eRecvFromDown:
    {
      sEvent = "RecvFromDown";
      nsMMOEngine::TEventRecvFromDown* pR = (nsMMOEngine::TEventRecvFromDown*)pBE;
      char s[200];
      memcpy(s, pR->data, pR->sizeData);
      s[pR->sizeData] = '\0';
      sEvent += " msg: ";
      sEvent += s;
    }
      break;
    default:BL_FIX_BUG();
  }
  printf("MMOEngine SS(0x%X): %s.\t\t", pSuperServer, sEvent.data());
  printf("CC=%d\n",GetCountConnection());
}
//---------------------------------------------------------------------------------------------
