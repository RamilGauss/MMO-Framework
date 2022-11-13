/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Size.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TSize::SetSize(const ImVec2& newSize)
{
    if (mSize != newSize) {
        mSize = newSize;
        mOnSizeCB.Notify();
    }
}
//--------------------------------------------------------------------------------
const ImVec2& TSize::GetSize() const
{
    return mSize;
}
//--------------------------------------------------------------------------------

