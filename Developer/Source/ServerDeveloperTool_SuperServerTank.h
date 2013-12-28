/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ServerDeveloperTool_SuperServerTankH
#define ServerDeveloperTool_SuperServerTankH

#include "../GameLib/IServerDeveloperTool.h"
#include "BaseEvent.h"
#include "Events.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"

class SuperServerForm;

class TServerDeveloperTool_SuperServerTank : public IServerDeveloperTool
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;
  
  TInputCmdDevTool mInputCmd;

  SuperServerForm* mSuperServerForm;
public:
  TServerDeveloperTool_SuperServerTank();
  virtual ~TServerDeveloperTool_SuperServerTank();

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
  void AddMasterQt();
  void DeleteMasterQt();

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);
};

#endif
