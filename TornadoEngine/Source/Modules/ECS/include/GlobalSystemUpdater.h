#pragma once

#include <vector>
#include "IConveyerPart.h"

namespace nsECSFramework
{
  class TGlobalSystemUpdater
  {
    std::vector<IConveyerPart*> mSystemVec;
  public:
    void Add( IConveyerPart* p )
    {
      mSystemVec.push_back( p );
    }
    void UpdateSystems()
    {
      for ( auto pSystem : mSystemVec )
        pSystem->Update();
    }
  };
}
