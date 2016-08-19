/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_AggregationScenario_ClientH
#define GP_AggregationScenario_ClientH

#include "GP_Scenario.h"
#include "IGP_Scenario_Builder.h"
#include "IGP_Scenario_SynchroClient.h"
#include "IGP_Scenario_Destructor.h"
#include "IGP_AggregationScenario.h"

#include "GP_Scenario_Builder.h"
#include "GP_Scenario_SynchroClient.h"
#include "GP_Scenario_Destructor.h"

class DllExport TGP_AggregationScenario_Client : 
  public IGP_Scenario_Builder, public IGP_Scenario_SynchroClient,
  public IGP_Scenario_Destructor, public IGP_AggregationScenario
{
  TScene* mPtrScene;

  TGP_Scenario_Builder       mBuilder;
  TGP_Scenario_SynchroClient mSynchro;
  TGP_Scenario_Destructor    mDestructor;
public:
  TGP_AggregationScenario_Client();
  virtual ~TGP_AggregationScenario_Client();

  virtual void Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP);
  virtual void LoadMap(std::string nameMap);
  virtual bool AddGameObject(TMapItem::TObject& desc);
  virtual int GetPhysicWorldID();

  virtual void SetEnable(int id, bool v);
  virtual bool UpdateGameObjectFromGameItem(int id, std::string type, std::string name);
  virtual bool UpdateGameObjectFromPattern(int id, TContainer internalState);

  virtual void UnloadAll();
  virtual bool DeleteGameObject(int id);// запустить инициализацию процесса уничтожения объекта

  virtual int GetProgress();
  virtual void SetScene(TScene* pScene);
  virtual void Thread_Bullet();
  virtual void Thread_Ogre();
  virtual void Thread_Logic();
  virtual void Thread_OpenAL();
protected:

};

#endif
