/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorMapLogicH
#define EditorMapLogicH

#include "ModuleClientLogic.h"
#include "UsePattern.h"
#include "FactoryBehaviourPattern_EoWM.h"

#include "GP_AggregationScenario_Client.h"

#include "./GraphicEngine/Events.h"

class TEditorMap;
class TShowTankWoT_test;
class TControlCamera;

class TEditorMapLogic : public TModuleClientLogic
{
  int mID_PhysicWorld;
  TEditorMap* mEditorMap;

  TUsePattern                   mUsePattern;
  TFactoryBehaviourPattern_EoWM mFBP_EoWM;

  boost::scoped_ptr<TGP_AggregationScenario_Client> mAggregationScenario_Client;
  boost::scoped_ptr<TShowTankWoT_test>              mPtrShowTank;
  boost::scoped_ptr<TControlCamera>                 mPtrControlCamera;

  unsigned int mID_TimerTryMoveCamera;
public:
  TEditorMapLogic();
  virtual ~TEditorMapLogic();

  virtual void StartEvent();
  virtual void StopEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id_sender, void* p, int size);
protected:
  void HandleFromGraphicEngine(nsGraphicEngine::TBaseEvent* pBaseGE);
  void HandleFromGraphicEngine_Mouse(nsGraphicEngine::TMouseEvent* pMouseGE);
  void HandleFromGraphicEngine_Key(nsGraphicEngine::TKeyEvent* pKeyGE);

private:
  void StartTimer();
  void InitForms();

  //void InitPhysic();
  void ShowTanks();

  void SoundEndWork();
  void GraphicEndWork();
  void FreeGraphicResource();

  //void PhysicBeginWork();
  void PhysicEndWork();

  void ProgressScenario(nsGameProcess::GP_TypeScenario type, int progress);
  void EndScenario(nsGameProcess::GP_TypeScenario type);
public:
  void LoadGameMap(std::string& nameMap);// in future should be locate in ClientLogic

protected:
  void CameraTryMove();
};

#endif
