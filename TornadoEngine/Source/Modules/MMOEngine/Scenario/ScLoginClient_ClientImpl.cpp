/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_ClientImpl.h"
#include "ContextScLoginClient.h"
#include "ManagerSession.h"
#include "Base.h"
#include "Logger.h"
#include "Events.h"
#include "EnumMMO.h"
#include "SrcEvent_ex.h"
#include "MD5.h"
#include "CryptMITM.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_ClientImpl::TScLoginClient_ClientImpl(IScenario* pSc):
TBaseScLoginClient(pSc)
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvInherit(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->from)
  {
    case eSlave:
      RecvFromSlave(pDesc);
      break;
    case eMaster:
      RecvFromMaster(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::Work(unsigned int time_ms)
{
	unsigned int time_end_ms = Context()->GetTimeWait() + eTimeWait;
	if(time_end_ms < time_ms)
  {
    // ошибка на той стороне
    TEventError event;
    event.code = LoginClient_ClientNoAnswer;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::TryLogin(unsigned int ip, unsigned short port, unsigned char subNet,
                                         void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
{
	if(Begin()==false)
  {
    // генерация ошибки
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TScenarioLoginClient::TryLogin() scenario is not active.\n");
    BL_FIX_BUG();
    return;
  }
  Context()->SetNeedLeaveQueue(false);
  Context()->SetSubNet(subNet);

  TContainer cMITM;
  TBreakPacket bpLP;// контейнер для всего пакета
  if(Context()->GetMS()->GetUseCryptTCP())
  {
    // если данные шифруются, то формировать так:
    // получить RSA public key от ManagerSession
    TContainer cRSA;
    bool resRSA = Context()->GetMS()->GetRSAPublicKeyForUp(cRSA);
    BL_ASSERT(resRSA);
    TCryptMITM cryptMITM;
    bool res = cryptMITM.Calc(cRSA.GetPtr(), cRSA.GetSize(),
      pLogin, sizeLogin, pPassword, sizePassword, cMITM);
    BL_ASSERT(res);

    bpLP.PushFront(cMITM.GetPtr(), cMITM.GetSize());
		// сохранить на будущее
		Context()->Set_L_AES_RSA(cMITM.GetPtr(), cMITM.GetSize());
  }
  else
  {
    // иначе просто отослать данные:
    // формирование пакета
    bpLP.PushFront((char*)pLogin,    sizeLogin);
    bpLP.PushFront((char*)pPassword, sizePassword);
  }
  THeaderTryLoginC2M h;
  bpLP.PushFront((char*)&h, sizeof(h));

  // отослать пакет для попытки авторизации
  SetID_SessionClientMaster(Context()->GetMS()->Send(ip, port, bpLP, subNet));
  if(GetID_SessionClientMaster()==INVALID_HANDLE_SESSION)
  {
    // Генерация ошибки
    TEventError event;
    event.code = LoginClient_ClientMasterNotReady;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
    return;
  }
  
  SetTimeWaitForNow();
}
//-----------------------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvFromSlave(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eCheckConnectToSlaveS2C:
      CheckConnectToSlaveS2C(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eResultLoginM2C:
      ResultLoginM2C(pDesc);
      break;
    case eInfoSlaveM2C:
      InfoSlaveM2C(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::CheckConnectToSlaveS2C(TDescRecvSession* pDesc)
{
  TEventResultLogin* pEvent = new TEventResultLogin;
  pEvent->res = TMaster::eAccept;
  // поместить данные, которые шлет сервер в качестве приветствия
  char* pDataResClient = (char*)Context()->GetSaveAcceptDataPtr();
  int sizeResClient    = Context()->GetSaveAcceptDataSize();
  pEvent->c.SetDataByCount( pDataResClient, sizeResClient);
  Context()->GetSE()->AddEventWithoutCopy<TEventResultLogin>(pEvent);

  ((IContextScenario*)Context())->SetID_Session(pDesc->id_session);
  End();
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::ResultLoginM2C(TDescRecvSession* pDesc)
{
  // обновить время таймера
  SetTimeWaitForNow();
  //==============================
  THeaderResultLoginM2C* pH = (THeaderResultLoginM2C*)pDesc->data;
  switch(pH->result)
  {
    case THeaderResultLoginM2C::eAccept:
    {
      // сохранить свой ключ и данные авторизации
      Context()->SetClientKey(pH->id_client);
      char* p  = ((char*)(pH)) + sizeof(THeaderResultLoginM2C);
      int size = pH->sizeResClient;
      Context()->SaveAcceptData(p, size);
      EventSetClientKey(pH->id_client);
    }
      break;
    case THeaderResultLoginM2C::eReject:
    {
      CloseSessionMaster();

			TEventResultLogin* pEvent = new TEventResultLogin;
			pEvent->res = TMaster::eReject;
			// поместить данные, которые поясняют причину отказа
			char* pDataResClient = pDesc->data + sizeof(THeaderResultLoginM2C);
			pEvent->c.SetDataByCount( pDataResClient, pH->sizeResClient);
			Context()->GetSE()->AddEventWithoutCopy<TEventResultLogin>(pEvent);
      End();
    }
      break;
    case THeaderResultLoginM2C::eQueue:
    {
      Context()->SetClientKey(pH->id_client);
      EventSetClientKey(pH->id_client);

      Context()->SetNumInQueue(pH->numInQueue);

      TEventEnterInQueue event;
      event.numInQueue = pH->numInQueue;
      Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    }
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::InfoSlaveM2C(TDescRecvSession* pDesc)
{
  Context()->SetNeedLeaveQueue(false);
  // смотрим что нам прислали
  THeaderInfoSlaveM2C* pInfoSlave = (THeaderInfoSlaveM2C*)pDesc->data;
  Context()->SetSlaveIP_Port(pInfoSlave->ip_port_slave);
  // чисто для отладки, что бы удостовериться что назначили
  // в будущем можно будет удалить
  Context()->SetClientKey(pInfoSlave->id_client);
  EventSetClientKey(pInfoSlave->id_client);

  // формируем пакет для Master
  TBreakPacket bp;
  THeaderCheckInfoSlaveC2M h;
  h.id_client = Context()->GetClientKey();// равнозначно - pInfoSlave->id_client;
  bp.PushFront((char*)&h, sizeof(h));

  Context()->GetMS()->Send(GetID_SessionClientMaster(),bp);
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::LeaveQueue()
{
  // спросить у контекста состоит ли клиент в очереди
  if(Context()->GetNumInQueue()==0)
    return;

  TBreakPacket bp;
  THeaderLeaveQueueC2M h;
  bp.PushFront((char*)&h, sizeof(h));

  unsigned int id_master = GetID_SessionClientMaster();
  if(id_master==INVALID_HANDLE_SESSION)
    return;

  Context()->SetNeedLeaveQueue(true);
  Context()->GetMS()->Send(id_master,bp);
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::CloseSessionMaster()
{
  Context()->GetMS()->CloseSession(GetID_SessionClientMaster());
  SetID_SessionClientMaster(INVALID_HANDLE_SESSION);
}
//--------------------------------------------------------------
void TScLoginClient_ClientImpl::Disconnect()
{
  // ждет ли в очереди и хочет ли выйти из нее
  if(Context()->NeedLeaveQueue())
  {
    TEventLeaveQueue event;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
    return;
  }
  // пере подключить транспорт с мастера на Slave
  // формируем пакет для Slave
  TBreakPacket bp;
  THeaderConnectToSlaveC2S h;
  // для Slave отдать свой ID, он по нему нас зарегистрирует  
  h.id_client = Context()->GetClientKey();
  // для проверки на надежность нашего канала 
  if(Context()->GetMS()->GetUseCryptTCP())
    bp.PushFront(Context()->GetPtr_L_AES_RSA(),Context()->GetSize_L_AES_RSA());
  bp.PushFront((char*)&h, sizeof(h));
  // открыть сессию по IP:port
  TIP_Port ip_port_slave = Context()->GetSlaveIP_Port();
  unsigned int id_slave = 
    Context()->GetMS()->Send(ip_port_slave.ip,
                             ip_port_slave.port,
                             bp, Context()->GetSubNet());
  // проверка на наличие готовности Slave
  if(id_slave==INVALID_HANDLE_SESSION)
  {
    // Генерация ошибки
    TEventError event;
    event.code = LoginClient_ClientNotExistSlave;
    Context()->GetSE()->AddEventCopy(&event, sizeof(event));
    End();
    return;
  }
  SetID_SessionClientSlave(id_slave);
  SetTimeWaitForNow();
}
//--------------------------------------------------------------
