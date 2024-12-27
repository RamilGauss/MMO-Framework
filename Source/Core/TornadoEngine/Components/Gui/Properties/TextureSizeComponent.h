/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Share/PropertyOf.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/TextureSize.h>

namespace nsGuiWrapper
{
    struct DllExport TTextureSizeComponent : 
        nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTextureSize>, nsECSFramework::IComponent
    {
        unsigned int width = 0;
        unsigned int height = 0;
    };
}