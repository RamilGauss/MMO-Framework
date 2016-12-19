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
#include "ShowTankWoT_test.h"
#include "ControlCamera.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

TEditorMapLogic::TEditorMapLogic()
{
  mID_TimerTryMoveCamera = -1;
  mPtrShowTank.reset(new TShowTankWoT_test);
  mPtrControlCamera.reset(new TControlCamera);
}
//-------------------------------------------------------------------
TEditorMapLogic::~TEditorMapLogic()
{

}
//-------------------------------------------------------------------
void TEditorMapLogic::StartEvent()
{
  if(mAggregationScenario_Client.get())
  {
    mAggregationScenario_Client->GetCB_Progress()->Register( &TEditorMapLogic::ProgressScenario, this);
    mAggregationScenario_Client->GetCB_End()->Register( &TEditorMapLogic::EndScenario, this);
  }

  CallBackModule(nsListModules::Timer, &TEditorMapLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::InitForms);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::ShowTanks);

  mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorMapLogic::FreeGraphicResource,this);
  mComp.pGraphicEngine->GetCBEndWork()->Register( &TEditorMapLogic::GraphicEndWork ,this);
  mComp.pPhysicEngine->GetCBEndWork()->Register( &TEditorMapLogic::PhysicEndWork ,this);
  mComp.pSoundEngine->GetCBEndWork()->Register( &TEditorMapLogic::SoundEndWork ,this);
}
//-------------------------------------------------------------------
void TEditorMapLogic::StopEvent()
{
  mAggregationScenario_Client.reset(NULL);
}
//-------------------------------------------------------------------
void TEditorMapLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("EditorMap");
}
//-------------------------------------------------------------------
TFactoryBehaviourPatternModel* TEditorMapLogic::GetFBPM()
{
  return &mFBP_EoWM;
}
//--------------------------------------------------------------------
bool TEditorMapLogic::WorkClient()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Logic();
  return true;
}
//-------------------------------------------------------------------
void TEditorMapLogic::Input(int id_sender, void* p, int size)
{
  switch(id_sender)
  {
    case nsListModules::GraphicEngine:
      HandleFromGraphicEngine((nsGraphicEngine::TBaseEvent*)p);
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::Timer:
      {
        TModuleTimer::TEvent* pTE = (TModuleTimer::TEvent*)p;
        if(pTE->id==mID_TimerTryMoveCamera)
          mPtrControlCamera->CameraTryMove(); 
      }
      break;
    case nsListModules::FromSomeToLogic:// EditorMap
    {
      //### пока через строку, потом должен быть протокол
      char* pLMP = (char*)p;
      char s[300];
      strncpy(s, pLMP, size);
      s[size] = '\0';
      std::string sNameMap;
      sNameMap = s;
      LoadGameMap(sNameMap);
      //### пока через строку, потом должен быть протокол
    }
      break;
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------
void TEditorMapLogic::StartTimer()
{
  // вызовется из потока таймера
  mID_TimerTryMoveCamera = mComp.pTimer->New(30);
}
//----------------------------------------------------------
void TEditorMapLogic::InitForms()
{ //mComp.pGraphicEngine->GetGE()->GetWindow()->setFullscreen(true, 1280, 1024);
  mEditorMap = new TEditorMap;
  mEditorMap->Show();

  mComp.pGraphicEngine->GetGE()->SetWindowCaptionUtf8("Редактор карт");
}
//----------------------------------------------------------
void TEditorMapLogic::PhysicEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::GraphicEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_Ogre();
  
  //mPtrControlCamera->CameraTryMove();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::SoundEndWork()
{
  if(mAggregationScenario_Client.get())
    mAggregationScenario_Client->Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::FreeGraphicResource()
{
  delete mEditorMap;
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::LoadGameMap(std::string& nameMap)
{
  if(mAggregationScenario_Client.get())
    if(mAggregationScenario_Client->Activate(nsGameProcess::eBuilder))
  {
    mAggregationScenario_Client->Setup( &mUsePattern, &mFBP_EoWM );
    mAggregationScenario_Client->LoadMap(nameMap);
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::ProgressScenario(nsGameProcess::GP_TypeScenario type, int progress)
{
  switch(type)
  {
    case nsGameProcess::eBuilder:
    case nsGameProcess::eDestructor:
      // отрисовка прогресса загрузки или выгрузки
      break;
    case nsGameProcess::eSynchroClient:
      // не должны сюда попасть
      BL_FIX_BUG();
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::EndScenario(nsGameProcess::GP_TypeScenario type)
{
  switch(type)
  {
    case nsGameProcess::eBuilder:
    case nsGameProcess::eDestructor:
      if( mAggregationScenario_Client->Activate(nsGameProcess::eSynchroClient)==false )
      {
        BL_FIX_BUG();
      }
      // ??? вызов из физического потока?
      if(type==nsGameProcess::eBuilder)
        mComp.pPhysicEngine->GetPE()->Setup( mAggregationScenario_Client->GetPhysicWorldID(), 
                                             TPhysicEngine_Bullet::eStatePause );
      // ???
      break;
    case nsGameProcess::eSynchroClient:
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::HandleFromGraphicEngine(nsGraphicEngine::TBaseEvent* pBaseGE)
{
  switch( pBaseGE->type )
  {
    case nsGraphicEngine::eMouse:
      HandleFromGraphicEngine_Mouse((nsGraphicEngine::TMouseEvent*)pBaseGE);
      break;
    case nsGraphicEngine::eKeyBoard:
      HandleFromGraphicEngine_Key((nsGraphicEngine::TKeyEvent*)pBaseGE);
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::HandleFromGraphicEngine_Mouse(nsGraphicEngine::TMouseEvent* pMouseGE)
{
  switch( pMouseGE->typeEvent )
  {
    case nsGraphicEngine::eButtonDown:
      //if( (pMouseGE->pressedButtons&(1<<OIS::MB_Left)) )
        //mPtrControlCamera->MouseLeftButtonDown(pMouseGE->x, pMouseGE->y);
      break;
    case nsGraphicEngine::eButtonUp:
      //if( (pMouseGE->pressedButtons&(1<<OIS::MB_Left))==0 )// отжали левую кнопку
        //mPtrControlCamera->MouseLeftButtonUp();
      break;
    case nsGraphicEngine::eButtonDblClick:
      break;
    case nsGraphicEngine::eWheel:
      break;
    case nsGraphicEngine::eMove:
      if( pMouseGE->pressedButtons&(1<<OIS::MB_Left) )
        mPtrControlCamera->MoveMouse(pMouseGE->dx, pMouseGE->dy);// двигать камеру
      else if( pMouseGE->pressedButtons&(1<<OIS::MB_Right) )
      {// двигать объект
        int a = 0;
      }
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::HandleFromGraphicEngine_Key(nsGraphicEngine::TKeyEvent* pKeyGE)
{
  switch( pKeyGE->key )
  {
    case OIS::KC_W:
      mPtrControlCamera->SetMoveForward(pKeyGE->pressed);
      break;
    case OIS::KC_S:
      mPtrControlCamera->SetMoveBackward(pKeyGE->pressed);
      break;
    case OIS::KC_A:
      mPtrControlCamera->SetMoveLeft(pKeyGE->pressed);
      break;
    case OIS::KC_D:
      mPtrControlCamera->SetMoveRight(pKeyGE->pressed);
      break;
    case OIS::KC_Q:
      mPtrControlCamera->SetMoveDown(pKeyGE->pressed);
      break;
    case OIS::KC_E:
      mPtrControlCamera->SetMoveUp(pKeyGE->pressed);
      break;
    case OIS::KC_ESCAPE:
      Exit();
      break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::ShowTanks()
{
  mPtrShowTank->ShowTanks(4);
}
//---------------------------------------------------------------------------------------------
