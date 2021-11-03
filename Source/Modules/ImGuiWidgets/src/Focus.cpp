/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Focus.h"

using namespace nsImGuiWidgets;

void TFocus::SetIsFocused(bool value)
{
    mIsFocused = value;
}
//----------------------------------------------------------------------------
bool TFocus::IsFocused() const
{
    return mIsFocused;
}
//----------------------------------------------------------------------------