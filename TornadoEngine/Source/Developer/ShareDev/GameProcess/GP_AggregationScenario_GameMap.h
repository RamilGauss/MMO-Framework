/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_AggregationScenario_GameMapH
#define GP_AggregationScenario_GameMapH

#include "IGP_AggregationScenario.h"

#include "GP_Scenario_Builder.h"
#include "GP_Scenario_Synchro.h"
#include "GP_Scenario_Destructor.h"

class DllExport TGP_AggregationScenario_GameMap : 
	public IGP_AggregationScenario,
	public IGP_Scenario_Builder, 
	public IGP_Scenario_Synchro, 
	public IGP_Scenario_Destructor 
{
  TGP_Scenario_Builder       mBuilder;
  TGP_Scenario_SynchroClient mSynchro;
  TGP_Scenario_Destructor    mDestructor;

	int mID_World;
public:
  TGP_AggregationScenario_GameMap();
  virtual ~TGP_AggregationScenario_GameMap();

	// Builder
  virtual void LoadMap(std::string nameMap);

	// Synchro
	virtual TGameObject* AddGameObject(TMapItem::TObject* pObject);
	virtual void UpdateGameObjectByMapParam(int id, bool force = false);
	virtual void UpdateGameMapParam();
	virtual bool DeleteGameObject(int id);

	// Destructor
  virtual void UnloadAll();
protected:
  virtual IGP_Scenario* GetByType(nsGameProcess::GP_TypeScenario type);

private:
	void End_BuildGameMap(nsGameProcess::GP_TypeScenario type);
	void Progress_BuildGameMap(nsGameProcess::GP_TypeScenario type, int progress);
};

#endif
