/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DevTool_EditorTerrain.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorTerrainLogic.h"

using namespace nsListModules;

TDevTool_EditorTerrain::TDevTool_EditorTerrain()
{

}
//-------------------------------------------------------------
TDevTool_EditorTerrain::~TDevTool_EditorTerrain()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorTerrain::GetVariantConveyer()
{
  return "EditorTerrain";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorTerrain::GetModuleLogic()
{
  return new TEditorTerrainLogic;
}
//-----------------------------------------------------------------------

