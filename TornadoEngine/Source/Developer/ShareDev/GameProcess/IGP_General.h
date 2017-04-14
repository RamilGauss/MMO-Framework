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
class TFactoryBehaviourPattern;

class DllExport IGP_General
{
protected:
	enum{eDefaultProgressStep = 10};

  TScene*                   mPtrScene;
	TFactoryBehaviourPattern* mFBP;
	std::set<int>             mSetID_Module;

  TCallBackRegistrator1<nsGameProcess::GP_TypeScenario> mCB_End;
  int mProgressStep;
  TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int> mCB_Progress;

	int mPhysicWorldID;
public:
  IGP_General();
  virtual ~IGP_General();

  TCallBackRegistrator1<nsGameProcess::GP_TypeScenario>* GetCB_End();
  void SetProgressStep(int step);
  TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int>* GetCB_Progress();

	virtual void Setup(std::set<int>& setID_Module, 
		TFactoryBehaviourPattern* pFBP, TScene* pScene, int id_world);

	virtual void Work() = 0;

	bool UsePhysic();
	bool UseGraphic();
	bool UseSound();
private:
	bool flgUsePhysic;
	bool flgUseGraphic;
	bool flgUseSound;
};

#endif
