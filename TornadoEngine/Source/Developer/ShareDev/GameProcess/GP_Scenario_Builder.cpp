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
  flgActiveTask_ThreadLogic = false;
  flgActiveTask_ThreadBullet = false;
  flgActiveTask_ThreadOgre   = false;
  flgActiveTask_ThreadOpenAL = false;

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
    flgProgressComplete    = false;
    flgActiveTask_ThreadLogic  = true;
    flgActiveTask_ThreadBullet = true;
    flgActiveTask_ThreadOgre   = true;
    flgActiveTask_ThreadOpenAL = true;
  }
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::AddGameObject(TMapItem::TObject& desc)
{
  if(mBuilder.BuildObject(&desc))
  {
    flgProgressComplete    = false;
    flgActiveTask_ThreadLogic  = true;
    flgActiveTask_ThreadBullet = true;
    flgActiveTask_ThreadOgre   = true;
    flgActiveTask_ThreadOpenAL = true;
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
void TGP_Scenario_Builder::Setup(TUsePattern* pUsePattern, TFactoryBehaviourPatternModel* pFBP)
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
  Enter(eBulletActive);
  if(flgActiveTask_ThreadBullet==false)
  {
    Leave(eBulletActive);
    return;
  }
  if(IsActive()==false)
  {
    flgActiveTask_ThreadBullet = false;
    Leave(eBulletActive);
    return;
  }
  mBuilder.BuildFromThread_Bullet();
  Leave(eBulletActive);
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Ogre()
{
  Enter(eOgreActive);
  flgActive_ThreadOgre = true;

  if(flgActiveTask_ThreadOgre==false)
  {
    Leave(eOgreActive);
    return;
  }
  if(IsActive()==false)
  {
    flgActiveTask_ThreadOgre = false;
    Leave(eOgreActive);
    return;
  }
  mBuilder.BuildFromThread_Ogre();
  Leave(eOgreActive);
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Logic()
{
  if(flgActiveTask_ThreadLogic==false)
    return;
  if(IsActive()==false)
  {
    flgActiveTask_ThreadLogic = false;
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
    flgProgressComplete = true;
    mCB_End.Notify(GetType());
    flgActiveTask_ThreadLogic = false;
  }
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_OpenAL()
{
  Enter(eOpenALActive);
  if(flgActiveTask_ThreadOpenAL==false)
  {
    Leave(eOpenALActive);
    return;
  }
  if(IsActive()==false)
  {
    flgActiveTask_ThreadOpenAL = false;
    Leave(eOpenALActive);
    return;
  }
  mBuilder.BuildFromThread_OpenAL();
  Leave(eOpenALActive);
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsActive()
{
  if( flgProgressComplete )
    return false;
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

  // обработка может быть как в другом потоке, так и в этом же.
  flgActive = false;
  while(IsAnyThreadActive()==true)
    ht_msleep(eTimeFeedBackThread);
}
//-----------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsAnyThreadActive()
{
  if((flgActive_ThreadBullet && flgActiveTask_ThreadBullet) ||
     (flgActive_ThreadOgre   && flgActiveTask_ThreadOgre  ) ||
     (flgActive_ThreadOpenAL && flgActiveTask_ThreadOpenAL))
    return true;
  return false;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::Enter(TypeActive t)
{
  SetActiveTask( t, true );
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::Leave(TypeActive t)
{
  SetActiveTask( t, false );
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::SetActiveTask(TypeActive t, bool v)
{
  switch(t)
  {
    case eOgreActive: 
      flgActive_ThreadOgre = v;
      break;
    case eBulletActive: 
      flgActive_ThreadBullet = v;
      break;
    case eOpenALActive:
      flgActive_ThreadOpenAL = v;
      break;
  }
}
//-----------------------------------------------------------------------------
