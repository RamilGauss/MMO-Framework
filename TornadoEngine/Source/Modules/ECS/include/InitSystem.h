#pragma once
#include "System.h"

namespace nsECSFramework
{
  class DllExport TInitSystem : public TSystem
  {
  public:
    virtual void Update() { assert( true ); }
  };
}
