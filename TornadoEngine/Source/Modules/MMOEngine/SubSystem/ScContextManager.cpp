/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScContextManager.h"
#include "IScenario.h"
#include "BL_Debug.h"
#include "IScenarioContext.h"


using namespace std;
using namespace nsMMOEngine;

TScContextManager::TScContextManager()
{
  pActiveContextSc = NULL;
}
//---------------------------------------------------------------------
TScContextManager::~TScContextManager()
{

}
//---------------------------------------------------------------------
bool TScContextManager::Activate(IScenarioContext* pCSc)
{
  bool res;
  if(pActiveContextSc)// если есть активный, то поместить в очередь на активацию
  {
    // даже если сейчас активен тот же сценарий, поместить в очередь
    mListWaitActivation.push_back(pCSc);
    res = false;
  }
  else
  {
    pActiveContextSc = pCSc;
    res = true;
  }
  
  NotifyActiveEvent();
  return res;
}
//---------------------------------------------------------------------
void TScContextManager::Disactivate()
{
  BL_ASSERT(pActiveContextSc);
  // следующий сценарий
  if(mListWaitActivation.size())
  {
    pActiveContextSc = mListWaitActivation.front();
    mListWaitActivation.pop_front();

    pActiveContextSc->DelayBegin();
  }
  else
    pActiveContextSc = NULL;

  NotifyDisactiveEvent();
}
//---------------------------------------------------------------------
void TScContextManager::Work()
{
  if(pActiveContextSc)
    pActiveContextSc->Work();
}
//---------------------------------------------------------------------
bool TScContextManager::IsActive()
{
  return pActiveContextSc!=NULL;
}
//---------------------------------------------------------------------
TCallBackRegistrator1<TScContextManager*>* TScContextManager::GetCallBackActivate()
{
  return &mCallBackActivateEvent;
}
//---------------------------------------------------------------------
TCallBackRegistrator1<TScContextManager*>* TScContextManager::GetCallBackDisactivate()
{
  return &mCallBackDisactivateEvent;
}
//---------------------------------------------------------------------
void TScContextManager::NotifyActiveEvent()
{
  mCallBackActivateEvent.Notify(this);
}
//---------------------------------------------------------------------
void TScContextManager::NotifyDisactiveEvent()
{
  mCallBackDisactivateEvent.Notify(this);
}
//---------------------------------------------------------------------
IScenarioContext* TScContextManager::GetActive()
{
  return pActiveContextSc;
}
//---------------------------------------------------------------------
