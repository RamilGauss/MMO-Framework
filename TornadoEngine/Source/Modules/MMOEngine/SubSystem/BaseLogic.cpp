/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseLogic.h"
#include "Base.h"
#include "ContainerContextSc.h"

using namespace nsMMOEngine;

TBaseLogic::TBaseLogic( TBase* p )
{
  mBase = p;
  mEntMng = mBase->mEntMng.get();
}
//-----------------------------------------------------------------------------------
unsigned int TBaseLogic::GetNewID()
{
  auto ret = mCreationID;
  mCreationID++;
  return ret;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TBaseLogic::AddContainer()
{
  TContainerContextSc* pC = new TContainerContextSc;
  mBase->SetupScForContext( pC );
  return pC;
}
//--------------------------------------------------------------------------
void TBaseLogic::DeleteContainer( TContainerContextSc* pC )
{
  mBase->DelayDeleteContainerScenario( pC );
}
//--------------------------------------------------------------------------

