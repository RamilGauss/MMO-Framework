/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IScenarioContext.h"
#include "Base.h"
#include <stddef.h>
#include "IScenario.h"
#include "ScContextManager.h"

using namespace nsMMOEngine;

IScenarioContext::IScenarioContext()
{
    mUserPtr = nullptr;
    mSessionID = INVALID_HANDLE_SESSION;
    mManagerContextSc = nullptr;
    mSessionManager = nullptr;
    mSrcEvent = nullptr;
    mScenario = nullptr;
}
//-----------------------------------------------------------------
IScenarioContext::~IScenarioContext()
{

}
//-----------------------------------------------------------------
void IScenarioContext::SetSessionID(unsigned int id)
{
    mSessionID = id;
}
//-----------------------------------------------------------------
unsigned int IScenarioContext::GetSessionID()
{
    return mSessionID;
}
//-----------------------------------------------------------------
void IScenarioContext::SetMSc(TScContextManager* pMSc)
{
    mManagerContextSc = pMSc;
}
//-----------------------------------------------------------------
TScContextManager* IScenarioContext::GetMSc()
{
    return mManagerContextSc;
}
//-----------------------------------------------------------------
void IScenarioContext::SetMS(TSessionManager* pMS)
{
    mSessionManager = pMS;
}
//-----------------------------------------------------------------
TSessionManager* IScenarioContext::GetMS()
{
    return mSessionManager;
}
//-----------------------------------------------------------------
void IScenarioContext::SetSE(TSrcEvent* pS)
{
    mSrcEvent = pS;
}
//-----------------------------------------------------------------
TSrcEvent* IScenarioContext::GetSE()
{
    return mSrcEvent;
}
//-----------------------------------------------------------------
void IScenarioContext::SetSc(IScenario* pSc)
{
    mScenario = pSc;
}
//-----------------------------------------------------------------
IScenario* IScenarioContext::GetSc()
{
    return mScenario;
}
//-----------------------------------------------------------------
void IScenarioContext::DelayBegin()
{
    mScenario->SetContext(this);
    mScenario->DelayBegin();
}
//-----------------------------------------------------------------
void IScenarioContext::Work()
{
    mScenario->SetContext(this);
    mScenario->Work();
}
//-----------------------------------------------------------------
bool IScenarioContext::Activate()
{
    return mManagerContextSc->Activate(this);
}
//-----------------------------------------------------------------
void IScenarioContext::Deactivate()
{
    mStateTimeWait.SetCurrentStateToUndef();// окончание должно приводит к неопределенному состоянию контекста

    mManagerContextSc->Deactivate();
}
//-----------------------------------------------------------------
void IScenarioContext::SetUserPtr(void* p)
{
    mUserPtr = p;
}
//------------------------------------------------------------
void* IScenarioContext::GetUserPtr()
{
    return mUserPtr;
}
//------------------------------------------------------------
