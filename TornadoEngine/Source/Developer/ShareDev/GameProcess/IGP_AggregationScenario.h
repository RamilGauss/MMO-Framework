/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_AggregationScenarioH
#define IGP_AggregationScenarioH

#include "TypeDef.h"
#include "GP_TypeScenario.h"
#include "IGP_General.h"

class IGP_Scenario;

class DllExport IGP_AggregationScenario : public IGP_General
{
protected:
  IGP_Scenario* mPtrCurrentScenario;
public:
  IGP_AggregationScenario();
  virtual ~IGP_AggregationScenario();

  nsGameProcess::GP_TypeScenario GetCurrentScenarioType();
  
  virtual bool Activate(nsGameProcess::GP_TypeScenario type);

	// IGP_General
	virtual void WorkByModule_Logic();
	virtual void WorkByModule_Physic();
	virtual void WorkByModule_Graphic();
	virtual void WorkByModule_Sound();
protected:
  virtual IGP_Scenario* GetByType(nsGameProcess::GP_TypeScenario type) = 0;

  void Begin( IGP_Scenario* pNew_General );
  void End();

  IGP_Scenario* GetCurrentScenario();

  void RegisterScenarioOnEvent(IGP_General* pSc);
  
  bool IsActive(nsGameProcess::GP_TypeScenario type);
protected:
  void EndEventScenario(nsGameProcess::GP_TypeScenario type);
  void ProgressEventScenario(nsGameProcess::GP_TypeScenario type, int progress);
};

#endif 
