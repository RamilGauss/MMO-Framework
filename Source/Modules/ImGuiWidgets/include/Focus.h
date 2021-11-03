/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Typedef.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TFocus
    {
        bool mIsFocused = false;
    public:
        using TFocusCallback = TCallbackPool<bool>;

        TFocusCallback mFocusCB;

        void SetIsFocused(bool value);
        bool IsFocused() const;
    };
}
