/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGP_General.h"

IGP_General::IGP_General()
{
  mPtrScene     = NULL;
	mFBP          = NULL;
  mProgressStep = eDefaultProgressStep;
}
//------------------------------------------------------------------------
IGP_General::~IGP_General()
{

}
//------------------------------------------------------------------------
TCallBackRegistrator1<nsGameProcess::GP_TypeScenario>* IGP_General::GetCB_End()
{
  return &mCB_End;
}
//------------------------------------------------------------------------
void IGP_General::SetProgressStep(int step)
{
  mProgressStep = step;
}
//------------------------------------------------------------------------
TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int>* IGP_General::GetCB_Progress()
{
  return &mCB_Progress;
}
//------------------------------------------------------------------------
void IGP_General::Setup(std::set<int>& setID_Module, 
									 TFactoryBehaviourPatternModel* pFBP, TScene* pScene)
{
	mPtrScene     = pScene;
	mFBP          = pFBP;
	mSetID_Module = setID_Module;
}
//------------------------------------------------------------------------
