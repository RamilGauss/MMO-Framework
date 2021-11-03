/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/Window.h>

namespace nsGuiWrapper
{
    struct DllExport TWindowComponent : nsECSFramework::IComponent
    {
        nsImGuiWidgets::TWindow* value = nullptr;
    };
}