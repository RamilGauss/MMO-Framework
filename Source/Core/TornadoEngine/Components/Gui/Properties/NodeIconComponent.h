/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/TextureSize.h>

#include "Share/PropertyOf.h"

namespace nsGuiWrapper
{
    struct DllExport TNodeIconComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTextureSize>, nsECSFramework::IComponent
    {
        int width = 0;
        int height = 0;
    };
}