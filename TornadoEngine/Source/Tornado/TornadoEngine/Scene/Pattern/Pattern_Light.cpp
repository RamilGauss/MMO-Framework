/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Light.h"
#include "GraphicEngine/GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

namespace nsPattern_Light
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

using namespace nsPattern_Light;

TPattern_Light::TPattern_Light() :
  TBehaviourPattern(&g_DefaultParameterMap)
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
TPattern_Light::~TPattern_Light()
{

}
//---------------------------------------------------------------------------
bool TPattern_Light::BuildByModule_Graphic(bool fast)
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
std::string TPattern_Light::GetNameLight()
{
  return GetFromParameterMap<std::string>(sName);
}
//---------------------------------------------------------------------------
int TPattern_Light::GetType()
{
  return GetFromParameterMap<int>(sType);
}
//---------------------------------------------------------------------------
bool TPattern_Light::GetIsCastShadow()
{
  std::string v = GetFromParameterMap<std::string>(sIsCastShadow);
  if( v=="true" )
    return true;
  return false;
}
//---------------------------------------------------------------------------
bool TPattern_Light::GetIsVisible()
{
  std::string v = GetFromParameterMap<std::string>(sIsVisible);
  if( v=="true" )
    return true;
  return false;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPattern_Light::GetDirVector()
{
  nsMathTools::TVector3 result;
  result.x = GetFromParameterMap<float>(sDir_x);
  result.y = GetFromParameterMap<float>(sDir_y);
  result.z = GetFromParameterMap<float>(sDir_z);
  return result;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPattern_Light::GetDiffuseColour()
{
  nsMathTools::TVector3 result;
  result.x = GetFromParameterMap<float>(sDiffuseColour_R);
  result.y = GetFromParameterMap<float>(sDiffuseColour_G);
  result.z = GetFromParameterMap<float>(sDiffuseColour_B);
  return result;
}
//---------------------------------------------------------------------------
nsMathTools::TVector3 TPattern_Light::GetSpecularColour()
{
  nsMathTools::TVector3 result;
  result.x = GetFromParameterMap<float>(sSpecularColour_R);
  result.y = GetFromParameterMap<float>(sSpecularColour_G);
  result.z = GetFromParameterMap<float>(sSpecularColour_B);
  return result;
}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Light::GetBaseType()
{
  return TPatternNameManager::eLight;
}
//------------------------------------------------------------------------
