#pragma once
#include "System.h"

namespace nsECSFramework
{
  class DllExport TExecuteSystem : public TSystem
  {
  public:
    virtual void Update() final;
    virtual void Execute() = 0;
  };
}
