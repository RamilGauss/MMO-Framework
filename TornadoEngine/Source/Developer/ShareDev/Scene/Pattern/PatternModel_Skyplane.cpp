/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Skyplane.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "ManagerNamePattern.h"

namespace nsPatternModel_Skyplane
{
	const char* sPlane_D        	= "Plane_D";
	const char* sPlane_normal_x 	= "Plane_normal_x";
	const char* sPlane_normal_y 	= "Plane_normal_y";
	const char* sPlane_normal_z 	= "Plane_normal_z";
	const char* sNameOgreMaterial = "NameOgreMaterial";
	const char* sScale     				= "scale";
	const char* sTiling    				= "tiling";
	const char* sDrawFirst 				= "drawFirst";
	const char* sBow       				= "bow";
	const char* sXsegments 				= "xsegments";
	const char* sYsegments 				= "ysegments";

	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Skyplane;

TPatternModel_Skyplane::TPatternModel_Skyplane() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sPlane_D        	,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sPlane_normal_x 	,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sPlane_normal_y 	,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sPlane_normal_z 	,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sNameOgreMaterial ,""));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sScale     				,"1"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sTiling    				,"1"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDrawFirst 				,"false"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sBow       				,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sXsegments 				,"100"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sYsegments 				,"100"));
}
//---------------------------------------------------------------------------
TPatternModel_Skyplane::~TPatternModel_Skyplane()
{

}
//---------------------------------------------------------------------------
bool TPatternModel_Skyplane::LoadByModule_Graphic(bool fast)
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	Ogre::Plane plane;
	plane.d = GetPlane_D();
	nsMathTools::TVector3 normal = GetPlane_Normal();
	plane.normal.x = normal.x;
	plane.normal.y = normal.y;
	plane.normal.z = normal.z;
	Ogre::String nameMaterial = GetNameMaterialOgre();
	Ogre::Real scale = GetScale();
	Ogre::Real tiling = GetTiling(); 
	bool drawFirst = GetDrawFirst();
	Ogre::Real bow = GetBow();
	int xsegments = GetXsegments(); 
	int ysegments = GetYsegments(); 

	mSceneMgr->setSkyPlane(true, plane, nameMaterial, scale, tiling, drawFirst, bow, xsegments, ysegments);
	return true;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetPlane_D()
{
	float v = 0;
	GetFromParameterMap<float>(sPlane_D, v);
	return v;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternModel_Skyplane::GetPlane_Normal()
{
	nsMathTools::TVector3 normal(0,0,0);
	GetFromParameterMap<float>(sPlane_normal_x, normal.x);
	GetFromParameterMap<float>(sPlane_normal_y, normal.y);
	GetFromParameterMap<float>(sPlane_normal_z, normal.z);
	return normal;
}
//---------------------------------------------------------------------------
std::string TPatternModel_Skyplane::GetNameMaterialOgre()
{
	std::string v;
	GetFromParameterMap<std::string>(sNameOgreMaterial, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetScale()
{
	float v = 0;
	GetFromParameterMap<float>(sScale, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetTiling()
{
	float v = 0;
	GetFromParameterMap<float>(sTiling, v);
	return v;
}
//---------------------------------------------------------------------------
bool TPatternModel_Skyplane::GetDrawFirst()
{
	std::string drawFirst;
	GetFromParameterMap<std::string>(sDrawFirst, drawFirst);
	if(drawFirst=="true")
		return true;
	return false;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetBow()
{
	float v = 0;
	GetFromParameterMap<float>(sBow, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetXsegments()
{
	float v = 0;
	GetFromParameterMap<float>(sXsegments, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternModel_Skyplane::GetYsegments()
{
	float v = 0;
	GetFromParameterMap<float>(sYsegments, v);
	return v;
}
//---------------------------------------------------------------------------