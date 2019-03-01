/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "IComponent.h"

namespace nsMappedComponents
{
  struct DllExport IUniqueComponent : IComponent {};

  struct DllExport IHasComponent : IComponent {};
 
  struct DllExport IMultiComponent : IComponent {};

  struct DllExport IMultiMixComponent : IComponent {};



  // deprecated
  // урезанная и оптимизированная версия multi
  struct DllExport IGroupedComponent : IComponent 
  {
    virtual int GetGroupCount() = 0;
    virtual int GetGroupNumber() = 0;
  };
}
