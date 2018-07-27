/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ModuleLogic.h"
#include "InputCmdDevTool.h"

#include "GP_AggregationScenario_GameMap.h"
#include "Scene.h"

class DllExport TModuleClientLogic : public TModuleLogic
{
protected:
  TInputCmdDevTool                                   mInputCmd;

  std::shared_ptr<TGP_AggregationScenario_GameMap> mAggregationScenario_Client;

  std::shared_ptr<TScene>                          mScene;

public:
  TModuleClientLogic();

  virtual bool WorkInherit();
  virtual void ParseCmd(std::vector<std::string>& arg);
protected:
  virtual bool WorkClient() = 0;
};
