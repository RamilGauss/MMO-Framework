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
#include "IGP_Scenario.h"

class DllExport TGP_Scenario_Builder : 
  public IGP_Scenario_Builder, public IGP_Scenario
{
  int mLastCountStepProgress;
  TBuilderGameMap mBuilder;

  bool flgActive;
  bool flgNeedWorkByModule;
public:
  TGP_Scenario_Builder();
  virtual ~TGP_Scenario_Builder();

  // IGP_Builder
  virtual void LoadMap(std::string nameMap);

  // IGP_General
  virtual void Work();

  // IGP_Scenario
  virtual nsGameProcess::GP_TypeScenario GetType();
  virtual bool IsActive();

  virtual void Activate();
  virtual void Deactivate();
private:
  void DumpGameObjectToScene();
};

#endif
