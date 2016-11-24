/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_BuilderH
#define GP_Scenario_BuilderH

#include "IGP_Scenario_Builder.h"
#include "BuilderGameMap.h"
#include "GP_Scenario.h"

class DllExport TGP_Scenario_Builder : 
  public IGP_Scenario_Builder, public TGP_Scenario
{
  int mLastProgressEvent;
  TBuilderGameMap mBuilder;

  volatile bool flgProgressComplete;
  volatile bool flgActive;

  // активна ли функция
  volatile bool flgActive_ThreadBullet;
  volatile bool flgActive_ThreadOgre;
  volatile bool flgActive_ThreadOpenAL;

  // требуется ли получать квант для выполнения задания
  volatile bool flgActiveTask_ThreadLogic;
  volatile bool flgActiveTask_ThreadBullet;
  volatile bool flgActiveTask_ThreadOgre;
  volatile bool flgActiveTask_ThreadOpenAL;
  enum
  {
    eTimeFeedBackThread = 1, // мс
  };
public:
  TGP_Scenario_Builder();
  virtual ~TGP_Scenario_Builder();

  virtual void Setup(TUsePattern* pUsePattern, TFactoryBehaviourPatternModel* pFBP);
  virtual void LoadMap(std::string nameMap);
  virtual bool AddGameObject(std::list<TMapItem::TObject>& listDesc);
  virtual int GetPhysicWorldID();

  virtual void SetScene(TScene* pScene);
  virtual void Thread_Bullet();
  virtual void Thread_Ogre();
  virtual void Thread_Logic();
  virtual void Thread_OpenAL();

  virtual nsGameProcess::GP_TypeScenario GetType();
  virtual bool IsActive();

  virtual void Activate();
  virtual void Deactivate();
private:
  bool IsAnyThreadActive();

  typedef enum{eOgreActive, eBulletActive, eOpenALActive}TypeActive;
  void Enter(TypeActive t);
  void Leave(TypeActive t);
  
  void SetActiveTask(TypeActive t, bool v);
};

#endif
