/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IScenario.h"
#include <stddef.h>
#include "Base/Common/BL_Debug.h"
#include "IScenarioContext.h"

using namespace nsMMOEngine;

IScenario::IScenario()
{
    mCurContext = nullptr;

    AddCallBack(eContextBySession, &mCBNeedContextBySession);
    AddCallBack(eEnd, &mCBEnd);
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
    Notify(eEnd, this);
    // сценарий закончен
    mCurContext->Deactivate();
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
void IScenario::SetContext(IScenarioContext* pCSc)
{
    mCurContext = pCSc;
}
//---------------------------------------------------------------------
IScenarioContext* IScenario::GetContext()
{
    return mCurContext;
}
//---------------------------------------------------------------------
void IScenario::NeedContextBySession(unsigned int sessionID)
{
    Notify(eContextBySession, sessionID);
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
void IScenario::NeedContextByClientKey(unsigned int clientKey)
{
    Notify(eContextByClientKey, clientKey);
}
//---------------------------------------------------------------------
