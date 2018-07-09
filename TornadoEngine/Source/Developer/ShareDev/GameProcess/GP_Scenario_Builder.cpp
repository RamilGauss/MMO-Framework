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

#include "GameObject.h"
#include "Scene.h"

TGP_Scenario_Builder::TGP_Scenario_Builder()
{
  mLastCountStepProgress = 0;
  flgActive = false;
  flgNeedWorkByModule = false;
}
//---------------------------------------------------------------------------------
TGP_Scenario_Builder::~TGP_Scenario_Builder()
{

}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::LoadMap( std::string nameMap )
{
  TBaseItem* pBI =
    TModuleLogic::Get()->GetFGI()->Get( TFactoryGameItem::Map, nameMap );
  TMapItem* pMI = (TMapItem*) pBI;
  if( pMI )
    if( mBuilder.BuildMap( pMI ) )
      flgNeedWorkByModule = true;
}
//---------------------------------------------------------------------------------
void TGP_Scenario_Builder::Work()
{
  if( IsActive() == false )
    return;
  if( flgNeedWorkByModule == false )
    return;
  mBuilder.Build();
  // анализ прогресса
  int progress = mBuilder.GetProgress();// например 13%
  int cntStep = progress / mProgressStep;// 13/10 = 1
  if( mLastCountStepProgress != cntStep )// 0!=1
  {
    mCB_Progress.Notify( GetType(), progress );
    mLastCountStepProgress = cntStep;// cnt = 1
  }

  if( progress == 100 )
  {
    DumpGameObjectToScene();
    flgNeedWorkByModule = false;
    flgActive = false;

    mCB_End.Notify( GetType() );
  }
}
//---------------------------------------------------------------------------------
bool TGP_Scenario_Builder::IsActive()
{
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
  mLastCountStepProgress = 0;
  flgNeedWorkByModule = false;
  flgActive = true;
  mBuilder.Init( mSetID_Module, mFBP, mPhysicWorldID );
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::Deactivate()
{
  // снаружи сказали "стоп!"
  flgActive = false;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_Builder::DumpGameObjectToScene()
{
  TBuilderGameMap::TListPtrGameObject listGO;
  mBuilder.GetResult( listGO );

  for( auto* pGO : listGO )
  {
    mPtrScene->Include( pGO );
  }
}
//-----------------------------------------------------------------------------
