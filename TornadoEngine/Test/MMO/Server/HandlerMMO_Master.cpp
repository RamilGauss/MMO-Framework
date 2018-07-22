/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include <boost/lexical_cast.hpp>

#include "HandlerMMO_Master.h"
#include "BaseEvent.h"
#include "Events.h"
#include "CommonParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Master.h"
#include "Logger.h"
#include "../SubSystem/SessionManager.h"

using namespace std;

THandlerMMO_Master::THandlerMMO_Master() : THandlerMMO( eMaster )
{
  std::string slaveLogin = SLAVE_LOGIN;
  mSHA256.FastCalc( (void*) slaveLogin.data(), slaveLogin.length(), mSlaveHashLogin );
}
//-----------------------------------------------------------------------------------
void THandlerMMO_Master::HandleFromMMOEngine( nsEvent::TEvent* pEvent )
{
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TMaster* pMaster = (nsMMOEngine::TMaster*)pEvent->pSrc;

  string sEvent;
  switch( pBE->mType )
  {
    case nsMMOEngine::eTryConnectDown:
    {
      auto pTryConnectDown = (nsMMOEngine::TTryConnectDownEvent*) pBE;
      sEvent = "TryConnectDown";
      auto sessionID = pTryConnectDown->sessionID;
      std::string password = CLIENT_PASSWORD;

      if( memcmp( mSlaveHashLogin.GetPtr(), pTryConnectDown->hashLogin, pTryConnectDown->hashLoginSize ) == 0 )
        password = SLAVE_PASSWORD;
      else
        AddTryConnectClientToMaster( sessionID );

      pMaster->Accept( sessionID, password );
    }
    break;
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      AddConnection( ((nsMMOEngine::TConnectDownEvent*) pBE)->sessionID );
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      RemoveConnection( ((nsMMOEngine::TDisconnectDownEvent*) pBE)->sessionID );
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
    case nsMMOEngine::eRecvFromDown:
    {
      sEvent = "RecvFromDown";
      //nsMMOEngine::TRecvFromDownEvent* pR = (nsMMOEngine::TRecvFromDownEvent*)pBE;
      //char s[200];
      //memcpy( s, pR->data, pR->dataSize );
      //s[pR->dataSize] = '\0';
      //sEvent += " msg: ";
      //sEvent += s;
      //// получили пакет от Slave с id_client
      //std::list<unsigned int> l_id;
      //l_id.push_front( boost::lexical_cast<int>(s) );
      //char* sMsgFromMaster = "Master say hello!";
      //int sizeMsg = strlen( sMsgFromMaster );
      //pMaster->SendByClientKey( l_id, sMsgFromMaster, sizeMsg );
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
    case nsMMOEngine::eTryLogin:
    {
      sEvent = "TryLogin";
      nsMMOEngine::TTryLoginEvent* pETL = (nsMMOEngine::TTryLoginEvent*)pBE;
      char lenLogin = *(pETL->c.GetPtr());
      char s[100];
      memcpy( s, pETL->c.GetPtr() + 1, lenLogin );
      s[lenLogin] = '\0';
      unsigned int clientID = boost::lexical_cast<int>(s);
      pMaster->SetResultLogin( true, pETL->sessionID, clientID, (void*)"Welcome", strlen( "Welcome" ) );
    }
    break;
    case nsMMOEngine::eLogin:
    {
      sEvent = "Login";
      auto pLoginEvent = (nsMMOEngine::TLoginEvent*)pBE;
      unsigned int clientID = pLoginEvent->clientID;
      AddClient( clientID );
    }
    break;
    case nsMMOEngine::eLogoff:
    {
      nsMMOEngine::TLogoffEvent* pLogoff = (nsMMOEngine::TLogoffEvent*)pBE;
      char s[100];
      sprintf( s, "%u", pLogoff->clientID );
      sEvent = "Logoff ";
      sEvent += s;
      RemoveClient( pLogoff->clientID );
    }
    break;
    case nsMMOEngine::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    default:BL_FIX_BUG();
  }

  if( pBE->mType == nsMMOEngine::eError )
  {
    GetLogger( ServerLog )->WriteF( "MMOEngine M (0x%p): %s.\t", pMaster, sEvent.data() );
    PrintCC( ServerLog );
  }
}
//---------------------------------------------------------------------------------------------
