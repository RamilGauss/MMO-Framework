/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/IComponent.h>

namespace nsLogicWrapper
{
    struct DllExport TTargetHandlerComponent : nsECSFramework::IComponent
    {
        enum class From
        {
            ALL, CHILDS
        };

        From from = From::ALL;

        // Use if ALL
        enum class Filter
        {
            EVERYWHERE, THIS_UNVIVERSE, THIS_SCENE
        };

        Filter filter = Filter::EVERYWHERE;

        std::string entityGuid;
        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;
    };
}
