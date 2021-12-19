/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/InputText.h>

namespace nsGuiWrapper
{
    struct DllExport TInputTextComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        mutable nsImGuiWidgets::TInputText* value = nullptr;

        std::string text;
    };
}