/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"

#include <functional>

namespace nsImGuiWidgets
{
    class TLabel : public TWidget
    {
        std::string mText;
    public:
        TLabel(const std::string& name) : TWidget(name) {}

        void SetText(const char* s)
        {
            mText = s;
        }
        void AppendText(const char* s)
        {
            mText += s;
        }
    protected:
        void RenderInheritance() override final
        {
            ImVec4 color(1,1,1,1);
            ImGui::TextColored(color, mText.c_str());
        }
    };
}
