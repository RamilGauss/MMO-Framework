/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IModule.h"

bool IModule::Work()
{
  bool res = WorkInherit();
  return res;
}
//--------------------------------------------------------------------------------------
bool IModule::WorkInherit()
{
  return true;
}
//--------------------------------------------------------------------------------------
