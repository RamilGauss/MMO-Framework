/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputText.h"

#include <imgui_internal.h>
#include <imgui_stdlib.h>

using namespace nsImGuiWidgets;

int nsImGuiWidgets::nsInputText::EditCallback(ImGuiInputTextCallbackData* data)
{
    auto inputText = (TInputText*)data->UserData;
    inputText->SetTextEdited();
    return 0;
}
//------------------------------------------------------------------------------------
void TInputText::RenderInheritance()
{
    ImGui::PushItemWidth(GetSize().x);

    auto str = GetInputTextValue();

    auto flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackEdit | ImGuiInputTextFlags_AutoSelectAll;
    if (ImGui::InputText(mTitle.c_str(), &str, flags, nsInputText::EditCallback, this)) {
        mOnTextEditEndsCB.Notify(this);
    }
    if (mIsTextEdited) {
        SetInputTextValue(str);

        mOnTextEditCB.Notify(this);
        mIsTextEdited = false;
    }

    ImGui::PopItemWidth();
}
//------------------------------------------------------------------------------------
void TInputText::SetTextEdited()
{
    mIsTextEdited = true;
}
//------------------------------------------------------------------------------------