/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorModelLogic.h"
#include "ListModules.h"
#include "Logger.h"

#include "ModuleTimer.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"

TEditorModelLogic::TEditorModelLogic()
{

}
//-------------------------------------------------------------------
TEditorModelLogic::~TEditorModelLogic()
{

}
//-------------------------------------------------------------------
void TEditorModelLogic::StartEvent()
{
  CallBackModule(nsListModules::Timer, &TEditorModelLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TEditorModelLogic::InitForms);

  CallBackModule(nsListModules::PhysicEngine, &TEditorModelLogic::InitPhysic);

  mComp.pGraphicEngine->GetCBBeginWork()->Register( &TEditorModelLogic::GraphicBeginWork ,this);

  mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorModelLogic::FreeGraphicResource,this);

  mComp.pPhysicEngine->GetCBBeginWork()->Register( &TEditorModelLogic::PhysicBeginWork ,this);
  mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorModelLogic::PhysicEndWork ,this);
}
//-------------------------------------------------------------------
void TEditorModelLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("EditorMap");
}
//-------------------------------------------------------------------
bool TEditorModelLogic::WorkClient()
{
  return true;
}
//-------------------------------------------------------------------
void TEditorModelLogic::Input(int id_sender, void* p, int size)
{
  switch(id_sender)
  {
    case nsListModules::GraphicEngine:
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::Timer:
      break;
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------
void TEditorModelLogic::StartTimer()
{
  // вызовется из потока таймера
  unsigned int mID_Timer = mComp.pTimer->New(10);
}
//----------------------------------------------------------
void TEditorModelLogic::InitForms()
{
  //mDebugPanel = new TDebugPanel;
  //mDebugPanel->Show();
}
//----------------------------------------------------------
void TEditorModelLogic::PhysicEndWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorModelLogic::InitPhysic()
{

}
//---------------------------------------------------------------------------------------------
void TEditorModelLogic::GraphicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorModelLogic::PhysicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorModelLogic::FreeGraphicResource()
{
  //delete mClientMain;
  //delete mDebugPanel;
}
//---------------------------------------------------------------------------------------------
