/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <entt/entt.hpp>
#include <vector>
#include "ECSconfig.h"
#include "ConveyerPartMaster.h"

namespace nsECSFramework
{
  class DllExport TWorld : public TConveyerPartMaster
  {
  public:
    TWorld();
  };
}