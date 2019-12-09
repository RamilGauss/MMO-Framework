/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#ifndef INPUT_MANAGER_OIS_H
#define INPUT_MANAGER_OIS_H

#include <MyGUI.h>
#include <OIS.h>

class TInputManagerOIS : public OIS::MouseListener, public OIS::KeyListener
{
public:
  TInputManagerOIS();
  virtual ~TInputManagerOIS();

  void CreateInput(size_t _handle);
  void DestroyInput();
  void CaptureInput();
  void SetInputViewSize(int _width, int _height);

  void SetMousePosition(int _x, int _y);


  static std::string ConvertKey2Str(const OIS::KeyCode key);

protected:
  void CheckPosition();

  void ConvertOIS2MyGUI(const OIS::KeyEvent &arg, MyGUI::Char& text, MyGUI::KeyCode& key );

private:
  OIS::InputManager* mInputManager;
  OIS::Keyboard* mKeyboard;
  OIS::Mouse* mMouse;

  int mCursorX;
  int mCursorY;
};

#endif 
