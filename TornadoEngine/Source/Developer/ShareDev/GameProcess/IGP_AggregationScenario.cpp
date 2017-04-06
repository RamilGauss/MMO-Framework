/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGP_AggregationScenario.h"
#include "IGP_Scenario.h"

#include <stddef.h>

IGP_AggregationScenario::IGP_AggregationScenario()
{
  mPtrCurrentScenario = NULL;
}
//-----------------------------------------------------------------
IGP_AggregationScenario::~IGP_AggregationScenario()
{

}
//-----------------------------------------------------------------
void IGP_AggregationScenario::Begin( IGP_Scenario* pScenario )
{
  mPtrCurrentScenario = pScenario;
	// перед началом работы по сценарию необходимо обновить параметры работы
	mPtrCurrentScenario->Setup(mSetID_Module,mFBP,mPtrScene,mPhysicWorldID);
	mPtrCurrentScenario->SetProgressStep(mProgressStep);
}
//-----------------------------------------------------------------
void IGP_AggregationScenario::End()
{
  mPtrCurrentScenario = NULL;
}
//-----------------------------------------------------------------
nsGameProcess::GP_TypeScenario IGP_AggregationScenario::GetCurrentScenarioType()
{
  if( GetCurrentScenario()==NULL )
    return nsGameProcess::eUndef;
  return GetCurrentScenario()->GetType();
}
//-----------------------------------------------------------------
IGP_Scenario* IGP_AggregationScenario::GetCurrentScenario()
{
  return mPtrCurrentScenario;
}
//-----------------------------------------------------------------
bool IGP_AggregationScenario::Activate(nsGameProcess::GP_TypeScenario type)
{
	IGP_Scenario* pCurrentScenario = GetCurrentScenario();
  if( pCurrentScenario )
  {// сценарий может быть заблокирован, например, идёт загрузка карты
    if( pCurrentScenario->IsActive())
      return false;
  }
	IGP_Scenario* pNewScenario = GetByType(type);
  // нет такого типа
  if( pNewScenario==NULL )
    return false;
  // если текущий такой же какой нужен
  if( type==GetCurrentScenarioType() )
    return true;
  // деактивация старого
	if( pCurrentScenario )
		pCurrentScenario->Deactivate();// синхронизация и остановка всех потоков
  // смена текущего
  End();
  Begin( pNewScenario );
  // начало работы, сценарий сам решит когда, куда и какой поток направлять
  GetCurrentScenario()->Activate();
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
void IGP_AggregationScenario::RegisterScenarioOnEvent(IGP_General* pSc)
{
  pSc->GetCB_End()     ->Register(&IGP_AggregationScenario::EndEventScenario, this);
  pSc->GetCB_Progress()->Register(&IGP_AggregationScenario::ProgressEventScenario, this);
}
//---------------------------------------------------------------------------------------------
void IGP_AggregationScenario::Work()
{
  IGP_Scenario* pScenario = GetCurrentScenario();
  if( pScenario )
    pScenario->Work();
}
//---------------------------------------------------------------------------------------------
bool IGP_AggregationScenario::IsActive(nsGameProcess::GP_TypeScenario type)
{
  return GetCurrentScenarioType()==type;
}
//---------------------------------------------------------------------------------------------
