/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IGP_General.h"
#include "ListModules.h"

IGP_General::IGP_General()
{
  mPtrScene      = NULL;
  mFBP           = NULL;
  mProgressStep  = eDefaultProgressStep;
  mPhysicWorldID = -1;

  flgUsePhysic  = false;
  flgUseGraphic = false;
  flgUseSound   = false;
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
                   TFactoryBehaviourPattern* pFBP, TScene* pScene, int id_world)
{
  mPtrScene      = pScene;
  mFBP           = pFBP;
  mSetID_Module  = setID_Module;
  mPhysicWorldID = id_world;

  flgUsePhysic  = bool(mSetID_Module.find(nsListModules::PhysicEngine) !=mSetID_Module.end());
  flgUseGraphic = bool(mSetID_Module.find(nsListModules::GraphicEngine)!=mSetID_Module.end());
  flgUseSound   = bool(mSetID_Module.find(nsListModules::SoundEngine)  !=mSetID_Module.end());
}
//------------------------------------------------------------------------
bool IGP_General::UsePhysic()
{
  return flgUsePhysic;
}
//------------------------------------------------------------------------
bool IGP_General::UseGraphic()
{
  return flgUseGraphic;
}
//------------------------------------------------------------------------
bool IGP_General::UseSound()
{
  return flgUseSound;
}
//------------------------------------------------------------------------
