/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_Scenario_Builder.h"
#include "FactoryGameItem.h"
#include "ModuleLogic.h"
#include "HiTimer.h"

TGP_Scenario_Builder::TGP_Scenario_Builder()
{
  mLastProgressEvent = 0;
  flgActive = false;
  flgActive_ThreadLogic  = false;
  flgActive_ThreadBullet = false;
  flgActive_ThreadOgre   = false;
  flgActive_ThreadOpenAL = false;
}
//---------------------------------------------------------------------------------
TGP_Scenario_Builder::~TGP_Scenario_Builder()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::LoadMap(std::string nameMap)
{
  TBaseItem* pBI = 
    TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map,nameMap);
  TMapItem* pMI = (TMapItem*)pBI;
  if(mBuilder.BuildMap(pMI))
  {
    flgActive_ThreadLogic  = true;
    flgActive_ThreadBullet = true;
    flgActive_ThreadOgre   = true;
    flgActive_ThreadOpenAL = true;
  }
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::AddGameObject(TMapItem::TObject& desc)
{
  if(mBuilder.BuildObject(&desc))
  {
    flgActive_ThreadLogic  = true;
    flgActive_ThreadBullet = true;
    flgActive_ThreadOgre   = true;
    flgActive_ThreadOpenAL = true;
    return true;
  }

  return false;
}
//---------------------------------------------------------------------------------
int TGP_Scenario_Builder::GetPhysicWorldID()
{
  return mBuilder.GetPhysicWorldID();
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Setup(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP)
{
  mBuilder.Init(pUsePattern, pFBP);
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::SetScene(TScene* pScene)
{
  mPtrScene = pScene;
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Bullet()
{
  if(flgActive_ThreadBullet==false)
    return;
  if(IsActive()==false)
  {
    flgActive_ThreadBullet = false;
    return;
  }
  mBuilder.BuildFromThread_Bullet();
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Ogre()
{
  if(flgActive_ThreadOgre==false)
    return;
  if(IsActive()==false)
  {
    flgActive_ThreadOgre = false;
    return;
  }
  mBuilder.BuildFromThread_Ogre();
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Logic()
{
  if(flgActive_ThreadLogic==false)
    return;
  if(IsActive()==false)
  {
    flgActive_ThreadLogic = false;
    return;
  }

  mBuilder.BuildFromThread_Logic();
  // анализ прогресса
  int progress = mBuilder.GetProgress();
  if(progress%mProgressStep==0)
  {
    if(mLastProgressEvent!=progress)
    {
      mCB_Progress.Notify(GetType(), progress);
      mLastProgressEvent = progress;
    }
  }

  if(progress==100)
  {
    mCB_End.Notify(GetType());
    flgActive_ThreadLogic = false;
  }
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_OpenAL()
{
  if(flgActive_ThreadOpenAL==false)
    return;
  if(IsActive()==false)
  {
    flgActive_ThreadOpenAL = false;
    return;
  }
  mBuilder.BuildFromThread_OpenAL();
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsActive()
{
  // меняется во времени!
  return flgActive;
}
//-------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_Builder::GetType()
{
  return nsGameProcess::eBuilder;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::Activate()
{
  flgActive = true;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::Deactivate()
{
  // снаружи сказали "стоп!"
  flgActive = false;
  while(IsAnyThreadActive()==true)
    ht_msleep(eTimeFeedBackThread);
}
//-----------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsAnyThreadActive()
{
  if(flgActive_ThreadBullet ||
     flgActive_ThreadOgre   ||
     flgActive_ThreadOpenAL)
    return true;
  return false;
}
//-----------------------------------------------------------------------------
