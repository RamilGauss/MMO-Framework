/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComboBox.h"

using namespace nsImGuiWidgets;

int TComboBox::GetCurrent() 
{ 
    return mCurrentItemIndex; 
}
//----------------------------------------------------------------------------------------
void TComboBox::SetCurrent(int value) 
{ 
    mCurrentItemIndex = value; 
}
//----------------------------------------------------------------------------------------
void TComboBox::SetItems(const std::vector<std::string>& items)
{
    mItems = items;
}
//----------------------------------------------------------------------------------------
void TComboBox::RenderInheritance()
{
    ImGuiStyle& style = ImGui::GetStyle();
    float w = ImGui::CalcItemWidth();
    float spacing = style.ItemInnerSpacing.x;
    float button_sz = ImGui::GetFrameHeight();
    ImGui::PushItemWidth(w - spacing * 2.0f - button_sz * 2.0f);

    auto cur = mCurrentItem == nullptr ? nullptr : mCurrentItem->c_str();

    if (ImGui::BeginCombo(mTitle.c_str(), cur)) {
        for (int n = 0; n < mItems.size(); n++) {
            bool is_selected = (mCurrentItem == &mItems[n]);
            if (ImGui::Selectable(mItems[n].c_str(), is_selected))
                mCurrentItem = &mItems[n];
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
}
//----------------------------------------------------------------------------------------