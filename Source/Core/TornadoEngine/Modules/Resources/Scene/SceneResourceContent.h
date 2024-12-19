/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "PrefabInstance.h"
#include "Modules/Resources/Common/EntityContent.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSceneResourceContent
    {
        std::list<TEntityContent> entities;
        std::list<TPrefabInstance> prefabInstances;
    };
}
