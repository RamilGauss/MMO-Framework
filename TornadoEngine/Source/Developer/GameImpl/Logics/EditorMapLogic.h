/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorMapLogicH
#define EditorMapLogicH

#include "ModuleClientLogic.h"
#include "FactoryBehaviourPattern_EoWM.h"

#include "GP_AggregationScenario_GameMap.h"

#include "./GraphicEngine/Events.h"
#include "PhysicEngine_Bullet.h"
#include "Modifier_Terrain.h"

class TEditorMap;
class TStatusBar;
class TShowTankWoT_test;
class TControlCamera;

class TEditorMapLogic : public TModuleClientLogic
{
  int         mPhysicWorldID;
  TEditorMap* mEditorMap;
  TStatusBar* mStatusBar;

	TPhysicEngine_Bullet::eStateWorld    mStatePhysicWorld;
  TFactoryBehaviourPattern_EoWM        mFBP_EoWM;

  boost::scoped_ptr<TShowTankWoT_test> mPtrShowTank;
  boost::scoped_ptr<TControlCamera>    mPtrControlCamera;

  unsigned int mID_TimerTryMoveCamera;

	std::string mCurrentGameMap;
	//### прототипы TODO перенос в базовый класс?
	bool flgIsTerrainGroupUpdate;
	void CheckTerrainGroupUpdateForSave();
	//###
public:
  TEditorMapLogic();
  virtual ~TEditorMapLogic();

  virtual void StartEvent();
  virtual void StopEvent();
  virtual void InitLog();

  virtual TFactoryBehaviourPattern* GetFBP();

public:// TEditorMapLogic for GUI
	void TogglePhysicState(TPhysicEngine_Bullet::eStateWorld stateWorld);

	// in future should be locate in ClientLogic
	void LoadGameMap(std::string& nameMap);
	void SaveAsGameMap(std::string& nameMap);
	void SaveGameMap();
	
	void ModifyTerrain_Extent(TModifier_Terrain::TDescTarget& descTarget);

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

	void LoadSettingCamera();
	void SaveSettingCamera();

  void ShowTest();

  void FreeGraphicResource();

  void ProgressScenario(nsGameProcess::GP_TypeScenario type, int progress);
  void EndScenario(nsGameProcess::GP_TypeScenario type);
protected:
  void CameraTryMove();
};

// uses in GUI
extern DllExport TEditorMapLogic* g_EditorMapLogic;

#endif
