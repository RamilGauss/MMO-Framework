#pragma once
#include "IConveyerPart.h"
#include "GlobalAccess.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TConveyerPartWithGlobalAccess : public IConveyerPart, public TGlobalAccess {};
  }
}
