/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"
#include <list>
#include "Config.h"
#include "LinkToList.h"

namespace nsECSFramework
{
  struct DllExport IComponent
  {
    virtual ~IComponent()
    {
    }
    bool operator< ( const IComponent& other ) const
    {
      return true;
    }
  private:
    friend class TEntity;

    TLinkToList<short> mInEntityLinkList;

    std::list<TLinkToList<TEntityID>> mContainerLinkList;
  };

  struct DllExport IUniqueComponent : IComponent
  {
  };
  struct DllExport IMultiComponent : IComponent
  {
  };
  struct DllExport IMultiMixComponent : IComponent
  {
  };
  struct DllExport IHasComponent : IComponent
  {
  };
}