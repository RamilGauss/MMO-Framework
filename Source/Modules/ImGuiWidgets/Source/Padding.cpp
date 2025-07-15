/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Padding.h"

namespace nsImGuiWidgets
{
    void TPadding::SetLeftPadding(int value)
    {
        mLeft = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetTopPadding(int value)
    {
        mTop = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetRightPadding(int value)
    {
        mRight = value;
    }
    //---------------------------------------------------------------------------------------
    void TPadding::SetBottomPadding(int value)
    {
        mBottom = value;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetLeftPadding() const
    {
        return mLeft;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetTopPadding() const
    {
        return mTop;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetRightPadding() const
    {
        return mRight;
    }
    //---------------------------------------------------------------------------------------
    int TPadding::GetBottomPadding() const
    {
        return mBottom;
    }
    //---------------------------------------------------------------------------------------
}
