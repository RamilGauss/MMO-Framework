/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ApplySetup_MapGraphicConfig.h"

#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include <OgreRenderWindow.h>

TApplySetup_MapGraphicConfig::TApplySetup_MapGraphicConfig()
{

}
//------------------------------------------------------------------------
TApplySetup_MapGraphicConfig::~TApplySetup_MapGraphicConfig()
{

}
//------------------------------------------------------------------------
void TApplySetup_MapGraphicConfig::Set(nsMathTools::TVector3& backgroundColour, 
																			 TMapItem::TFog& fog, nsMathTools::TVector3& ambientLight)
{
  mBackgroundColour = backgroundColour;
	mFog = fog;
	mAmbientLight = ambientLight;
}
//------------------------------------------------------------------------
void TApplySetup_MapGraphicConfig::WorkFromThread_Ogre()
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();
	Ogre::RenderWindow* mWindow   = pGE->GetWindow();
	
	// BackGroundColour
	Ogre::ColourValue fadeColour;
	fadeColour.r = mBackgroundColour.x;
	fadeColour.g = mBackgroundColour.y;
	fadeColour.b = mBackgroundColour.z;
	mWindow->getViewport(0)->setBackgroundColour(fadeColour);

	// Fog
	fadeColour.r = mFog.colour.x;
	fadeColour.g = mFog.colour.y;
	fadeColour.b = mFog.colour.z;
  mSceneMgr->setFog((Ogre::FogMode)mFog.mode, fadeColour, mFog.expDensity, mFog.linearStart, mFog.linearEnd);

	// AmbientLight
	Ogre::ColourValue ambient;
	ambient.r = mAmbientLight.x;
	ambient.g = mAmbientLight.y;
	ambient.b = mAmbientLight.z;
	mSceneMgr->setAmbientLight(ambient);
}
//------------------------------------------------------------------------
