/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

namespace nsMMOEngine
{
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
    struct TScenarioBaseHeader
    {
      char type;
      char subType;
    }_PACKED;
#if defined( WIN32 )
#pragma pack(pop)
#endif
}
