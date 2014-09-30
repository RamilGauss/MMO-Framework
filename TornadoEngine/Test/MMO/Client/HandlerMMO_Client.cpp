/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO_Client.h"
#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "NetSystem.h"
#include "Client.h"

using namespace std;

THandlerMMO_Client::THandlerMMO_Client()
{
}
//-----------------------------------------------------------------------------------
void THandlerMMO_Client::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
  nsMMOEngine::TBaseEvent* pBE  = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TClient* pClient = (nsMMOEngine::TClient*)pEvent->ptr_object;

  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      IncreaseCountConnection();
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      DecreaseCountConnection();
      break;
    case nsMMOEngine::eError:
    {
      nsMMOEngine::TEventError* pEr = (nsMMOEngine::TEventError*)pBE;
      sEvent = GetStrError(pEr->code);
    }
      break;
    case nsMMOEngine::eRecvFromUp:
    {
      sEvent = "RecvFromUp";
      nsMMOEngine::TEventRecvFromUp* pR = (nsMMOEngine::TEventRecvFromUp*)pBE;
      char s[200];
      memcpy(s, pR->data, pR->sizeData);
      s[pR->sizeData] = '\0';
      sEvent += " msg: ";
      sEvent += s;
    }
      break;
    case nsMMOEngine::eResultLogin:
    {
      sEvent = "ResultLogin";
      nsMMOEngine::TEventResultLogin* pRes = (nsMMOEngine::TEventResultLogin*)pBE;
      if(pRes->res==nsMMOEngine::TMaster::eAccept)
      {
        sEvent += " Accept ";
        IncreaseCountConnection();
      }
      else
        sEvent += " Reject ";
      sEvent.append(pRes->c.GetPtr(), pRes->c.GetSize());
    }
      break;
    case nsMMOEngine::eEnterInQueue:
    {
      sEvent = "InQueueLoginClient";
      //pClient->LeaveQueue();
    }
      break;
    case nsMMOEngine::eLeaveQueue:
      sEvent = "LeaveQueue";
      break;
    default:BL_FIX_BUG();
  }
  printf("MMOEngine: %s.\t\t",sEvent.data());
  printf("CC=%d\n",GetCountConnection());
}
//---------------------------------------------------------------------------------------------
