/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>
#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TIdentity
    {
        static ImGuiID mLastId;

        ImGuiID mId;
    public:
        TIdentity();

        ImGuiID GetId() const;
    };
}
