/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <vector>
#include <memory>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include "CallBackRegistrator.h"
#include "SynchroPoint.h"
#include "ModulesThreadManager.h"
#include "DeveloperTool_DLL.h"

class ILoaderDLL;
class IDevTool;
class TThreadModules;
class IModule;

class DllExport TGameEngine
{
  ILoaderDLL* mLoaderDLL;

  FuncGetDevTool  mGetDevTool;
  FuncFreeDevTool mFreeDevTool;

  typedef std::vector<std::string> TVecStr;
  typedef std::vector< TVecStr > TVecVecStr;
  TVecVecStr mVecVecStrModule;

  typedef std::vector<IModule*> TVecPtrModule;
  typedef std::vector< TVecPtrModule > TVecVecPtrModule;
  TVecVecPtrModule mVecVecModule;

  typedef std::map<std::string, int> TMapStrInt;
  typedef TMapStrInt::value_type TMapStrIntVT;
  typedef TMapStrInt::iterator TMapStrIntIt;
  TMapStrInt mMapName_IDModule;

  IDevTool* mDevTool;

  std::shared_ptr<TModulesThreadManager> mMngThreadModules;

  std::shared_ptr<TSynchroPoint> mSynchroPoint;

  TCallBackRegistrator1<std::string> mCB_Stop;

  boost::mutex mMutex;
  boost::condition_variable mConditionVariable;
public:
  TGameEngine();

  void Work( int variant_use, const char* sNameDLL, std::vector<std::string>& vecParam );// начало работы
  std::string GetVersion();
private:
  void Init();
  bool LoadDLL( int variant_use, const char* sNameDLL );

  bool CreateModules();
  bool PrepareConveyer();
  void LinkModulesToSynchroPoint();

  void StartThread_StartThreads();

  void StartThreadsWithModules();
  void StopThreadsWithModules();
  void Suspend();
  void Resume();

private:
  bool FindIDByNameModule( std::string& nameSrc, int& id );
private:
  void Done();
  void StopThreadByModule( std::string sNameModule );// callback
  void Event( int id, std::string param = "" );
};
