/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO.h"
#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "NetSystem.h"
#include "Client.h"

using namespace std;

THandlerMMO::THandlerMMO()
{
  mSlave  = NULL;
  mMaster = NULL;
  mCountConnection = 0;
}
//-----------------------------------------------------------------------------------
void THandlerMMO::Work()
{
  nsEvent::TEvent* pEvent = GetEvent();
  while(pEvent)
  {
    // обработать событие
    HandleFromMMOEngine(pEvent);
    delete pEvent;
    pEvent = GetEvent();
  }
}
//-----------------------------------------------------------------------------------
void THandlerMMO::HandleFromMMOEngine(nsEvent::TEvent* pEvent)
{
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();

  string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eConnectDown:
      sEvent = "ConnectDown";
      mCountConnection++;
      // если это Slave, то отправить пакет Мастеру с ID_Client
      if(pEvent->ptr_object==mSlave)
      {
        unsigned int id_client;
        bool res = mSlave->FindClientKeyBySession(
          ((nsMMOEngine::TEventConnectDown*)pBE)->id_session,id_client);
        TBreakPacket bp;
        char s[50];
        sprintf(s,"%d",id_client);
        bp.PushFront(s, strlen(s));
        mSlave->SendUp(bp);
      }
      break;
    case nsMMOEngine::eDisconnectDown:
      sEvent = "DisconnectDown";
      mCountConnection--;
      break;
    case nsMMOEngine::eConnectUp:
      sEvent = "ConnectUp";
      if(mMaster->IsConnectUp())
      {
#ifdef WIN32
        char* sLocalHost = ns_getSelfIP(0);
#else
        char sLocalHost[100];
        get_ip_first_eth(sLocalHost);
#endif
        unsigned int masterIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
        mSlave->ConnectUp(masterIP, MASTER_PORT, 
          LOGIN_SLAVE, strlen(LOGIN_SLAVE), 
          PASSWORD_SLAVE, strlen(PASSWORD_SLAVE));
      }
      mCountConnection++;
      break;
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      mCountConnection--;
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
      if(pEvent->ptr_object==mMaster)
      {
        // получили пакет от Slave с id_client
        std::list<unsigned int> l_id;
        l_id.push_front(atoi(s));
        TBreakPacket bp;
        char* sMsgFromMaster = "Master say hello!";
        bp.PushFront(sMsgFromMaster, strlen(sMsgFromMaster));
        mMaster->SendByClientKey(l_id, bp);
      }
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
      sEvent = "SaveContext";
      break;
    case nsMMOEngine::eRestoreContext:
      sEvent = "RestoreContext";
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
      mMaster->SetResultLogin(true, pETL->id_session, ID_Client, "Wellcome", strlen("Wellcome"));
    }
      break;
    case nsMMOEngine::eResultLogin:
    {
      sEvent = "ResultLogin";
      nsMMOEngine::TEventResultLogin* pRes = (nsMMOEngine::TEventResultLogin*)pBE;
      if(pRes->res==nsMMOEngine::TMaster::eAccept)
      {
        sEvent += " Accept ";
        mCountConnection++;
      }
      else
        sEvent += " Reject ";
      sEvent.append(pRes->c.GetPtr(), pRes->c.GetSize());
    }
      break;
    case nsMMOEngine::eDestroyGroup:
      sEvent = "DestroyGroup";
      break;
    case nsMMOEngine::eEnterInQueue:
    {
      sEvent = "InQueueLoginClient";
      //nsMMOEngine::TClient* pClient = (nsMMOEngine::TClient*)pEvent->ptr_object;
      //pClient->LeaveQueue();
    }
      break;
    case nsMMOEngine::eLeaveQueue:
      sEvent = "LeaveQueue";
      break;
  }
  printf("MMOEngine: %s.\t\t",sEvent.data());
  printf("CC=%d\n",mCountConnection);
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::SetServerMMO(nsMMOEngine::TMaster* pMaster, nsMMOEngine::TSlave* pSlave)
{
  mMaster = pMaster;
  mSlave  = pSlave;
}
//---------------------------------------------------------------------------------------------
string THandlerMMO::GetStrError(int code)
{
  string s = "Error ";
  switch(code)
  {
    // open
    case nsMMOEngine::OpenClient_MoreThenOneSubNet:
      s += "OpenClient_MoreThenOneSubNet";
      break;
    // CreateGroup
    case nsMMOEngine::CreateGroup_ClientNotExist:
      s += "CreateGroup_ClientNotExist";
      break;
    // LoginSlave
    case nsMMOEngine::LoginSlave_MasterNotReady:
      s += "LoginSlave_MasterNotReady";
      break;
    case nsMMOEngine::LoginSlave_NoAnswerFromMaster:
      s += "LoginSlave_NoAnswerFromMaster";
      break;
    //--------------------------------------
    // LoginMaster
    case nsMMOEngine::LoginClient_MasterKeyBusy:
      s += "LoginClient_MasterKeyBusy";
      break;
    case nsMMOEngine::LoginMaster_SSNotReady:
      s += "LoginMaster_SSNotReady";
      break;
    case nsMMOEngine::LoginMaster_NoAnswerFromSS:
      s += "LoginMaster_NoAnswerFromSS";
      break;
    //--------------------------------------
    // LoginClient
    case nsMMOEngine::LoginClient_EmptyLoginPassword:
      s += "LoginClient_EmptyLoginPassword";
      break;
    case nsMMOEngine::LoginClient_ClientSecondEnter:
      s += "LoginClient_ClientSecondEnter";
      break;
    case nsMMOEngine::LoginClient_ClientMasterNotReady:
      s += "LoginClient_ClientMasterNotReady";
      break;
    case nsMMOEngine::LoginClient_ClientNoAnswer:
      s += "LoginClient_ClientNoAnswer";
      break;
    case nsMMOEngine::LoginClient_ClientNotExistSlave:
      s += "LoginClient_ClientNotExistSlave";
      break;
    case nsMMOEngine::LoginClient_SlaveNoAnswer:
      s += "LoginClient_SlaveNoAnswer";
      break;
    case nsMMOEngine::LoginClient_MasterClientNotActive:
      s += "LoginClient_MasterClientNotActive";
      break;
    case nsMMOEngine::LoginClient_SuperServerNoAnswer:
      s += "LoginClient_SuperServerNoAnswer";
      break;
    //--------------------------------------
    // RCM
    case nsMMOEngine::RCM_ClientNoAnswer:
      s += "RCM_ClientNoAnswer";
      break;
  }
  return s;
}
//---------------------------------------------------------------------------------------------
