/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScenarioFlow.h"
#include "Events.h"
#include "ManagerSession.h"

using namespace nsMMOEngine;

TScenarioFlow::TScenarioFlow()
{

}
//-------------------------------------------------------------------------
TScenarioFlow::~TScenarioFlow()
{

}
//-------------------------------------------------------------------------
void TScenarioFlow::SendUp(TBreakPacket bp, bool check)
{
  THeaderSendUp h;
  bp.PushFront((char*)&h, sizeof(h));
  HandlePacket( bp, check);
}
//-------------------------------------------------------------------------
void TScenarioFlow::SendDown(TBreakPacket bp, bool check)
{
  THeaderSendDown h;
  bp.PushFront((char*)&h, sizeof(h));
  HandlePacket( bp, check);
}
//-------------------------------------------------------------------------
void TScenarioFlow::Recv(TDescRecvSession* pDesc)
{
  NeedContextBySession(pDesc->id_session);

  THeaderFlow* pPacket = (THeaderFlow*)pDesc->data;
  switch(pPacket->subType)
  {
    case eUp:
      Recv<TEventRecvFromDown>(pDesc);
      break;
    case eDown:
      Recv<TEventRecvFromUp>(pDesc);
      break;
  }
}
//-------------------------------------------------------------------------
void TScenarioFlow::DelayBegin()
{
  Context()->SendAndRemoveFirst();
  End();
}
//-------------------------------------------------------------------------
void TScenarioFlow::HandlePacket(TBreakPacket& bp, bool check)
{
  // попытатьс€ активизироватьс€
  if(Begin())
  {
    // отсылка сразу
    Context()->Send(bp, check);
    // сценарий закончен
    End();
  }
  else
  {
    // пока отослать нельз€, сохранить пакет до момента возможности
    Context()->SaveBreakPacket(bp, check);
  }
}
//-------------------------------------------------------------------------
