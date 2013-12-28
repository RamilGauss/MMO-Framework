/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IGameH
#define IGameH

#include <boost/function.hpp>
#include <vector>

#include "IClientDeveloperTool.h"
#include "IServerDeveloperTool.h"
#include "LoaderDLL.h"
#include "WrapperMakerTransport.h"
#include "DstEvent.h"
#include "DeveloperTool_DLL.h"

#define STR_GAME "GameEngine"

class IGame : public TDstEvent
{
  ILoaderDLL* mLoaderDLL;

  FuncFreeDeveloperTool mFreeDeveloperTool;
public:  
  typedef boost::function<bool ()> FuncHandleEvent;
protected:  
  typedef std::vector<FuncHandleEvent> TVectorFunc;
  TVectorFunc mMainThreadVecModule;
protected:  

  FuncGetClientDeveloperTool mGetClientDeveloperTool;
  FuncGetServerDeveloperTool mGetServerDeveloperTool;

	volatile bool flgNeedStop;
	volatile bool flgActive;
	TWrapperMakerTransport mWrapperMakerTransport;

protected:  
  IClientDeveloperTool* mClientDeveloperTool;
  IServerDeveloperTool* mServerDeveloperTool;
  
  enum{eWaitFeedBack = 30, // мс
  };
public:
  typedef enum{
    eClient,eSlave,eMaster,eSuperServer,
  }eTypeRealize;

  IGame();
  virtual ~IGame();

  void Work(int variant_use, const char* sNameDLL, std::vector<std::string>& arg);// начало работы

  void Stop();
  bool LoadDLL(int variant_use, const char* sNameDLL);
protected:
	eTypeRealize mType;
protected:
  void Init();
  void InitLog();
  void SetupFuncAndDevToolByType(int variant_use);
  void SetupNetComponent(nsMMOEngine::TBase* pBase);

  virtual bool Work() = 0;
  virtual bool Init(int variant_use, 
                    const char* sNameDLL, 
                    std::vector<std::string>& arg) = 0;
  virtual void Done() = 0;

 	virtual void MakeVectorModule() = 0;
  // опросить интерфейсы, которые не наследуются от TSrcEvent
  virtual void CollectEvent() = 0;

  virtual void HandleEvent(nsEvent::TEvent* pEvent) = 0;
  // пробежка по всем модулям
  bool MakeEventFromModule();
 	void HandleEventByDeveloper();
};
//---------------------------------------------------------
struct TDescThread
{
  IGame::FuncHandleEvent pFunc;
  int             sleep_ms;
  volatile bool   flgActive;
  volatile bool   flgNeedStop;
  TDescThread()
  {
    pFunc       = NULL;
    sleep_ms    = 20;
    flgActive   = false;
    flgNeedStop = false;
  }
  void Work();
};

#endif
