/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Label.h"

using namespace nsImGuiWidgets;

//-------------------------------------------------------------------------------------
void TLabel::SetText(const char* s)
{
    mText = s;
}
//-------------------------------------------------------------------------------------
void TLabel::AppendText(const char* s)
{
    mText += s;
}
//-------------------------------------------------------------------------------------
void TLabel::RenderInheritance()
{
    ImVec4 color(1, 1, 1, 1);
    ImGui::TextColored(color, mText.c_str());
}
//-------------------------------------------------------------------------------------
int TLabel::GetTextLength()
{
    return mText.size();
}
//-------------------------------------------------------------------------------------
