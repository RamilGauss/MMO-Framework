/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGP_AggregationScenario.h"
#include "IGP_Scenario_General.h"
#include <stddef.h>
#include "GP_Scenario.h"

IGP_AggregationScenario::IGP_AggregationScenario()
{
  mPtrCurrentScenario_General = NULL;
  mPtrCurrentScenario_Scenario = NULL;
}
//-----------------------------------------------------------------
IGP_AggregationScenario::~IGP_AggregationScenario()
{

}
//-----------------------------------------------------------------
void IGP_AggregationScenario::Begin( IGP_Scenario_General* pNew_General, TGP_Scenario* pNew_Scenario )
{
  mPtrCurrentScenario_General  = pNew_General;
  mPtrCurrentScenario_Scenario = pNew_Scenario;
}
//-----------------------------------------------------------------
void IGP_AggregationScenario::End()
{
  mPtrCurrentScenario_General = NULL;
  mPtrCurrentScenario_Scenario = NULL;
}
//-----------------------------------------------------------------
nsGameProcess::GP_TypeScenario IGP_AggregationScenario::GetCurrentScenarioType()
{
  if(GetCurrentSc()==NULL)
    return nsGameProcess::eUndef;
  return GetCurrentSc()->GetType();
}
//-----------------------------------------------------------------
IGP_Scenario_General* IGP_AggregationScenario::GetCurrentScGeneral()
{
  return mPtrCurrentScenario_General;
}
//-----------------------------------------------------------------
TGP_Scenario* IGP_AggregationScenario::GetCurrentSc()
{
  return mPtrCurrentScenario_Scenario;
}
//-----------------------------------------------------------------
bool IGP_AggregationScenario::Activate(nsGameProcess::GP_TypeScenario type)
{// прототип идеи агрегата!
  if(GetCurrentSc())
  {
    if(GetCurrentSc()->IsActive())
      return false;
  }
  TGP_Scenario* pScenario = NULL;
  IGP_Scenario_General* pGeneral = NULL;
  GetByType(type, pGeneral, pScenario);
  // нет такого типа
  if(pScenario==NULL || pGeneral==NULL)
    return false;
  // если текущий такой же какой нужен
  if(pScenario==GetCurrentSc() || pGeneral==GetCurrentScGeneral())
    return true;
  // деактивация старого
  if(GetCurrentSc())
    GetCurrentSc()->Deactivate();// синхронизация и остановка всех потоков
  // смена текущего
  End();
  Begin(pGeneral, pScenario);
  // начало работы, сценарий сам решит когда, куда и какой поток направлять
  GetCurrentSc()->Activate();
  return true;
}
//-----------------------------------------------------------------
void IGP_AggregationScenario::EndEventScenario(nsGameProcess::GP_TypeScenario type)
{
  mCB_End.Notify(type);
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::ProgressEventScenario(nsGameProcess::GP_TypeScenario type, int progress)
{
  mCB_Progress.Notify(type, progress);
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::RegisterScenarioOnEvent(IGP_Scenario_General* pSc)
{
  pSc->GetCB_End()     ->Register(&IGP_AggregationScenario::EndEventScenario, this);
  pSc->GetCB_Progress()->Register(&IGP_AggregationScenario::ProgressEventScenario, this);
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_Bullet()
{
  IGP_Scenario_General* pGP_General = GetCurrentScGeneral();
  if( pGP_General )
    pGP_General->Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_Ogre()
{
  IGP_Scenario_General* pGP_General = GetCurrentScGeneral();
  if( pGP_General )
    pGP_General->Thread_Ogre();
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_Logic()
{
  IGP_Scenario_General* pGP_General = GetCurrentScGeneral();
  if( pGP_General )
    pGP_General->Thread_Logic();
}
//---------------------------------------------------------------------------------------------
#include "GP_Scenario_Builder.h"
void IGP_AggregationScenario::Thread_OpenAL()
{
  IGP_Scenario_General* pGP_General = GetCurrentScGeneral();
  if( pGP_General )
    pGP_General->Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
bool IGP_AggregationScenario::IsActive(nsGameProcess::GP_TypeScenario type)
{
  return GetCurrentScenarioType()==type;
}
//---------------------------------------------------------------------------------------------
