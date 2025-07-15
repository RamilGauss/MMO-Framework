/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Anchors.h"

namespace nsImGuiWidgets
{
    bool TAnchors::IsAnyAnchor() const
    {
        return mLeftAnchor.isUsed | mRightAnchor.isUsed | mTopAnchor.isUsed| mBottomAnchor.isUsed;
    }

    TAnchors::TAnchor TAnchors::GetLeftAnchor() const
    {
        return mLeftAnchor;
    }

    TAnchors::TAnchor TAnchors::GetRightAnchor() const
    {
        return mRightAnchor;
    }

    TAnchors::TAnchor TAnchors::GetTopAnchor() const
    {
        return mTopAnchor;
    }

    TAnchors::TAnchor TAnchors::GetBottomAnchor() const
    {
        return mBottomAnchor;
    }

    void TAnchors::SetLeftAnchor(const TAnchor& value)
    {
        mLeftAnchor = value;
    }

    void TAnchors::SetRightAnchor(const TAnchor& value)
    {
        mRightAnchor = value;
    }

    void TAnchors::SetTopAnchor(const TAnchor& value)
    {
        mTopAnchor = value;
    }

    void TAnchors::SetBottomAnchor(const TAnchor& value)
    {
        mBottomAnchor = value;
    }
}
