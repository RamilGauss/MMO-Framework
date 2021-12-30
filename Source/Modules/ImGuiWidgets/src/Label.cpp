/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Label.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

//-------------------------------------------------------------------------------------
void TLabel::SetText(const std::string& value)
{
    mText = value;
}
//-------------------------------------------------------------------------------------
void TLabel::AppendText(const std::string& value)
{
    mText += value;
}
//-------------------------------------------------------------------------------------
void TLabel::RenderInheritance()
{
    mWrapWidth = mSize.x;

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImGui::PushTextWrapPos(ImGui::GetCursorPos().x + mWrapWidth);

    ImGui::TextColored(mColor, mText.c_str());

    ImU32 counturColor = IM_COL32(mCounturColor.x * 255, mCounturColor.y * 255,
        mCounturColor.z * 255, mCounturColor.w * 255);
    draw_list->AddRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMin() + mSize, counturColor);

    ImGui::PopTextWrapPos();
}
//-------------------------------------------------------------------------------------
int TLabel::GetTextLength()
{
    return mText.size();
}
//-------------------------------------------------------------------------------------
std::string TLabel::GetText()
{
    return mText;
}
//-------------------------------------------------------------------------------------
void TLabel::SetColor(const ImVec4& color)
{
    mColor = color;
}
//-------------------------------------------------------------------------------------
ImVec4 TLabel::GetColor() const
{
    return mColor;
}
//-------------------------------------------------------------------------------------
