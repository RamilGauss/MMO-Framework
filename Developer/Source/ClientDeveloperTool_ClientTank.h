/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ClientDeveloperTool_ClientTankH
#define ClientDeveloperTool_ClientTankH

#include "../GameLib/IClientDeveloperTool.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "ClientMain.h"
#include "GameRoomPrepare.h"
#include "WaitForm.h"
#include "../MMOEngine/Include/BaseEvent.h"
#include "InputCmdDevTool.h"
#include "TestControlTank.h"
#include "DevProtocol.h"

class TClientMain;
class TGameRoomPrepare;
class TWaitForm;
class TBaseGUI;


class TClientDeveloperTool_ClientTank : public IClientDeveloperTool
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

  IBaseObjectCommon* mTank;
  IBaseObjectCommon* mHangar;

	// показать магию
	TTestControlTank mTestControlTank;

public:
  TClientDeveloperTool_ClientTank ();
  virtual ~TClientDeveloperTool_ClientTank ();

  virtual void Init(TComponentClient* pComponent, std::vector<std::string>& arg);

  virtual std::string GetTitleWindow();
  
	virtual void Event(nsEvent::TEvent* pEvent);
  virtual void Done();
  
	virtual IMakerObjectCommon* GetMakerObjectCommon();
  virtual std::string GetPathXMLFile();

protected:
  void ParseCmd(std::vector<std::string>& arg);

  void InitLog();
  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);
  void HandleFromGUI(nsEvent::TBaseEvent* pData);
  void HandleFromDev(nsDevProtocol::TBase* pData);

	void MouseEvent(nsEvent::TMouseEvent* pEvent);
	void KeyEvent(nsEvent::TKeyEvent* pEvent);

protected:
  void SetCurrentForm(TBaseGUI* mGameRoomPrepare);
protected:
  void Connect(nsMMOEngine::TBaseEvent* pBE);
  void ConnectUp();
  void DisconnectUp();
protected:
  void CreateObjects();
  void CreateHangar();
  void CreateTank();

};

#endif
