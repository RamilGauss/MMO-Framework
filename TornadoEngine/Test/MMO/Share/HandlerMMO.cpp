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
#include "ResolverSelf_IP_v4.h"
#include "Client.h"

using namespace std;

static int mCountConnection = 0;

THandlerMMO::THandlerMMO()
{

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
string THandlerMMO::GetStrError(int code)
{
  string s = "\tError ";
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
void THandlerMMO::IncreaseCountConnection()
{
  mCountConnection++;
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::DecreaseCountConnection()
{
  mCountConnection--;
}
//---------------------------------------------------------------------------------------------
int THandlerMMO::GetCountConnection()
{
  return mCountConnection;
}
//---------------------------------------------------------------------------------------------
