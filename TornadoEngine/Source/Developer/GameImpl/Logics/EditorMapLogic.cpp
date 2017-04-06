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
	mPhysicWorldID    = -1;

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
		// Создание физического мира.
		if( mPhysicWorldID==-1 )
			mPhysicWorldID = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->AddWorld();

    mAggregationScenario_Client->GetCB_Progress()->Register( &TEditorMapLogic::ProgressScenario, this);
    mAggregationScenario_Client->GetCB_End()->Register( &TEditorMapLogic::EndScenario, this);
		mAggregationScenario_Client->Setup( GetUseID_Module(), GetFBPM(), mScene.get(), mPhysicWorldID);
  }

	StartTimer();
	InitForms();
	ShowTest();

	mComp.pGraphicEngine->GetCBStopEvent()->Register( &TEditorMapLogic::FreeGraphicResource,this);
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
		mAggregationScenario_Client->Work();

	CheckTerrainGroupUpdateForSave();
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
  mID_TimerTryMoveCamera = mComp.pTimer->New(30);
}
//----------------------------------------------------------
void TEditorMapLogic::InitForms()
{ 
  mEditorMap = new TEditorMap;
  mEditorMap->Show();

  mComp.pGraphicEngine->GetGE()->SetWindowCaptionUtf8("Редактор карт");
}
//----------------------------------------------------------
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
    case nsGameProcess::eSynchro:
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
      if( mAggregationScenario_Client->Activate(nsGameProcess::eSynchro)==false )
      {
        BL_FIX_BUG();
      }
      if(type==nsGameProcess::eBuilder)
        mComp.pPhysicEngine->GetPE()->
				Setup( mPhysicWorldID, mStatePhysicWorld );
      break;
    case nsGameProcess::eSynchro:
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
	//if( pMouseGE->pressedButtons&(1<<OIS::MB_Left) )
	//	mComp.pGraphicEngine->GetGE()->SetGUIEnableEvent( false );
	//else
	//	mComp.pGraphicEngine->GetGE()->SetGUIEnableEvent( true );

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
		case OIS::KC_RETURN:// experimental
		{
			if( OIS::Keyboard::Alt & pKeyGE->modifier )
			{
				Ogre::RenderWindow* pRW = mComp.pGraphicEngine->GetGE()->GetWindow();
				int width  = pRW->getWidth();
				int height = pRW->getHeight();
				bool isFullScreen = pRW->isFullScreen();
				pRW->setFullscreen(!isFullScreen, width, height);
			}
		}
		break;
  }
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::ShowTest()
{
	//TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->SetUseClipCursor(false);

	Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
	pCamera->setPosition(60,60,60);
	pCamera->lookAt(0,30,0);
	Ogre::Radian fovy(3.14f/3);// масштаб относительно 1 у.е.
	//pCamera->setFOVy(fovy);

	//mPtrShowTank->ShowTanks(10);
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
			if( mPhysicWorldID!=-1 )
			{
				mComp.pPhysicEngine->GetPE()->
					Setup( mPhysicWorldID, mStatePhysicWorld );
			}
		}
			break;
		default:BL_FIX_BUG();
	}
}
//---------------------------------------------------------------------------------------------
