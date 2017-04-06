/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Skybox.h"

#include "PatternContext_Skybox.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

TPatternModel_Skybox::TPatternModel_Skybox()
{

}
//---------------------------------------------------------------------------
TPatternModel_Skybox::~TPatternModel_Skybox()
{

}
//---------------------------------------------------------------------------
TBehaviourPatternContext* TPatternModel_Skybox::MakeNewConext()
{
	return new TPatternContext_Skybox(this);
}
//---------------------------------------------------------------------------
bool TPatternModel_Skybox::LoadByModule_Graphic(bool fast)
{
	TPatternContext_Skybox* pSkyBoxContext = (TPatternContext_Skybox*)mContext;

	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	//Ogre::Plane plane;
	//plane.d = 1000;
	//plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
	//mSceneMgr->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);
	return true;
}
//---------------------------------------------------------------------------
