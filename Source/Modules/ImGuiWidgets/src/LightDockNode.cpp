
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LightDockNode.h"

using namespace nsImGuiWidgets;

bool TLightDockNode::operator == (const TLightDockNode& other)
{
    auto isEqual = (id == other.id);

    for (int i = 0; i < 2; i++) {
        if (child[i] != nullptr) {
            if (other.child[i] != nullptr) {
                isEqual &= child[i]->operator== (*(other.child[i]));
            } else {
                isEqual = false;
            }
        }
    }

    isEqual &= splitMode == other.splitMode;

    isEqual &= windows.size() == other.windows.size();

    isEqual &= windows == other.windows;

    isEqual &= selectedWindowIndex == other.selectedWindowIndex;

    return isEqual;
}
//------------------------------------------------------------------------
bool TLightDockNode::HasChild() const
{
    return child[0] != nullptr || child[1] != nullptr;
}
//------------------------------------------------------------------------