/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTextureUv
    {
    public:
        void SetTextureMaxUv(const ImVec2& value);
        void SetTextureMinUv(const ImVec2& value);

        ImVec2 GetTextureMinUv() const;
        ImVec2 GetTextureMaxUv() const;
    protected:
        ImVec2 mTextureMinUv = { 0,0 };
        ImVec2 mTextureMaxUv = { 1,1 };
    };
}
