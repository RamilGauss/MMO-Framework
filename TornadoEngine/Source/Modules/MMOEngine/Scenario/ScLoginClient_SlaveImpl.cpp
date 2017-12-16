/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_SlaveImpl.h"
#include "ContextScLoginClient.h"
#include "ManagerSession.h"
#include "Base.h"
#include "Logger.h"
#include "Events.h"
#include "EnumMMO.h"

#include "SrcEvent_ex.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_SlaveImpl::TScLoginClient_SlaveImpl(IScenario* pSc):
TBaseScLoginClient(pSc)
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvInherit(TDescRecvSession* pDesc)
{
  // защита от хака
  if(pDesc->sizeData<sizeof(THeader))
    return;
  //=======================================
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->from)
  {
    case eClient:
      RecvFromClient(pDesc);
      break;
    case eMaster:
      RecvFromMaster(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::Work(unsigned int time_ms)
{
  if(Context()->GetTimeWait() + eTimeWait < ht_GetMSCount())
  {
    // ошибка на той стороне
    // непонятно в чем дело, но клиент сдох
    TEventError event;
    event.code = LoginClient_SlaveNoAnswer;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvFromClient(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eConnectToSlaveC2S:
      ConnectToSlaveC2S(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eInfoClientM2S:
      InfoClientM2S(pDesc);
      break;
    case eCheckClientConnectM2S:
      CheckClientConnectM2S(pDesc);
      break;
    case eDisconnectClientM2S:
      DisconnectClientM2S(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::ConnectToSlaveC2S(TDescRecvSession* pDesc)
{
  // защита от хака
  if(pDesc->sizeData<sizeof(THeaderConnectToSlaveC2S))
    return;
  
  THeaderConnectToSlaveC2S* pHeader = (THeaderConnectToSlaveC2S*)pDesc->data;
  // существует ли вообще клиент с данным ключом,
  // то есть был ли добавлен на ожидание от Мастера данный Клиент
  // загрузить контекст для работы
  NeedContextByClientSessionByClientKey(pDesc->id_session,
                                        pHeader->id_client);

  if(Context()==NULL)
  {
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScLoginClient_SlaveImpl::SetIsExistClientID() id client is not exist.\n");
    BL_FIX_BUG();
    return;
  }
  // запомнить сессию Клиента
  SetID_SessionClientSlave(pDesc->id_session);

  // уведомить Мастера о запросе от клиента
  THeaderClientConnectS2M h;
  h.id_client = Context()->GetClientKey();// указать какой клиент захотел соединиться
  mBP.Reset();
  mBP.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);
  // сохранить информацию о логине и пароле клиента
  char* data   = pDesc->data     + sizeof(THeaderConnectToSlaveC2S);
  int sizeData = pDesc->sizeData - sizeof(THeaderConnectToSlaveC2S);

  Context()->Set_L_AES_RSA(data, sizeData);
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::InfoClientM2S(TDescRecvSession* pDesc)
{
  THeaderInfoClientM2S* pHeader = (THeaderInfoClientM2S*)pDesc->data;
  NeedContextByClientKey(pHeader->id_client);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //--------------------------------------------
  // начало сценария
  if(Context()->WasBegin()==false)
  {
    // стартовали впервые
    Context()->SetWasBegin();
    if(Begin()==false)
    {
      // генерация ошибки
      GetLogger(STR_NAME_MMO_ENGINE)->
        WriteF_time("TScLoginClient_SlaveImpl::InfoClientM2S() scenario is not active.\n");
      BL_FIX_BUG();
      return;
    }
  }
  // Если WasBegin==true - старт уже был, Мастер не дождался, Клиент остановил у себя сценарий
  // потом Клиент еще раз попытался авторизоваться, а Slave еще его ждет, т.е. это уже
  // вторая попытка войти. Что ж продолжим авторизацию.

  SetTimeWaitForNow();
  // запомнить сессию
  SetID_SessionMasterSlave(pDesc->id_session);
  
  Context()->SetClientKey(pHeader->id_client);
  // сформировать квитанцию
  mBP.Reset();
  THeaderCheckInfoClientS2M h;
  h.id_client = Context()->GetClientKey();
  mBP.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionMasterSlave(), mBP);
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::CheckClientConnectM2S(TDescRecvSession* pDesc)
{
  THeaderCheckClientConnectM2S* pHeader = (THeaderCheckClientConnectM2S*)pDesc->data;
  NeedContextByClientKey_SecondCallSlave(pHeader->id_client);
  if(Context()==NULL)
    return;
  //--------------------------------------------
  // отсылка уведомления Developer Slave события Connect
  TEventConnectDown* pEvent = new TEventConnectDown;
  pEvent->id_session = GetID_SessionClientSlave();
  pEvent->c.SetData(Context()->GetPtr_L_AES_RSA(),
                    Context()->GetSize_L_AES_RSA());
  
  Context()->GetSE()->AddEventWithoutCopy<TEventConnectDown>(pEvent);
  // отослать клиенту уведомление
  THeaderCheckConnectToSlaveS2C h;
  mBP.Reset();
  mBP.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionClientSlave(), mBP);
  Context()->Accept();
  End();
}
//--------------------------------------------------------------
void TScLoginClient_SlaveImpl::DisconnectClientM2S(TDescRecvSession* pDesc)
{
  THeaderDisconnectClientM2S* pH = (THeaderDisconnectClientM2S*)pDesc->data;
  NeedContextByClientKey(pH->id_client);
  
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  Context()->Reject();
  Context()->GetMS()->CloseSession(Context()->GetID_SessionClientSlave());
  End();  
}
//--------------------------------------------------------------
