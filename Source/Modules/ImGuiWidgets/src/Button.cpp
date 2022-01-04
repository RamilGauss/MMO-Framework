/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Button.h"

using namespace nsImGuiWidgets;

//-------------------------------------------------------------------------------
void TButton::RenderInheritance()
{
    if (ImGui::Button(mTitle.c_str(), GetSize())) {
        mOnClickCB.Notify(this);
    }
}
//-------------------------------------------------------------------------------