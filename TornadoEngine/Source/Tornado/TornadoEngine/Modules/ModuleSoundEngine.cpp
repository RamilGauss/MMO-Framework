/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModuleSoundEngine.h"

TModuleSoundEngine::TModuleSoundEngine()
{

}
//----------------------------------------------------------------------
bool TModuleSoundEngine::WorkInherit()
{
  return true;
}
//----------------------------------------------------------------------
void TModuleSoundEngine::StartEvent()
{
  mCBStartEvent.Notify();
}
//----------------------------------------------------------------------
void TModuleSoundEngine::StopEvent()
{
  mCBStopEvent.Notify();
}
//----------------------------------------------------------------------
