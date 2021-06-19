///*
//Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
//Гудаков Рамиль Сергеевич 
//Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
//See for more information LICENSE.md.
//*/
//
//#include "StatusBar.h"
//
//#include <Precompiled.h>
//#include <OgreRenderWindow.h>
//
//#include "ModuleLogic.h"
//#include "Components.h"
//#include "ModuleGraphicEngine.h"
//
//TStatusBar* g_StatusBar = NULL;
//
//TStatusBar::TStatusBar() 
//{
//  g_StatusBar = this;
//
//  mTextView = nullptr;
//  mBClear   = nullptr;
//}
////------------------------------------------------------
//TStatusBar::~TStatusBar()
//{
//
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::Activate()
//{
//  assignWidget(mTextView, "TextView");
//  assignWidget(mBClear,   "bClear");
//
//  mBClear->eventMouseButtonClick += MyGUI::newDelegate(this, &TStatusBar::sl_Clear);
//  
//  ResizeWindowEvent();
//}
////-------------------------------------------------------------------------------------
//const char* TStatusBar::GetNameLayout()
//{
//  return "StatusBar.layout";
//}
////-------------------------------------------------------------------------------------
//void* TStatusBar::GetParent()
//{
//  return nullptr;
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::SetupTabChild()
//{
//
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
//{
//  switch(_key.getValue())
//  {
//    case MyGUI::KeyCode::Escape:
//      TModuleLogic::Get()->Exit();
//      break;
//    default:;
//  }
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::AddText(std::string text, bool appendLineFolding)
//{
//  MyGUI::UString ustr;
//  if( appendLineFolding )
//    ustr = text + "\n";
//  else
//    ustr = text;
//
//  mTextView->addText(ustr);
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::ClearText()
//{
//  size_t len = mTextView->getTextLength();
//  mTextView->eraseText(0, len);
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::ResizeWindowEvent()
//{
//  Ogre::RenderWindow* pRW = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetWindow();
//
//  unsigned int width;
//  unsigned int height; 
//  unsigned int colourDepth; 
//  int left;
//  int top;
//  pRW->getMetrics(width, height, colourDepth, left, top);
//
//  int widthWidget  = mMainWidget->getWidth();
//  int heightWidget = mMainWidget->getHeight();
//
//  mMainWidget->setPosition(0, height - heightWidget);
//}
////-------------------------------------------------------------------------------------
//void TStatusBar::sl_Clear(MyGUI::Widget* _sender)
//{
//  ClearText();
//}
////-------------------------------------------------------------------------------------
