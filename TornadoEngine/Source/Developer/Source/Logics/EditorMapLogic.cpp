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

  CallBackModule(nsListModules::PhysicEngine, &TEditorMapLogic::InitPhysic);

  mComp.pGraphicEngine->GetCBBeginWork()->Register( &TEditorMapLogic::GraphicBeginWork ,this);

  mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorMapLogic::FreeGraphicResource,this);

  mComp.pPhysicEngine->GetCBBeginWork()->Register( &TEditorMapLogic::PhysicBeginWork ,this);
  mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorMapLogic::PhysicEndWork ,this);
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

}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::InitPhysic()
{
  mID_PhysicWorld = mComp.pPhysicEngine->GetPE()->AddWorld();
  btDiscreteDynamicsWorld* dynamicsWorld = mComp.pPhysicEngine->GetPE()->GetWorld(mID_PhysicWorld);
  dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::GraphicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::PhysicBeginWork()
{

}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::FreeGraphicResource()
{
  delete mEditorMap;
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::LoadGameMap(std::string& nameMap)
{
  mMGM.GetBGM()->InitPhysic( mID_PhysicWorld );

  TMapItem* pMapItem = (TMapItem*)mFGI.Get( TFactoryGameItem::Map, nameMap );
  if( mMGM.GetBGM()->BuildMap( pMapItem )==false )
  {
    BL_FIX_BUG();
    return;
  }
}
//---------------------------------------------------------------------------------------------
