/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternContext_Light.h"
#include "ManagerNamePattern.h"

#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

namespace nsPatternContext_Light
{
	const char* sName 						= "Name";
	const char* sType 						= "Type";
	const char* sIsCastShadow     = "IsCastShadow";
	const char* sIsVisible        = "IsVisible";
	const char* sDir_x 						= "Dir_x";
	const char* sDir_y 						= "Dir_y";
	const char* sDir_z 						= "Dir_z";
	const char* sDiffuseColour_R  = "DiffuseColour_R";
	const char* sDiffuseColour_G  = "DiffuseColour_G";
	const char* sDiffuseColour_B  = "DiffuseColour_B";
	const char* sSpecularColour_R = "SpecularColour_R";
	const char* sSpecularColour_G = "SpecularColour_G";
	const char* sSpecularColour_B = "SpecularColour_B";
}

using namespace nsPatternContext_Light;

TPatternContext_Light::TPatternContext_Light(TBehaviourPatternModel* pModel):
TBehaviourPatternContext(pModel)
{

}
//---------------------------------------------------------------------------
TPatternContext_Light::~TPatternContext_Light()
{

}
//---------------------------------------------------------------------------
std::string TPatternContext_Light::GetNameLight()
{
	std::string nameMaterial;
	GetFromParameterMap<std::string>(sName, nameMaterial);
	return nameMaterial;
}
//---------------------------------------------------------------------------
int TPatternContext_Light::GetType()
{
	int type;
	GetFromParameterMap<int>(sType, type);
	return type;
}
//---------------------------------------------------------------------------
bool TPatternContext_Light::GetIsCastShadow()
{
	std::string v;
	GetFromParameterMap<std::string>(sIsCastShadow, v);
	if( v=="true" )
		return true;
	return false;
}
//---------------------------------------------------------------------------
bool TPatternContext_Light::GetIsVisible()
{
	std::string v;
	GetFromParameterMap<std::string>(sIsVisible, v);
	if( v=="true" )
		return true;
	return false;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternContext_Light::GetDirVector()
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
nsMathTools::TVector3 TPatternContext_Light::GetDiffuseColour()
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
nsMathTools::TVector3 TPatternContext_Light::GetSpecularColour()
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
