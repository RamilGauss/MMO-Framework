/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Title.h"

using namespace nsImGuiWidgets;

void TTitle::SetTitle(const std::string& str)
{
    mTitle = str;
}
//---------------------------------------------------------
std::string TTitle::GetTitle() const
{
    return mTitle;
}
//---------------------------------------------------------

