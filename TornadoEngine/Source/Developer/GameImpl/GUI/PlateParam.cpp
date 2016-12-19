/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PlateParam.h"

TPlateParam::TPlateParam()
{

}
//---------------------------------------------------------------------------------------------
TPlateParam::~TPlateParam()
{

}
//---------------------------------------------------------------------------------------------
void TPlateParam::Activate()
{
  assignWidget(bApply,   "bApply");
  assignWidget(bClose,   "bClose");
  assignWidget(ebWidth,  "ebWidth");
  assignWidget(ebHeight, "ebHeight"); 
  assignWidget(ebLength, "ebLength");

  bApply->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlateParam::sl_Apply);
  bClose->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlateParam::sl_Close);
}
//---------------------------------------------------------------------------------------------
void* TPlateParam::GetParent()
{
  return nullptr;
}
//---------------------------------------------------------------------------------------------
const char* TPlateParam::GetNameLayout()
{
  return "PlastinaParam.layout";
}
//---------------------------------------------------------------------------------------------
void TPlateParam::SetupTabChild()
{
  mVectorChild_Tab.push_back(ebWidth);
  mVectorChild_Tab.push_back(ebHeight);
  mVectorChild_Tab.push_back(ebLength);
  mVectorChild_Tab.push_back(bApply);
  mVectorChild_Tab.push_back(bClose);
}
//---------------------------------------------------------------------------------------------
void TPlateParam::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
    case MyGUI::KeyCode::Return:
      //sl_Enter(_sender);
      break;
    default:;
  }
}
//---------------------------------------------------------------------------------------------
void TPlateParam::sl_Apply(MyGUI::Widget* _sender)
{

}
//---------------------------------------------------------------------------------------------
void TPlateParam::sl_Close(MyGUI::Widget* _sender)
{
  Hide();
}
//---------------------------------------------------------------------------------------------
