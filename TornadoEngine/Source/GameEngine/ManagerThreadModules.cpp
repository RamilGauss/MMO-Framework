/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerThreadModules.h"

#include "ThreadModules.h"
#include <boost/foreach.hpp>

TManagerThreadModules::TManagerThreadModules()
{

}
//---------------------------------------------------------------------------------
TManagerThreadModules::~TManagerThreadModules()
{
  Done();
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::SetCountThread(int cnt)
{
  for( int i = 0 ; i < cnt ; i++)
    mVecThread.push_back(new TThreadModules);
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::AddModuleByThread(int indexThread, IModule* pModule)
{
  mVecThread[indexThread]->AddModule(pModule);
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::SetCallbackStop(TCallBackRegistrator1<std::string>* pCB)
{
  BOOST_FOREACH(TThreadModules*& pThread, mVecThread)
    pThread->SetCallbackStop(pCB);
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::Start()
{
  BOOST_FOREACH(TThreadModules*& pThread, mVecThread)
    pThread->Start();
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::Stop()
{
  BOOST_FOREACH(TThreadModules*& pThread, mVecThread)
    pThread->Stop();
}
//---------------------------------------------------------------------------------
void TManagerThreadModules::Done()
{
  BOOST_FOREACH(TThreadModules*& pThread, mVecThread)
    delete pThread;
}
//---------------------------------------------------------------------------------
