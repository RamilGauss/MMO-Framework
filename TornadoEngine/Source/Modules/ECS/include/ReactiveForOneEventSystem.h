/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "System.h"
#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  class DllExport TReactiveForOneEventSystem : public TBaseReactiveSystem
  {
  public:
    TReactiveForOneEventSystem();
    virtual void Update() final;
  };
}
