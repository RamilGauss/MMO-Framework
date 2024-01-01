/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <ECS/include/IComponent.h>
#include <ImGuiWidgets/include/TreeView.h>

namespace nsGuiWrapper
{
    struct DllExport TTreeViewComponent : nsECSFramework::IComponent
    {
        // Not use directly!
#pragma IGNORE_ATTRIBUTE
        mutable nsImGuiWidgets::TTreeView* value = nullptr;
    };
}