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
    class DllExport TAnchors
    {
    public:
        struct DllExport TAnchor
        {
            bool isUsed = false;
            int offset = 0;
        };

        bool IsAnyAnchor() const;

        TAnchor GetLeft() const;
        TAnchor GetRight() const;
        TAnchor GetTop() const;
        TAnchor GetBottom() const;

        void SetLeft(const TAnchor& value);
        void SetRight(const TAnchor& value);
        void SetTop(const TAnchor& value);
        void SetBottom(const TAnchor& value);
    private:
        TAnchor mLeft;
        TAnchor mRight;
        TAnchor mTop;
        TAnchor mBottom;
    };
}
