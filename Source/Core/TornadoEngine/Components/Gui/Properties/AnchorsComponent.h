/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/Anchors.h"

#include "TornadoEngine/Share/PropertyOf.h"

namespace nsGuiWrapper
{
    struct DllExport TAnchorsComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TAnchors>, nsECSFramework::IComponent
    {
        bool leftIsUsed = false;
        int leftOffset = 0;

        bool rightIsUsed = false;
        int rightOffset = 0;

        bool topIsUsed = false;
        int topOffset = 0;

        bool bottomIsUsed = false;
        int bottomOffset = 0;
    };
}