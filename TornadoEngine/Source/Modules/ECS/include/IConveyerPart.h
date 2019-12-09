/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "TypeDef.h"

namespace nsECSFramework
{
  class DllExport IConveyerPart
  {
  public:
    virtual void Init() { }
    virtual void Update() = 0;

    // только для TFeature
    virtual void PrepareFeature() { }
  };
}
