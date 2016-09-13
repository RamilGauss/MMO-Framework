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
  mPtrCurrentScenario = NULL;
}
//-----------------------------------------------------------------
IGP_AggregationScenario::~IGP_AggregationScenario()
{
  // форсированно
  if(GetCurrentSc())
    GetCurrentSc()->Deactivate();// синхронизация и остановка всех потоков
  End();
}
//-----------------------------------------------------------------
void IGP_AggregationScenario::Begin(void* pNewScenario)
{
  mPtrCurrentScenario = pNewScenario;
}
//-----------------------------------------------------------------
void IGP_AggregationScenario::End()
{
  mPtrCurrentScenario = NULL;
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
  return (IGP_Scenario_General*)mPtrCurrentScenario;
}
//-----------------------------------------------------------------
TGP_Scenario* IGP_AggregationScenario::GetCurrentSc()
{
  return (TGP_Scenario*)mPtrCurrentScenario;
}
//-----------------------------------------------------------------
bool IGP_AggregationScenario::Activate(nsGameProcess::GP_TypeScenario type)
{// прототип идеи агрегата!
  if(GetCurrentSc())
  {
    if(GetCurrentSc()->IsActive())
      return false;
  }
  TGP_Scenario* pSc = GetByType(type);
  // нет такого типа
  if(pSc==NULL)
    return false;
  // если текущий такой же какой нужен
  if(pSc==GetCurrentSc())
    return true;
  // деактивация старого
  if(GetCurrentSc())
    GetCurrentSc()->Deactivate();// синхронизация и остановка всех потоков
  // смена текущего
  End();
  Begin(pSc);
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
  if(GetCurrentScGeneral())
    GetCurrentScGeneral()->Thread_Bullet();
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_Ogre()
{
  if(GetCurrentScGeneral())
    GetCurrentScGeneral()->Thread_Ogre();
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_Logic()
{
  if(GetCurrentScGeneral())
    GetCurrentScGeneral()->Thread_Logic();
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Thread_OpenAL()
{
  if(GetCurrentScGeneral())
    GetCurrentScGeneral()->Thread_OpenAL();
}
//---------------------------------------------------------------------------------------------
bool IGP_AggregationScenario::IsActive(nsGameProcess::GP_TypeScenario type)
{
  return GetCurrentScenarioType()==type;
}
//---------------------------------------------------------------------------------------------
