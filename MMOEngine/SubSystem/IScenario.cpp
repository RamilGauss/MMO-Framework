/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IScenario.h"
#include <stddef.h>
#include "BL_Debug.h"
#include "Base.h"
#include "IContextScenario.h"

using namespace nsMMOEngine;

IScenario::IScenario()
{
  mCurContext = NULL;

  AddCallBack(eContextBySession,   &mCBNeedContextBySession);
  AddCallBack(eEnd,                &mCBEnd);
  AddCallBack(eContextByClientKey, &mCBContextByClientKey);
}
//---------------------------------------------------------------------
IScenario::~IScenario()
{

}
//---------------------------------------------------------------------
bool IScenario::Begin()
{
  return mCurContext->Activate();
}
//---------------------------------------------------------------------
void IScenario::End()
{
	// уведомить об окончании сценария
  Notify<IScenario*>(eEnd, this);
	// сценарий закончен
  mCurContext->Disactivate();
}
//---------------------------------------------------------------------
void IScenario::DelayBegin()
{
  BL_FIX_BUG();
}
//---------------------------------------------------------------------
void IScenario::Work()
{

}
//---------------------------------------------------------------------
void IScenario::SetContext(IContextScenario* pCSc)
{
  mCurContext = pCSc;
}
//---------------------------------------------------------------------
IContextScenario* IScenario::GetContext()
{
  return mCurContext;
}
//---------------------------------------------------------------------
void IScenario::NeedContextBySession(unsigned int id_session)
{
  Notify<unsigned int>(eContextBySession, id_session);
}
//---------------------------------------------------------------------
unsigned char IScenario::GetType()
{
  return mType;
}
//---------------------------------------------------------------------
void IScenario::SetType(unsigned char type)
{
  mType = type;
}
//---------------------------------------------------------------------
void IScenario::NeedContextByClientKey(unsigned int id_client)
{
  Notify<unsigned int>(eContextByClientKey, id_client);
}
//---------------------------------------------------------------------
