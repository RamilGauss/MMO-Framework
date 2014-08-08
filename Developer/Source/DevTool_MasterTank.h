/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_MasterTankH
#define DevTool_MasterTankH

#include "DevTool_Server.h"
#include "PrototypeMMOBaseEvent.h"
#include "PrototypeMMOEvents.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"
#include <list>

class MasterForm;

class TDevTool_MasterTank : public TDevTool_Server
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;

  unsigned int mCounterClient;

  MasterForm* mMasterForm;

  TInputCmdDevTool mInputCmd;

	typedef std::list<unsigned int> TListUint;
	TListUint mListKeyAllClient;

public:
  TDevTool_MasterTank();
  virtual ~TDevTool_MasterTank();

  virtual void Init(std::vector<std::string>& arg);
  virtual void Done();
  virtual void Event(nsEvent::TEvent* pEvent);
protected:
  virtual int GetIDPrototypeMMOEngineServer(){return PROTOTYPE_TYPE_MMO_ENGINE_MASTER;}
protected:
  void ParseCmd(std::vector<std::string>& arg);

  void InitLog();
  void HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE);
  void HandleFromQt(nsEvent::TEvent* pEvent);

  void InitQtForm();
  void ConnectUpQt();
  void DisconnectUpQt();
  void AddSlaveQt();
  void DeleteSlaveQt();

  void CreateGroup();

  void TryLogin(PrototypeMMOEventTryLogin* pEvent);
  void ConnectDown(PrototypeMMOEventConnectDown* pEvent);
  void DisconnectDown(PrototypeMMOEventDisconnectDown* pEvent);

  void ConnectUp(PrototypeMMOEventConnectUp* pBE);
  void DisconnectUp(PrototypeMMOEventDisconnectUp* pBE);
};

#endif
