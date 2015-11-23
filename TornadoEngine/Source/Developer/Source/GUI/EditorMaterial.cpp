/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorMaterial.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "ModuleLogic.h"
#include "ListModules.h"
#include "LogicEventCallBack.h"
#include "ModuleGraphicEngine.h"

#include <OgreManualObject.h>


TEditorMaterial::TEditorMaterial() 
{

}
//------------------------------------------------------
TEditorMaterial::~TEditorMaterial()
{

}
//-------------------------------------------------------------------------------------
void TEditorMaterial::Activate()
{

}
//-------------------------------------------------------------------------------------
const char* TEditorMaterial::GetNameLayout()
{
  return "EditorMaterial.layout";
}
//-------------------------------------------------------------------------------------
void* TEditorMaterial::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TEditorMaterial::SetupTabChild()
{

}
//-------------------------------------------------------------------------------------
void TEditorMaterial::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
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
