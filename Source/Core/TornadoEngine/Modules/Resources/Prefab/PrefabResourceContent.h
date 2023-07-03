/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EntityContent.h"
#include "PrefabPatch.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPrefabResourceContent
    {
        std::string guid;
        
        std::list<TEntityContent> entities;

        TPrefabPatch patch;
    };
}
