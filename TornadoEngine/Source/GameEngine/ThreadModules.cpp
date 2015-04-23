/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ThreadModules.h"
#include <boost/foreach.hpp>
#include "IModule.h"
#include "IDevTool.h"


TThreadModules::TThreadModules()
{

}
//----------------------------------------------------------------
void TThreadModules::Work()
{
  int cnt = mVecModule.size();
  for( int i = 0 ; i < cnt ; i++)
  {
    IModule* pM = mVecModule[i];
    if(pM->Work()==false)
      mCB_Stop->Notify(pM->GetName());
  }
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
void TThreadModules::StartEvent()
{
  BOOST_FOREACH( IModule* pM, mVecModule)
    pM->StartEvent();
}
//----------------------------------------------------------------
void TThreadModules::StopEvent()
{
  BOOST_FOREACH( IModule* pM, mVecModule)
    pM->StopEvent();
}
//----------------------------------------------------------------
