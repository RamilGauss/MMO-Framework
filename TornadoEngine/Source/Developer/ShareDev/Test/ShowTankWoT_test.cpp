/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShowTankWoT_test.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

TShowTankWoT_test::TShowTankWoT_test()
{

}
//---------------------------------------------------------------------------------------------
void TShowTankWoT_test::AddEntity(Ogre::Entity* pEnt, TOrient& orient, Ogre::SceneManager* pSM)
{
  pEnt->setCastShadows(true);
  Ogre::SceneNode* pNode = pSM->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  pNode->setScale(orient.scale);
  pNode->rotate(orient.axisRotate, orient.angleRotate);
  pNode->setPosition(orient.pos);
}
//---------------------------------------------------------------------------------------------
void TShowTankWoT_test::ShowTank(int index, Ogre::Vector3& pos)
{
  // вставка Танка, прототип модели
  Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();

  TOrient orGun     (Ogre::Vector3(1,0,0), Ogre::Radian( 3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,   3,  4) + pos);
  TOrient orHull    (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, -10,-10) + pos);
  TOrient orChassisL(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10) + pos);
  TOrient orChassisR(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10) + pos);
  TOrient orTurret  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,   0,-10) + pos);
  TOrient orTrackL  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10) + pos);
  TOrient orTrackR  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10) + pos);

  char sHull[50], sTurret[50], sChassisL[50], sChassisR[50], sGun[50], sTrackL[50], sTrackR[50];
  sprintf(sHull,     "Hull%d",     index); 
  sprintf(sTurret,   "Turret%d",   index); 
  sprintf(sChassisL, "ChassisL%d", index); 
  sprintf(sChassisR, "ChassisR%d", index); 
  sprintf(sGun,      "Gun%d",      index); 
  sprintf(sTrackL,   "TrackL%d",   index); 
  sprintf(sTrackR,   "TrackR%d",   index); 

  AddEntity(pSM->createEntity(sHull,     "KingTiger/Hull.mesh"),    orHull,     pSM);
  AddEntity(pSM->createEntity(sTurret,   "KingTiger/Turret.mesh"),  orTurret,   pSM);
  AddEntity(pSM->createEntity(sChassisL, "KingTiger/ChassisL.mesh"),orChassisL, pSM);
  AddEntity(pSM->createEntity(sChassisR, "KingTiger/ChassisR.mesh"),orChassisR, pSM);
  AddEntity(pSM->createEntity(sGun,      "KingTiger/Gun.mesh"),     orGun,      pSM);
  AddEntity(pSM->createEntity(sTrackL,   "KingTiger/TrackL.mesh"),  orTrackL,   pSM);
  AddEntity(pSM->createEntity(sTrackR,   "KingTiger/TrackR.mesh"),  orTrackR,   pSM);
}
//---------------------------------------------------------------------------------------------
void TShowTankWoT_test::ShowTanks(int cnt)
{
  Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
  pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  
  Ogre::Vector3 pos;
  pos.y = 0;
  pos.z = 0;
  for( int i = 0 ; i < cnt ; i++ )
  {
    pos.x = i*50;
    ShowTank(i, pos);
  }
  Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
  pCamera->setPosition(160,160,160);
  pCamera->lookAt(0,0,0);
}
//---------------------------------------------------------------------------------------------