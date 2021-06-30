/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"

namespace nsImGuiWidgets
{
    class TInputInt : public TWidget
    {
    public:
        TInputInt(const std::string& name) : TWidget(name) {}
    protected:
        void RenderInheritance() override final
        {
            static int v = 0;
            ImGui::InputInt("INT", &v);
        }
    };
}
