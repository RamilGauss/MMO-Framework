/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogic.h"

TModuleServerLogic::TModuleServerLogic()
{

}
//----------------------------------------------------------------
TModuleServerLogic::~TModuleServerLogic()
{

}
//----------------------------------------------------------------
bool TModuleServerLogic::Work()
{
  // чистая логика принятия решений
  InputFromModules();
  OutputFromModules();
  return true;
}
//----------------------------------------------------------------
void TModuleServerLogic::StartEvent()
{

}
//----------------------------------------------------------------
void TModuleServerLogic::StopEvent()
{

}
//----------------------------------------------------------------
