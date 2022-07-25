/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Padding.h"

namespace nsImGuiWidgets
{
    void TPadding::SetLeft(int value)
    {
        mLeft = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetTop(int value)
    {
        mTop = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetRight(int value)
    {
        mRight = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetBottom(int value)
    {
        mBottom = value;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetLeft() const
    {
        return mLeft;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetTop() const
    {
        return mTop;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetRight() const
    {
        return mRight;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetBottom() const
    {
        return mBottom;
    }
    //---------------------------------------------------------------------------------------
}
