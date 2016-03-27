/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleClientLogic.h"

TModuleClientLogic::TModuleClientLogic()
{
  TPreBuilder::TVectorTypeTask vecType;
  vecType.push_back(TPreBuilder::eOgre);
  vecType.push_back(TPreBuilder::eBullet);
  vecType.push_back(TPreBuilder::eOpenAL);

  mMGM.GetBGM()->Init(vecType, &mFGI);
}
//----------------------------------------------------------------
bool TModuleClientLogic::WorkInherit()
{
  InputFromSynchroPoint();
  bool res = WorkClient();
  res &= !NeedExit();
  return res;
}
//----------------------------------------------------------------
void TModuleClientLogic::ParseCmd(std::vector<std::string>& arg)
{
  mInputCmd.SetArg(arg);
}
//------------------------------------------------------------------------