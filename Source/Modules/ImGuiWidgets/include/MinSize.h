/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <limits>
#include "imgui.h"

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TMinSize
    {
    public:
        void SetMinSize(const ImVec2& value);
        ImVec2 GetMinSize() const;
    protected:
        ImVec2 mValue = { 0, 0 };
    };
}
