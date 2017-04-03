/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_SynchroClientH
#define GP_Scenario_SynchroClientH

#include "IGP_Scenario_Synchro.h"
#include "IGP_Scenario.h"

class DllExport TGP_Scenario_SynchroClient : 
	public IGP_Scenario_Synchro, public IGP_Scenario
{
public:
  TGP_Scenario_SynchroClient();
  virtual ~TGP_Scenario_SynchroClient();

	// IGP_Scenario_Synchro
	virtual TGameObject* AddGameObject(TMapItem::TObject* pObject);
	virtual void UpdateGameObjectByGameItem(int id, bool force = false);
	virtual void UpdateGameMapParam();
	virtual bool DeleteGameObject(int id);

	// IGP_General
  virtual void WorkByModule_Physic();
  virtual void WorkByModule_Graphic();
  virtual void WorkByModule_Logic();
  virtual void WorkByModule_Sound();

	// IGP_Scenario
  virtual nsGameProcess::GP_TypeScenario GetType();

  virtual void Activate();
  virtual void Deactivate();
};

#endif
