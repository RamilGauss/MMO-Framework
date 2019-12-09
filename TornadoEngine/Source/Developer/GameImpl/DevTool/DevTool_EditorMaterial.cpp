/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DevTool_EditorMaterial.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorMaterialLogic.h"

using namespace nsListModules;

TDevTool_EditorMaterial::TDevTool_EditorMaterial()
{

}
//-------------------------------------------------------------
TDevTool_EditorMaterial::~TDevTool_EditorMaterial()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorMaterial::GetVariantConveyer()
{
  return "EditorMaterial";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorMaterial::GetModuleLogic()
{
  return new TEditorMaterialLogic;
}
//-----------------------------------------------------------------------

