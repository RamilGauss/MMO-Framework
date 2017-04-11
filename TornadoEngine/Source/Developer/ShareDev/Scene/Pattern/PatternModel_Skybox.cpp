/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Skybox.h"

#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

namespace nsPatternModel_Skypbox
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Skypbox;

TPatternModel_Skybox::TPatternModel_Skybox() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPatternModel_Skybox::~TPatternModel_Skybox()
{

}
//---------------------------------------------------------------------------
bool TPatternModel_Skybox::LoadByModule_Graphic(bool fast)
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	//Ogre::Plane plane;
	//plane.d = 1000;
	//plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
	//mSceneMgr->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);
	return true;
}
//---------------------------------------------------------------------------
