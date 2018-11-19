#pragma once

namespace nsECSFramework
{
  template<typename SystemType>
  class TGlobalSystemInitializer
  {
    std::vector<IConveyerPart*> mSystemVec;
  public:
    void Add( IConveyerPart* p )
    {
      mSystemVec.push_back( p );
    }
    void InitSystems()
    {
      for ( auto pSystem : mSystemVec )
        pSystem->Init();
    }
  };
}
