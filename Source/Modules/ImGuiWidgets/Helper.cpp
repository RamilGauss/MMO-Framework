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
