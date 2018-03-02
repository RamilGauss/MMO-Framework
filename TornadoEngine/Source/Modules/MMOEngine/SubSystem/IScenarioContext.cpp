/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IScenarioContext.h"
#include "Base.h"
#include <stddef.h>
#include "IScenario.h"
#include "ScContextManager.h"

using namespace nsMMOEngine;

IScenarioContext::IScenarioContext()
{
  mUserPtr          = NULL;
  mID_Session       = INVALID_HANDLE_SESSION;
  mManagerContextSc = NULL;
  mManagerSession   = NULL;
  mSrcEvent         = NULL;
  mScenario         = NULL;
}
//-----------------------------------------------------------------
IScenarioContext::~IScenarioContext()
{

}
//-----------------------------------------------------------------
void IScenarioContext::SetID_Session(unsigned int id)
{
  mID_Session = id;
}
//-----------------------------------------------------------------
unsigned int IScenarioContext::GetID_Session()
{
  return mID_Session;
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
  mManagerSession = pMS;
}
//-----------------------------------------------------------------
TSessionManager* IScenarioContext::GetMS()
{
  return mManagerSession;
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
void IScenarioContext::Disactivate()
{
  mManagerContextSc->Disactivate();
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
