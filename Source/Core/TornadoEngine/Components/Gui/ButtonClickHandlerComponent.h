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
#include "IButtonClickHandler.h"

namespace nsGuiWrapper
{
    struct DllExport TButtonClickHandlerComponent : nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable IButtonClickHandler* handler = nullptr;

        std::string handlerTypeName;

        // this scene or prefab
        std::string partOfGuid;

        std::string entityGuid;
    };
}