/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EnumMMO.h"

using namespace nsMMOEngine;

std::string nsMMOEngine::GetEventType( EventType type )
{
  std::string s;
  switch( type )
  {
    case eTryConnectDown:
      s = "TryConnectDown";
      break;
    case eConnectDown:
      s = "ConnectDown";
      break;
    case eDisconnectDown:
      s = "DisconnectDown";
      break;
    case eConnectUp:
      s = "ConnectUp";
      break;
    case eDisconnectUp:
      s = "DisconnectUp";
      break;
    case eError:
      s = "Error";
      break;
    case eRecvFromDown:
      s = "RecvFromDown";
      break;
    case eRecvFromUp:
      s = "RecvFromUp";
      break;
    case eSaveContext:
      s = "SaveContext";
      break;
    case eRestoreContext:
      s = "RestoreContext";
      break;
    case eTryLogin:
      s = "TryLogin";
      break;
    case eLogin:
      s = "Login";
      break;
    case eLogoff:
      s = "Logoff";
      break;
    case eResultLogin:
      s = "ResultLogin";
      break;
    case eDestroyGroup:
      s = "DestroyGroup";
      break;
    case eEnterInQueue:
      s = "EnterInQueue";
      break;
    case eLeaveQueue:
      s = "LeaveQueue";
      break;
  }
  return s;
}
//-------------------------------------------------------------------------------------------------
std::string nsMMOEngine::GetStrError( ErrorCode code )
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
//-------------------------------------------------------------------------------------------------
std::string nsMMOEngine::GetMMOType( TypeMMO type )
{
  std::string s;
  switch( type )
  {
    case eClient:
      s = "Client";
      break;
    case eSlave:
      s = "Slave";
      break;
    case eMaster:
      s = "Master";
      break;
    case eSuperServer:
      s = "SuperServer";
      break;
  }
  return s;
}
//-------------------------------------------------------------------------------------------------
