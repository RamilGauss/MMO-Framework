/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <string>
#include "TypeDef.h"

static const char* STR_NAME_MMO_ENGINE = "MMOEngine";
static const char* STR_NAME_NET_TRANSPORT = "NetTransport";

static const int INVALID_HANDLE_SESSION = 0;

namespace nsMMOEngine
{
  enum ErrorCode
  {
    // open
    OpenClient_MoreThenOneSubNet,
    // CreateGroup
    CreateGroup_ClientNotExist,
    // LoginSlave
    LoginSlave_MasterNotReady,
    LoginSlave_NoAnswerFromMaster,
    //--------------------------------------
    // LoginMaster
    LoginMaster_SSNotReady,
    LoginMaster_NoAnswerFromSS,
    //--------------------------------------
    // LoginClient
    LoginClient_EmptyLoginPassword,
    LoginClient_ClientSecondEnter,
    LoginClient_ClientMasterNotReady,
    LoginClient_ClientNoAnswer,
    LoginClient_ClientNotExistSlave,
    LoginClient_ClientSlaveNotActive,
    LoginClient_ClientMasterNotSendSlaveInfo,
    LoginClient_ClientMasterNotDisconnect,
    LoginClient_ClientMasterNotActive,
    LoginClient_ClientMasterForgetUpdateQueue,
    LoginClient_SlaveClientNotActive,
    LoginClient_SlaveMasterNotActive,
    LoginClient_MasterKeyBusy,
    LoginClient_MasterDeveloperNotActive,
    LoginClient_MasterClientNotActive,
    LoginClient_MasterSlaveNotActive,
    LoginClient_MasterForgetUpdateQueue,
    LoginClient_MasterSuperServerNotActive,
    LoginClient_MasterClientNotConnectToSlave,
    //--------------------------------------
    // RCM
    RCM_ClientNoAnswer,
  };

  // попытка connect всегда происходит к верхнему объекту
  // если получилось, то получишь ConnectUp, иначе Error
  // если кто-то пытается подключиться к верхнему объекту, то вызовется TryConnectDown
  // далее нужно вызвать Accept или Reject
  enum EventType
  {
    eTryConnectDown,
    eConnectDown,
    eDisconnectDown,
    eConnectUp,
    eDisconnectUp,
    eError,
    eRecvFromDown,
    eRecvFromUp,
    eSaveContext,
    eRestoreContext,
    eTryLogin,// попытка авторизоваться
    eLogin,   // клиент авторизовался
    eLogoff,  // клиент на мастере отключился
    eResultLogin,
    eDestroyGroup,
    eEnterInQueue,
    eLeaveQueue,
  };

  extern DllExport std::string GetStrError( int code );
}
