/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleClientLogic.h"

bool TModuleClientLogic::Work()
{
  InputFromSynchroPoint();
  bool resWork = WorkClient();
  resWork &= !NeedExit();
  return resWork;
}
//----------------------------------------------------------------
void TModuleClientLogic::ParseCmd(std::vector<std::string>& arg)
{
  mInputCmd.SetArg(arg);
}
//------------------------------------------------------------------------