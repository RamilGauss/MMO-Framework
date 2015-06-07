/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ClientLogicH
#define ClientLogicH

#include "ModuleClientLogic.h"
#include "BaseEvent.h"
#include <Ogre.h>

class TClientMain;
class TDebugPanel;

struct btDefaultMotionState;

class TClientLogic : public TModuleClientLogic
{
  TClientMain* mClientMain;
  TDebugPanel* mDebugPanel;

  volatile float x;
  volatile float y;
  volatile float z;
  btDefaultMotionState* fallMotionState;
  void ShowDebugInfo();
public:
  TClientLogic();
  virtual ~TClientLogic();

  virtual void StartEvent();
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
  
  void PhysicBeginWork();
  void PhysicEndWork();
};

#endif
