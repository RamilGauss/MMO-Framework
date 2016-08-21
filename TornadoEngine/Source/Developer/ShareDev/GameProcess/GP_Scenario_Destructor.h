/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_DestructorH
#define GP_Scenario_DestructorH

#include "IGP_Scenario_Destructor.h"
#include "GP_Scenario.h"

class DllExport TGP_Scenario_Destructor : 
  public IGP_Scenario_Destructor, public TGP_Scenario
{
public:
  TGP_Scenario_Destructor();
  virtual ~TGP_Scenario_Destructor();

  virtual void UnloadAll();
  virtual bool DeleteGameObject(int id);

  virtual void SetScene(TScene* pScene);
  virtual void Thread_Bullet();
  virtual void Thread_Ogre();
  virtual void Thread_Logic();
  virtual void Thread_OpenAL();

  virtual nsGameProcess::GP_TypeScenario GetType();
  virtual bool IsBlock();
};

#endif
