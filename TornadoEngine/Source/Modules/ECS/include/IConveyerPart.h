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
