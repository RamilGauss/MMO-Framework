/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include <GraphicEngine/Texture.h>

namespace nsGraphicWrapper
{
    struct DllExport TTextureFromCameraComponent : nsECSFramework::IComponent
    {
        std::string cameraGuid;

#pragma IGNORE_ATTRIBUTE
        mutable nsGraphicEngine::TTexture* value = nullptr;
    };
}