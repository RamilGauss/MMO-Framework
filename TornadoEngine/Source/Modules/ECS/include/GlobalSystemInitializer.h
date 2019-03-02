/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

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
