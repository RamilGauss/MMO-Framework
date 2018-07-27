/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleClientLogic.h"

TModuleClientLogic::TModuleClientLogic()
{
  mAggregationScenario_Client.reset( new TGP_AggregationScenario_GameMap );
  mScene.reset( new TScene );
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
void TModuleClientLogic::ParseCmd( std::vector<std::string>& arg )
{
  mInputCmd.Init();
  mInputCmd.SetArg( arg );
}
//------------------------------------------------------------------------