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
#include "IFrameMouseMoveHandler.h"

#include "HandlerTarget.h"

namespace nsGuiWrapper
{
    struct DllExport TFrameMouseMoveHandlerComponent : nsCommonWrapper::THandlerTarget, nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable IFrameMouseMoveHandler* handler = nullptr;
    };
}