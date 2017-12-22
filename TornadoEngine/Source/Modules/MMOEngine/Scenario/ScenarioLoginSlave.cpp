/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScenarioLoginSlave.h"
#include "BL_Debug.h"
#include "ManagerSession.h"
#include "Logger.h"
#include "HiTimer.h"
#include "Events.h"
#include "EnumMMO.h"

#include "SrcEvent_ex.h"

using namespace nsMMOEngine;

TScenarioLoginSlave::TScenarioLoginSlave()
{

}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::ConnectToMaster( unsigned int ip, unsigned short port, 
                                           void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                                           unsigned char subNet)
{
  Context()->SetConnect(false);
  if(Begin()==false)
  {
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScenarioLoginSlave::ConnectToMaster() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
  // закрыть соединение
  Context()->GetMS()->CloseSession(Context()->GetID_Session());
  TContainer cMITM;
  mBP.Reset();
  if((Context()->GetMS()->GetUseCryptTCP())&&
     (pLogin!=NULL)&&(sizeLogin>0)&&(pPassword!=NULL)&&(sizePassword>0))
  {
    // если данные шифруются, то формировать так:
    TContainer cRSA;
    bool resRSA = Context()->GetMS()->GetRSAPublicKeyForUp(cRSA);
    BL_ASSERT(resRSA);
    bool res = mCryptMITM.Calc(cRSA.GetPtr(), cRSA.GetSize(),
      pLogin, sizeLogin, pPassword, sizePassword, cMITM);
    BL_ASSERT(res);

    mBP.PushFront(cMITM.GetPtr(), cMITM.GetSize());
  }
  THeaderFromSlave h;
  mBP.PushFront((char*)&h, sizeof(h));

  Context()->SetID_Session( Context()->GetMS()->Connect(ip, port, mBP, subNet) );
  if(Context()->GetID_Session()==INVALID_HANDLE_SESSION)
  {
    // Генерация ошибки
    TEventError event;
    event.code = LoginSlave_MasterNotReady;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
  else
    Context()->SetTimeWait(ht_GetMSCount() + eTimeoutWait_ms);
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::Work()
{
  unsigned int now = ht_GetMSCount();
  if(Context()->GetTimeWait()<now)
  {
    // Генерация ошибки
    TEventError event;
    event.code = LoginSlave_NoAnswerFromMaster;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::RecvFromMaster(TDescRecvSession* pDesc)
{
  Context()->SetConnect(true);
  End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginSlave::RecvFromSlave(TDescRecvSession* pDesc)
{
  if(Begin()==false)
  {
    End();
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScenarioLoginSlave::RecvFromSlave() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
  Context()->SetID_Session(pDesc->id_session);

  // событие наружу
  TEventConnectDown* pEvent = new TEventConnectDown;
  pEvent->id_session = pDesc->id_session;
  // сохранить информацию о логине и пароле клиента
  char* data   = pDesc->data     + sizeof(THeaderFromSlave);
  int sizeData = pDesc->sizeData - sizeof(THeaderFromSlave);
  pEvent->c.SetData(data,sizeData);
  Context()->GetSE()->AddEventWithoutCopy<TEventConnectDown>(pEvent);

  mBP.Reset();
  THeaderAnswerMaster h;
  mBP.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(Context()->GetID_Session(), mBP);

  End();
}
//--------------------------------------------------------------------------
void TScenarioLoginSlave::Recv(TDescRecvSession* pDesc)
{
  NeedContextBySession(pDesc->id_session);
  THeaderLoginSlave* pPacket = (THeaderLoginSlave*)pDesc->data;
  switch(pPacket->subType)
  {
    case eFromSlave:
      RecvFromSlave(pDesc);
      break;
    case eAnswerMaster:
      RecvFromMaster(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------  
