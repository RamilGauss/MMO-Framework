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
#include "ResolverSelf_IP_v4.h"
#include "Client.h"
#include "Logger.h"
#include "EnumMMO.h"

using namespace std;

THandlerMMO_Client::THandlerMMO_Client() : THandlerMMO( eClient )
{
}
//-----------------------------------------------------------------------------------
void THandlerMMO_Client::HandleFromMMOEngine( nsEvent::TEvent* pEvent )
{
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TClient* pClient = (nsMMOEngine::TClient*)pEvent->ptr_object;

  string sEvent;
  switch( pBE->mType )
  {
    case nsMMOEngine::eTryConnectDown:
      BL_FIX_BUG();
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      AddConnection( ((nsMMOEngine::TConnectUpEvent*) pBE)->sessionID );
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      RemoveConnection( ((nsMMOEngine::TDisconnectUpEvent*) pBE)->sessionID );
      break;
    case nsMMOEngine::eError:
    {
      nsMMOEngine::TErrorEvent* pEr = (nsMMOEngine::TErrorEvent*)pBE;
      sEvent = nsMMOEngine::GetStrError( pEr->code );
    }
    break;
    case nsMMOEngine::eRecvFromUp:
    {
      sEvent = "RecvFromUp";
      nsMMOEngine::TRecvFromUpEvent* pR = (nsMMOEngine::TRecvFromUpEvent*)pBE;
      char s[200];
      memcpy( s, pR->data, pR->dataSize );
      s[pR->dataSize] = '\0';
      sEvent += " msg: ";
      sEvent += s;
    }
    break;
    case nsMMOEngine::eResultLogin:
    {
      sEvent = "ResultLogin";
      auto pRes = (nsMMOEngine::TResultLoginEvent*)pBE;
      if( pRes->res == nsMMOEngine::TMaster::eAccept )
      {
        sEvent += " Accept ";
        //IncreaseConnectUpCount();
      }
      else
        sEvent += " Reject ";
      sEvent.append( pRes->c.GetPtr(), pRes->c.GetSize() );
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

  if( pBE->mType == nsMMOEngine::eError )
    GetLogger( ClientLog )->WriteF( "MMOEngine: %s.\t\n", sEvent.data() );
}
//---------------------------------------------------------------------------------------------
