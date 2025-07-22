/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/TextureReference.h"

namespace nsGuiWrapper
{
    struct DllExport TTextureReferenceComponent : 
        nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTextureReference>, nsECSFramework::IComponent
    {
        std::string resourceGuid;
    };
}