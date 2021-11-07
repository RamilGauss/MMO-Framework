/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base.h"
#include "ContainerTypes.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
#pragma pack(push, 1)
  struct DllExport TBaseEvent
  {
    // переназначить в наследуемом классе
    EventType mType;
    TContainer c;
  };
#pragma pack(pop)

}