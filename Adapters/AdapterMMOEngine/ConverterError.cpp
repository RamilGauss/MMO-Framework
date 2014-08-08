/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ConverterError.h"
#include "BL_Debug.h"

TConverterError::TConverterError()
{

}
//----------------------------------------------------------------------------------------
TConverterError::~TConverterError()
{

}
//----------------------------------------------------------------------------------------
tPrototypeMMOErrorCode TConverterError::Work(nsMMOEngine::ErrorCode error)
{
  switch(error)
  {
    case nsMMOEngine::OpenClient_MoreThenOneSubNet:
      return OpenClient_MoreThenOneSubNet;
    case nsMMOEngine::CreateGroup_ClientNotExist:
      return CreateGroup_ClientNotExist;
    case nsMMOEngine::LoginSlave_MasterNotReady:
      return LoginSlave_MasterNotReady;
    case nsMMOEngine::LoginSlave_NoAnswerFromMaster:
      return LoginSlave_NoAnswerFromMaster;
    case nsMMOEngine::LoginClientMaster_KeyBusy:
      return LoginClientMaster_KeyBusy;
    case nsMMOEngine::LoginMaster_SSNotReady:
      return LoginMaster_SSNotReady;
    case nsMMOEngine::LoginMaster_NoAnswerFromSS:
      return LoginMaster_NoAnswerFromSS;
    case nsMMOEngine::LoginClient_ClientSecondEnter:
      return LoginClient_ClientSecondEnter;
    case nsMMOEngine::LoginClient_ClientMasterNotReady:
      return LoginClient_ClientMasterNotReady;
    case nsMMOEngine::LoginClient_ClientNoAnswer:
      return LoginClient_ClientNoAnswer;
    case nsMMOEngine::LoginClient_ClientNotExistSlave:
      return LoginClient_ClientNotExistSlave;
    case nsMMOEngine::LoginClient_SlaveNoAnswer:
      return LoginClient_SlaveNoAnswer;
    case nsMMOEngine::LoginClient_MasterClientNotActive:
      return LoginClient_MasterClientNotActive;
    case nsMMOEngine::LoginClient_SuperServerNoAnswer:
      return LoginClient_SuperServerNoAnswer;
    case nsMMOEngine::RCM_ClientNoAnswer:
      return RCM_ClientNoAnswer;
  }
  BL_FIX_BUG();
  return OpenClient_MoreThenOneSubNet;
}
//----------------------------------------------------------------------------------------
