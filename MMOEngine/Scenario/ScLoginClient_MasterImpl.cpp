/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_MasterImpl.h"
#include "ContextScLoginClient.h"
#include "ManagerSession.h"
#include "Base.h"
#include "Logger.h"
#include "Events.h"
#include "ErrorCode.h"
#include "SrcEvent_ex.h"

using namespace std;
using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_MasterImpl::TScLoginClient_MasterImpl(IScenario* pSc):
TBaseScLoginClient(pSc)
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_MasterImpl::RecvInherit(TDescRecvSession* pDesc)
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
    case eSlave:
      RecvFromSlave(pDesc);
      break;
    case eSuperServer:
      RecvFromSuperServer(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_MasterImpl::Work(unsigned int now_ms)
{
  // если клиент в очереди, обновить номер
  if(Context()->GetNumInQueue())
  {
    if(now_ms > Context()->GetTimeLastNeedNumInQueue() + eDeltaTimeNumInQueue_ms)
    {
      NeedNumInQueueByClientKey(Context()->GetID_SessionClientMaster());
      Context()->SetTimeLastNeedNumInQueue(now_ms);

      TBreakPacket bp;
      THeaderResultLoginM2C h;
      h.result     = THeaderResultLoginM2C::eQueue;
      h.numInQueue = Context()->GetNumInQueue();
      bp.PushFront((char*)&h, sizeof(h));
      Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);
    }
    return;
  }
  // 
  if(Context()->GetTimeWait() + Context()->GetDeltaTimeWaitMS() < now_ms)
  {
    // ошибка на той стороне
    TEventError event;
    event.code = LoginClient_MasterClientNotActive;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    Context()->Reject();
    Context()->SetTimeWaitElapsed();
    End();
		
		BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_MasterImpl::Reject(void* resForClient, int sizeResClient)
{
  Context()->Reject();

  // сформировать отказ для клиента
  THeaderResultLoginM2C h;
  h.result = THeaderResultLoginM2C::eReject;
  h.sizeResClient = sizeResClient;

  TBreakPacket bp;
  bp.PushFront((char*)resForClient, sizeResClient);
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);

  End();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::Accept(unsigned int key, void* resForClient, int sizeResClient, 
                                       unsigned int id_session_slave, 
                                       unsigned int id_superserver)
{
  // сохранить свой ключ
  Context()->SetClientKey(key);
  // сохранить сессию СуперСервера
  SetID_SessionMasterSS(id_superserver);
  // сохранить сессию Slave
  SetID_SessionMasterSlave(id_session_slave);
  // выставить состояние контекста
  Context()->Accept();

  // если SuperServer существует, то отослать запрос ему
  // если нет, то отослать ответ клиенту сразу
  if(GetID_SessionMasterSS()==INVALID_HANDLE_SESSION)
  {
    // сразу ответ клиенту и Slave
    SendResultAccept2ClientAndSlave(key,
                                    resForClient, sizeResClient);
    return;
  }
  
  Context()->SaveAcceptData(resForClient, sizeResClient);
  // SuperServer
  TBreakPacket bp;
  THeaderRequestM2SS h;
  h.id_client = key;
  bp.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(GetID_SessionMasterSS(), bp);
  // ждем ответ от SuperServer
  SetWaitSS();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::Queue(int num, void* resForClient, int sizeResClient)
{
  Context()->SetNumInQueue(num);
	Context()->SaveQueueData(resForClient, sizeResClient);

  TBreakPacket bp;
  THeaderResultLoginM2C h;
  h.result     = THeaderResultLoginM2C::eQueue;
  h.numInQueue = num;
  bp.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::RecvFromClient(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eTryLoginC2M:
      TryLoginC2M(pDesc);
      break;
    case eLeaveQueueC2M:
      LeaveQueueC2M(pDesc);
      break;
    case eCheckInfoSlaveC2M:
      CheckInfoSlaveC2M(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::RecvFromSlave(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eClientConnectS2M:
      ClientConnectS2M(pDesc);
      break;
    case eCheckInfoClientS2M:
      CheckInfoClientS2M(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::RecvFromSuperServer(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eCheckRequestSS2M:
      CheckRequestSS2M(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::CheckRequestSS2M(TDescRecvSession* pDesc)
{
  THeaderCheckRequestSS2M* pHeader = (THeaderCheckRequestSS2M*)pDesc->data;
  NeedContextByClientKey(pHeader->id_client);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //-------------------------------------------------------------
  // анализ ответа SuperServer-а
  if(pHeader->isExistInSystem)
  {
    Context()->Reject();
    // клиент уже есть в системе, повторная авторизация
    string sReject = "Reject login. Client was been authorized.";
    // сформировать отказ для клиента
    THeaderResultLoginM2C h;
    h.result = THeaderResultLoginM2C::eReject;
    h.sizeResClient = sReject.length();
    
    TBreakPacket bp;
    bp.PushFront((char*)sReject.data(), sReject.length());
    bp.PushFront((char*)&h, sizeof(h));

    Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);
    End();
    return;
  }
  //
  void* resForClient  = Context()->GetSaveAcceptDataPtr();
  int   sizeResClient = Context()->GetSaveAcceptDataSize();

  Context()->Accept();

  SendResultAccept2ClientAndSlave(pHeader->id_client,
                                  resForClient,sizeResClient);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::TryLoginC2M(TDescRecvSession* pDesc)
{
  // защита от хака
  if(pDesc->sizeData<sizeof(THeaderTryLoginC2M))
    return;
  //=====================================
  NeedContextBySession(pDesc->id_session);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //-------------------------------------------------------------
  if(Begin()==false)
  {
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScLoginClient_MasterImpl::TryLoginC2M() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
	SetWaitSS();// ждем
  SetTimeWaitForNow();
  // новая сессия, сохранить
  SetID_SessionClientMaster(pDesc->id_session);
  // в буфере, который передали, содержится заголовок и блок
  // размер блока прописан в заголовке
  
	THeaderTryLoginC2M* pPacket = (THeaderTryLoginC2M*)pDesc->data;
	char* data   = pDesc->data     + sizeof(THeaderTryLoginC2M);
	int sizeData = pDesc->sizeData - sizeof(THeaderTryLoginC2M);
	// генерация события о попытке авторизации
	TEventTryLogin* pEvent = new TEventTryLogin;
	pEvent->id_session = GetID_SessionClientMaster();
	pEvent->c.SetData(data,sizeData);
	Context()->GetSE()->AddEventWithoutCopy<TEventTryLogin>(pEvent);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::LeaveQueueC2M(TDescRecvSession* pDesc)
{
  // защита от хака не нужна, данные пакета не используются
  //=====================================
  NeedContextBySession(pDesc->id_session);
  if(Context()==NULL)
  {
    End();
    return;
  }
  //-------------------------------------------------------------
  if(Context()->GetNumInQueue()==0)
    return;
  Context()->Reject();
  Context()->GetMS()->CloseSession(GetID_SessionClientMaster());
  End();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::ClientConnectS2M(TDescRecvSession* pDesc)
{
  THeaderClientConnectS2M* pHeader = (THeaderClientConnectS2M*)pDesc->data;
  NeedContextByClientKey(pHeader->id_client);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //------------------------------------------------------------
  // квитанция о запросе
  THeaderCheckClientConnectM2S h;
  h.id_client = pHeader->id_client;
  TBreakPacket bp;
  bp.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bp);

  // конец сценария
  End();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::CheckInfoClientS2M(TDescRecvSession* pDesc)
{
  THeaderCheckInfoClientS2M* pHeader = (THeaderCheckInfoClientS2M*)pDesc->data;
  NeedContextByClientKey(pHeader->id_client);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //------------------------------------------------------------
  // ip и port Slave для клиента
  TIP_Port ip_port_slave;
  Context()->GetMS()->GetInfo(GetID_SessionMasterSlave(), ip_port_slave);

  // отослать информацию о Slave
  THeaderInfoSlaveM2C h;
  h.id_client     = Context()->GetClientKey();
  h.ip_port_slave = ip_port_slave;
  TBreakPacket bp;
  bp.PushFront((char*)&h, sizeof(h));
  Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::SendResultAccept2ClientAndSlave(unsigned int key, 
                                                                void* resForClient, 
                                                                int sizeResClient)
{
  // Client
  TBreakPacket bp;
  bp.PushFront((char*)resForClient, sizeResClient);
  THeaderResultLoginM2C hForClient;
  hForClient.id_client     = key;
  hForClient.result        = THeaderResultLoginM2C::eAccept;
  hForClient.sizeResClient = sizeResClient;
  bp.PushFront((char*)&hForClient, sizeof(hForClient));
  Context()->GetMS()->Send(GetID_SessionClientMaster(), bp);
  bp.UnlinkPart();// очистить от частей
  // Slave
  THeaderInfoClientM2S hForSlave;
  hForSlave.id_client = key;
  bp.PushFront((char*)&hForSlave, sizeof(hForSlave));
  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bp);

  // ждем ответ от Slave
  SetWaitSlave();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::Disconnect()
{
  THeaderDisconnectClientM2S h;
  h.id_client = Context()->GetClientKey();
  TBreakPacket bp;
  bp.PushFront((char*)&h,sizeof(h));
  Context()->GetMS()->Send(GetID_SessionMasterSlave(), bp);
  End();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::CheckInfoSlaveC2M(TDescRecvSession* pDesc)
{
  // защита от хака
  if(pDesc->sizeData!=sizeof(THeaderCheckInfoSlaveC2M))
    return;
  //=====================================
  THeaderCheckInfoSlaveC2M* pHeader = (THeaderCheckInfoSlaveC2M*)pDesc->data;
  NeedContextBySession(pDesc->id_session);
  //NeedContextByClientKey(pHeader->id_client);
  if(Context()==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  //------------------------------------------------------------
  // Мастер сам рвет соединение и клиент получает событие дисконнект,
  Context()->GetMS()->CloseSession(pDesc->id_session);

  // и ждем ответа от Slave о том, что Клиент подцепился к Slave
  SetWaitClient();
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::SetWaitSS()
{
  Context()->SetDeltaTimeWaitMS(eTimeWaitSS_ms);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::SetWaitSlave()
{
  Context()->SetDeltaTimeWaitMS(eTimeWaitSlave_ms);
}
//--------------------------------------------------------------
void TScLoginClient_MasterImpl::SetWaitClient()
{
  Context()->SetDeltaTimeWaitMS(eTimeWaitClient_ms);
}
//--------------------------------------------------------------
