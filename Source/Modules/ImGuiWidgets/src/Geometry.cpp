/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Geometry.h"
#include "Helper.h"

using namespace nsImGuiWidgets;

void TGeometry::SetPos(const ImVec2& newPos)
{
    if (mPos != newPos) {
        mPos = newPos;
        mOnPositionCB.Notify();
    }
}
//--------------------------------------------------------------------------------
void TGeometry::SetSize(const ImVec2& newSize)
{
    if (mSize != newSize) {
        mSize = newSize;
        mOnSizeCB.Notify();
    }
}
//--------------------------------------------------------------------------------
const ImVec2& TGeometry::GetPos() const
{
    return mPos;
}
//--------------------------------------------------------------------------------
const ImVec2& TGeometry::GetSize() const
{
    return mSize;
}
//--------------------------------------------------------------------------------

