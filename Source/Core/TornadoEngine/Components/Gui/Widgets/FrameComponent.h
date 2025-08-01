/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include "ImGuiWidgets/Include/Frame.h"

namespace nsGuiWrapper
{
    struct DllExport TFrameComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        nsImGuiWidgets::TFrame* value = nullptr;
    };
}