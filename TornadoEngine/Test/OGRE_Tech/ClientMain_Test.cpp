/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientMain_Test.h"

TClientMain_Test::TClientMain_Test()
{

}
//------------------------------------------------------
TClientMain_Test::~TClientMain_Test()
{

}
//-------------------------------------------------------------------------------------
void TClientMain_Test::Activate()
{
  assignWidget(bEnter,"bEnter");
  assignWidget(bExit, "bExit");

  assignWidget(ebIP,    "ebIP");
  assignWidget(ebPort,  "ebPort");
  assignWidget(ebLogin, "ebLogin");

	assignWidget(lIP, "lIP");

  bEnter->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain_Test::sl_Enter);
  bExit ->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain_Test::sl_Exit);
}
//-------------------------------------------------------------------------------------
void TClientMain_Test::sl_Enter(MyGUI::Widget* _sender)
{

}
//-------------------------------------------------------------------------------------
void TClientMain_Test::sl_Exit(MyGUI::Widget* _sender)
{

}
//-------------------------------------------------------------------------------------
const char* TClientMain_Test::GetNameLayout()
{
  return "ClientMain.layout";
}
//-------------------------------------------------------------------------------------
void* TClientMain_Test::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TClientMain_Test::SetupTabChild()
{
  mVectorChild_Tab.push_back(ebIP);
  mVectorChild_Tab.push_back(ebLogin);
  mVectorChild_Tab.push_back(ebPort);
}
//-------------------------------------------------------------------------------------
void TClientMain_Test::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
    case MyGUI::KeyCode::Return:
      sl_Enter(_sender);
      break;
    default:;
  }
}
//-------------------------------------------------------------------------------------
void TClientMain_Test::SetFPS(float fps)
{
	char s[100];
	sprintf(s, "%3f", fps);
	lIP->setCaption(s);
}
//-------------------------------------------------------------------------------------
