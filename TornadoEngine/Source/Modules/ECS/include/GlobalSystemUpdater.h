#pragma once

//#include "SingletonPattern.h"
#include <vector>
#include "IConveyerPart.h"

namespace MWorks
{
  namespace ECS
  {
    class TGlobalSystemUpdater// : public TSingletonPattern<TGlobalSystemUpdater>
    {
      std::vector<IConveyerPart*> mSystemVec;
    public:
      void Add( IConveyerPart* p )
      {
        mSystemVec.push_back( p );
      }
      void UpdateSystems()
      {
        for( auto pSystem : mSystemVec )
          pSystem->Update();
      }
    };
  }
}