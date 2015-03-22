/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleGraphicEngine_Dev.h"
#include "GraphicEngine_OGRE_MyGUI.h"

void TModuleGraphicEngine_Dev::Input(int id, void* p, int size)
{

}
//--------------------------------------------------------------------------
bool TModuleGraphicEngine_Dev::Output(void* p, int size)
{
  return true;
}
//--------------------------------------------------------------------------
void TModuleGraphicEngine_Dev::StartEvent()
{
  TModuleGraphicEngine::StartEvent();

  mClientMain.reset(new TClientMain);

  GetGE()->GetSceneManager()->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  TOrient orGun     (Ogre::Vector3(1,0,0), Ogre::Radian( 3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 3,4));
  TOrient orHull    (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,-10,-10));
  TOrient orChassisL(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orChassisR(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTurret  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 0,-10));
  TOrient orTrackL  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTrackR  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));

  AddEntity(GetGE()->GetSceneManager()->createEntity("Hull",     "KingTiger/Hull.mesh"),    orHull);
  AddEntity(GetGE()->GetSceneManager()->createEntity("Turret",   "KingTiger/Turret.mesh"),  orTurret);
  AddEntity(GetGE()->GetSceneManager()->createEntity("ChassisL", "KingTiger/ChassisL.mesh"),orChassisL);
  AddEntity(GetGE()->GetSceneManager()->createEntity("ChassisR", "KingTiger/ChassisR.mesh"),orChassisR);
  AddEntity(GetGE()->GetSceneManager()->createEntity("Gun",      "KingTiger/Gun.mesh"),     orGun);
  AddEntity(GetGE()->GetSceneManager()->createEntity("TrackL",   "KingTiger/TrackL.mesh"),  orTrackL);
  AddEntity(GetGE()->GetSceneManager()->createEntity("TrackR",   "KingTiger/TrackR.mesh"),  orTrackR);
  //---------------------------------------------------------------------------
  mClientMain->Show();
}
//--------------------------------------------------------------------------
void TModuleGraphicEngine_Dev::StopEvent()
{

}
//--------------------------------------------------------------------------
void TModuleGraphicEngine_Dev::AddEntity(Ogre::Entity* pEnt, TOrient& orient)
{
  pEnt->setCastShadows(false);
  Ogre::SceneNode* pNode = GetGE()->GetSceneManager()->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  pNode->setScale(orient.scale);
  pNode->rotate(orient.axisRotate, orient.angleRotate);
  pNode->setPosition(orient.pos);
}
//---------------------------------------------------------------------------------------------
