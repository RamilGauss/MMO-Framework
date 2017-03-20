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
#include "ControlCamera.h"
#include "ProtocolGUI2Logic.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

//###
#include "ShowTankWoT_test.h"
#include "BuilderShapePlate_Ogre.h"
#include "MaterialItem.h"
#include "ShapeItem.h"
#include "TerrainItem.h"
#include "BuilderShapeCylinder_Ogre.h"
#include "BuilderTerrain_Ogre.h"
//###

TEditorMapLogic::TEditorMapLogic()
{
	mStatePhysicWorld = TPhysicEngine_Bullet::eStatePause;

	flgIsTerrainGroupUpdate = false;

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

		mAggregationScenario_Client->SetScene(mScene.get());
  }

  CallBackModule(nsListModules::Timer, &TEditorMapLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::InitForms);
  CallBackModule(nsListModules::GraphicEngine, &TEditorMapLogic::ShowTest);

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
			HandlePacketFromGUI(p, size);
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

	CheckTerrainGroupUpdateForSave();
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
      if(type==nsGameProcess::eBuilder)
        mComp.pPhysicEngine->GetPE()->
				Setup( mAggregationScenario_Client->GetPhysicWorldID(), 
				 mStatePhysicWorld );
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
void TEditorMapLogic::ShowTest()
{
	Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
	pCamera->setPosition(60,60,60);
	pCamera->lookAt(0,30,0);
	Ogre::Radian fovy(3.14f/3);// масштаб относительно 1 у.е.
	//pCamera->setFOVy(fovy);
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::CheckTerrainGroupUpdateForSave()
{
	Ogre::TerrainGroup* pTG = GetC()->pGraphicEngine->GetGE()->GetTerrainGroup();
	// проверка: идёт ли создание данных для теней и света для земли
	if( pTG->isDerivedDataUpdateInProgress() )
	{
		if( flgIsTerrainGroupUpdate==false )
		{
			// начался процесс создания, TODO: вывести сообщение в GUI?
			flgIsTerrainGroupUpdate = true;
		}
	}
	else
	{
		if( flgIsTerrainGroupUpdate )
		{
			// закончился процесс создания, TODO: вывести сообщение в GUI?
			pTG->saveAllTerrains(false);
			flgIsTerrainGroupUpdate = false;
		}
	}
	// README: флаг flgIsTerrainGroupUpdate надо учитывать при попытке загрузки карты.
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::HandlePacketFromGUI(void* p, int size)
{
	nsProtocolGUI2Logic::TBaseProtocolGUI2Logic* pBase = (nsProtocolGUI2Logic::TBaseProtocolGUI2Logic*)p;
	switch( pBase->type )
	{
		case nsProtocolGUI2Logic::eLoadMap:
		{
			nsProtocolGUI2Logic::TLoadMap* pLoadMap = (nsProtocolGUI2Logic::TLoadMap*)p;
			LoadGameMap(pLoadMap->nameMap);
		}
			break;
		case nsProtocolGUI2Logic::eSetupStateCurrentPhysicWorld:
		{
			nsProtocolGUI2Logic::TSetupStateCurrentPhysicWorld* pSetupPhysicWorld = 
				(nsProtocolGUI2Logic::TSetupStateCurrentPhysicWorld*)p;
			mStatePhysicWorld = pSetupPhysicWorld->stateWorld;
			int id = mAggregationScenario_Client->GetPhysicWorldID();
			if( id!=-1 )
			{
				mComp.pPhysicEngine->GetPE()->
					Setup( id, mStatePhysicWorld );
			}
		}
			break;
		default:BL_FIX_BUG();
	}
}
//---------------------------------------------------------------------------------------------
