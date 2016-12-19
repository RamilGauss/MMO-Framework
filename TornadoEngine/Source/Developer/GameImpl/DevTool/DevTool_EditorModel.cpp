/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_EditorModel.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorModelLogic.h"

using namespace nsListModules;

TDevTool_EditorModel::TDevTool_EditorModel()
{

}
//-------------------------------------------------------------
TDevTool_EditorModel::~TDevTool_EditorModel()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorModel::GetVariantConveyer()
{
  return "EditorModel";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorModel::GetModuleLogic()
{
  return new TEditorModelLogic;
}
//-----------------------------------------------------------------------
