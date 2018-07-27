/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "ResolverSelf_IP_v4.h"
#include "HandlerMMO_Slave.h"
#include "Slave.h"
#include "Logger.h"

const int SLAVE_LOAD_PER_CLIENT = 5;

THandlerMMO_Slave::THandlerMMO_Slave( nsMMOEngine::TBase* pBase ) : THandlerMMO( pBase, eSlave )
{

}
//-----------------------------------------------------------------------------------
void THandlerMMO_Slave::HandleFromMMOEngine( nsEvent::TEvent* pEvent )
{
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TSlave* pSlave = (nsMMOEngine::TSlave*)pEvent->pSrc;

  auto ccDown = pSlave->GetCountDown();

  std::string sEvent;
  switch( pBE->mType )
  {
    case nsMMOEngine::eTryConnectDown:
    {
      sEvent = "TryConnectDown";
      std::string password = CLIENT_PASSWORD;
      auto sessionID = ((nsMMOEngine::TTryConnectDownEvent*) pBE)->sessionID;
      pSlave->Accept( sessionID, password );
    }
    break;
    case nsMMOEngine::eConnectDown:
    {
      sEvent = "ConnectDown";
      auto sessionID = ((nsMMOEngine::TConnectDownEvent*) pBE)->sessionID;
      AddConnection( sessionID );
      // если это Slave, то отправить пакет Мастеру с ID_Client
      unsigned int id_client;
      bool res = pSlave->FindClientKeyBySession( sessionID, id_client );
      char s[100];
      sprintf( s, "%d", id_client );
      int sizeMsg = strlen( s );
      pSlave->SendUp( s, sizeMsg );
      // при авторизации клиента выставить нагрузку
      pSlave->SetLoad( SLAVE_LOAD_PER_CLIENT * ccDown );
    }
    break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      RemoveConnection( ((nsMMOEngine::TDisconnectDownEvent*) pBE)->sessionID );
      pSlave->SetLoad( SLAVE_LOAD_PER_CLIENT * ccDown );
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
      //sEvent = "RecvFromDown";
      //nsMMOEngine::TRecvFromDownEvent* pR = (nsMMOEngine::TRecvFromDownEvent*)pBE;
      //char s[200];
      //memcpy( s, pR->data, pR->dataSize );
      //s[pR->dataSize] = '\0';
      //sEvent += " msg: ";
      //sEvent += s;
      nsMMOEngine::TRecvFromDownEvent* pR = (nsMMOEngine::TRecvFromDownEvent*)pBE;
      pSlave->SendDown( pR->sessionID, (char*) pR->GetData(), pR->GetSize() );
      return;
    }
    break;
    case nsMMOEngine::eRecvFromUp:
    {
      sEvent = "RecvFromUp";
      //nsMMOEngine::TRecvFromUpEvent* pR = (nsMMOEngine::TRecvFromUpEvent*)pBE;
      //char s[200];
      //memcpy( s, pR->data, pR->dataSize );
      //s[pR->dataSize] = '\0';
      //sEvent += " msg: ";
      //sEvent += s;
    }
    break;
    case nsMMOEngine::eSaveContext:
    {
      sEvent = "SaveContext";
      nsMMOEngine::TSaveContextEvent* pSE = (nsMMOEngine::TSaveContextEvent*)pBE;
      char* pData = "This is context, motherfucker!";
      int   size = strlen( pData );
      pSlave->SaveContext( pSE->sessionID, pData, size );
      pSlave->SetLoad( SLAVE_LOAD_PER_CLIENT * ccDown );
    }
    break;
    case nsMMOEngine::eRestoreContext:
    {
      sEvent = "RestoreContext";
      nsMMOEngine::TRestoreContextEvent* pRE = (nsMMOEngine::TRestoreContextEvent*)pBE;
      char sContext[200];
      memcpy( sContext, pRE->c.GetPtr(), pRE->c.GetSize() );
      sContext[pRE->c.GetSize()] = '\0';
      char s[200];
      sprintf( s, "id=%d, data=\"%s\" ", pRE->sessionID, sContext );
      pSlave->SetLoad( SLAVE_LOAD_PER_CLIENT * ccDown );
    }
    break;
    default:BL_FIX_BUG();
  }

  if( pBE->mType == nsMMOEngine::eError )
  {
    GetLogger( ServerLog )->WriteF( "MMOEngine S (0x%p): %s.\t", pSlave, sEvent.data() );
    PrintCC( ServerLog );
  }
}
//---------------------------------------------------------------------------------------------
