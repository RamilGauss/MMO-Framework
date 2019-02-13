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
#include "ParserConveyerFile.h"
#include "MakerLoaderDLL.h"
#include "ILoaderDLL.h"

#include "fmt/core.h"

TGameEngine::TGameEngine()
{
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
bool TGameEngine::LoadDLL( int variant_use, std::string& sNameDLL )
{
  if ( mLoaderDLL->Init( sNameDLL.data() ) == false )
  {
    GetLogger( sName )->WriteF_time( "LoadDLL() FAIL init.\n" );
    return false;
  }
  mFreeDevTool = (FuncFreeDevTool) mLoaderDLL->Get( StrFreeDevTool );
  if ( mFreeDevTool == nullptr )
  {
    GetLogger( sName )->WriteF_time( "LoadDLL() FAIL load FuncFree.\n" );
    return false;
  }
  mGetDevTool = (FuncGetDevTool) mLoaderDLL->Get( StrGetDevTool );
  if ( mGetDevTool == nullptr )
  {
    GetLogger( sName )->WriteF_time( "LoadDLL() FAIL load FuncGetdevTool.\n" );
    return false;
  }
  if ( mDevTool != nullptr )
  {
    GetLogger( sName )->WriteF_time( "LoadDLL() warning, object was loaded.\n" );
    return true;
  }
  mDevTool = mGetDevTool( variant_use );
  if ( mDevTool == nullptr )// нет DLL - нет движка.
    return false;

  Event( nsGameEngine::eAfterCreateDevTool );
  return true;
}
//----------------------------------------------------------------------
void TGameEngine::Init()
{
  GetLogger()->Done();
  GetLogger()->Register( sName );
}
//------------------------------------------------------------------------
void TGameEngine::Work( int variant_use, std::string& sNameDLL, std::vector<std::string>& vecParam )// начало работы
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

  Work();
  // чистка
  Done();
}
//------------------------------------------------------------------------
void TGameEngine::Work()
{
  for ( auto& pModule : mModulePtrList )
    pModule->StartEvent();

  bool needStop = false;
  while( !needStop )
  {
    for ( auto& pModule : mModulePtrList )
      if( pModule->Work() == false )
      {
        Event( nsGameEngine::eStopThreads, pModule->GetName() );
        needStop = true;
      }
  }

  for ( auto& pModule : mModulePtrList )
    pModule->StopEvent();
}
//------------------------------------------------------------------------
std::string TGameEngine::GetVersion()
{
  return fmt::format( "Tornado Game Engine, Version {}, mode work \"{}\"", sVersion, sModeWork );
}
//------------------------------------------------------------------------
bool TGameEngine::PrepareConveyer()
{
  auto sFileDescConveyer = mDevTool->GetFileDescConveyer();
  auto sVariantConveyer = mDevTool->GetVariantConveyer();
  TParserConveyerFile parser;
  if( parser.Work( sFileDescConveyer ) )
    mModuleNameList = parser.GetResult( sVariantConveyer );
  if ( mModuleNameList.size() > 0 )
    return true;
  auto sError = parser.GetStrError();
  Event( nsGameEngine::eParseFileConveyerError, sError );
  return false;
}
//------------------------------------------------------------------------
bool TGameEngine::CreateModules()
{
  if ( mModuleNameList.size() == 0 )
    return false;

  for ( auto& moduleName : mModuleNameList )
  {
    IModule* pModule = mDevTool->GetModuleByName( moduleName );
    if ( pModule != nullptr )
      mModulePtrList.push_back( pModule );
    else
      Event( nsGameEngine::eModuleNotMade, moduleName );
  }
  Event( nsGameEngine::eAfterCreateModules );

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
  for ( auto& pModule : mModulePtrList )
  {
    pModule->SetSynchroPoint( mSynchroPoint.get() );
    pModule->SetSelfID( pModule->GetID() );
  }
  mSynchroPoint->SetupAfterRegister();
}
//------------------------------------------------------------------------
