/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Color.h"

namespace nsImGuiWidgets
{
    void TColor::SetColor(const ImVec4& value)
    {
        mColor = value;
    }
    //----------------------------------------------------------------------------
    ImVec4 TColor::GetColor() const
    {
        return mColor;
    }
    //----------------------------------------------------------------------------
}
