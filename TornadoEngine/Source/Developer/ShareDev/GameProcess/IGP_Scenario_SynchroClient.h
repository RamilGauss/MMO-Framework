/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_Scenario_SynchroClientH
#define IGP_Scenario_SynchroClientH

#include "TypeDef.h"
#include "IGP_Scenario_General.h"
#include <string>
#include "ContainerTypes.h"

class DllExport IGP_Scenario_SynchroClient : public IGP_Scenario_General
{
public:
  IGP_Scenario_SynchroClient();
  virtual ~IGP_Scenario_SynchroClient();

  virtual void SetEnable(int id, bool v) = 0;
  virtual bool UpdateGameObjectFromGameItem(int id, std::string type, std::string name) = 0;
  virtual bool UpdateGameObjectFromPattern(int id, TContainer internalState) = 0;
};

#endif
