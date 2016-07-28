/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_SynchroClientH
#define GP_Scenario_SynchroClientH

#include "IGP_Scenario_SynchroClient.h"
#include "GP_Scenario.h"

class DllExport GP_Scenario_SynchroClient : public IGP_Scenario_SynchroClient, 
  public TGP_Scenario
{
public:
  GP_Scenario_SynchroClient();
  virtual ~GP_Scenario_SynchroClient();

  virtual void SetEnable(int id, bool v);
  virtual bool UpdateGameObjectFromGameItem(int id, std::string type, std::string name);
  virtual bool UpdateGameObjectFromPattern(int id, TContainer internalState);
};

#endif
