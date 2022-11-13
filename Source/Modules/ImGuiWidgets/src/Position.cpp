/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Position.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TPosition::SetPos(const ImVec2& newPos)
{
    if (mPos != newPos) {
        mPos = newPos;
        mOnPositionCB.Notify();
    }
}
//--------------------------------------------------------------------------------
const ImVec2& TPosition::GetPos() const
{
    return mPos;
}
//--------------------------------------------------------------------------------
