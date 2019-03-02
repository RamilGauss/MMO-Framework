/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <list>
#include "EntityManager.h"

namespace nsECSFramework
{
  struct DllExport IComponent
  {
  private:
    friend class TEntity;

    TEntityList& entityList;
    TEntityList::iterator it;

  };

  struct DllExport IUniqueComponent : IComponent
  {
  };
  struct DllExport IMultiComponent : IComponent
  {
  };
  struct DllExport IMultiMixComponent : IMultiComponent
  {
  };
  struct DllExport IHasComponent : IComponent
  {
  };
}