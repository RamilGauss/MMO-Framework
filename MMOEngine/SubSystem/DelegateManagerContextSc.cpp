/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DelegateManagerContextSc.h"
#include "ContainerContextSc.h"
#include "Base.h"

using namespace nsMMOEngine;

static TBase* g_pBase = NULL;

TDelegateManagerContextSc::TDelegateManagerContextSc()
{

}
//--------------------------------------------------------------------------
TDelegateManagerContextSc::~TDelegateManagerContextSc()
{

}
//--------------------------------------------------------------------------
void TDelegateManagerContextSc::SetBase(TBase* pBase)
{
	g_pBase = pBase;
}
//--------------------------------------------------------------------------
TContainerContextSc* TDelegateManagerContextSc::AddContainer()
{
	TContainerContextSc* pC = new TContainerContextSc;
	g_pBase->SetupScForContext(pC);
	return pC;
}
//--------------------------------------------------------------------------
void TDelegateManagerContextSc::DeleteContainer(TContainerContextSc* pC)
{
	g_pBase->DelayDeleteContainerScenario(pC);
}
//--------------------------------------------------------------------------
