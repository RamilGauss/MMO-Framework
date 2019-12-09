/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

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
