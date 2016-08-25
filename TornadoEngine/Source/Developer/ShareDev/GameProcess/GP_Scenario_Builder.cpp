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
  flgActive = false;
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
  mBuilder.BuildMap(pMI);
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::AddGameObject(TMapItem::TObject& desc)
{
  return mBuilder.BuildObject(&desc);
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
  if(IsActive()==false)
    return;
  flgActive_ThreadBullet = true;


  flgActive_ThreadBullet = false;
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Ogre()
{
  if(IsActive()==false)
    return;
  flgActive_ThreadOgre = true;


  flgActive_ThreadOgre = false;
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_Logic()
{
  // анализ прогресса
  //mBuilder.
  int progress = 0;
  mCB_Progress.Notify(GetType(), progress);

  if(progress==100)
    mCB_End.Notify(GetType());
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Thread_OpenAL()
{
  if(IsActive()==false)
    return;
  flgActive_ThreadOpenAL = true;


  flgActive_ThreadOpenAL = false;
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
