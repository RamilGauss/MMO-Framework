/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ScenarioLoginMaster.h"
#include "Logger.h"
#include "ManagerSession.h"
#include "Events.h"
#include "EnumMMO.h"
#include "SrcEvent_ex.h"

using namespace nsMMOEngine;

TScenarioLoginMaster::TScenarioLoginMaster()
{

}
//--------------------------------------------------------------
TScenarioLoginMaster::~TScenarioLoginMaster()
{

}
//--------------------------------------------------------------
void TScenarioLoginMaster::ConnectToSuperServer(unsigned int ip, unsigned short port, 
                                                void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                                                unsigned char subNet)
{
  Context()->SetConnect(false);
  if(Begin()==false)
  {
    End();
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScenarioLoginMaster::ConnectToSuperServer() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
  Context()->GetMS()->CloseSession(Context()->GetID_Session());
  // создать пакет
  TContainer cMITM;
  mBP.Reset();
  if((Context()->GetMS()->GetUseCryptTCP())&&
     (pLogin!=NULL)&&(sizeLogin>0)&&(pPassword!=NULL)&&(sizePassword>0))
  {
    // если данные шифруются, то формировать так:
    TContainer cRSA;
    bool resRSA = Context()->GetMS()->GetRSAPublicKeyForUp(cRSA);
    BL_ASSERT(resRSA);
    //TCryptMITM cryptMITM;
    bool res = mCryptMITM.Calc(cRSA.GetPtr(), cRSA.GetSize(),
      pLogin, sizeLogin, pPassword, sizePassword, cMITM);
    BL_ASSERT(res);

    mBP.PushFront(cMITM.GetPtr(), cMITM.GetSize());
  }
  THeaderFromMaster h;
  mBP.PushFront((char*)&h, sizeof(h));

  Context()->SetID_Session( Context()->GetMS()->Send(ip, port, mBP, subNet));
  if(Context()->GetID_Session()==INVALID_HANDLE_SESSION)
  {
    // Генерация ошибки
    TEventError event;
    event.code = LoginMaster_SSNotReady;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
  else
    Context()->SetTimeWait(ht_GetMSCount() + eTimeoutWait_ms);
}
//--------------------------------------------------------------
void TScenarioLoginMaster::Work()
{
  unsigned int now = ht_GetMSCount();
  if(Context()->GetTimeWait()<now)
  {
    // ошибка на той стороне
    TEventError event;
    event.code = LoginMaster_NoAnswerFromSS;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
}
//--------------------------------------------------------------
void TScenarioLoginMaster::RecvFromSuperServer(TDescRecvSession* pDesc)
{
  Context()->SetConnect(true);
  End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginMaster::RecvFromMaster(TDescRecvSession* pDesc)
{
  if(Begin()==false)
  {
    End();
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // внутренняя ошибка
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScenarioLoginMaster::RecvFromMaster() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
  Context()->SetID_Session(pDesc->id_session);

  // событие наружу
  TEventConnectDown* pEvent = new TEventConnectDown;
  pEvent->id_session = pDesc->id_session;
  // сохранить информацию о логине и пароле клиента
  char* data   = pDesc->data     + sizeof(THeaderFromMaster);
  int sizeData = pDesc->sizeData - sizeof(THeaderFromMaster);
  pEvent->c.SetDataByCount(data,sizeData);
  Context()->GetSE()->AddEventWithoutCopy<TEventConnectDown>(pEvent);

  mBP.Reset();
  THeaderAnswerFromSS h;
  mBP.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(Context()->GetID_Session(), mBP);
  End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginMaster::Recv(TDescRecvSession* pDesc)
{
  NeedContextBySession(pDesc->id_session);
  THeaderLoginMaster* pPacket = (THeaderLoginMaster*)pDesc->data;
  switch(pPacket->subType)
  {
    case eFromMaster:
      RecvFromMaster(pDesc);
      break;
    case eAnswerFromSS:
      RecvFromSuperServer(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------------------------
