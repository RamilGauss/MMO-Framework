/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GP_Scenario_BuilderH
#define GP_Scenario_BuilderH

#include "IGP_Scenario_Builder.h"
#include "BuilderGameMap.h"
#include "GP_Scenario.h"

class DllExport TGP_Scenario_Builder : 
  public IGP_Scenario_Builder, public TGP_Scenario
{
  TBuilderGameMap mBuilder;
  volatile bool flgNeedThreadQuant;// требуется ли получать квант из других потоков для реализации загрузки
public:
  TGP_Scenario_Builder();
  virtual ~TGP_Scenario_Builder();

  virtual void Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP);
  virtual void LoadMap(std::string nameMap);
  virtual bool AddGameObject(TMapItem::TObject& desc);
  virtual int GetPhysicWorldID();

  virtual void SetScene(TScene* pScene);
  virtual void Thread_Bullet();
  virtual void Thread_Ogre();
  virtual void Thread_Logic();
  virtual void Thread_OpenAL();

  virtual nsGameProcess::GP_TypeScenario GetType();
  virtual bool IsBlock();
};

#endif
