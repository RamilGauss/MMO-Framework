/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuSeparator.h"

using namespace nsImGuiWidgets;

TMenuSeparator::TMenuSeparator(const std::string& menu, const std::string& name) : TWidget(name)
{
    mMenu = menu;
}
//--------------------------------------------------------------------------------------------------
void TMenuSeparator::RenderInheritance()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu(mMenu.c_str())) {
            ImGui::Separator();
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}
//--------------------------------------------------------------------------------------------------