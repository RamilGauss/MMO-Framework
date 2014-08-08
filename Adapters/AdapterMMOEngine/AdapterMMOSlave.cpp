/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterMMOSlave.h"
#include "Slave.h"
#include "ConverterEvents.h"
#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#define mSlave ((nsMMOEngine::TSlave*)mPtrSlave)

AdapterMMOSlave::AdapterMMOSlave():
mConverter(new TConverterEvents),mMakerTransport(new TWrapperMakerTransport)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);

  mPtrSlave = new nsMMOEngine::TSlave;
  
  mSlave->Init(mMakerTransport.get());

  mSlave->SetDstObject(this);
  mSlave->SetSelfID(ID_Slave);
}
//--------------------------------------------------------------------------------------------------------
AdapterMMOSlave::~AdapterMMOSlave()
{
  delete mSlave;
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::Open(PrototypeMMODescOpen* pDesc, int count)
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = pDesc->subNet;
  descOpen.port   = pDesc->port;
  return mSlave->Open( &descOpen, count );
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::DisconnectUp()
{
  mSlave->DisconnectUp();
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SendUp(TBreakPacket bp, bool check)
{
  mSlave->SendUp(bp, check);
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::IsConnectUp()
{
  return mSlave->IsConnectUp();
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::IsConnect(unsigned int id)
{
  return mSlave->IsConnect(id);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SetLoad(int procent)
{
  mSlave->SetLoad(procent);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SetTimeLiveSession(unsigned int time_ms)
{
  mSlave->SetTimeLiveSession(time_ms);
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
{
  return mSlave->GetInfoSession(id_session, ip_port);
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, void* login_password, int size_login_password)
{
  return mSlave->IsSessionSecurity(id_session, crypt, size_crypt, login_password, size_login_password);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::DisconnectByKeyClient(unsigned int id_client)
{
  mSlave->DisconnectByKeyClient(id_client);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SendByClientKey(std::list<unsigned int>& l, TBreakPacket bp)
{
  mSlave->SendByClientKey(l, bp);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  mSlave->SendDown(id_session, bp, check);
}
//--------------------------------------------------------------------------------------------------------
int AdapterMMOSlave::GetCountDown()
{
  return mSlave->GetCountDown();
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  return mSlave->GetDescDown(index, pDesc, sizeDesc);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::ConnectUp(unsigned int ip, unsigned short port, unsigned char subNet)
{
  mSlave->ConnectUp(ip, port, subNet);
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::SaveContext(unsigned int id_session, void* data, int size)
{
  mSlave->SaveContext(id_session, data, size);
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::FindClientKeyBySession(unsigned int id_session, unsigned int &id)
{
  return mSlave->FindClientKeyBySession(id_session, id);
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::FindSessionByClientKey(unsigned int id, unsigned int& id_session)
{
  return mSlave->FindSessionByClientKey(id, id_session);
}
//--------------------------------------------------------------------------------------------------------
PrototypeBaseModule* AdapterMMOSlave::NewExample()
{
  return new AdapterMMOSlave;
}
//--------------------------------------------------------------------------------------------------------
void AdapterMMOSlave::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//--------------------------------------------------------------------------------------------------------
int  AdapterMMOSlave::GetVersionAdapter()
{
  return 1;
}
//--------------------------------------------------------------------------------------------------------
bool AdapterMMOSlave::Work()
{
  //дать квант времени и транслировать события в игровой движок
  mSlave->Work();
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
//--------------------------------------------------------------------------------------------------------
