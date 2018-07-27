/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ModuleComponent.h"
#include "PhysicEngine_Bullet.h"

class DllExport TModulePhysicEngine : public TModuleComponent
{
  std::shared_ptr<TPhysicEngine_Bullet> mPE;
public:
  TModulePhysicEngine();

  TPhysicEngine_Bullet* GetPE();

  virtual void StartEvent();
  virtual bool WorkInherit();
  virtual void StopEvent();
};
