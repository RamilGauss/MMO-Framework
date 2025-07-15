/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MMOEngine/Include/Base.h"
#include "MMOEngine/SubSystem/DelegateManagerContextSc.h"
#include "MMOEngine/SubSystem/ContainerContextSc.h"

using namespace nsMMOEngine;

TDelegateManagerContextSc::TDelegateManagerContextSc(TBase* pBase)
{
    mBase = pBase;
}
//--------------------------------------------------------------------------
TDelegateManagerContextSc::~TDelegateManagerContextSc()
{

}
//--------------------------------------------------------------------------
TContainerContextSc* TDelegateManagerContextSc::AddContainer()
{
    TContainerContextSc* pC = new TContainerContextSc;
    mBase->SetupScForContext(pC);
    return pC;
}
//--------------------------------------------------------------------------
void TDelegateManagerContextSc::DeleteContainer(TContainerContextSc* pC)
{
    mBase->DelayDeleteContainerScenario(pC);
}
//--------------------------------------------------------------------------
