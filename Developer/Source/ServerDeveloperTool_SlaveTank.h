/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ServerDeveloperTool_SlaveTankH
#define ServerDeveloperTool_SlaveTankH

#include "../GameLib/IServerDeveloperTool.h"
#include "BaseEvent.h"
#include "InputCmdDevTool.h"
#include "Events.h"
#include "TestControlTank.h"

class SlaveForm;

class TServerDeveloperTool_SlaveTank : public IServerDeveloperTool
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;

  SlaveForm* mSlaveForm;

  TInputCmdDevTool mInputCmd;

	TTestControlTank mTestControlTank;
public:
  TServerDeveloperTool_SlaveTank();
  virtual ~TServerDeveloperTool_SlaveTank();

	virtual void Init(TComponentServer* pComponent, std::vector<std::string>& arg);
	virtual int GetTimeRefreshMS();

	virtual void Done();
	virtual void Event(nsEvent::TEvent* pEvent);

	virtual IMakerObjectGeneral* GetMakerObjectGeneral();
	virtual std::string GetPathXMLFile();

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
