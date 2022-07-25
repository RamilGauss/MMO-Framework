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

        virtual void SetLeft(int value);
        virtual void SetTop(int value);
        virtual void SetRight(int value);
        virtual void SetBottom(int value);

        virtual int GetLeft() const;
        virtual int GetTop() const;
        virtual int GetRight() const;
        virtual int GetBottom() const;
    protected:
        int mTop = 0;
        int mLeft = 0;
        int mBottom = 0;
        int mRight = 0;
    };
}
