/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputText.h"

using namespace nsImGuiWidgets;

void TInputText::RenderInheritance()
{
    ImGui::InputText(mTitle.c_str(), mValue, SIZE);
}
//------------------------------------------------------------------------------------