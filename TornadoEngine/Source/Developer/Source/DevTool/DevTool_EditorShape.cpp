/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_EditorShape.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorShapeLogic.h"

using namespace nsListModules;

TDevTool_EditorShape::TDevTool_EditorShape()
{

}
//-------------------------------------------------------------
TDevTool_EditorShape::~TDevTool_EditorShape()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorShape::GetVariantConveyer()
{
  return "EditorShape";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorShape::GetModuleByID(int id)
{
  TModuleDev* pModule = NULL;
  switch(id)
  {
    case ClientLogic: 
      pModule = new TEditorShapeLogic; break;
    default: pModule = TDevTool_Share::GetModuleByID(id);
  }
  return pModule;
}
//-----------------------------------------------------------------------

