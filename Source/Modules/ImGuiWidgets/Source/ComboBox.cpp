/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/ComboBox.h"

using namespace nsImGuiWidgets;

void TComboBox::RenderInheritance()
{
    ImGui::PushItemWidth(GetSize().x);

    auto currentIndex = GetCurrentIndex();

    auto& items = GetItems();

    auto cur = (currentIndex == -1) ? nullptr : items[currentIndex].c_str();

    if (ImGui::BeginCombo(mTitle.c_str(), cur)) {
        for (int i = 0; i < items.size(); i++) {
            bool isSelected = (currentIndex == i);
            if (ImGui::Selectable(items[i].c_str(), isSelected)) {
                currentIndex = i;

                SetCurrentIndex(currentIndex);
            }
            if (isSelected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}
//----------------------------------------------------------------------------------------