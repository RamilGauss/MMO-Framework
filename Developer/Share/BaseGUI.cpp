/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "BaseGUI.h"
#include "MyGUI_DeprecatedTypes.h"

void TBaseGUI::Show()
{
  if(mMainWidget==nullptr)
  {
    initialise(GetNameLayout(), (MyGUI::Widget*)GetParent());
    Activate();
    InitTabJump();// научить окно прыгать по табуляции между детьми
    RegisterOnKeyEvent();
  }

  mMainWidget->setVisible(true);
}
//--------------------------------------------------------------
void TBaseGUI::Hide()
{
  mMainWidget->setVisible(false);
}
//--------------------------------------------------------------
void TBaseGUI::InitTabJump()
{
  mVectorChild_Tab.clear();
  SetupTabChild();
  int cnt = mVectorChild_Tab.size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    MyGUI::Widget* pChild = mVectorChild_Tab.at(i);
    pChild->eventKeyButtonPressed += MyGUI::newDelegate(this,&TBaseGUI::sl_TabJump);
  }
}
//--------------------------------------------------------------
void TBaseGUI::sl_TabJump(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  if(mVectorChild_Tab.size()==0) return;
  if(_key!=MyGUI::KeyCode::Tab) return;

  MyGUI::VectorWidgetPtr::iterator fit = 
    std::find(mVectorChild_Tab.begin(),mVectorChild_Tab.end(),_sender);

  if(mVectorChild_Tab.end()!=fit)
  {
    int curFocus = fit-mVectorChild_Tab.begin();
    curFocus++;
    int nextFocus = curFocus >= (int)mVectorChild_Tab.size() ?  0 : curFocus;
    MyGUI::Widget* pChild = mVectorChild_Tab.at(nextFocus);
    MyGUI::InputManager::getInstance().setKeyFocusWidget(pChild);
  }
}
//--------------------------------------------------------------
void TBaseGUI::RegisterOnKeyEvent()
{
  mMainWidget->eventKeyButtonPressed += MyGUI::newDelegate(this,&TBaseGUI::sl_KeyEvent);
  int cnt = mMainWidget->getChildCount();
  for(int i = 0 ; i < cnt ; i++ )
  {
    MyGUI::Widget* pChild = mMainWidget->getChildAt(i);
    pChild->eventKeyButtonPressed += MyGUI::newDelegate(this,&TBaseGUI::sl_KeyEvent);
  }
}
//--------------------------------------------------------------
void TBaseGUI::sl_KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  KeyEvent(_sender, _key, _char);
}
//--------------------------------------------------------------
void TBaseGUI::Shutdown()
{
  shutdown();
}
//--------------------------------------------------------------
