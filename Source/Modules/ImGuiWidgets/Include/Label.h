/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <functional>

#include "ImGuiWidgets/Include/Unit.h"

namespace nsImGuiWidgets
{
    class DllExport TLabel : public TUnit
    {
    public:
        void SetText(const std::string& value);
        void AppendText(const std::string& value);
        int GetTextLength();
        std::string GetText();

        void SetColor(const ImVec4& color);
        ImVec4 GetColor() const;

    protected:
        void RenderInheritance() override final;

        std::string mText;
        ImVec4 mColor = ImVec4(1, 1, 1, 1);

        int mWrapWidth = 200;
        ImVec4 mCounturColor = ImVec4(1, 1, 0, 1);
    };
}
