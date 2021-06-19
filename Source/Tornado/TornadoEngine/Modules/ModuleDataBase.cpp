/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModuleDataBase.h"
#include "HiTimer.h"

TModuleDataBase::TModuleDataBase()
{

}
//----------------------------------------------------------------------
TModuleDataBase::~TModuleDataBase()
{

}
//----------------------------------------------------------------------
bool TModuleDataBase::WorkInherit()
{
  //ht_msleep(20);//###
  return true;
}
//----------------------------------------------------------------------
void TModuleDataBase::StartEvent()
{
  mCBStartEvent.Notify();
}
//----------------------------------------------------------------------
void TModuleDataBase::StopEvent()
{
  mCBStopEvent.Notify();
}
//----------------------------------------------------------------------
