/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScContextManager.h"
#include "IScenario.h"
#include "Base/Common/BL_Debug.h"
#include "IScenarioContext.h"


using namespace std;
using namespace nsMMOEngine;

TScContextManager::TScContextManager()
{
    mPtrActiveContextSc = nullptr;
}
//---------------------------------------------------------------------
TScContextManager::~TScContextManager()
{

}
//---------------------------------------------------------------------
bool TScContextManager::Activate(IScenarioContext* pCSc)
{
    bool res;
    if (mPtrActiveContextSc) { // если есть активный, то поместить в очередь на активацию
        // даже если сейчас активен тот же сценарий, поместить в очередь
        mListWaitActivation.push_back(pCSc);
        res = false;
    } else {
        mPtrActiveContextSc = pCSc;
        res = true;
    }

    NotifyActiveEvent();
    return res;
}
//---------------------------------------------------------------------
void TScContextManager::Deactivate()
{
    BL_ASSERT(mPtrActiveContextSc);

    // следующий сценарий
    if (mListWaitActivation.size()) {
        mPtrActiveContextSc = mListWaitActivation.front();
        mListWaitActivation.pop_front();

        mPtrActiveContextSc->DelayBegin();
    } else
        mPtrActiveContextSc = nullptr;

    NotifyDisactiveEvent();
}
//---------------------------------------------------------------------
void TScContextManager::Work()
{
    if (mPtrActiveContextSc)
        mPtrActiveContextSc->Work();
}
//---------------------------------------------------------------------
bool TScContextManager::IsActive()
{
    return mPtrActiveContextSc != nullptr;
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
    return mPtrActiveContextSc;
}
//---------------------------------------------------------------------
