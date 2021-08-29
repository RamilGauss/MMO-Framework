/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"

#include <functional>

namespace nsImGuiWidgets
{
    class DllExport TToolTip : public TUnit
    {
    protected:
        void BeginRender() override {}
        void EndRender() override {}

        void RenderInheritance() override final
        {
            ImGui::BeginTooltip();
            ImGui::Text(mTitle.c_str());
            ImGui::EndTooltip();
        }
    };
}
