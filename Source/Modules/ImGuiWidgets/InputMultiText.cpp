/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputMultiText.h"

using namespace nsImGuiWidgets;

std::string TInputMultiText::GetText()
{
    return mValue;
}
//------------------------------------------------------------------------------------
void TInputMultiText::SetText(const std::string& str)
{
    strcpy_s(mValue, str.c_str());
}
//------------------------------------------------------------------------------------
void TInputMultiText::RenderInheritance()
{
    if (ImGui::InputTextMultiline(mTitle.c_str(), mValue, SIZE, mSize)) {
        mTextEditCB.Notify(this);
    }
}
//------------------------------------------------------------------------------------