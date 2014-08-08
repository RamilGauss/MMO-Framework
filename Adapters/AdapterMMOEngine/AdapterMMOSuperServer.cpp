/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterMMOSuperServer.h"
#include "SuperServer.h"
#include "ConverterEvents.h"
#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#define mSuperServer ((nsMMOEngine::TSuperServer*)mPtrSuperServer)

AdapterMMOSuperServer::AdapterMMOSuperServer():
mConverter(new TConverterEvents),mMakerTransport(new TWrapperMakerTransport)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);

  mPtrSuperServer = new nsMMOEngine::TSuperServer;
  
  mSuperServer->Init(mMakerTransport.get());

  mSuperServer->SetDstObject(this);
  mSuperServer->SetSelfID(ID_SuperServer);
}
//-----------------------------------------------------------------------------------------------
AdapterMMOSuperServer::~AdapterMMOSuperServer()
{
  delete mSuperServer;
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::Open(PrototypeMMODescOpen* pDesc, int count)
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = pDesc->subNet;
  descOpen.port   = pDesc->port;
  return mSuperServer->Open( &descOpen, count );
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::DisconnectUp()
{
  mSuperServer->DisconnectUp();
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::SendUp(TBreakPacket bp, bool check)
{
  mSuperServer->SendUp(bp, check);
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::IsConnectUp()
{
  return mSuperServer->IsConnectUp();
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::IsConnect(unsigned int id)
{
  return mSuperServer->IsConnect(id);
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::SetLoad(int procent)
{
  mSuperServer->SetLoad(procent);
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::SetTimeLiveSession(unsigned int time_ms)
{
  mSuperServer->SetTimeLiveSession(time_ms);
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
{
  return mSuperServer->GetInfoSession(id_session, ip_port);
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, void* login_password, int size_login_password)
{
  return mSuperServer->IsSessionSecurity(id_session, crypt, size_crypt, login_password, size_login_password);
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::DisconnectByKeyClient(unsigned int id_client)
{
  mSuperServer->DisconnectByKeyClient(id_client);
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::SendByClientKey(std::list<unsigned int>& l, TBreakPacket bp)
{
  mSuperServer->SendByClientKey(l, bp);
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  mSuperServer->SendDown(id_session, bp, check);
}
//-----------------------------------------------------------------------------------------------
int  AdapterMMOSuperServer::GetCountDown()
{
  return mSuperServer->GetCountDown();
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  return mSuperServer->GetDescDown(index, pDesc, sizeDesc);
}
//-----------------------------------------------------------------------------------------------
PrototypeBaseModule* AdapterMMOSuperServer::NewExample()
{
  return new AdapterMMOSuperServer;
}
//-----------------------------------------------------------------------------------------------
void AdapterMMOSuperServer::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//-----------------------------------------------------------------------------------------------
int  AdapterMMOSuperServer::GetVersionAdapter()
{
  return 1;
}
//-----------------------------------------------------------------------------------------------
bool AdapterMMOSuperServer::Work()
{
  //дать квант времени и транслировать события в игровой движок
  mSuperServer->Work();
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
//-----------------------------------------------------------------------------------------------
