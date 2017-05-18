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
#include "ConverterLocale.h"
#include "GameObject.h"
#include "Pattern_Terrain.h"

#include <boost/locale/util.hpp>
#include <boost/cstdint.hpp>

//###
#include "ShowTankWoT_test.h"
#include "StatusBar.h"
//###

TEditorMapLogic* g_EditorMapLogic = NULL;

TEditorMapLogic::TEditorMapLogic()
{
	g_EditorMapLogic = this;

	mStatePhysicWorld = TPhysicEngine_Bullet::eStatePause;
	mPhysicWorldID    = -1;

	flgIsTerrainGroupUpdate = false;

  mID_TimerTryMoveCamera = -1;
  mPtrShowTank.reset(new TShowTankWoT_test);
  mPtrControlCamera.reset(new TControlCamera);

	mEditorMap = NULL;
	mStatusBar = NULL;
}
//-------------------------------------------------------------------
TEditorMapLogic::~TEditorMapLogic()
{

}
//-------------------------------------------------------------------
void TEditorMapLogic::StartEvent()
{
  if( mAggregationScenario_Client.get() )
  {
		// Создание физического мира
		if( mPhysicWorldID==-1 )
			mPhysicWorldID = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->AddWorld();

    mAggregationScenario_Client->GetCB_Progress()->Register( &TEditorMapLogic::ProgressScenario, this);
    mAggregationScenario_Client->GetCB_End()->Register( &TEditorMapLogic::EndScenario, this);
		mAggregationScenario_Client->Setup( GetUseID_Module(), GetFBP(), mScene.get(), mPhysicWorldID);
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
TFactoryBehaviourPattern* TEditorMapLogic::GetFBP()
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

	mStatusBar = new TStatusBar;
	mStatusBar->Show();

	mStatusBar->ClearText();
	mStatusBar->AddText("Editor Game Map.");
	
	mStatusBar->AddText("----------------------------------------");
}
//----------------------------------------------------------
void TEditorMapLogic::FreeGraphicResource()
{
  delete mEditorMap;
	delete mStatusBar;
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
	bool fast = bool(pKeyGE->modifier & OIS::Keyboard::Shift);
	mPtrControlCamera->SetFast(fast); 

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
	pCamera->setPosition(-10,40,-10);
	pCamera->lookAt(-4,40,-4);
	//Ogre::Radian fovy(3.14f/3);// масштаб относительно 1 у.е.
	//pCamera->setFOVy(fovy);

	Ogre::Real f = pCamera->getFarClipDistance();
	Ogre::Real n = pCamera->getNearClipDistance();
	pCamera->setNearClipDistance(0.01f);
	n = pCamera->getNearClipDistance();
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
void TEditorMapLogic::TogglePhysicState(TPhysicEngine_Bullet::eStateWorld stateWorld)
{
	mStatePhysicWorld = stateWorld;
	if( mPhysicWorldID!=-1 )
	{
		mComp.pPhysicEngine->GetPE()->
			Setup( mPhysicWorldID, mStatePhysicWorld );
	}
}
//---------------------------------------------------------------------------------------------
void TEditorMapLogic::ModifyTerrain_Extent()
{
	if( mAggregationScenario_Client.get()==NULL )
		return;
	if( mAggregationScenario_Client->GetCurrentScenarioType()!=nsGameProcess::eSynchro )
		return;

	int cnt = mScene->GetCountUsing();
	for( int i = 0 ; i < cnt ; i++ )
	{
		TGameObject* pGO = mScene->GetUsingByIndex(i);
		if( pGO==NULL )
			continue;
		if( pGO->GetPattern()->GetBaseType()!=TManagerNamePattern::eTerrain )
			continue;
		TPattern_Terrain* pTerrain = (TPattern_Terrain*)pGO->GetPattern();
		pTerrain->ModifyExtent();
		break;
		//mScene->GetUsingByID(id);
	}
}
//---------------------------------------------------------------------------------------------
