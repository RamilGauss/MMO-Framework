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

        bool open = false;
        if (mIsCheckable) {
            open = ImGui::MenuItem(GetTitle().c_str(), nullptr, &mIsChecked);
        } else {
            std::string title = (mTextureId == nullptr) ? GetTitle() : "";
            open = ImGui::MenuItem(title.c_str());

            if (mTextureId != nullptr) {
                RenderContent(-1, mWidth / 2);
            }
        }
        if (open || mChooseText) {
            mOnLeftClickCB.Notify(this);
        }
    }
}
//------------------------------------------------------------------------------------------