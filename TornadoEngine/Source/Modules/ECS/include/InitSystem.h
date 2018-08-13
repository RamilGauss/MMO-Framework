#pragma once
#include "System.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TInitSystem : public TSystem
    {
    public:
      virtual void Update() { assert(true); }
    };
  }
}
