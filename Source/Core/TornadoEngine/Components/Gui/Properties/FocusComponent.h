/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/Focus.h"

#include "TornadoEngine/Share/PropertyOf.h"

namespace nsGuiWrapper
{
    struct DllExport TFocusComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TFocus>, nsECSFramework::IComponent
    {
        bool value = false;
    };
}
