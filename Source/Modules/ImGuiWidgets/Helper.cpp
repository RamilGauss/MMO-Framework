/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Helper.h"
#include <cmath>

bool nsImGuiWidgets::operator != (const ImVec2& l, const ImVec2& r)
{
    return (std::abs(l.x - r.x) + std::abs(l.y - r.y) > 0.001f);
}
//-------------------------------------------------------------------------
ImVec2 nsImGuiWidgets::operator + (const ImVec2& l, const ImVec2& r)
{
    return {l.x + r.x, l.y + r.y};
}
//-------------------------------------------------------------------------
ImVec2 nsImGuiWidgets::operator - (const ImVec2& l, const ImVec2& r)
{
    return {l.x - r.x, l.y - r.y};
}
//-------------------------------------------------------------------------
ImVec2& nsImGuiWidgets::operator += (ImVec2& l, const ImVec2& r)
{
    l = l + r;
    return l;
}
//-------------------------------------------------------------------------
bool nsImGuiWidgets::InRect(const ImVec2& pos, const ImVec2& size, const ImVec2& point)
{
    auto max = pos + size;
    if ((point.x >= pos.x && max.x > point.x) &&
        (point.y >= pos.y && max.y > point.y)) {
        return true;
    }
    return false;
}
//-------------------------------------------------------------------------
