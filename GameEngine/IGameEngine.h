/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGameEngineH
#define IGameEngineH

#include "DstEvent.h"
#include "DeveloperTool_DLL.h"
#include <vector>
#include "SaveToFile.h"
#include "StatisticValue.h"
#include "IDevTool.h"

class IModule;
class ILoaderDLL;

class DllExport IGameEngine : public TDstEvent
{
  ILoaderDLL* mLoaderDLL;

  FuncGetDevTool  mGetDevTool;
  FuncFreeDevTool mFreeDevTool;

  typedef std::vector<IModule*> TVectorPtr;
  TVectorPtr mMainThreadVecModule;

	volatile bool flgNeedStop;
	volatile bool flgActive;

  TSaveToFile mLogLoad;

  typedef TStatType_double TStatLoad;
  TStatLoad mStatLoad;

  unsigned int mStartTime;

  enum
  {
    eWaitFeedBack = 30, // мс
  };

protected:
  IDevTool* mDevTool;
public:

  IGameEngine();
  virtual ~IGameEngine();

  void Work(int variant_use, const char* sNameDLL, std::vector<std::string>& arg);// начало работы

	int GetVersion();
	virtual int GetVersionRelease() = 0;

private:
  void Stop();
  bool LoadDLL(int variant_use, const char* sNameDLL);
  void Init();
  void InitLog();
  void Done();

  // пробежка по всем модулям
  bool MakeEventFromModule();
  void HandleEventByDeveloper();
  bool Init(int variant_use, 
            const char* sNameDLL, 
            std::vector<std::string>& arg);
  void CalcAndWaitRestTime();
protected:
  virtual void SetupDevModule() = 0;
  virtual void FreeDevModule() = 0;

  void PushModule(IModule* ptr);

  IModule* GetModulePtr(int index);
};

#endif
