/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "Widget.h"

namespace nsImGuiWidgets
{
    class TComboBox : public TWidget
    {
    protected:
        int mCurrentItemIndex = 0;
        std::vector<std::string> mItems = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO", "PPPP", "QQQQQQQQQQ", "RRR", "SSSS"};
        std::string* mCurrentItem = nullptr;
    public:
        TComboBox(const std::string& name) : TWidget(name) {}

        int GetCurrent() { return mCurrentItemIndex; }
        void SetCurrent(int value) { mCurrentItemIndex = value; }

        void SetItems(std::vector<std::string>& items)
        {
            mItems = items;
        }
    protected:
        void RenderInheritance() override final
        {
            ImGuiStyle& style = ImGui::GetStyle();
            float w = ImGui::CalcItemWidth();
            float spacing = style.ItemInnerSpacing.x;
            float button_sz = ImGui::GetFrameHeight();
            ImGui::PushItemWidth(w - spacing * 2.0f - button_sz * 2.0f);

            auto cur = mCurrentItem == nullptr ? nullptr : mCurrentItem->c_str();

            if (ImGui::BeginCombo(GetName(), cur)) {
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
    };
}