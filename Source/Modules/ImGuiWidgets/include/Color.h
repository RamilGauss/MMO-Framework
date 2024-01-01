/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "imgui.h"

namespace nsImGuiWidgets
{
    struct DllExport TColor
    {
    public:
        void SetColor(const ImVec4& value);
        ImVec4 GetColor() const;

    private:
        ImVec4 mColor = { 0.0f, 0.0f, 0.0f, 1.0f };
    };
}
