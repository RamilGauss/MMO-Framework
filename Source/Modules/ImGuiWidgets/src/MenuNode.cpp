/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNode.h"
#include "ImGuiCustom.h"

using namespace nsImGuiWidgets;

void TMenuNode::SetCallback(TCallback callback)
{
    mCallback = callback;
}
//------------------------------------------------------------------------------------------
void TMenuNode::SetCheckable(bool value)
{
    mIsCheckable = value;
}
//------------------------------------------------------------------------------------------
bool TMenuNode::IsCheckable()
{
    return mIsCheckable;
}
//------------------------------------------------------------------------------------------
void TMenuNode::SetChecked(bool value)
{
    mIsChecked = value;
}
//------------------------------------------------------------------------------------------
bool TMenuNode::IsChecked()
{
    return mIsChecked;
}
//------------------------------------------------------------------------------------------
void TMenuNode::Render()
{
    if (mWidgets.size()) {
        auto open = ImGui::BeginMenu(GetTitle().c_str());
        if(open) {

            for (auto& node : mWidgets) {
                node->Render();
            }
            ImGui::EndMenu();
        }
    } else {

        const auto textureSize = ImVec2(GetTextureWidth(), GetTextureHeight());

        bool open = false;
        if (mIsCheckable) {
            open = TImGuiCustom::MenuItem(GetTitle().c_str(), nullptr, &mIsChecked, true, GetTextureId(), textureSize);
        } else {
            open = TImGuiCustom::MenuItem(GetTitle().c_str(), nullptr, false, true, GetTextureId(), textureSize);
        }
        if (open) {
            mOnLeftClickCB.Notify(this);
        }
    }
}
//------------------------------------------------------------------------------------------