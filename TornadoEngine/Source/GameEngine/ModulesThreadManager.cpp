/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModulesThreadManager.h"

#include "ThreadModules.h"

TModulesThreadManager::TModulesThreadManager()
{

}
//---------------------------------------------------------------------------------
TModulesThreadManager::~TModulesThreadManager()
{
  Done();
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::SetCountThread( int cnt )
{
  for( int i = 0; i < cnt; i++ )
    mVecThread.push_back( new TThreadModules );
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::AddModuleByThread( int indexThread, IModule* pModule )
{
  mVecThread[indexThread]->AddModule( pModule );
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::SetCallbackStop( TCallBackRegistrator1<std::string>* pCB )
{
  for( TThreadModules*& pThread : mVecThread )
    pThread->SetCallbackStop( pCB );
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::Start()
{
  for( TThreadModules*& pThread : mVecThread )
    pThread->Start();
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::Stop()
{
  for( TThreadModules*& pThread : mVecThread )
    pThread->Stop();
}
//---------------------------------------------------------------------------------
void TModulesThreadManager::Done()
{
  for( TThreadModules*& pThread : mVecThread )
    delete pThread;
}
//---------------------------------------------------------------------------------
