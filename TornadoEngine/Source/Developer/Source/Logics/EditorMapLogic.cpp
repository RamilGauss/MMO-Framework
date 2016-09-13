/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMapLogic.h"
#include "ListModules.h"
#include "Logger.h"

#include "ModuleTimer.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"
#include "ModuleSoundEngine.h"

#include "EditorMap.h"

TEditorMapLogic::TEditorMapLogic()
{

}
//-------------------------------------------------------------------
TEditorMapLogic::~TEditorMapLogic()
{

}
//-------------------------------------------------------------------
void TEditorMapLogic::StartEvent()
{
  CallBackModule(nsListModules::Timer, &TEditorMapLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::InitForms);

  mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorMapLogic::FreeGraphicResource,this);
  mComp.pGraphicEngine->GetCBEndWork()->Register( &TEditorMapLogic::GraphicEndWork ,this);
  mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorMapLogic::PhysicEndWork ,this);
  mComp.pSoundEngine->GetCBEndWork()->Register( &TEditorMapLogic::SoundEndWork ,this);
}
//-------------------------------------------------------------------
void TEditorMapLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("EditorMap");
}
//-------------------------------------------------------------------
bool TEditorMapLogic::WorkClient()
{
  mAggregationScenario_Client.Thread_Logic();
  return true;
}
//-------------------------------------------------------------------
void TEditorMapLogic::Input(int id_sender, void* p, int size)
{
  switch(id_sender)
  {
    case nsListModules::GraphicEngine:
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::Timer:
      break;
    case nsListModules::FromSomeToLogic:// EditorMap
    {
      //### пока через строку, потом должен быть протокол
      TLoadMapParam* pLMP = (TLoadMapParam*)p;
      LoadGameMap(pLMP->nameMap);
      //### пока через строку, потом должен быть протокол
    }
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------
void TEditorMapLogic::StartTimer()
{
  // вызовется из потока таймера
  unsigned int mID_Timer = mComp.pTimer->New(10);
}
//----------------------------------------------------------
void TEditorMapLogic::InitForms()
{
  mEditorMap = new TEditorMap;
  mEditorMap->Show();
}
//----------------------------------------------------------
void TEditorMapLogic::PhysicEndWork()
{
  mAggregationScenario_Client.Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
//void TEditorMapLogic::InitPhysic()// не удалять, пример установки вектора гравитации
//{
//  mID_PhysicWorld = mComp.pPhysicEngine->GetPE()->AddWorld();
//  btDiscreteDynamicsWorld* dynamicsWorld = mComp.pPhysicEngine->GetPE()->GetWorld(mID_PhysicWorld);
//  dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
//}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::GraphicEndWork()
{
  mAggregationScenario_Client.Thread_Ogre();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::SoundEndWork()
{
  mAggregationScenario_Client.Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::FreeGraphicResource()
{
  delete mEditorMap;
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::LoadGameMap(std::string& nameMap)
{
  if(mAggregationScenario_Client.Activate(nsGameProcess::eBuilder))
  {
    mAggregationScenario_Client.Setup( &mUsePattern, &mFBP_EoWM );
    mAggregationScenario_Client.LoadMap(nameMap);
  }
}
//---------------------------------------------------------------------------------------------
