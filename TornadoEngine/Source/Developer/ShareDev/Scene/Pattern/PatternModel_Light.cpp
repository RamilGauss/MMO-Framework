/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Light.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

namespace nsPatternModel_Light
{
	const char* sName             = "Name";
	const char* sType             = "Type";
	const char* sIsCastShadow     = "IsCastShadow";
	const char* sIsVisible        = "IsVisible";
	const char* sDir_x            = "Dir_x";
	const char* sDir_y            = "Dir_y";
	const char* sDir_z            = "Dir_z";
	const char* sDiffuseColour_R  = "DiffuseColour_R";
	const char* sDiffuseColour_G  = "DiffuseColour_G";
	const char* sDiffuseColour_B  = "DiffuseColour_B";
	const char* sSpecularColour_R = "SpecularColour_R";
	const char* sSpecularColour_G = "SpecularColour_G";
	const char* sSpecularColour_B = "SpecularColour_B";
  
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Light;

TPatternModel_Light::TPatternModel_Light() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sName            ,"mainLight"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sType            ,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sIsCastShadow    ,"true"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sIsVisible       ,"true"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDir_x           ,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDir_y           ,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDir_z           ,"0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDiffuseColour_R ,"1.0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDiffuseColour_G ,"1.0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sDiffuseColour_B ,"1.0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sSpecularColour_R,"1.0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sSpecularColour_G,"1.0"));
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sSpecularColour_B,"1.0"));
}
//---------------------------------------------------------------------------
TPatternModel_Light::~TPatternModel_Light()
{

}
//---------------------------------------------------------------------------
bool TPatternModel_Light::LoadByModule_Graphic(bool fast)
{
	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	Ogre::String nameLight = GetNameLight();
	Ogre::Light* pLight = NULL;
	if( mSceneMgr->hasLight(nameLight) )
		pLight = mSceneMgr->getLight(nameLight);
	else
		pLight = mSceneMgr->createLight(nameLight);

	pLight->setType((Ogre::Light::LightTypes)GetType());
	pLight->setCastShadows(GetIsCastShadow());
	pLight->setVisible(GetIsVisible());
	nsMathTools::TVector3 pos;
	GetPosition(pos);
	Ogre::Vector3 posLight;
	posLight.x = pos.x;
	posLight.y = pos.y;
	posLight.z = pos.z;
	pLight->setPosition(posLight);
	nsMathTools::TVector3 dir = GetDirVector();
	Ogre::Vector3 dirLight;
	dirLight.x = dir.x;
	dirLight.y = dir.y;
	dirLight.z = dir.z;
	dirLight.normalise();
	pLight->setDirection(dirLight);

	nsMathTools::TVector3 diffuseColour = GetDiffuseColour();
	pLight->setDiffuseColour(diffuseColour.x, diffuseColour.y, diffuseColour.z);
	
	nsMathTools::TVector3 specularColour = GetSpecularColour();
	pLight->setSpecularColour(specularColour.x, specularColour.y, specularColour.z);

	return true;
}
//---------------------------------------------------------------------------
std::string TPatternModel_Light::GetNameLight()
{
	std::string nameMaterial;
	GetFromParameterMap<std::string>(sName, nameMaterial);
	return nameMaterial;
}
//---------------------------------------------------------------------------
int TPatternModel_Light::GetType()
{
	int type;
	GetFromParameterMap<int>(sType, type);
	return type;
}
//---------------------------------------------------------------------------
bool TPatternModel_Light::GetIsCastShadow()
{
	std::string v;
	GetFromParameterMap<std::string>(sIsCastShadow, v);
	if( v=="true" )
		return true;
	return false;
}
//---------------------------------------------------------------------------
bool TPatternModel_Light::GetIsVisible()
{
	std::string v;
	GetFromParameterMap<std::string>(sIsVisible, v);
	if( v=="true" )
		return true;
	return false;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternModel_Light::GetDirVector()
{
	nsMathTools::TVector3 result;
	float v;
	GetFromParameterMap<float>(sDir_x, v);
	result.x = v;
	GetFromParameterMap<float>(sDir_y, v);
	result.y = v;
	GetFromParameterMap<float>(sDir_z, v);
	result.z = v;
	return result;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternModel_Light::GetDiffuseColour()
{
	nsMathTools::TVector3 result;
	float v;
	GetFromParameterMap<float>(sDiffuseColour_R, v);
	result.x = v;
	GetFromParameterMap<float>(sDiffuseColour_G, v);
	result.y = v;
	GetFromParameterMap<float>(sDiffuseColour_B, v);
	result.z = v;
	return result;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternModel_Light::GetSpecularColour()
{
	nsMathTools::TVector3 result;
	float v;
	GetFromParameterMap<float>(sSpecularColour_R, v);
	result.x = v;
	GetFromParameterMap<float>(sSpecularColour_G, v);
	result.y = v;
	GetFromParameterMap<float>(sSpecularColour_B, v);
	result.z = v;
	return result;
}
//---------------------------------------------------------------------------