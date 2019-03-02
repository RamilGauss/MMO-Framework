/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <entt/entt.hpp>

#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  class DllExport TReactiveForManyEventsSystem : public TBaseReactiveSystem
  {
    // Важен порядок возникновения событий
    // все изменившиеся
    TVectorRise<TEntity> mReactionEntities;
  public:
    TReactiveForManyEventsSystem();
    virtual void Update() final;
  };
}
