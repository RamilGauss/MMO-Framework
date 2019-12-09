/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DevTool_EditorTableSound.h"
#include "ModuleDev.h"
#include "ListModules.h"

#include "EditorTableSoundLogic.h"

using namespace nsListModules;

TDevTool_EditorTableSound::TDevTool_EditorTableSound()
{

}
//-------------------------------------------------------------
TDevTool_EditorTableSound::~TDevTool_EditorTableSound()
{

}
//-------------------------------------------------------------
std::string TDevTool_EditorTableSound::GetVariantConveyer()
{
  return "EditorTableSound";
}
//-------------------------------------------------------------
TModuleDev* TDevTool_EditorTableSound::GetModuleLogic()
{
  return new TEditorTableSoundLogic;
}
//-----------------------------------------------------------------------
