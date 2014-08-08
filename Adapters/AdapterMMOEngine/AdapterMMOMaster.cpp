/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterMMOMaster.h"
#include "Structs.h"
#include "Master.h"
#include "ConverterEvents.h"
#include "WrapperMakerTransport.h"
#include "SrcEvent_ex.h"

#define mMaster ((nsMMOEngine::TMaster*)mPtrMaster)

AdapterMMOMaster::AdapterMMOMaster():
mConverter(new TConverterEvents),mMakerTransport(new TWrapperMakerTransport)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);

  mPtrMaster = new nsMMOEngine::TMaster;

  mMaster->Init(mMakerTransport.get());

  mMaster->SetDstObject(this);
  mMaster->SetSelfID(ID_Master);
}
//--------------------------------------------------------------------------------------------------
AdapterMMOMaster::~AdapterMMOMaster()
{
  delete mMaster;
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::Open(PrototypeMMODescOpen* pDesc, int count)
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = pDesc->subNet;
  descOpen.port   = pDesc->port;
  return mMaster->Open( &descOpen, count );
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::DisconnectUp()
{
  mMaster->DisconnectUp();
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SendUp(TBreakPacket bp, bool check)
{
  mMaster->SendUp(bp, check);
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::IsConnectUp()
{
  return mMaster->IsConnectUp();
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::IsConnect(unsigned int id)
{
  return mMaster->IsConnect(id);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SetLoad(int procent)
{
  mMaster->SetLoad(procent);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SetTimeLiveSession(unsigned int time_ms)
{
  mMaster->SetTimeLiveSession(time_ms);
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
{
  return mMaster->GetInfoSession(id_session, ip_port);
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, void* login_password, int size_login_password)
{
  return mMaster->IsSessionSecurity(id_session, crypt, size_crypt, login_password, size_login_password);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::DisconnectByKeyClient(unsigned int id_client)
{
  mMaster->DisconnectByKeyClient(id_client);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SendByClientKey(std::list<unsigned int>& l, TBreakPacket bp)
{
  mMaster->SendByClientKey(l, bp);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SendDown(unsigned int id_session, TBreakPacket bp, bool check)
{
  mMaster->SendDown(id_session, bp, check);
}
//--------------------------------------------------------------------------------------------------
int  AdapterMMOMaster::GetCountDown()
{
  return mMaster->GetCountDown();
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::GetDescDown(int index, void* pDesc, int& sizeDesc)
{
  return mMaster->GetDescDown(index, pDesc, sizeDesc);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::ConnectUp(unsigned int ip, unsigned short port, unsigned char subNet)
{
  mMaster->ConnectUp(ip, port, subNet);
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::TryCreateGroup(std::list<unsigned int>& l_id_client, unsigned int& id_group)
{
  return mMaster->TryCreateGroup(l_id_client, id_group);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::DestroyGroup(unsigned int id_group)
{
  mMaster->DestroyGroup(id_group);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::LeaveGroup(unsigned int id_client)
{
  mMaster->LeaveGroup(id_client);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::GetListForGroup(unsigned int id_group, std::list<unsigned int>& l)
{
  mMaster->GetListForGroup(id_group, l);
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::SetResultLogin(bool res, unsigned int id_session, unsigned int id_client, void* resForClient, int sizeResClient)
{
  mMaster->SetResultLogin(res, id_session, id_client, resForClient, sizeResClient);
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::FindSlaveSessionByGroup(unsigned int id_group, unsigned int& id_session)
{
  return mMaster->FindSlaveSessionByGroup(id_group, id_session);
}
//--------------------------------------------------------------------------------------------------
PrototypeBaseModule* AdapterMMOMaster::NewExample()
{
  return new AdapterMMOMaster;
}
//--------------------------------------------------------------------------------------------------
void AdapterMMOMaster::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//--------------------------------------------------------------------------------------------------
int AdapterMMOMaster::GetVersionAdapter()
{
  return 1;
}
//--------------------------------------------------------------------------------------------------
bool AdapterMMOMaster::Work()
{
  //дать квант времени и транслировать события в игровой движок
  mMaster->Work();
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
//--------------------------------------------------------------------------------------------------
