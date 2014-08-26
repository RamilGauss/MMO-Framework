/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_MasterTankH
#define DevTool_MasterTankH

#include "DevTool_Server.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"
#include <list>
#include "BaseEvent.h"
#include "Events.h"
#include "ListModule.h"

class TMasterForm;

class TDevTool_MasterTank : public TDevTool_Server
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;

  unsigned int mCounterClient;

  TMasterForm* mMasterForm;

  TInputCmdDevTool mInputCmd;

	typedef std::list<unsigned int> TListUint;
	TListUint mListKeyAllClient;

public:
  TDevTool_MasterTank();
  virtual ~TDevTool_MasterTank();

  virtual void Init(std::vector<std::string>& arg);
  virtual void Done();
  virtual void Event(nsEvent::TEvent* pEvent);
  
  virtual std::string GetPathServerLog(){return ".\\serverLoad_Master.xls";}
protected:
  virtual int GetIDPrototypeMMOEngineServer(){return MODULE_MMO_ENGINE_MASTER;}
protected:
  void ParseCmd(std::vector<std::string>& arg);

  void InitLog();
  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);
  void HandleFromQt(nsEvent::TEvent* pEvent);

  void InitQtForm();
  void ConnectUpQt();
  void DisconnectUpQt();
  void AddSlaveQt();
  void DeleteSlaveQt();

  void CreateGroup();

  void TryLogin(nsMMOEngine::TEventTryLogin* pEvent);
  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);

  void ConnectUp(nsMMOEngine::TEventConnectUp* pBE);
  void DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE);
};

#endif
