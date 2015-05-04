/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModulePhysicEngine.h"

TModulePhysicEngine::TModulePhysicEngine()
{
  mPE.reset(new TPhysicEngine_Bullet);
}
//---------------------------------------------------------------------------------
bool TModulePhysicEngine::WorkInherit()
{
  InputFromSynchroPoint();
  mPE->Work();
  OutputToSynchroPoint();
  return true;
}
//---------------------------------------------------------------------------------
void TModulePhysicEngine::StartEvent()
{
  
}
//---------------------------------------------------------------------------------
void TModulePhysicEngine::StopEvent()
{

}
//---------------------------------------------------------------------------------
TPhysicEngine_Bullet* TModulePhysicEngine::GetPE()
{
  return mPE.get();
}
//---------------------------------------------------------------------------------
