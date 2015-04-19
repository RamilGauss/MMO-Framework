/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientLogic.h"
#include "ListModules.h"
#include "ModuleTimer.h"
#include "ClientMain.h"
#include "Logger.h"
#include <Ogre.h>
#include "ModuleGraphicEngine.h"

bool TClientLogic::WorkClient()
{
  return true;
}
//----------------------------------------------------------
void TClientLogic::Input(int id, void* p, int size)
{
  switch(id)
  {
    case nsListModules::GraphicEngine:
      break;
    case nsListModules::MMOEngineClient:
      HandleFromMMOEngine((nsMMOEngine::TBaseEvent*)p);
      break;
    case nsListModules::PhysicEngine:
      break;
    case nsListModules::SoundEngine:
      break;
    case nsListModules::Timer:
      CallBackModule(nsListModules::GraphicEngine, &TClientLogic::ShowFPS);
      break;
    default:BL_FIX_BUG();
  }
}
//----------------------------------------------------------
void TClientLogic::StartEvent()
{
  CallBackModule(nsListModules::Timer, &TClientLogic::StartTimer);
  CallBackModule(nsListModules::GraphicEngine, &TClientLogic::InitForms);
}
//----------------------------------------------------------
void TClientLogic::StartTimer()
{
  // вызовется из потока таймера
  unsigned int mID_Timer = mComp.pTimer->New(1000);
}
//----------------------------------------------------------
void TClientLogic::InitForms()
{
  mClientMain = new TClientMain;
  mClientMain->Show();
}
//----------------------------------------------------------
void TClientLogic::InitLog()
{
  GetLogger()->Register("Inner");// для логирования внутренних событий
  GetLogger()->Init("Client");
}
//---------------------------------------------------------------------------------------------
void TClientLogic::HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE)
{
  std::string sEvent;  
  switch(pBE->mType)
  {
    case nsMMOEngine::eDisconnectUp:
      sEvent = "DisconnectUp";
      break;
    case nsMMOEngine::eError:
      sEvent = "Error";
      break;
    case nsMMOEngine::eEnterInQueue:
      sEvent = "EnterInQueue";
      break;
    case nsMMOEngine::eLeaveQueue:
      sEvent = "LeaveQueue";
      break;
    case nsMMOEngine::eRecvFromUp:
      sEvent = "RecvFromUp";
      break;
    case nsMMOEngine::eResultLogin:
      sEvent = "ResultLogin";
      CallBackModule(nsListModules::GraphicEngine, &TClientLogic::LoginOnServer);
      break;
    default:BL_FIX_BUG();
  }
  GetLogger("Inner")->WriteF_time("MMOEngine: %s.\n",sEvent.data());
}
//---------------------------------------------------------------------------------------------
struct TOrient
{
  const Ogre::Vector3 axisRotate;
  const Ogre::Radian  angleRotate;
  const Ogre::Vector3 scale;
  const Ogre::Vector3 pos;
  TOrient(Ogre::Vector3 _axisRotate, Ogre::Radian _angleRotate, 
    Ogre::Vector3 _scale, Ogre::Vector3 _pos):
  axisRotate(_axisRotate), angleRotate(_angleRotate),
    scale(_scale),pos(_pos){}
};
//---------------------------------------------------------------------------------------------
void AddEntity(Ogre::Entity* pEnt, TOrient& orient, Ogre::SceneManager* pSM)
{
  pEnt->setCastShadows(false);
  Ogre::SceneNode* pNode = pSM->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  pNode->setScale(orient.scale);
  pNode->rotate(orient.axisRotate, orient.angleRotate);
  pNode->setPosition(orient.pos);
}
//---------------------------------------------------------------------------------------------
void TClientLogic::LoginOnServer()
{
  mClientMain->Hide();
  // вставка Танка (временно), прототип модели
  //###
  Ogre::SceneManager* pSM = mComp.pGraphicEngine->GetGE()->GetSceneManager();
  pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  TOrient orGun     (Ogre::Vector3(1,0,0), Ogre::Radian( 3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 3,4));
  TOrient orHull    (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0,-10,-10));
  TOrient orChassisL(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orChassisR(Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTurret  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10,-10,10), Ogre::Vector3(0, 0,-10));
  TOrient orTrackL  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));
  TOrient orTrackR  (Ogre::Vector3(1,0,0), Ogre::Radian(-3.14f/2), Ogre::Vector3(10, 10,10), Ogre::Vector3(0, -20,-10));

  AddEntity(pSM->createEntity("Hull",     "KingTiger/Hull.mesh"),    orHull,     pSM);
  AddEntity(pSM->createEntity("Turret",   "KingTiger/Turret.mesh"),  orTurret,   pSM);
  AddEntity(pSM->createEntity("ChassisL", "KingTiger/ChassisL.mesh"),orChassisL, pSM);
  AddEntity(pSM->createEntity("ChassisR", "KingTiger/ChassisR.mesh"),orChassisR, pSM);
  AddEntity(pSM->createEntity("Gun",      "KingTiger/Gun.mesh"),     orGun,      pSM);
  AddEntity(pSM->createEntity("TrackL",   "KingTiger/TrackL.mesh"),  orTrackL,   pSM);
  AddEntity(pSM->createEntity("TrackR",   "KingTiger/TrackR.mesh"),  orTrackR,   pSM);

  Ogre::Camera* pCamera = mComp.pGraphicEngine->GetGE()->GetCamera();
  pCamera->setPosition(60,60,60);
  pCamera->lookAt(0,0,0);
  //###
}
//---------------------------------------------------------------------------------------------
void TClientLogic::ShowFPS()
{
  float fps = mComp.pGraphicEngine->GetGE()->GetWindow()->getAverageFPS();
  mClientMain->SetFPS(fps);
}
//---------------------------------------------------------------------------------------------
