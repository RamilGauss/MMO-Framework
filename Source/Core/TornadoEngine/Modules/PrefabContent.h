/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ResourceContent.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabHeader
    {
        // Reserved
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabContent : TResourceContent
    {
        TPrefabHeader header;
    };
}