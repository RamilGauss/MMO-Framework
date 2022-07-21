/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Anchors.h"

namespace nsImGuiWidgets
{
    bool TAnchors::IsAnyAnchor() const
    {
        return mLeft.isUsed | mRight.isUsed | mTop.isUsed| mBottom.isUsed;
    }

    TAnchors::TAnchor TAnchors::GetLeft() const
    {
        return mLeft;
    }

    TAnchors::TAnchor TAnchors::GetRight() const
    {
        return mRight;
    }

    TAnchors::TAnchor TAnchors::GetTop() const
    {
        return mTop;
    }

    TAnchors::TAnchor TAnchors::GetBottom() const
    {
        return mBottom;
    }

    void TAnchors::SetLeft(const TAnchor& value)
    {
        mLeft = value;
    }

    void TAnchors::SetRight(const TAnchor& value)
    {
        mRight = value;
    }

    void TAnchors::SetTop(const TAnchor& value)
    {
        mTop = value;
    }

    void TAnchors::SetBottom(const TAnchor& value)
    {
        mBottom = value;
    }
}
