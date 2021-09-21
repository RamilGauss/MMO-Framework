/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Visibility.h"

using namespace nsImGuiWidgets;

bool TVisibility::IsShown()
{
    return mIsShown;
}
//------------------------------------------------------------------------
void TVisibility::SetShow(bool value)
{
    mIsShown = value;
}
//------------------------------------------------------------------------
void TVisibility::Show()
{
    SetShow(true);
}
//------------------------------------------------------------------------
void TVisibility::Hide()
{
    SetShow(false);
}
//------------------------------------------------------------------------
