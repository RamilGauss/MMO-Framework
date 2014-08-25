/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ServerDeveloperTool_SlaveTankH
#define ServerDeveloperTool_SlaveTankH

#include "DevTool_Server.h"
#include "InputCmdDevTool.h"
#include "TestControlTank.h"
#include "ListMultiThread.h"
#include "BaseEvent.h"
#include "Events.h"
#include "ListModule.h"

class SlaveForm;

class TDevTool_SlaveTank : public TDevTool_Server
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;

  SlaveForm* mSlaveForm;

  TInputCmdDevTool mInputCmd;

	TTestControlTank mTestControlTank;
public:
  TDevTool_SlaveTank();
  virtual ~TDevTool_SlaveTank();

	virtual void Init(std::vector<std::string>& arg);
	virtual void Done();
	virtual void Event(nsEvent::TEvent* pEvent);
protected:
  virtual int GetIDPrototypeMMOEngineServer(){return MODULE_MMO_ENGINE_SLAVE;}
protected:
  void ParseCmd(std::vector<std::string>& arg);
  void InitLog();

  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);
  void HandleFromQt(nsEvent::TEvent* pEvent);

  void InitQtForm();
  void ConnectUpQt();
  void DisconnectUpQt();
  void AddClientQt();
  void DeleteClientQt();

  void ConnectUp(nsMMOEngine::TEventConnectUp* pBE);
  void DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE);

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);

  void SaveContextClient(nsMMOEngine::TEventSaveContext* pEvent);
  void RestoreContextClient(nsMMOEngine::TEventRestoreContext* pEvent);
};

#endif
