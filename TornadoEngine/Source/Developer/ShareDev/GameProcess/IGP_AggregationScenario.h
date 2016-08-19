/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_AggregationScenarioH
#define IGP_AggregationScenarioH

class IGP_Scenario_General;

class IGP_AggregationScenario
{
protected:
  IGP_Scenario_General* volatile mPtrCurrentScenario;// для смены указателя только в потоке Логики
public:
  IGP_AggregationScenario();
  virtual ~IGP_AggregationScenario();

  enum{eUndefType=0};
  int GetCurrentScenarioType();
protected:
  void Begin(IGP_Scenario_General* pNewScenario);
  void End();
};

#endif 
