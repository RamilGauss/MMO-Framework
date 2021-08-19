/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNode.h"

using namespace nsImGuiWidgets;

void TMenuNode::SetCallback(TCallback callback)
{
    mCallback = callback;
}
//------------------------------------------------------------------------------------------
void TMenuNode::SetSelected(bool value)
{
    mSelected = value;
}
//------------------------------------------------------------------------------------------
void TMenuNode::Render()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu(mMenu.c_str())) {
            //if (ImGui::MenuItem(GetName(), "CTRL+Z", &mSelected)) {
            //    if (mCallback) {
            //        mCallback(this);
            //    }
            //}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}
//------------------------------------------------------------------------------------------