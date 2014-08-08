/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterMMOClient.h"
#include "Structs.h"
#include "Client.h"
#include "ConverterEvents.h"
#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#define mClient ((nsMMOEngine::TClient*)mPtrClient)

AdapterMMOClient::AdapterMMOClient():
mConverter(new TConverterEvents),mMakerTransport(new TWrapperMakerTransport)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);

  mPtrClient = new nsMMOEngine::TClient;
  
  mClient->Init(mMakerTransport.get());

  mClient->SetDstObject(this);
  mClient->SetSelfID(ID_Client);
}
//------------------------------------------------------------------------------------
AdapterMMOClient::~AdapterMMOClient()
{
  delete mClient;
}
//------------------------------------------------------------------------------------
bool AdapterMMOClient::Open(PrototypeMMODescOpen* pDesc, int count)
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = pDesc->subNet;
  descOpen.port   = pDesc->port;
  return mClient->Open( &descOpen, count );
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::DisconnectUp()
{
  mClient->DisconnectUp();
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::SendUp(TBreakPacket bp, bool check )
{
  mClient->SendUp(bp, check );
}
//------------------------------------------------------------------------------------
bool AdapterMMOClient::IsConnectUp()
{
  return mClient->IsConnectUp();
}
//------------------------------------------------------------------------------------
bool AdapterMMOClient::IsConnect(unsigned int id)
{
  return mClient->IsConnect(id);
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::SetLoad(int procent)
{
  mClient->SetLoad(procent);
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::SetTimeLiveSession(unsigned int time_ms)
{
  mClient->SetTimeLiveSession(time_ms);
}
//------------------------------------------------------------------------------------
bool AdapterMMOClient::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
{
  return mClient->GetInfoSession(id_session, ip_port);
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::Login(unsigned int ip, unsigned short port, void* data, int size)
{
  mClient->Login(ip, port, data, size);
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::LeaveQueue()
{
  mClient->LeaveQueue();
}
//------------------------------------------------------------------------------------
PrototypeBaseModule* AdapterMMOClient::NewExample()
{
  return new AdapterMMOClient;
}
//------------------------------------------------------------------------------------
void AdapterMMOClient::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//------------------------------------------------------------------------------------
int AdapterMMOClient::GetVersionAdapter()
{
  return 1;
}
//------------------------------------------------------------------------------------
bool AdapterMMOClient::Work()
{
  //дать квант времени и транслировать события в игровой движок
  mClient->Work();
  nsEvent::TEvent* pEvent = GetEvent();
  while(pEvent)
  {
    // конвертация из событий модуля в события прототипа
    PrototypeMMOBaseEvent* pProtoEvent = 
      mConverter->Work((nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr());
    // трансляция события
    AddEventWithoutCopy(pProtoEvent, pEvent->time_ms);
    delete pEvent;
    pEvent = GetEvent();
  }
  return true;
}
//------------------------------------------------------------------------------------
