///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
//Гудаков Рамиль Сергеевич 
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#include "PlateVarGeomParam.h"
//
//TPlateVarGeomParam::TPlateVarGeomParam()
//{
//
//}
////---------------------------------------------------------------------------------------------
//TPlateVarGeomParam::~TPlateVarGeomParam()
//{
//
//}
////---------------------------------------------------------------------------------------------
//void TPlateVarGeomParam::Activate()
//{
//  assignWidget(ebThickness, "ebThickness"); 
//  assignWidget(ebWidth,     "ebWidth");
//  assignWidget(ebLength,    "ebLength");
//  assignWidget(ibGeom,      "ibGeom");
//  assignWidget(bApply,      "bApply");
//  assignWidget(bClose,      "bClose");
//
//  bApply->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlateVarGeomParam::sl_Apply);
//  bClose->eventMouseButtonClick += MyGUI::newDelegate(this, &TPlateVarGeomParam::sl_Close);
//}
////---------------------------------------------------------------------------------------------
//void* TPlateVarGeomParam::GetParent()
//{
//  return nullptr;
//}
////---------------------------------------------------------------------------------------------
//const char* TPlateVarGeomParam::GetNameLayout()
//{
//  return "PlastinaVarGeomParam.layout";
//}
////---------------------------------------------------------------------------------------------
//void TPlateVarGeomParam::SetupTabChild()
//{
//  mVectorChild_Tab.push_back(ebThickness);
//  mVectorChild_Tab.push_back(ebWidth);
//  mVectorChild_Tab.push_back(ebLength);
//  mVectorChild_Tab.push_back(bApply);
//}
////---------------------------------------------------------------------------------------------
//void TPlateVarGeomParam::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
//{
//  switch(_key.getValue())
//  {
//    case MyGUI::KeyCode::Return:
//      //sl_Enter(_sender);
//      break;
//    default:;
//  }
//}
////---------------------------------------------------------------------------------------------
//void TPlateVarGeomParam::sl_Apply(MyGUI::Widget* _sender)
//{
//
//}
////---------------------------------------------------------------------------------------------
//void TPlateVarGeomParam::sl_Close(MyGUI::Widget* _sender)
//{
//  Hide();
//}
////---------------------------------------------------------------------------------------------
