/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/Dialog.h>

namespace nsGuiWrapper
{
    struct DllExport TDialogComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        mutable nsImGuiWidgets::TDialog* value = nullptr;
    };
}