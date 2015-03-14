/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ThreadModules.h"
#include <boost/foreach.hpp>
#include "IModule.h"

void TThreadModules::Work()
{
  BOOST_FOREACH( IModule* pM, mVecModule)
    if(pM->Work()==false)
      mCB_Stop->Notify(pM->GetName());
}
//----------------------------------------------------------------
void TThreadModules::AddModule(IModule* pModule)
{
  mVecModule.push_back(pModule);
}
//----------------------------------------------------------------
void TThreadModules::SetCallbackStop(TCallBackRegistrator1<std::string>* pCB)
{
  mCB_Stop = pCB;
}
//----------------------------------------------------------------
