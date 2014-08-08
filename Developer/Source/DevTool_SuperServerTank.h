/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_SuperServerTankH
#define DevTool_SuperServerTankH

#include "DevTool_Server.h"
#include "PrototypeMMOBaseEvent.h"
#include "PrototypeMMOEvents.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"

class SuperServerForm;

class TDevTool_SuperServerTank : public TDevTool_Server
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;
  
  TInputCmdDevTool mInputCmd;

  SuperServerForm* mSuperServerForm;
public:
  TDevTool_SuperServerTank();
  virtual ~TDevTool_SuperServerTank();

	virtual void Init(std::vector<std::string>& arg);
	virtual void Done();
	virtual void Event(nsEvent::TEvent* pEvent);
protected:
  virtual int GetIDPrototypeMMOEngineServer(){return PROTOTYPE_TYPE_MMO_ENGINE_SUPER_SERVER;}
protected:
  void ParseCmd(std::vector<std::string>& arg);
  
  void InitLog();

  void HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE);
  void HandleFromQt(nsEvent::TEvent* pEvent);

  void InitQtForm();
  void AddMasterQt();
  void DeleteMasterQt();

  void ConnectDown(PrototypeMMOEventConnectDown* pEvent);
  void DisconnectDown(PrototypeMMOEventDisconnectDown* pEvent);
};

#endif
