/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "GraphicEngine/BaseGUI.h"
#include <MyGUI.h>

class TDebugPanel : public TBaseGUI
{
public:
  TDebugPanel();
  virtual ~TDebugPanel();

  void SetFPS( float fps );
  void SetX( float v );
  void SetY( float v );
  void SetZ( float v );
protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent( MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char );
protected:
  MyGUI::TextBox* lFPS;

  MyGUI::TextBox* lX;
  MyGUI::TextBox* lY;
  MyGUI::TextBox* lZ;
};
