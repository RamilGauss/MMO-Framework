/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include "Base.h"
#include "ContainerTypes.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
  struct DllExport TBaseEvent
  {
    // переназначить в наследуемом классе
    tTypeEvent mType;
    TContainer c;
  }_PACKED;
#if defined( WIN32 )
#pragma pack(pop)
#endif

}

#endif