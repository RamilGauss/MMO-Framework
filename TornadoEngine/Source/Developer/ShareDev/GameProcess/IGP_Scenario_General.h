/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_Scenario_GeneralH
#define IGP_Scenario_GeneralH

#include "TypeDef.h"

class TScene;

class DllExport IGP_Scenario_General
{
public:
  IGP_Scenario_General();
  virtual ~IGP_Scenario_General();

  virtual void SetScene(TScene* pScene) = 0;
  virtual void Thread_Bullet() = 0;
  virtual void Thread_Ogre()   = 0;
  virtual void Thread_Logic()  = 0;
  virtual void Thread_OpenAL() = 0;
};

#endif
