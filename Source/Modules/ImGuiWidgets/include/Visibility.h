/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TVisibility
    {
    public:
        bool IsShown();
        void SetShow(bool value);

        void Show();
        void Hide();
    protected:
        bool mIsShown = true;
    };
}
