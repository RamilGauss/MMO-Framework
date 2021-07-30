/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputInt.h"

using namespace nsImGuiWidgets;

TInputInt::TInputInt(const std::string& name) : TWidget(name) 
{
}
//------------------------------------------------------------------------------------
void TInputInt::RenderInheritance()
{
    static int v = 0;
    ImGui::InputInt("INT", &v);
}
//------------------------------------------------------------------------------------