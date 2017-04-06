/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleComponent.h"
#include "BaseLogicPacket.h"
#include "LogicEventCallBack.h"

TModuleComponent::TModuleComponent()
{
  mLogicID = -1;
}
//------------------------------------------------------------------------
void TModuleComponent::SetLogicID(int id)
{
  mLogicID = id;
}
//------------------------------------------------------------------------
void TModuleComponent::Input(int id_sender, void* p, int size)
{
  if(id_sender!=mLogicID)
    return;

  TBaseLogicPacket* pBLP = (TBaseLogicPacket*)p;
  switch(pBLP->type)
  {
    case nsBaseLogicPacket::eCallBack0:
      ((TLogicEventCallBack0*)pBLP)->mCB.Notify();
      break;
    default:;
  }
}
//--------------------------------------------------------------
void TModuleComponent::OutputToSynchroPoint()
{
  while(1)
  { // модуль создал события
    nsEvent::TEvent* pEvent = TDstEvent::GetEvent();
    if(pEvent==NULL)
      break;

    TSynchroAbonent::AddEventWithoutCopy(mLogicID, pEvent->pContainer);
    pEvent->pContainer = NULL;
    delete pEvent;
  }
}
//---------------------------------------------------------------------------------
TCallBackRegistrator0* TModuleComponent::GetCBStartEvent()
{
	return &mCBStartEvent;
}
//---------------------------------------------------------------------------------
TCallBackRegistrator0* TModuleComponent::GetCBStopEvent()
{
	return &mCBStopEvent;
}
//---------------------------------------------------------------------------------


