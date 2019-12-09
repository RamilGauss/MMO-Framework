/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EditorTableSound.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "ModuleLogic.h"
#include "ListModules.h"
#include "LogicEventCallBack.h"
#include "ModuleGraphicEngine.h"

#include <OgreManualObject.h>

TEditorTableSound::TEditorTableSound() 
{

}
//------------------------------------------------------
TEditorTableSound::~TEditorTableSound()
{

}
//-------------------------------------------------------------------------------------
void TEditorTableSound::Activate()
{

}
//-------------------------------------------------------------------------------------
const char* TEditorTableSound::GetNameLayout()
{
  return "EditorTableSound.layout";
}
//-------------------------------------------------------------------------------------
void* TEditorTableSound::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TEditorTableSound::SetupTabChild()
{

}
//-------------------------------------------------------------------------------------
void TEditorTableSound::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
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
