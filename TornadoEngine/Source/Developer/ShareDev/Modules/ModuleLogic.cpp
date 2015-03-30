/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleLogic.h"

static TModuleLogic* g_ptrModuleLogic = NULL;

TModuleLogic::TModuleLogic()
{
  g_ptrModuleLogic = this;
  flgNeedExit = false;
}
//--------------------------------------------------------------------
void TModuleLogic::SetComponents(TComponents components)
{
  mComp = components;
}
//--------------------------------------------------------------------
TModuleLogic* TModuleLogic::Get()
{
  return g_ptrModuleLogic;
}
//--------------------------------------------------------------------
void TModuleLogic::Exit( int reason )
{
  flgNeedExit = true;
}
//--------------------------------------------------------------------
bool TModuleLogic::NeedExit()
{
  return flgNeedExit;
}
//--------------------------------------------------------------------
TComponents* TModuleLogic::GetC()
{
  return &mComp;
}
//--------------------------------------------------------------------
