#pragma once
#include "IConveyerPart.h"
#include "GlobalAccess.h"

namespace nsECSFramework
{
  class DllExport TConveyerPartWithGlobalAccess : public IConveyerPart, public TGlobalAccess { };
}
