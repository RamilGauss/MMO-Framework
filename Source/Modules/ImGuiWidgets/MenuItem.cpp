/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuItem.h"

using namespace nsImGuiWidgets;

TMenuItem::TMenuItem(const std::string& menu, const std::string& name) : TWidget(name)
{
    mMenu = menu;
}
//------------------------------------------------------------------------------------------
void TMenuItem::SetCallback(TCallback callback)
{
    mCallback = callback;
}
//------------------------------------------------------------------------------------------
void TMenuItem::SetSelected(bool value)
{
    mSelected = value;
}
//------------------------------------------------------------------------------------------
void TMenuItem::RenderInheritance()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu(mMenu.c_str())) {
            if (ImGui::MenuItem(GetName(), "CTRL+Z", &mSelected)) {
                if (mCallback) {
                    mCallback(this);
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}
//------------------------------------------------------------------------------------------