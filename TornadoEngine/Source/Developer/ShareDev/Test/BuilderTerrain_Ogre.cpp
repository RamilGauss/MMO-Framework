/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTerrain_Ogre.h"
#include "TerrainItem.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"


TBuilderTerrain_Ogre::TBuilderTerrain_Ogre()
{

}
//--------------------------------------------------------------------
void TBuilderTerrain_Ogre::Show()
{
	Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
	Ogre::RenderWindow* pW  = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetWindow();
	//pSM->setFog(Ogre::FOG_EXP, Ogre::ColourValue(0.7, 0.7, 0.8));//, 0, 10000, 25000);
	//pSM->setFog(Ogre::FOG_LINEAR, Ogre::ColourValue(0.7, 0.7, 0.8), 0, 5000, 6000);

	Ogre::ColourValue fadeColour(0.8, 0.8, 0.8);
	pSM->setFog(Ogre::FOG_LINEAR, fadeColour, 0.0, 4000, 6000);
	pW->getViewport(0)->setBackgroundColour(fadeColour);

	Ogre::Plane plane;
	plane.d = 1000;
	plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;

	pSM->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);

	//TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager()
	//	->setSkyBox(true, "Skybox/Hills");


	std::string s = "";
	TTerrainItem tItem(s);
	//tItem.mGraphic[0].

	//mTerrainGlobals = new Ogre::TerrainGlobalOptions();
	//
	//mTerrainGroup = new Ogre::TerrainGroup( pSM, Ogre::Terrain::ALIGN_X_Z, 513, 12000.0);
	//mTerrainGroup->setFilenameConvention(Ogre::String("terrain"), Ogre::String("dat"));
	//mTerrainGroup->setOrigin(Ogre::Vector3::ZERO);
}
//--------------------------------------------------------------------
