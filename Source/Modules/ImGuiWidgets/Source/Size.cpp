/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Size.h"
#include "ImGuiWidgets/Include/Helper.h"

using namespace nsImGuiWidgets;

void TSize::SetSize(const ImVec2& value, bool withNotify)
{
    withNotify &= (mSize != value);
    mSize = value;

    if (withNotify) {
        mOnSizeCB.Notify();
    }
}
//--------------------------------------------------------------------------------
const ImVec2& TSize::GetSize() const
{
    return mSize;
}
//--------------------------------------------------------------------------------

