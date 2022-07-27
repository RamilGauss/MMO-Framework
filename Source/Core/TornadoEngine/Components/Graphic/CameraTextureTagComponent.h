/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include "ECS/include/IComponent.h"
#include <GraphicEngine/Texture.h>

namespace nsGraphicWrapper
{
    struct DllExport TCameraTextureTagComponent : nsECSFramework::IComponent
    {
#pragma IGNORE_ATTRIBUTE
        mutable nsGraphicEngine::TTexture* value = nullptr;
    };
}