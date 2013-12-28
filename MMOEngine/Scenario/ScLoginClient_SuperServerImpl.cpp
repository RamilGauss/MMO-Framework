/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_SuperServerImpl.h"
#include "Logger.h"
#include "ContextScLoginClient.h"
#include "ManagerSession.h"
#include "Events.h"
#include "ErrorCode.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_SuperServerImpl::TScLoginClient_SuperServerImpl(IScenario* pSc):
TBaseScLoginClient(pSc)
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RecvInherit(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->from)
  {
    case eMaster:
      RecvFromMaster(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::Work(unsigned int time_ms)
{
  BL_FIX_BUG();
}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RecvFromMaster(TDescRecvSession* pDesc)
{
  THeader* pHeader = (THeader*)pDesc->data;
  switch(pHeader->subType)
  {
    case eRequestM2SS:
      RequestM2SS(pDesc);
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RequestM2SS(TDescRecvSession* pDesc)
{
  unsigned int id_session_master = pDesc->id_session;

  THeaderRequestM2SS* pRequest = (THeaderRequestM2SS*)pDesc->data;
  NeedContextByMasterSessionByClientKey(id_session_master, pRequest->id_client);

  bool isExist = false;
  if(Context()->GetFakeClient())
    isExist = true;
    // проверка
  if(Begin()==false)
    BL_FIX_BUG();
  End();
  // формирование пакета
  TBreakPacket bp;// контейнер дл€ всего пакета
  THeaderCheckRequestSS2M h;
  h.id_client       = pRequest->id_client;
  h.isExistInSystem = isExist;
  bp.PushFront((char*)&h, sizeof(h));
  // отослать пакет дл€ попытки авторизации
  Context()->GetMS()->Send(id_session_master, bp);
}
//--------------------------------------------------------------
void TScLoginClient_SuperServerImpl::SetFakeClient(bool val)
{
  Context()->SetFakeClient(val);
}
//--------------------------------------------------------------
