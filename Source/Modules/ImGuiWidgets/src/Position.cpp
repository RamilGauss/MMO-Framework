/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Position.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TPosition::SetPosition(const ImVec2& value, bool withNotify)
{
    withNotify &= (mPosition != value);
    mPosition = value;

    if (withNotify) {
        mOnPositionCB.Notify();
    }
}
//--------------------------------------------------------------------------------
const ImVec2& TPosition::GetPosition() const
{
    return mPosition;
}
//--------------------------------------------------------------------------------
