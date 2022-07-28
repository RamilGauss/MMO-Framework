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

        virtual void SetLeftPadding(int value);
        virtual void SetTopPadding(int value);
        virtual void SetRightPadding(int value);
        virtual void SetBottomPadding(int value);

        virtual int GetLeftPadding() const;
        virtual int GetTopPadding() const;
        virtual int GetRightPadding() const;
        virtual int GetBottomPadding() const;
    private:
        int mTop = 0;
        int mLeft = 0;
        int mBottom = 0;
        int mRight = 0;
    };
}
