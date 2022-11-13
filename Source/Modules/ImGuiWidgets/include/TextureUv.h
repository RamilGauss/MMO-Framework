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
        virtual void SetMaxUV(const ImVec2& value);
        virtual void SetMinUV(const ImVec2& value);

        virtual ImVec2 GetMinUV() const;
        virtual ImVec2 GetMaxUV() const;
    protected:
        ImVec2 mMinUV = { 0,0 };
        ImVec2 mMaxUV = { 1,1 };
    };
}
