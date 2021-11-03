/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputText.h"

#include <imgui_internal.h>

using namespace nsImGuiWidgets;

std::string TInputText::GetText()
{
    return mValue;
}
//------------------------------------------------------------------------------------
void TInputText::SetText(const std::string& str)
{
    strcpy_s(mValue, str.c_str());
}
//------------------------------------------------------------------------------------
static int EditCallback(ImGuiInputTextCallbackData* data)
{
    auto inputText = (TInputText*) data->UserData;
    inputText->mOnTextEditCB.Notify(inputText);
    return 0;
}
//------------------------------------------------------------------------------------
void TInputText::RenderInheritance()
{
    auto flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackEdit | ImGuiInputTextFlags_AutoSelectAll;
    if (ImGui::InputText(mTitle.c_str(), mValue, SIZE, flags, EditCallback, this)) {
        mOnTextEditEndsCB.Notify(this);
    }
}
//------------------------------------------------------------------------------------