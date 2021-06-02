/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "GraphicEngine/BaseGUI.h"
#include <MyGUI.h>

class TStatusBar : public TBaseGUI
{
public:
  TStatusBar();
  virtual ~TStatusBar();

  void AddText( std::string text, bool appendLineFolding = true );
  void ClearText();

  void ResizeWindowEvent();
protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent( MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char );

protected:
  void sl_Clear( MyGUI::Widget* _sender );
protected:
  MyGUI::EditBox* mTextView;
  MyGUI::Button*  mBClear;
};

extern DllExport TStatusBar* g_StatusBar;

