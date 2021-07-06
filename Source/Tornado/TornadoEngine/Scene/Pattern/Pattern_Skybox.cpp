/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Skybox.h"

#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

namespace nsPattern_SkyBox
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_SkyBox;
using namespace nsGraphicEngine;

TPattern_Skybox::TPattern_Skybox() :
  TBehaviourPattern(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPattern_Skybox::~TPattern_Skybox()
{

}
//---------------------------------------------------------------------------
bool TPattern_Skybox::BuildByModule_Graphic(bool fast)
{
  TGraphicEngine_Ogre_ImGui* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
  Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

  //Ogre::Plane plane;
  //plane.d = 1000;
  //plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
  //mSceneMgr->setSkyPlane(true, plane, "Examples/CloudySky", 500, 20, true, 0.5, 150, 150);
  return true;
}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Skybox::GetBaseType()
{
  return TPatternNameManager::eSky;
}
//------------------------------------------------------------------------
