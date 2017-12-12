/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_SynchroH
#define GP_Scenario_SynchroH

#include "IGP_Scenario_Synchro.h"
#include "IGP_Scenario.h"

class DllExport TGP_Scenario_Synchro : 
  public IGP_Scenario_Synchro, public IGP_Scenario
{
public:
  TGP_Scenario_Synchro();
  virtual ~TGP_Scenario_Synchro();

  // IGP_Scenario_Synchro
  virtual TGameObject* AddGameObject(TMapItem::TObject* pObject);
  virtual bool DeleteGameObject(int id);

  virtual void SaveMap(std::string nameMap);

  // IGP_General
  virtual void Work();

  // IGP_Scenario
  virtual nsGameProcess::GP_TypeScenario GetType();

  virtual void Activate();
  virtual void Deactivate();
};

#endif
