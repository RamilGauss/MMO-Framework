/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_EditorMap.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorMapLogic.h"

using namespace nsListModules;

TDevTool_EditorMap::TDevTool_EditorMap()
{

}
//-------------------------------------------------------------
TDevTool_EditorMap::~TDevTool_EditorMap()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorMap::GetVariantConveyer()
{
  return "EditorMap";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorMap::GetModuleLogic()
{
  return new TEditorMapLogic;
}
//-----------------------------------------------------------------------
