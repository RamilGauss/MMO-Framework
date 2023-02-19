/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputMultiText.h"

#include <imgui_stdlib.h>

using namespace nsImGuiWidgets;

int nsImGuiWidgets::nsInputMultiText::EditCallback(ImGuiInputTextCallbackData* data)
{
    auto inputText = (TInputMultiText*)data->UserData;
    inputText->SetTextEdited();
    return 0;
}
//------------------------------------------------------------------------------------
void TInputMultiText::RenderInheritance()
{
    auto str = GetInputTextValue();

    auto flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackEdit | ImGuiInputTextFlags_AutoSelectAll;
    if (ImGui::InputTextMultiline(mTitle.c_str(), &str, GetSize(), flags, nsInputMultiText::EditCallback, this)) {
        mOnTextEditCB.Notify(this);
    }

    if (mIsTextEdited) {
        SetInputTextValue(str);

        mOnTextEditCB.Notify(this);
        mIsTextEdited = false;
    }
}
//------------------------------------------------------------------------------------
void TInputMultiText::SetTextEdited()
{
    mIsTextEdited = true;
}
//------------------------------------------------------------------------------------