/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GameRoomPrepareH
#define GameRoomPrepareH

#include "BaseGUI.h"
#include <MyGUI.h>

class TGameRoomPrepare :
  public TBaseGUI
{

public:
  TGameRoomPrepare();
  virtual ~TGameRoomPrepare();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:

  void sl_Fight(MyGUI::Widget* _sender);
  void sl_Exit(MyGUI::Widget* _sender);

  MyGUI::Button* bFight;
  MyGUI::Button* bExit;

  //MyGUI::EditBox* ebIP;
  //MyGUI::EditBox* ebPort; 
  //MyGUI::EditBox* ebLogin;

};

#endif 
