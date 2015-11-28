/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMap.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "ModuleLogic.h"
#include "ListModules.h"
#include "LogicEventCallBack.h"
#include "ModuleGraphicEngine.h"

#include <OgreManualObject.h>

TEditorMap::TEditorMap() 
{

}
//------------------------------------------------------
TEditorMap::~TEditorMap()
{

}
//-------------------------------------------------------------------------------------
void TEditorMap::Activate()
{

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
