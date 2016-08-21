/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_Scenario_GeneralH
#define IGP_Scenario_GeneralH

#include "TypeDef.h"
#include "CallBackRegistrator.h"

class TScene;

class DllExport IGP_Scenario_General
{
protected:
  TCallBackRegistrator0 mCB_End;
  int mProgressStep;
  TCallBackRegistrator1<int> mCB_Progress;
public:
  IGP_Scenario_General();
  virtual ~IGP_Scenario_General();

  TCallBackRegistrator0* GetCB_End();
  void SetProgressStep(int step);
  TCallBackRegistrator1<int>* GetCB_Progress();

  virtual void SetScene(TScene* pScene) = 0;

  virtual void Thread_Logic()  = 0;
  virtual void Thread_Bullet() = 0;
  virtual void Thread_Ogre()   = 0;
  virtual void Thread_OpenAL() = 0;
};

#endif
