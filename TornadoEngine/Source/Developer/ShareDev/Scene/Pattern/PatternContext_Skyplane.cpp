/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternContext_Skyplane.h"
#include "ManagerNamePattern.h"

namespace nsPatternContext_Skyplane
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
}

using namespace nsPatternContext_Skyplane;

TPatternContext_Skyplane::TPatternContext_Skyplane(TBehaviourPatternModel* pModel):
TBehaviourPatternContext(pModel)
{

}
//---------------------------------------------------------------------------
TPatternContext_Skyplane::~TPatternContext_Skyplane()
{

}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetPlane_D()
{
	float v = 0;
	GetFromParameterMap<float>(sPlane_D, v);
	return v;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPatternContext_Skyplane::GetPlane_Normal()
{
	nsMathTools::TVector3 normal(0,0,0);
	GetFromParameterMap<float>(sPlane_normal_x, normal.x);
	GetFromParameterMap<float>(sPlane_normal_y, normal.y);
	GetFromParameterMap<float>(sPlane_normal_z, normal.z);
	return normal;
}
//---------------------------------------------------------------------------
std::string TPatternContext_Skyplane::GetNameMaterialOgre()
{
	std::string v;
	GetFromParameterMap<std::string>(sNameOgreMaterial, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetScale()
{
	float v = 0;
	GetFromParameterMap<float>(sScale, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetTiling()
{
	float v = 0;
	GetFromParameterMap<float>(sTiling, v);
	return v;
}
//---------------------------------------------------------------------------
bool TPatternContext_Skyplane::GetDrawFirst()
{
	std::string drawFirst;
	GetFromParameterMap<std::string>(sDrawFirst, drawFirst);
	if(drawFirst=="true")
		return true;
	return false;
}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetBow()
{
	float v = 0;
	GetFromParameterMap<float>(sBow, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetXsegments()
{
	float v = 0;
	GetFromParameterMap<float>(sXsegments, v);
	return v;
}
//---------------------------------------------------------------------------
float TPatternContext_Skyplane::GetYsegments()
{
	float v = 0;
	GetFromParameterMap<float>(sYsegments, v);
	return v;
}
//---------------------------------------------------------------------------
