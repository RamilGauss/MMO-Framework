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

class TEditorMap;

class TEditorMapLogic : public TModuleClientLogic
{
  int mID_PhysicWorld;
  TEditorMap* mEditorMap;

  TUsePattern                   mUsePattern;
  TFactoryBehaviourPattern_EoWM mFBP_EoWM;

public:
  TEditorMapLogic();
  virtual ~TEditorMapLogic();

  virtual void StartEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id_sender, void* p, int size);
private:
  void StartTimer();
  void InitForms();

  //void InitPhysic();

  void SoundEndWork();
  void GraphicEndWork();
  void FreeGraphicResource();

  //void PhysicBeginWork();
  void PhysicEndWork();

public:
  void LoadGameMap(std::string& nameMap);// in future should be locate in ClientLogic
};

#endif
