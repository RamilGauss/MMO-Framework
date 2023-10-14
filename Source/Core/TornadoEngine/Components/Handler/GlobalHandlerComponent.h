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
    struct DllExport TGlobalHandlerComponent : nsECSFramework::IComponent
    {
        std::string handlerTypeName;

#pragma IGNORE_ATTRIBUTE
        mutable void* handler = nullptr;
    };
}