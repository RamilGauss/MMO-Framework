/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IContextScenario.h"
#include "Base.h"
#include <stddef.h>
#include "IScenario.h"
#include "ManagerContextSc.h"

using namespace nsMMOEngine;

IContextScenario::IContextScenario()
{
  mUserPtr          = NULL;
  mID_Session       = INVALID_HANDLE_SESSION;
  mManagerContextSc = NULL;
  mManagerSession   = NULL;
  mSrcEvent         = NULL;
  mScenario         = NULL;
}
//-----------------------------------------------------------------
IContextScenario::~IContextScenario()
{

}
//-----------------------------------------------------------------
void IContextScenario::SetID_Session(unsigned int id)
{
  mID_Session = id;
}
//-----------------------------------------------------------------
unsigned int IContextScenario::GetID_Session()
{
  return mID_Session;
}
//-----------------------------------------------------------------
void IContextScenario::SetMSc(TManagerContextSc* pMSc)
{
  mManagerContextSc = pMSc;
}
//-----------------------------------------------------------------
TManagerContextSc* IContextScenario::GetMSc()
{
  return mManagerContextSc;
}
//-----------------------------------------------------------------
void IContextScenario::SetMS(TManagerSession* pMS)
{
  mManagerSession = pMS;
}
//-----------------------------------------------------------------
TManagerSession* IContextScenario::GetMS()
{
  return mManagerSession;
}
//-----------------------------------------------------------------
void IContextScenario::SetSE(TSrcEvent* pS)
{
  mSrcEvent = pS;
}
//-----------------------------------------------------------------
TSrcEvent* IContextScenario::GetSE()
{
  return mSrcEvent;
}
//-----------------------------------------------------------------
void IContextScenario::SetSc(IScenario* pSc)
{
  mScenario = pSc;
}
//-----------------------------------------------------------------
IScenario* IContextScenario::GetSc()
{
  return mScenario;
}
//-----------------------------------------------------------------
void IContextScenario::DelayBegin()
{
  mScenario->SetContext(this);
  mScenario->DelayBegin();
}
//-----------------------------------------------------------------
void IContextScenario::Work()
{
  mScenario->SetContext(this);
  mScenario->Work();
}
//-----------------------------------------------------------------
bool IContextScenario::Activate()
{
  return mManagerContextSc->Activate(this);
}
//-----------------------------------------------------------------
void IContextScenario::Disactivate()
{
  mManagerContextSc->Disactivate();
}
//-----------------------------------------------------------------
void IContextScenario::SetUserPtr(void* p)
{
  mUserPtr = p;
}
//------------------------------------------------------------
void* IContextScenario::GetUserPtr()
{
  return mUserPtr;
}
//------------------------------------------------------------
