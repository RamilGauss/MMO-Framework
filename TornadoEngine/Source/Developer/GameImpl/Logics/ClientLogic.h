/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ModuleClientLogic.h"
#include "MMOEngine/include/BaseEvent.h"
#include <Ogre.h>

class TClientMain;
class TDebugPanel;
class TShowTankWoT_test;

struct btDefaultMotionState;

class TClientLogic : public TModuleClientLogic
{
  TClientMain* mClientMain;
  TDebugPanel* mDebugPanel;

  std::shared_ptr<TShowTankWoT_test> mPtrShowTank;

  volatile float x;
  volatile float y;
  volatile float z;
  btDefaultMotionState* fallMotionState;
  void ShowDebugInfo();
public:
  TClientLogic();
  virtual ~TClientLogic();

  virtual void StartEvent();
  virtual void StopEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id, void* p, int size);
private:
  void StartTimer();
  void InitForms();

  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);

  void LoginOnServer();
  void ShowTank(int index, Ogre::Vector3& pos);
  void ShowTanks();

  void ShowFPS();

  void InitPhysic();
  
  void GraphicBeginWork();
  void FreeGraphicResource();
  
  //void PhysicBeginWork();
  //void PhysicEndWork();
};
