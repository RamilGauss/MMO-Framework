/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScenarioSendToClient.h"
#include "SessionManager.h"
#include "Events.h"
#include "SrcEvent_ex.h"

using namespace nsMMOEngine;

TScenarioSendToClient::TScenarioSendToClient()
{

}
//-------------------------------------------------------------------
TScenarioSendToClient::~TScenarioSendToClient()
{

}
//-------------------------------------------------------------------
void TScenarioSendToClient::Recv(TDescRecvSession* pDesc)
{
  THeader* pPacket = (THeader*)pDesc->data;
  switch(pPacket->subType)
  {
    case eSuperServer:
      RecvFromSuperServer(pDesc);
      break;
    case eMaster:
      RecvFromMaster(pDesc);
      break;
    case eSlave:
      RecvFromSlave(pDesc);
      break;
  }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromSuperServer(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
  SendAll<THeaderSuperServer>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromMaster(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
  SendAll<THeaderMaster>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromSlave(std::list<unsigned int>& lKey, TBreakPacket& bp)
{
  SendAll<THeaderSlave>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromSuperServer(TDescRecvSession* pDesc)
{
  THeaderSuperServer* pH = (THeaderSuperServer*)pDesc->data;
  NeedContextByClientKey(pH->id_client);
  if(Context())
  {
    mBP.Reset();
    mBP.PushFront(pDesc->data + sizeof(THeaderSuperServer), 
                 pDesc->sizeData - sizeof(THeaderSuperServer) );

    Send<THeaderMaster>(pH->id_client, mBP);
  }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeaderMaster* pH = (THeaderMaster*)pDesc->data;
  NeedContextByClientKey(pH->id_client);
  if(Context())
  {
    mBP.Reset();
    mBP.PushFront(pDesc->data + sizeof(THeaderMaster), 
                 pDesc->sizeData - sizeof(THeaderMaster) );
    
    Send<THeaderSlave>(pH->id_client, mBP);
  }
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromSlave(TDescRecvSession* pDesc)
{
  THeaderSlave* pH = (THeaderSlave*)pDesc->data;

  TEventRecvFromUp* pEvent = new TEventRecvFromUp;
  // отцепиться от памяти, в которой содержится пакет
  pDesc->c.Unlink();
  // отдать память под контроль события
  pEvent->c.EntrustByCount(pDesc->data, pDesc->sizeData);
  pEvent->data     = pDesc->data     + sizeof(THeaderSlave);
  pEvent->sizeData = pDesc->sizeData - sizeof(THeaderSlave);
  // откуда пришел пакет - сессия
  pEvent->id_session = pDesc->id_session;
  // добавить событие без копирования и указать истинное время создания события в транспорте
  Context()->GetSE()->AddEventWithoutCopy<TEventRecvFromUp>(pEvent, pDesc->time_ms);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::DelayBegin()
{
  Context()->SendAndRemoveFirst();
  End();
}
//-------------------------------------------------------------------
