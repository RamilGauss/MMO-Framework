///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss
//Гудаков Рамиль Сергеевич
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#include "DebugPanel.h"
//
//TDebugPanel::TDebugPanel()
//{
//
//}
////------------------------------------------------------
//TDebugPanel::~TDebugPanel()
//{
//
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::Activate()
//{
//    assignWidget(lFPS, "lFPS");
//    assignWidget(lX, "lX");
//    assignWidget(lY, "lY");
//    assignWidget(lZ, "lZ");
//}
////-------------------------------------------------------------------------------------
//const char* TDebugPanel::GetNameLayout()
//{
//    return "DebugPanel.layout";
//}
////-------------------------------------------------------------------------------------
//void* TDebugPanel::GetParent()
//{
//    return nullptr;
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::SetupTabChild()
//{
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
//{
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::SetFPS(float fps)
//{
//    char s[100];
//    sprintf(s, "%d fps", int(fps));
//    lFPS->setCaption(s);
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::SetX(float v)
//{
//    char s[100];
//    sprintf(s, "%f", v);
//    lX->setCaption(s);
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::SetY(float v)
//{
//    char s[100];
//    sprintf(s, "%f", v);
//    lY->setCaption(s);
//}
////-------------------------------------------------------------------------------------
//void TDebugPanel::SetZ(float v)
//{
//    char s[100];
//    sprintf(s, "%f", v);
//    lZ->setCaption(s);
//}
////-------------------------------------------------------------------------------------
