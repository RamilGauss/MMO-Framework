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

using namespace std;

THandlerMMO_Slave::THandlerMMO_Slave()
{

}
//-----------------------------------------------------------------------------------
void THandlerMMO_Slave::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TSlave* pSlave  = (nsMMOEngine::TSlave*)pEvent->ptr_object;

  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
    {
      sEvent = "ConnectDown";
      IncreaseCountConnection();
      // если это Slave, то отправить пакет Мастеру с ID_Client
      unsigned int id_client;
      bool res = pSlave->FindClientKeyBySession(
        ((nsMMOEngine::TEventConnectDown*)pBE)->id_session, id_client);
      mBP.Reset();
      char s[100];
      sprintf(s,"%d",id_client);
      int sizeMsg = strlen(s);
      pSlave->SendUp(s, sizeMsg);
      // при авторизации клиента выставить нагрузку
      pSlave->SetLoad(40);
    }
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      DecreaseCountConnection();
      pSlave->SetLoad(0);
      break;
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
    case nsMMOEngine::eSaveContext:
    {
      sEvent = "SaveContext";
      nsMMOEngine::TEventSaveContext* pSE = (nsMMOEngine::TEventSaveContext*)pBE;
      char* pData = "This is context, motherfucker!";
      int   size  = strlen(pData);
      pSlave->SaveContext(pSE->id_session, pData, size);
    }
      break;
    case nsMMOEngine::eRestoreContext:
    {
      sEvent = "RestoreContext";
      nsMMOEngine::TEventRestoreContext* pRE = (nsMMOEngine::TEventRestoreContext*)pBE;
      char sContext[200];
      memcpy(sContext, pRE->c.GetPtr(), pRE->c.GetSize());
      sContext[pRE->c.GetSize()] = '\0';
      char s[200];
      sprintf(s, "id=%d, data=\"%s\" ", pRE->id_session, sContext); 
    }
      break;
    default:BL_FIX_BUG();
  }
  printf("MMOEngine S (0x%X): %s.\t\t", pSlave, sEvent.data());
  printf("CC=%d\n",GetCountConnection());
}
//---------------------------------------------------------------------------------------------
