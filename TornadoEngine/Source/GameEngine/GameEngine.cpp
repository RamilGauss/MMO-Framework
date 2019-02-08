/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>
#include <stdarg.h>

#include "GameEngine.h"
#include "BL_Debug.h"
#include "ShareMisc.h"
#include "HiTimer.h"
#include "Logger.h"
#include "ResolverSelf_IP_v4.h"
#include "IModule.h"
#include "FileOperation.h"
#include "IDevTool.h"
#include "EventGameEngine.h"
#include "ParserXMLConveyer.h"
#include "MakerLoaderDLL.h"
#include "ILoaderDLL.h"

#include "fmt/core.h"

//#include <boost/lexical_cast.hpp>

#define STR_GAME "GameEngine"
#define VERSION_GAME_ENGINE 8// надеюсь последняя версия :)

#define GAME_ENGINE_MODE_WORK "Single thread mode"
//#define GAME_ENGINE_MODE_WORK "Multi  thread mode"

TGameEngine::TGameEngine()
{
  mCB_Stop.Register( &TGameEngine::StopThreadByModule, this );

  mSynchroPoint.reset( new TSynchroPoint );

  TMakerLoaderDLL maker;
  mLoaderDLL = maker.New();

  mGetDevTool = nullptr;
  mFreeDevTool = nullptr;
  mDevTool = nullptr;

  Init();
}
//----------------------------------------------------------------------
void TGameEngine::Done()
{
  if ( mFreeDevTool )
    mFreeDevTool( mDevTool );

  mSynchroPoint.reset();

  TMakerLoaderDLL maker;
  maker.Delete( mLoaderDLL );

  GetLogger()->Done();
}
//----------------------------------------------------------------------
bool TGameEngine::LoadDLL( int variant_use, const char* sNameDLL )
{
  if ( mLoaderDLL->Init( sNameDLL ) == false )
  {
    GetLogger( STR_GAME )->WriteF_time( "LoadDLL() FAIL init.\n" );
    return false;
  }
  mFreeDevTool = (FuncFreeDevTool) mLoaderDLL->Get( StrFreeDevTool );
  if ( mFreeDevTool == NULL )
  {
    GetLogger( STR_GAME )->WriteF_time( "LoadDLL() FAIL load FuncFree.\n" );
    return false;
  }
  mGetDevTool = (FuncGetDevTool) mLoaderDLL->Get( StrGetDevTool );
  if ( mGetDevTool == NULL )
  {
    GetLogger( STR_GAME )->WriteF_time( "LoadDLL() FAIL load FuncGetdevTool.\n" );
    return false;
  }
  if ( mDevTool != NULL )
  {
    GetLogger( STR_GAME )->WriteF_time( "LoadDLL() warning, object was loaded.\n" );
    return true;
  }
  mDevTool = mGetDevTool( variant_use );
  if ( mDevTool == NULL )// нет DLL - нет движка.
    return false;

  mMngThreadModules.reset( new TModulesThreadManager );

  Event( nsGameEngine::eAfterCreateDevTool );
  return true;
}
//----------------------------------------------------------------------
void TGameEngine::Init()
{
  GetLogger()->Done();
  GetLogger()->Register( STR_GAME );
}
//------------------------------------------------------------------------
void TGameEngine::Work( int variant_use, const char* sNameDLL, std::vector<std::string>& vecParam )// начало работы
{
  if ( LoadDLL( variant_use, sNameDLL ) == false )
    return;
  mDevTool->SetVectorParam( vecParam );
  // подготовка конвейера
  if ( PrepareConveyer() == false )
    return;
  if ( CreateModules() == false )
    return;
  LinkModulesToSynchroPoint();
  // создать поток, который создает потоки модулей
  StartThread_StartThreads();
  // засыпаем, проснемся только если нас разбудят потоки с модулями
  Suspend();
  // останавливаем потоки с модулями
  StopThreadsWithModules();
  // чистка
  Done();
}
//------------------------------------------------------------------------
std::string TGameEngine::GetVersion()
{
  return fmt::format( "Tornado Game Engine, Version {}, mode work \"{}\"",
    VERSION_GAME_ENGINE, GAME_ENGINE_MODE_WORK );
}
//------------------------------------------------------------------------
void TGameEngine::StopThreadByModule( std::string sNameModule )
{
  // создать событие
  Event( nsGameEngine::eStopThreads, sNameModule );
  // разбудить главный поток
  Resume();
}
//------------------------------------------------------------------------
bool TGameEngine::PrepareConveyer()
{
  auto sFileDescConveyer = mDevTool->GetFileDescConveyer();
  auto sVariantConveyer = mDevTool->GetVariantConveyer();
  TParserXMLConveyer parser;
  if( parser.Work( sFileDescConveyer ) )
    mVecVecStrModule = parser.GetResult( sVariantConveyer );
  if ( mVecVecStrModule.size() > 0 )
    return true;
  auto sError = parser.GetStrError();
  Event( nsGameEngine::eParseFileConveyerError, sError );
  return false;
}
//------------------------------------------------------------------------
void TGameEngine::StartThread_StartThreads()
{
  boost::thread work_thread( boost::bind( &TGameEngine::StartThreadsWithModules, this ) );
}
//------------------------------------------------------------------------
void TGameEngine::Suspend()
{
  boost::mutex::scoped_lock lock( mMutex );
  mConditionVariable.wait( lock );
}
//------------------------------------------------------------------------
void TGameEngine::Resume()
{
  mConditionVariable.notify_all();
}
//------------------------------------------------------------------------
void TGameEngine::StartThreadsWithModules()
{
  // ждать пока главный поток уснет
  boost::mutex::scoped_lock lock( mMutex );
  while ( lock.owns_lock() == false )
    ht_msleep( 50 );

  int cntThread = mVecVecModule.size();
  mMngThreadModules->SetCountThread( cntThread );
  for ( int iThread = 0; iThread < cntThread; iThread++ )
  {
    // создать поток и поместить в него модули
    int cntModule = mVecVecModule[iThread].size();
    TVecPtrModule& vecModule = mVecVecModule[iThread];
    for ( int iModule = 0; iModule < cntModule; iModule++ )
      mMngThreadModules->AddModuleByThread( iThread, vecModule[iModule] );
  }
  mMngThreadModules->SetCallbackStop( &mCB_Stop );
  mMngThreadModules->Start();

  Event( nsGameEngine::eStartThreads );

  // разблокировать главный поток, что бы созданные потоки с модулями могли уведомить его.
  lock.unlock();
}
//------------------------------------------------------------------------
void TGameEngine::StopThreadsWithModules()
{
  mMngThreadModules->Stop();
  Event( nsGameEngine::eStopThreadsEnd );
}
//------------------------------------------------------------------------
bool TGameEngine::CreateModules()
{
  int cntThread = mVecVecStrModule.size();
  for ( int iThread = 0; iThread < cntThread; iThread++ )
  {
    // создать поток и поместить в него модули
    int cntModule = mVecVecStrModule[iThread].size();
    TVecStr& vecStrModule = mVecVecStrModule[iThread];

    TVecPtrModule vecPtrModule;
    for ( int iModule = 0; iModule < cntModule; iModule++ )
    {
      IModule* pModule = mDevTool->GetModuleByName( vecStrModule[iModule].data() );
      if ( pModule != nullptr )
      {
        vecPtrModule.push_back( pModule );
        mMapName_IDModule.insert( TMapStrIntVT( pModule->GetName(), pModule->GetID() ) );
      }
      else
        Event( nsGameEngine::eModuleNotMade, vecStrModule[iModule] );
    }
    if ( vecPtrModule.size() )
      mVecVecModule.push_back( vecPtrModule );
  }

  Event( nsGameEngine::eAfterCreateModules );

  if ( mVecVecStrModule.size() == 0 )
    return false;

  return true;
}
//------------------------------------------------------------------------
void TGameEngine::Event( int id, std::string param )
{
  std::string sEvent;
  if ( nsGameEngine::GetStrEventsByID( id, sEvent ) == false )
    return;

  std::string sError = sEvent;
  if ( param.length() )
    sError = fmt::format( sEvent, param );
  mDevTool->EventGameEngine( id, sError );
}
//------------------------------------------------------------------------
void TGameEngine::LinkModulesToSynchroPoint()
{
  int cntThread = mVecVecModule.size();
  for ( int iThread = 0; iThread < cntThread; iThread++ )
  {
    int cntModule = mVecVecModule[iThread].size();
    TVecPtrModule& vecModule = mVecVecModule[iThread];
    for ( int iModule = 0; iModule < cntModule; iModule++ )
    {
      vecModule[iModule]->SetSynchroPoint( mSynchroPoint.get() );
      vecModule[iModule]->SetSelfID( vecModule[iModule]->GetID() );
    }
  }
  mSynchroPoint->SetupAfterRegister();
}
//------------------------------------------------------------------------
bool TGameEngine::FindIDByNameModule( std::string& nameSrc, int& id )
{
  TMapStrIntIt fit = mMapName_IDModule.find( nameSrc );
  if ( fit == mMapName_IDModule.end() )
    return false;

  id = fit->second;
  return true;
}
//------------------------------------------------------------------------
