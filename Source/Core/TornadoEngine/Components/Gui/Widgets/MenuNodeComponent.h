/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ECS/Include/IComponent.h"
#include <ImGuiWidgets/include/MenuNode.h>

namespace nsGuiWrapper
{
    struct DllExport TMenuNodeComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        mutable nsImGuiWidgets::TMenuNode* value = nullptr;
    };
}