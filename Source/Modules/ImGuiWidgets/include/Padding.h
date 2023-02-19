/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TPadding
    {
    public:
        void SetLeftPadding(int value);
        void SetTopPadding(int value);
        void SetRightPadding(int value);
        void SetBottomPadding(int value);

        int GetLeftPadding() const;
        int GetTopPadding() const;
        int GetRightPadding() const;
        int GetBottomPadding() const;
    private:
        int mTop = 0;
        int mLeft = 0;
        int mBottom = 0;
        int mRight = 0;
    };
}
