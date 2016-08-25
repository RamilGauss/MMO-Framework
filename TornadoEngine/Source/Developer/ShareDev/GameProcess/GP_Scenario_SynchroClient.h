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

class DllExport TGP_Scenario_SynchroClient : public IGP_Scenario_SynchroClient, 
  public TGP_Scenario
{
public:
  TGP_Scenario_SynchroClient();
  virtual ~TGP_Scenario_SynchroClient();

  virtual void SetEnable(int id, bool v);
  virtual bool UpdateGameObjectFromGameItem(int id, std::string type, std::string name);
  virtual bool UpdateGameObjectFromPattern(int id, TContainer internalState);

  virtual void SetScene(TScene* pScene);
  virtual void Thread_Bullet();
  virtual void Thread_Ogre();
  virtual void Thread_Logic();
  virtual void Thread_OpenAL();

  virtual nsGameProcess::GP_TypeScenario GetType();

  virtual void Activate();
  virtual void Deactivate();
};

#endif
