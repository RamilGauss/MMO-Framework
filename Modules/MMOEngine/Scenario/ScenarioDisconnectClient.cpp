/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

// Begin и End не обрамлять,
// т.к. возможно есть активные сценарии, поэтому что бы не ждать их окончания
// и тут же отреагировать

#include "ScenarioDisconnectClient.h"
#include "Logger.h"
#include "ManagerSession.h"

using namespace std;
using namespace nsMMOEngine;

TScenarioDisconnectClient::TScenarioDisconnectClient()
{

}
//---------------------------------------------------------------
void TScenarioDisconnectClient::Recv(TDescRecvSession* pDesc)
{
  THeaderDisconnectClient* pH = (THeaderDisconnectClient*)pDesc->data;
  switch(pH->subType)
  {
    case eFromMaster:
      RecvFromMaster(pDesc);
      break;
    case eFromSlave:
      RecvFromSlave(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//---------------------------------------------------------------
void TScenarioDisconnectClient::Work()
{

}
//---------------------------------------------------------------
void TScenarioDisconnectClient::DisconnectFromSlave(unsigned int id_client)
{
  // формирование пакета
  TBreakPacket bp;// контейнер для всего пакета
  THeaderFromSlave h;
  h.id_client = id_client;
  bp.PushFront((char*)&h, sizeof(h));
  // отослать пакет для попытки авторизации
  Context()->GetMS()->Send(Context()->GetID_Session(), bp);
}
//---------------------------------------------------------------
void TScenarioDisconnectClient::DisconnectFromMaster(vector<unsigned int>& vecID_client)
{
  // формирование пакета
  TBreakPacket bp;// контейнер для всего пакета
  bp.PushFront((char*)&vecID_client[0],vecID_client.size()*sizeof(unsigned int));
  THeaderFromMaster h;
  h.countID = vecID_client.size();
  bp.PushFront((char*)&h, sizeof(h));
  // отослать пакет для попытки авторизации
  Context()->GetMS()->Send(Context()->GetID_Session(), bp);
}
//---------------------------------------------------------------
void TScenarioDisconnectClient::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeaderFromMaster* pH = (THeaderFromMaster*)pDesc->data;

  unsigned int* pArrID = (unsigned int*)(pDesc->data + sizeof(THeaderFromMaster));
  for(int i = 0 ; i < pH->countID ; i++ )
  {
    // нужен контекст под это ID
    NeedContextByClientKey(pArrID[i]);
  }
}
//---------------------------------------------------------------
void TScenarioDisconnectClient::RecvFromSlave(TDescRecvSession* pDesc)
{
  THeaderFromSlave* pH = (THeaderFromSlave*)pDesc->data;

  NeedContextByClientKey(pH->id_client);
}
//---------------------------------------------------------------
