/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_AggregationScenarioH
#define IGP_AggregationScenarioH

#include "GP_TypeScenario.h"

class IGP_Scenario_General;
class TGP_Scenario;

class IGP_AggregationScenario
{
protected:
  // для смены указателя только в потоке Логики
  void* mPtrCurrentScenario;
public:
  IGP_AggregationScenario();
  virtual ~IGP_AggregationScenario();

  nsGameProcess::GP_TypeScenario GetCurrentScenarioType();// L
  
  virtual bool Activate(nsGameProcess::GP_TypeScenario type) = 0;// L
protected:
  void Begin(IGP_Scenario_General* pNewScenario);
  void End();

  IGP_Scenario_General* GetCurrentScGeneral();
  TGP_Scenario*         GetCurrentSc();
};

#endif 
