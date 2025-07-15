/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/DockTree.h"

using namespace nsImGuiWidgets;

TDockTree& TDockTree::operator = (const TDockTree& other)
{
    root = other.root;
    ((TDockTree*)(&other))->root = nullptr;

    return *this;
}
//--------------------------------------------------------------
