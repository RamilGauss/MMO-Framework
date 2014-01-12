/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScRecommutationClient_SlaveImpl.h"
#include "Logger.h"
#include "ManagerSession.h"
#include "BaseScRecommutationClient_Struct.h"
#include "ContextScRecommutationClient.h"
#include "Events.h"
#include "SrcEvent_ex.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;


TScRecommutationClient_SlaveImpl::TScRecommutationClient_SlaveImpl(IScenario* pSc):
TBaseScRecommutationClient(pSc)
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::Work(unsigned int time_ms)
{
  unsigned int time_wait_ms = Context()->GetTimeWait() + eTimeWait;
  if(time_wait_ms < time_ms)
  {
    if(Context()->IsDonor())
    {
      TEventDisconnectDown event;
      event.id_session = Context()->GetID_SessionClientSlave();
      Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    }

    EventTimeClientElapsed(Context()->GetClientKey());
    Context()->GetMS()->CloseSession(Context()->GetID_SessionClientSlave());
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvInherit(TDescRecvSession* pDesc)
{
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
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eBeginDonor:
      BeginDonor(pDesc);
      break;
    case eInfoRecipientToDonor:
      InfoRecipientToDonor(pDesc);
      break;
    case eBeginRecipient:
      BeginRecipient(pDesc);
      break;
    case eDisconnectClient:
      DisconnectClientToSlave(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RecvFromClient(TDescRecvSession* pDesc)
{
  // защита от хака
  if(pDesc->sizeData < sizeof(THeader))
    return;
  //=======================================
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eCheckBeginClient:
      CheckBeginClient(pDesc);
      break;
    case eCheckInfoRecipient:
      CheckInfoRecipient(pDesc);
      break;
    case eRequestConnect:
      RequestConnect(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::BeginDonor(TDescRecvSession* pDesc)
{
  THeaderBeginDonor* pHeader = (THeaderBeginDonor*)pDesc->data;
  NeedContextByClientKeyForSlave(pHeader->id_client, true);
  if(Context()==NULL)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::BeginDonor() Context()==NULL.\n");
    BL_FIX_BUG();
    return;
  }
  //--------------------------------------------
  Context()->SetClientKey(pHeader->id_client);
  Context()->SetRoleAsDonor();// роль Донора
  // начало сценария
  if(Begin()==false)
  {
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::BeginDonor() scenario is not active.\n");
    BL_FIX_BUG();
    return;    
  }
  // сформировать пакет далее для Клиента
  TBreakPacket bp;
  THeaderBeginClient h;
  h.id_client = Context()->GetClientKey();
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionClientSlave(), bp);

  SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::InfoRecipientToDonor(TDescRecvSession* pDesc)
{
  THeaderInfoRecipientToDonor* pHeader = (THeaderInfoRecipientToDonor*)pDesc->data;
  NeedContextByClientKeyForSlave(pHeader->id_client, true);
  if(Context()==NULL)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::InfoRecipientToDonor() Context()==NULL.\n");
    BL_FIX_BUG();
    return;
  }
  //--------------------------------------------
  TBreakPacket bp;
  THeaderInfoRecipientToClient h;
  h.id_client         = pHeader->id_client;
  h.ip_port_recipient = pHeader->ip_port_recipient;
  h.random_num        = pHeader->random_num;
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionClientSlave(), bp);

  SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::BeginRecipient(TDescRecvSession* pDesc)
{
  THeaderBeginRecipient* pHeader = (THeaderBeginRecipient*)pDesc->data;
  NeedContextByClientKeyForSlave(pHeader->id_client, false);
  if(Context()==NULL)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::BeginRecipient() Context()==NULL.\n");
    BL_FIX_BUG();
    return;
  }
  //--------------------------------------------
  Context()->SetRandomNum(pHeader->random_num);
  Context()->SetClientKey(pHeader->id_client);
  Context()->SetRoleAsRecipient();// роль Реципиента
  Context()->SetID_SessionMasterSlave(pDesc->id_session);
  // начало сценария
  if(Begin()==false)
  {
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::BeginRecipient() scenario is not active.\n");
    BL_FIX_BUG();
    return;    
  }
  // сохранить Контекст в контекст (извините за каламбур)
  // Slave еще рано отдавать Контекст
  Context()->SaveContextData(pDesc->data + sizeof(THeaderBeginRecipient), 
                             pDesc->sizeData - sizeof(THeaderBeginRecipient));
  // сформировать пакет далее для Мастера
  TBreakPacket bp;
  THeaderCheckBeginRecipient h;
  h.id_client = Context()->GetClientKey();
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bp);

  SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::DisconnectClientToSlave(TDescRecvSession* pDesc)
{
  THeaderDisconnectClient* pHeader = (THeaderDisconnectClient*)pDesc->data;
  EventDisconnectClient(pHeader->id_client);
  // вызывать End(); нельзя, потому что тогда в Slave отработает по окончанию сценария 
  // добавлением Клиента
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::CheckBeginClient(TDescRecvSession* pDesc)
{
  NeedContextByClientSessionForSlave(pDesc->id_session, true);
  if(Context()==NULL)
  {
    // за то время что ждали ответа от Клиента, Клиент отвалился
    // смысла вызывать End нет, Контекста нет
    return;
  }
  //--------------------------------------------
  // Сохранить контекст по данному Клиенту
  TEventSaveContext event;
  event.id_session = pDesc->id_session;
  Context()->GetSE()->AddEventCopy(&event, sizeof(event));

  SetTimeWaitForNow();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::CheckInfoRecipient(TDescRecvSession* pDesc)
{
  NeedContextByClientSessionForSlave(pDesc->id_session, true);
  if(Context()==NULL)
  {
    // за то время что ждали ответа от Клиента, Клиент отвалился
    // смысла вызывать End нет, Контекста нет
    return;
  }
  //--------------------------------------------
  // Клиент готов к дисконнекту, рвем связь
  Context()->GetMS()->CloseSession(pDesc->id_session);

  // все, Клиента у нас больше нет
  End();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::RequestConnect(TDescRecvSession* pDesc)
{
  THeaderRequestConnect* pHeader = (THeaderRequestConnect*)pDesc->data;
  TDescRequestConnectForRecipient desc;
  desc.id_session = pDesc  ->id_session;
  desc.key        = pHeader->id_client;
  desc.random_num = pHeader->random_num;
  NeedContextByRequestForRecipient(&desc);

  if(Context()==NULL)
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScRecommutationClient_SlaveImpl::RequestConnect not found session=0x%X, key=%u", 
                  pDesc->id_session, pHeader->id_client);
    return;
  }
  // запомнить сессию
  SetID_SessionClientSlave(pDesc->id_session);
  // Клиенту
  TBreakPacket bpClient;
  THeaderCheckRequestConnect hClient;
  hClient.id_client = Context()->GetClientKey();
  bpClient.PushFront((char*)&hClient, sizeof(hClient));

  Context()->GetMS()->Send(GetID_SessionClientSlave(), bpClient);

  // Мастеру
  TBreakPacket bpMaster;
  THeaderClientConnect hMaster;
  hMaster.id_client = Context()->GetClientKey();
  bpMaster.PushFront((char*)&hMaster, sizeof(hMaster));

  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bpMaster);
  // разработчику
	TEventRestoreContext* pEvent = new TEventRestoreContext;
	pEvent->id_session = pDesc->id_session;
	pEvent->c.SetDataByCount(Context()->GetContextDataPtr(), Context()->GetContextDataSize());
	Context()->GetSE()->AddEventWithoutCopy<TEventRestoreContext>(pEvent);
  // завершить сценарий
  End();
}
//--------------------------------------------------------------
void TScRecommutationClient_SlaveImpl::SaveContext(void* data, int size)
{
  TBreakPacket bp;
  if(data && size)
    bp.PushFront((char*)data, size);

  THeaderCheckBeginDonor h;
  h.id_client   = Context()->GetClientKey();
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bp);
}
//--------------------------------------------------------------
