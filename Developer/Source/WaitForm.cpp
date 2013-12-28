/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WaitForm.h"

#include "Precompiled.h"
#include <atlconv.h>


TWaitForm::TWaitForm()
{

}
//------------------------------------------------------
TWaitForm::~TWaitForm()
{

}
//-------------------------------------------------------------------------------------
void TWaitForm::Activate()
{
  //assignWidget(bEnter,"bEnter");
  //assignWidget(bExit, "bExit");

  //assignWidget(ebIP,    "ebIP");
  //assignWidget(ebPort,  "ebPort");
  //assignWidget(ebLogin, "ebLogin");

  //bEnter->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain::sl_Enter);
  //bExit ->eventMouseButtonClick += MyGUI::newDelegate(this, &TClientMain::sl_Exit);
}
//-------------------------------------------------------------------------------------
//void TClientMain::sl_Enter(MyGUI::Widget* _sender)
//{
//
//}
////-------------------------------------------------------------------------------------
//void TClientMain::sl_Exit(MyGUI::Widget* _sender)
//{
//  Close();
//}
//-------------------------------------------------------------------------------------
//void TClientMain::sl_IP(MyGUI::EditBox* _sender)
//{
//  USES_CONVERSION;
//  std::string sA = W2A((LPCWSTR)_sender->getOnlyText().data());
//  int a = 0;
//}
//-------------------------------------------------------------------------------------
const char* TWaitForm::GetNameLayout()
{
  return "WaitForm.layout";
}
//-------------------------------------------------------------------------------------
void* TWaitForm::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TWaitForm::SetupTabChild()
{
  //mVectorChild_Tab.push_back(ebIP);
  //mVectorChild_Tab.push_back(ebLogin);
  //mVectorChild_Tab.push_back(ebPort);
}
//-------------------------------------------------------------------------------------
void TWaitForm::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
  case MyGUI::KeyCode::Return:
    //sl_Enter(_sender);
    break;
  default:;
  }
}
//-------------------------------------------------------------------------------------
