/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ServerDeveloperTool_MasterTankH
#define ServerDeveloperTool_MasterTankH

#include "../GameLib/IServerDeveloperTool.h"
#include "BaseEvent.h"
#include "Events.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"
#include <list>

class MasterForm;

class TServerDeveloperTool_MasterTank : public IServerDeveloperTool
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;

  unsigned int mCounterClient;

  MasterForm* mMasterForm;

  TInputCmdDevTool mInputCmd;

	typedef std::list<unsigned int> TListUint;
	TListUint mListKeyAllClient;

public:
  TServerDeveloperTool_MasterTank();
  virtual ~TServerDeveloperTool_MasterTank();

	virtual void Init(TComponentServer* pComponent, std::vector<std::string>& arg);
	virtual int GetTimeRefreshMS();

	virtual void Done();
	virtual void Event(nsEvent::TEvent* pEvent);

	virtual IMakerObjectCommon* GetMakerObjectCommon();
	virtual std::string GetPathXMLFile();

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
