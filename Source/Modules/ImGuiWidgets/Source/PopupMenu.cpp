/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/PopupMenu.h"
#include "ImGuiWidgets/Include/PopupNode.h"

using namespace nsImGuiWidgets;

int TPopupMenu::mLastId = 0;

TPopupMenu::TPopupMenu() : TWidgetContainer(nullptr)
{
    mLastId++;
    mId = mLastId;
}
//-------------------------------------------------------------------------
void TPopupMenu::Open()
{
    mIsOpen = true;
}
//-------------------------------------------------------------------------
void TPopupMenu::Render()
{
    std::string strId = std::to_string(mId);
    if (mIsOpen) {
        mIsOpen = false;
        ImGui::OpenPopup(strId.c_str());
    }
    if (ImGui::BeginPopup(strId.c_str())) {
        for (auto& node : mWidgets) {
            node->Render();
        }

        ImGui::EndPopup();
    }
}
//-------------------------------------------------------------------------
