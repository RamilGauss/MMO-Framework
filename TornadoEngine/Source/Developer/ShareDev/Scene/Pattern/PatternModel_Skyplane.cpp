/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Skyplane.h"
#include "PatternContext_Skyplane.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

TPatternModel_Skyplane::TPatternModel_Skyplane()
{

}
//---------------------------------------------------------------------------
TPatternModel_Skyplane::~TPatternModel_Skyplane()
{

}
//---------------------------------------------------------------------------
TBehaviourPatternContext* TPatternModel_Skyplane::MakeNewConext()
{
	return new TPatternContext_Skyplane(this);
}
//---------------------------------------------------------------------------
bool TPatternModel_Skyplane::LoadByModule_Graphic(bool fast)
{
	TPatternContext_Skyplane* pSkyPlaneContext = (TPatternContext_Skyplane*)mContext;

	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	Ogre::Plane plane;
	plane.d = pSkyPlaneContext->GetPlane_D();
	nsMathTools::TVector3 normal = pSkyPlaneContext->GetPlane_Normal();
	plane.normal.x = normal.x;
	plane.normal.y = normal.y;
	plane.normal.z = normal.z;
	Ogre::String nameMaterial = pSkyPlaneContext->GetNameMaterialOgre();
	Ogre::Real scale = pSkyPlaneContext->GetScale();
	Ogre::Real tiling = pSkyPlaneContext->GetTiling(); 
	bool drawFirst = pSkyPlaneContext->GetDrawFirst();
	Ogre::Real bow = pSkyPlaneContext->GetBow();
	int xsegments = pSkyPlaneContext->GetXsegments(); 
	int ysegments = pSkyPlaneContext->GetYsegments(); 

	mSceneMgr->setSkyPlane(true, plane, nameMaterial, scale, tiling, drawFirst, bow, xsegments, ysegments);
	return true;
}
//---------------------------------------------------------------------------
