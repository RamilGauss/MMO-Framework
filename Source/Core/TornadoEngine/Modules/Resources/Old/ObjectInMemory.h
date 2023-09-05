/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"
#include "ComponentInMemory.h"

namespace nsTornadoEngine
{
    struct DllExport TObjectInMemory
    {
        using Entity = std::list<TComponentInMemory>;

        std::list<Entity> entities;
        std::list<std::string> attachedPrefabGuids;
    };
}
