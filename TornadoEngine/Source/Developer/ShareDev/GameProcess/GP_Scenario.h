/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_ScenarioH
#define GP_ScenarioH

#include "TypeDef.h"
#include "GP_TypeScenario.h"

class TScene;

class DllExport TGP_Scenario
{
public:
  TGP_Scenario();
  virtual ~TGP_Scenario();

  virtual nsGameProcess::GP_TypeScenario GetType() = 0;
  virtual bool IsActive();

  // как правило поведение блокирующее, потому что идет синхронизация потоков
  virtual void Activate() = 0;
  virtual void Deactivate() = 0;
};

#endif
