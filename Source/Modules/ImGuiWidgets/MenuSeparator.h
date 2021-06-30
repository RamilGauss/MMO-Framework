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
    class TMenuSeparator : public TWidget
    {
    public:
        TMenuSeparator(const std::string& menu, const std::string& name) : TWidget(name)
        {
            mMenu = menu;
        }
    protected:
        std::string mMenu;

        bool mSelected = false;
        bool mEnabled = true;

        void RenderInheritance() override final
        {
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu(mMenu.c_str())) {
                    ImGui::Separator();
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
        }
    };
}
