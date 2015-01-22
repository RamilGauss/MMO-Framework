/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TutorialApplication.h"
#include <OgreSceneNode.h>
#include "ManagerGameObject.h"
#include "Tank.h"

#include "StorePathResources.h"
#include "BL_Debug.h"
#include "MapXML_Field.h"

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication()
{
  std::string sNameXML = "resources.xml";
  if(GetStorePathResources()->Load(sNameXML.data())==false)
  {
    BL_FIX_BUG();
  }
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication()
{
}
//---------------------------------------------------------------------------
void TutorialApplication::AddEntity(Ogre::Entity* pEnt, TOrient& orient)
{
  pEnt->setCastShadows(false);
  Ogre::SceneNode* pNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  pNode->setScale(orient.scale);
  pNode->rotate(orient.axisRotate, orient.angleRotate);
  pNode->setPosition(orient.pos);
}
//---------------------------------------------------------------------------
//bool res = TManagerGameMap::Singleton()->SetPathList("../media/map/list_maps.xml");
//TGameMap* pMap = TManagerGameMap::Singleton()->Create("first.xml");// name
//TGameMap* pMap = TManagerGameMap::Singleton()->Create(0);// id
//resLoad = TManagerGameObject::Singleton()->Load(0, pObject);// name
void TutorialApplication::createScene()
{
  bool res = TManagerGameObject::Singleton()->SetPathList("../../Resources/media/game_models/list_models.xml");
  TGameObject* pObject = new TTank;
  bool resLoad = TManagerGameObject::Singleton()->Load("kingtiger.xml", pObject);// name

  mSceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  TOrient orGun     (Ogre::Vector3(1,0,0), Ogre::Radian( 3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,   3,  4));
  TOrient orHull    (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, -10,-10));
  TOrient orChassisL(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orChassisR(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTurret  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,   0,-10));
  TOrient orTrackL  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTrackR  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  
  AddEntity(mSceneMgr->createEntity("Hull",     "KingTiger/Hull.mesh"),    orHull);
  AddEntity(mSceneMgr->createEntity("Turret",   "KingTiger/Turret.mesh"),  orTurret);
  AddEntity(mSceneMgr->createEntity("ChassisL", "KingTiger/ChassisL.mesh"),orChassisL);
  AddEntity(mSceneMgr->createEntity("ChassisR", "KingTiger/ChassisR.mesh"),orChassisR);
  AddEntity(mSceneMgr->createEntity("Gun",      "KingTiger/Gun.mesh"),     orGun);
  AddEntity(mSceneMgr->createEntity("TrackL",   "KingTiger/TrackL.mesh"),  orTrackL);
  AddEntity(mSceneMgr->createEntity("TrackR",   "KingTiger/TrackR.mesh"),  orTrackR);
}
//---------------------------------------------------------------------------
