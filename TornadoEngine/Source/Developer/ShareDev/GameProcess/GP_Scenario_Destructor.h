/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_DestructorH
#define GP_Scenario_DestructorH

#include "IGP_Scenario_Destructor.h"
#include "IGP_Scenario.h"

class DllExport TGP_Scenario_Destructor : 
  public IGP_Scenario_Destructor, public IGP_Scenario
{
  volatile bool flgActive;
public:
  TGP_Scenario_Destructor();
  virtual ~TGP_Scenario_Destructor();

  virtual void UnloadAll();

  virtual void Work();

  virtual nsGameProcess::GP_TypeScenario GetType();
  virtual bool IsActive();

  virtual void Activate();
  virtual void Deactivate();
};

#endif
