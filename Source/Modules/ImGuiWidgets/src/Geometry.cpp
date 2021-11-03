/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Geometry.h"

using namespace nsImGuiWidgets;

void TGeometry::SetPos(const ImVec2& newPos)
{
    mPos = newPos;
}
//--------------------------------------------------------------------------------
void TGeometry::SetSize(const ImVec2& newSize)
{
    mSize = newSize;
}
//--------------------------------------------------------------------------------
const ImVec2& TGeometry::GetPos()
{
    return mPos;
}
//--------------------------------------------------------------------------------
const ImVec2& TGeometry::GetSize()
{
    return mSize;
}
//--------------------------------------------------------------------------------

