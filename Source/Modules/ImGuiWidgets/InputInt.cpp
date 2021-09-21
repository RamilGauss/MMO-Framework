/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputInt.h"

using namespace nsImGuiWidgets;

void TInputInt::RenderInheritance()
{
    ImGui::PushID(mId);
    ImGui::InputInt(mTitle.c_str(), &mValue, mStep, mStepFast);
    ImGui::PopID();
}
//------------------------------------------------------------------------------------