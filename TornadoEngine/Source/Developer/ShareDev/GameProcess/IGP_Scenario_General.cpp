/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGP_Scenario_General.h"

IGP_Scenario_General::IGP_Scenario_General()
{
  mPtrScene     = NULL;
  mProgressStep = 10;
}
//------------------------------------------------------------------------
IGP_Scenario_General::~IGP_Scenario_General()
{

}
//------------------------------------------------------------------------
TCallBackRegistrator1<nsGameProcess::GP_TypeScenario>* IGP_Scenario_General::GetCB_End()
{
  return &mCB_End;
}
//------------------------------------------------------------------------
void IGP_Scenario_General::SetProgressStep(int step)
{
  mProgressStep = step;
}
//------------------------------------------------------------------------
TCallBackRegistrator2<nsGameProcess::GP_TypeScenario,int>* IGP_Scenario_General::GetCB_Progress()
{
  return &mCB_Progress;
}
//------------------------------------------------------------------------
