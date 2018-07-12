#include "EnumMMO.h"

using namespace nsMMOEngine;

std::string nsMMOEngine::GetStrError( int code )
{
  std::string s;
  switch( code )
  {
    case OpenClient_MoreThenOneSubNet:
      s = "OpenClient_MoreThenOneSubNet";
      break;
    // CreateGroup
    case CreateGroup_ClientNotExist:
      s = "CreateGroup_ClientNotExist";
      break;
      // LoginSlave
    case LoginSlave_MasterNotReady:
      s = "LoginSlave_MasterNotReady";
      break;
    case LoginSlave_NoAnswerFromMaster:
      s = "LoginSlave_NoAnswerFromMaster";
      break;
      // LoginMaster
    case LoginMaster_SSNotReady:
      s = "LoginMaster_SSNotReady";
      break;
    case LoginMaster_NoAnswerFromSS:
      s = "LoginMaster_NoAnswerFromSS";
      break;
      // LoginClient
    case LoginClient_EmptyLoginPassword:
      s = "LoginClient_EmptyLoginPassword";
      break;
    case LoginClient_ClientSecondEnter:
      s = "LoginClient_ClientSecondEnter";
      break;
    case LoginClient_ClientMasterNotReady:
      s = "LoginClient_ClientMasterNotReady";
      break;
    case LoginClient_ClientNoAnswer:
      s = "LoginClient_ClientNoAnswer";
      break;
    case LoginClient_ClientNotExistSlave:
      s = "LoginClient_ClientNotExistSlave";
      break;
    case LoginClient_ClientSlaveNotActive:
      s = "LoginClient_ClientSlaveNotActive";
      break;
    case LoginClient_ClientMasterNotSendSlaveInfo:
      s = "LoginClient_ClientMasterNotSendSlaveInfo";
      break;
    case LoginClient_ClientMasterNotDisconnect:
      s = "LoginClient_ClientMasterNotDisconnect";
      break;
    case LoginClient_ClientMasterNotActive:
      s = "LoginClient_ClientMasterNotActive";
      break;
    case LoginClient_ClientMasterForgetUpdateQueue:
      s = "LoginClient_ClientMasterForgetUpdateQueue";
      break;
    case LoginClient_SlaveClientNotActive:
      s = "LoginClient_SlaveClientNotActive";
      break;
    case LoginClient_SlaveMasterNotActive:
      s = "LoginClient_SlaveMasterNotActive";
      break;
    case LoginClient_MasterKeyBusy:
      s = "LoginClient_MasterKeyBusy";
      break;
    case LoginClient_MasterDeveloperNotActive:
      s = "LoginClient_MasterDeveloperNotActive";
      break;
    case LoginClient_MasterClientNotActive:
      s = "LoginClient_MasterClientNotActive";
      break;
    case LoginClient_MasterSlaveNotActive:
      s = "LoginClient_MasterSlaveNotActive";
      break;
    case LoginClient_MasterForgetUpdateQueue:
      s = "LoginClient_MasterForgetUpdateQueue";
      break;
    case LoginClient_MasterSuperServerNotActive:
      s = "LoginClient_MasterSuperServerNotActive";
      break;
    case LoginClient_MasterClientNotConnectToSlave:
      s = "LoginClient_MasterClientNotConnectToSlave";
      break;
      // RCM
    case RCM_ClientNoAnswer:
      s = "RCM_ClientNoAnswer";
      break;
  }
  return s;
}