/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/MinDistanceToParent.h"

namespace nsImGuiWidgets
{
    void TMinDistanceToParent::SetLeftMinDistance(int value)
    {
        mLeft = value;
    }
    //---------------------------------------------------------------------------------------
    void TMinDistanceToParent::SetTopMinDistance(int value)
    {
        mTop = value;
    }
    //---------------------------------------------------------------------------------------
    void TMinDistanceToParent::SetRightMinDistance(int value)
    {
        mRight = value;
    }
    //---------------------------------------------------------------------------------------
    void TMinDistanceToParent::SetBottomMinDistance(int value)
    {
        mBottom = value;
    }
    //---------------------------------------------------------------------------------------
    int TMinDistanceToParent::GetLeftMinDistance() const
    {
        return mLeft;
    }
    //---------------------------------------------------------------------------------------
    int TMinDistanceToParent::GetTopMinDistance() const
    {
        return mTop;
    }
    //---------------------------------------------------------------------------------------
    int TMinDistanceToParent::GetRightMinDistance() const
    {
        return mRight;
    }
    //---------------------------------------------------------------------------------------
    int TMinDistanceToParent::GetBottomMinDistance() const
    {
        return mBottom;
    }
    //---------------------------------------------------------------------------------------
}
