/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockTree.h"

using namespace nsImGuiWidgets;

bool TDockTree::operator == (const TDockTree& other)
{
    return false;
}
//--------------------------------------------------------------
TDockTree& TDockTree::operator = (const TDockTree& other)
{
    root = other.root;
    ((TDockTree*)(&other))->root = nullptr;

    return *this;
}
//--------------------------------------------------------------
