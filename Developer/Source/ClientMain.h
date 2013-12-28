/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ClientMainH
#define ClientMainH

#include "BaseGUI.h"
#include <MyGUI.h>

class TClientMain :
  public TBaseGUI
{
  bool IsOpen;
public:
  TClientMain();
  virtual ~TClientMain();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:

  void sl_Enter(MyGUI::Widget* _sender);
  void sl_Exit(MyGUI::Widget* _sender);

  MyGUI::Button* bEnter;
  MyGUI::Button* bExit;

  MyGUI::EditBox* ebIP;
  MyGUI::EditBox* ebPort; 
  MyGUI::EditBox* ebLogin;
private:
  void SaveInputParam(unsigned int ip, unsigned int port, const char* sLogin);
  void LoadInputParam();

};

#endif 
