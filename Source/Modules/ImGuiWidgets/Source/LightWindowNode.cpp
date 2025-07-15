/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/LightWindowNode.h"

using namespace nsImGuiWidgets;

bool TLightWindowNode::operator == (const TLightWindowNode& other) const
{
    return name == other.name;
}
//------------------------------------------------------------------