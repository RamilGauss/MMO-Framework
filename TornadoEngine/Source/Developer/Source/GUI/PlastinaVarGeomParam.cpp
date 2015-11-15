/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PlastinaVarGeomParam.h"

TPlastinaVarGeomParam::TPlastinaVarGeomParam()
{

}
//---------------------------------------------------------------------------------------------
TPlastinaVarGeomParam::~TPlastinaVarGeomParam()
{

}
//---------------------------------------------------------------------------------------------
void TPlastinaVarGeomParam::Activate()
{
  assignWidget(ebThickness, "ebThickness"); 
  assignWidget(ebWidth,     "ebWidth");
  assignWidget(ebLength,    "ebLength");
  assignWidget(ibGeom,      "ibGeom");
  assignWidget(bApply,      "bApply");
  assignWidget(bClose,      "bClose");

  bApply->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlastinaVarGeomParam::sl_Apply);
  bClose->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlastinaVarGeomParam::sl_Close);
}
//---------------------------------------------------------------------------------------------
void* TPlastinaVarGeomParam::GetParent()
{
  return nullptr;
}
//---------------------------------------------------------------------------------------------
const char* TPlastinaVarGeomParam::GetNameLayout()
{
  return "PlastinaVarGeomParam.layout";
}
//---------------------------------------------------------------------------------------------
void TPlastinaVarGeomParam::SetupTabChild()
{
  mVectorChild_Tab.push_back(ebThickness);
  mVectorChild_Tab.push_back(ebWidth);
  mVectorChild_Tab.push_back(ebLength);
  mVectorChild_Tab.push_back(bApply);
}
//---------------------------------------------------------------------------------------------
void TPlastinaVarGeomParam::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
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
void TPlastinaVarGeomParam::sl_Apply(MyGUI::Widget* _sender)
{

}
//---------------------------------------------------------------------------------------------
void TPlastinaVarGeomParam::sl_Close(MyGUI::Widget* _sender)
{
  Hide();
}
//---------------------------------------------------------------------------------------------
