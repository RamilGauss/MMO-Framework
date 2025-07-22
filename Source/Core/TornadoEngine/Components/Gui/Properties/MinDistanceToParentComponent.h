/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Share/PropertyOf.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/MinDistanceToParent.h"

namespace nsGuiWrapper
{
    struct DllExport TMinDistanceToParentComponent : nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TMinDistanceToParent>, nsECSFramework::IComponent
    {
        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;
    };
}