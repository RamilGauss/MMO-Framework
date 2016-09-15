/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMap.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "ListModules.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "LogicEventCallBack.h"
#include "EditorMapLogic.h"

#include <OgreManualObject.h>

TEditorMap::TEditorMap() 
{
  mBar                       = nullptr;
  mPopupMenu_File            = nullptr;
  mPopupMenu_NewShape        = nullptr;
  mPopupMenu_Instruments     = nullptr;
  miOpen                     = nullptr;
  miSave                     = nullptr;
  miExit                     = nullptr;
}
//------------------------------------------------------
TEditorMap::~TEditorMap()
{

}
//-------------------------------------------------------------------------------------
void TEditorMap::Activate()
{
  assignWidget(mBar, "Menu");
  // меню для виджетов
  mPopupMenu_File = mBar->findItemById("File", true)->getItemChild();
  //mPopupMenu_File->eventMenuCtrlAccept += MyGUI::newDelegate(this, &TEditorShape::sl_WidgetsSelect);

  miOpen = mPopupMenu_File->findItemById("Command_FileOpen");
  miSave = mPopupMenu_File->findItemById("Command_FileSave");
  miExit = mPopupMenu_File->findItemById("Command_FileExit");

  miOpen->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Open);
  miExit->eventMouseButtonClick += MyGUI::newDelegate(this, &TEditorMap::sl_Exit);
}
//-------------------------------------------------------------------------------------
const char* TEditorMap::GetNameLayout()
{
  return "EditorMap.layout";
}
//-------------------------------------------------------------------------------------
void* TEditorMap::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TEditorMap::SetupTabChild()
{

}
//-------------------------------------------------------------------------------------
void TEditorMap::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
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
void TEditorMap::sl_Open(MyGUI::Widget* _sender)
{
  std::string nameMap = "Field";
  TModuleLogic::Get()->AddEventCopy(nsListModules::FromSomeToLogic, 
    (void*)nameMap.data(), nameMap.length() );
}
//-------------------------------------------------------------------------------------
void TEditorMap::sl_Exit(MyGUI::Widget* _sender)
{
  TModuleLogic::Get()->Exit();
}
//-------------------------------------------------------------------------------------
