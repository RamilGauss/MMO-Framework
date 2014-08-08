/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ClientTankH
#define DevTool_ClientTankH

#include "DevTool_Client.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "ClientMain.h"
#include "GameRoomPrepare.h"
#include "WaitForm.h"
#include "PrototypeMMOBaseEvent.h"
#include "InputCmdDevTool.h"
#include "TestControlTank.h"
#include "DevProtocol.h"

class TClientMain;
class TGameRoomPrepare;
class TWaitForm;
class TBaseGUI;

class TDevTool_ClientTank : public TDevTool_Client
{
  TInputCmdDevTool mInputCmd;

  TBaseGUI*         mCurrentForm;

  TClientMain*      mClientMain;
  TGameRoomPrepare* mGameRoomPrepare;
  TWaitForm*        mWaitForm;

  bool flgDragCamera;
  int mOldX;
  int mOldY;

  unsigned int mIDkey;

  int mIndexCurObj;

  IBaseObjectGeneral* mTank;
  IBaseObjectGeneral* mHangar;

	// показать магию
	TTestControlTank mTestControlTank;

public:
  TDevTool_ClientTank ();
  virtual ~TDevTool_ClientTank ();
  
  virtual void Init(std::vector<std::string>& arg);

  virtual void Done();
  virtual void Event(nsEvent::TEvent* pEvent);
protected:
  void ParseCmd(std::vector<std::string>& arg);

  void InitLog();
  void HandleFromMMOEngine(PrototypeMMOBaseEvent* pBE);
  void HandleFromGUI(nsEvent::TBaseEvent* pData);
  void HandleFromDev(nsDevProtocol::TBase* pData);

	void MouseEvent(nsEvent::TMouseEvent* pEvent);
	void KeyEvent(nsEvent::TKeyEvent* pEvent);

protected:
  void SetCurrentForm(TBaseGUI* mGameRoomPrepare);
protected:
  void Connect(PrototypeMMOBaseEvent* pBE);
  void ConnectUp();
  void DisconnectUp();
protected:
  void CreateObjects();
  void CreateHangar();
  void CreateTank();

  virtual std::string GetTitleWindow(){return "Клиент танков";}
};

#endif
