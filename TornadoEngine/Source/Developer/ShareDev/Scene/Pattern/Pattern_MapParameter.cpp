/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_MapParameter.h"

#include "PhysicEngine/PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"
#include "ModuleGraphicEngine.h"

#include <btBulletDynamicsCommon.h>
#include <Dynamics/btDiscreteDynamicsWorld.h>
#include <OgreRoot.h>
#include <OgreEntity.h>
#include <OgreRenderWindow.h>

namespace nsPattern_MapParameter
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;

  const char* sTableSound          = "TableSound";
  const char* sGravity_x           = "Gravity_x";
  const char* sGravity_y           = "Gravity_y";
  const char* sGravity_z           = "Gravity_z";
  const char* sFog_mode            = "Fog_mode";
  const char* sFog_colourRed       = "Fog_colourRed";
  const char* sFog_colourGreen     = "Fog_colourGreen";
  const char* sFog_colourBlue      = "Fog_colourBlue";
  const char* sFog_expDensity      = "Fog_expDensity";
  const char* sFog_linearStart     = "Fog_linearStart";
  const char* sFog_linearEnd       = "Fog_linearEnd";
  const char* sBackgroundColour_r = "BackgroundColour_r";
  const char* sBackgroundColour_g = "BackgroundColour_g";
  const char* sBackgroundColour_b = "BackgroundColour_b";
  const char* sAmbientLight_r      = "AmbientLight_r";
  const char* sAmbientLight_g      = "AmbientLight_g";
  const char* sAmbientLight_b      = "AmbientLight_b";
}

using namespace nsPattern_MapParameter;

TPattern_MapParameter::TPattern_MapParameter() : 
TBehaviourPattern(&g_DefaultParameterMap)
{
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sTableSound,         "0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sGravity_x,          "0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sGravity_y,          "-9.81"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sGravity_z,          "0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_mode,           "3"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_colourRed,     "0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_colourGreen,   "0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_colourBlue,    "0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_expDensity,    "0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_linearStart,   "4000"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sFog_linearEnd,     "10000"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sBackgroundColour_r,"0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sBackgroundColour_g,"0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sBackgroundColour_b,"0.8"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sAmbientLight_r,    "1.0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sAmbientLight_g,    "1.0"));
  g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sAmbientLight_b,    "1.0"));
}
//---------------------------------------------------------------------------
TPattern_MapParameter::~TPattern_MapParameter()
{

}
//---------------------------------------------------------------------------
bool TPattern_MapParameter::BuildByModule_Graphic(bool fast)
{
  TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
  Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();
  Ogre::RenderWindow* mWindow   = pGE->GetWindow();

  //float fVal;
  // BackGroundColour
  Ogre::ColourValue fadeColour;
  fadeColour.r = GetFromParameterMap<float>(sBackgroundColour_r);
  fadeColour.g = GetFromParameterMap<float>(sBackgroundColour_g);
  fadeColour.b = GetFromParameterMap<float>(sBackgroundColour_b);
  mWindow->getViewport(0)->setBackgroundColour(fadeColour);

  // Fog
  fadeColour.r = GetFromParameterMap<float>(sFog_colourRed);
  fadeColour.g = GetFromParameterMap<float>(sFog_colourGreen);
  fadeColour.b = GetFromParameterMap<float>(sFog_colourBlue);

  Ogre::FogMode mode = (Ogre::FogMode)GetFromParameterMap<int>(sFog_mode);

  Ogre::Real expDensity  = GetFromParameterMap<float>(sFog_expDensity);
  Ogre::Real linearStart = GetFromParameterMap<float>(sFog_linearStart);
  Ogre::Real linearEnd   = GetFromParameterMap<float>(sFog_linearEnd);

  mSceneMgr->setFog(mode, fadeColour, expDensity, linearStart, linearEnd);

  // AmbientLight
  Ogre::ColourValue ambient;
  ambient.r = GetFromParameterMap<float>(sAmbientLight_r);
  ambient.g = GetFromParameterMap<float>(sAmbientLight_g);
  ambient.b = GetFromParameterMap<float>(sAmbientLight_b);
  mSceneMgr->setAmbientLight(ambient);
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_MapParameter::BuildByModule_Physic(bool fast)
{
  btDiscreteDynamicsWorld* dynamicsWorld = 
    TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(GetPhysicWorld());
  btVector3 vectorBullet;
  vectorBullet.setX( GetFromParameterMap<float>(sGravity_x) );
  vectorBullet.setY( GetFromParameterMap<float>(sGravity_y) );
  vectorBullet.setZ( GetFromParameterMap<float>(sGravity_z) );
  dynamicsWorld->setGravity(vectorBullet);
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_MapParameter::BuildByModule_Sound(bool fast)
{
  return true;
}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_MapParameter::GetBaseType()
{
  return TPatternNameManager::eMapParameter;
}
//------------------------------------------------------------------------
