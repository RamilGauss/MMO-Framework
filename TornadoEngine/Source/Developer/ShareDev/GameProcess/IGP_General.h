/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGP_GeneralH
#define IGP_GeneralH

#include "TypeDef.h"
#include "CallBackRegistrator.h"
#include "GP_TypeScenario.h"

#include <set>

class TScene;
class TFactoryBehaviourPatternModel;

class DllExport IGP_General
{
protected:
	enum{eDefaultProgressStep = 10};

  TScene*                        mPtrScene;
	TFactoryBehaviourPatternModel* mFBP;
	std::set<int>                  mSetID_Module;

  TCallBackRegistrator1<nsGameProcess::GP_TypeScenario> mCB_End;
  int mProgressStep;
  TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int> mCB_Progress;
public:
  IGP_General();
  virtual ~IGP_General();

  TCallBackRegistrator1<nsGameProcess::GP_TypeScenario>* GetCB_End();
  void SetProgressStep(int step);
  TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int>* GetCB_Progress();

	virtual void Setup(std::set<int>& setID_Module, 
		TFactoryBehaviourPatternModel* pFBP, TScene* pScene);

  virtual void WorkByModule_Logic()  = 0;
  virtual void WorkByModule_Physic() = 0;
  virtual void WorkByModule_Graphic()   = 0;
  virtual void WorkByModule_Sound() = 0;
};

#endif
