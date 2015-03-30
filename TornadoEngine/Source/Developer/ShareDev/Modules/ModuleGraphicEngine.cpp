/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleGraphicEngine.h"
#include "BL_Debug.h"
#include "GraphicEngine_OGRE_MyGUI.h"

TModuleGraphicEngine::TModuleGraphicEngine()
{
  mGE.reset(new TGraphicEngine_OGRE_MyGUI);
  mGE->SetSelfID(0);
  mGE->SetDstObject(this);
}
//---------------------------------------------------------------------------------
bool TModuleGraphicEngine::Work()
{
  InputFromSynchroPoint();
  bool resWork = mGE->Work();
  OutputToSynchroPoint();

  return resWork;
}
//---------------------------------------------------------------------------------
TGraphicEngine_OGRE_MyGUI* TModuleGraphicEngine::GetGE()
{
  return mGE.get();
}
//---------------------------------------------------------------------------------
void TModuleGraphicEngine::StartEvent()
{
  mCBSetup->Notify(this);
}
//---------------------------------------------------------------------------------
void TModuleGraphicEngine::StopEvent()
{

}
//---------------------------------------------------------------------------------
void TModuleGraphicEngine::SetFuncForSetup(TCallBackRegistrator1<TModuleDev*>* pCBSetup)
{
  mCBSetup = pCBSetup;
}
//---------------------------------------------------------------------------------
