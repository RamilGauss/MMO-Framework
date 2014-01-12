/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScenarioSendToClient.h"
#include "ManagerSession.h"
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
void TScenarioSendToClient::SendFromSuperServer(std::list<unsigned int>& lKey, TBreakPacket bp)
{
	SendAll<THeaderSuperServer>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromMaster(std::list<unsigned int>& lKey, TBreakPacket bp)
{
	SendAll<THeaderMaster>(lKey, bp);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::SendFromSlave(std::list<unsigned int>& lKey, TBreakPacket bp)
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
		TBreakPacket bp;
		bp.PushFront(pDesc->data + sizeof(THeaderSuperServer), 
			           pDesc->sizeData - sizeof(THeaderSuperServer) );

		Send<THeaderMaster>(pH->id_client, bp);
	}
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromMaster(TDescRecvSession* pDesc)
{
	THeaderMaster* pH = (THeaderMaster*)pDesc->data;
	NeedContextByClientKey(pH->id_client);
	if(Context())
	{
		TBreakPacket bp;
		bp.PushFront(pDesc->data + sizeof(THeaderMaster), 
			           pDesc->sizeData - sizeof(THeaderMaster) );
		
		Send<THeaderSlave>(pH->id_client, bp);
	}
}
//-------------------------------------------------------------------
void TScenarioSendToClient::RecvFromSlave(TDescRecvSession* pDesc)
{
	THeaderSlave* pH = (THeaderSlave*)pDesc->data;

	TEventRecvFromUp* pEvent = new TEventRecvFromUp;
	// отцепитьс€ от пам€ти, в которой содержитс€ пакет
	pDesc->c.Unlink();
	// отдать пам€ть под контроль событи€
	pEvent->c.EntrustByCount(pDesc->data, pDesc->sizeData);
	pEvent->data     = pDesc->data     + sizeof(THeaderSlave);
	pEvent->sizeData = pDesc->sizeData - sizeof(THeaderSlave);
	// откуда пришел пакет - сесси€
	pEvent->id_session = pDesc->id_session;
	// добавить событие без копировани€ и указать истинное врем€ создани€ событи€ в транспорте
	Context()->GetSE()->AddEventWithoutCopy<TEventRecvFromUp>(pEvent, pDesc->time_ms);
}
//-------------------------------------------------------------------
void TScenarioSendToClient::DelayBegin()
{
	Context()->SendAndRemoveFirst();
	End();
}
//-------------------------------------------------------------------
