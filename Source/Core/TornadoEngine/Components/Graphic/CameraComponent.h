/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"

#include "GraphicEngine/Camera.h"

namespace nsGraphicWrapper
{
    struct DllExport TCameraComponent : nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable nsGraphicEngine::TCamera* value = nullptr;
    };
}