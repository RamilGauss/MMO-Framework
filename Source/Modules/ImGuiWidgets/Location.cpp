/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Location.h"

using namespace nsImGuiWidgets;

void TLocation::SetPos(const ImVec2& newPos)
{
    mPos = newPos;
}
//--------------------------------------------------------------------------------
void TLocation::SetSize(const ImVec2& newSize)
{
    mSize = newSize;
}
//--------------------------------------------------------------------------------
const ImVec2& TLocation::GetPos()
{
    return mPos;
}
//--------------------------------------------------------------------------------
const ImVec2& TLocation::GetSize()
{
    return mSize;
}
//--------------------------------------------------------------------------------

