/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO_Master.h"
#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Master.h"

using namespace std;

THandlerMMO_Master::THandlerMMO_Master()
{

}
//-----------------------------------------------------------------------------------
void THandlerMMO_Master::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
  nsMMOEngine::TBaseEvent* pBE  = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
  nsMMOEngine::TMaster* pMaster = (nsMMOEngine::TMaster*)pEvent->ptr_object;

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
      // получили пакет от Slave с id_client
      std::list<unsigned int> l_id;
      l_id.push_front(atoi(s));
      TBreakPacket bp;
      char* sMsgFromMaster = "Master say hello!";
      bp.PushFront(sMsgFromMaster, strlen(sMsgFromMaster));
      pMaster->SendByClientKey(l_id, bp);
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
    case nsMMOEngine::eTryLogin:
    {
      sEvent = "TryLogin";
      nsMMOEngine::TEventTryLogin* pETL= (nsMMOEngine::TEventTryLogin*)pBE;
      char lenLogin = *(pETL->c.GetPtr());
      char s[100];
      memcpy(s, pETL->c.GetPtr()+1, lenLogin);
      s[lenLogin] = '\0';
      unsigned int ID_Client = atoi(s);
      pMaster->SetResultLogin(true, pETL->id_session, ID_Client, (void*)"Wellcome", strlen("Wellcome"));
      //mListClient.push_back(ID_Client);
			//if(mListClient.size()>19)
      //{
        //unsigned int id_group;
        //bool res = pMaster->TryCreateGroup(mListClient, id_group);
      //}
    }
      break;
    case nsMMOEngine::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    default:BL_FIX_BUG();
  }
  printf("MMOEngine M (0x%X): %s.\t\t", pMaster, sEvent.data());
  printf("CC=%d\n",GetCountConnection());
}
//---------------------------------------------------------------------------------------------
