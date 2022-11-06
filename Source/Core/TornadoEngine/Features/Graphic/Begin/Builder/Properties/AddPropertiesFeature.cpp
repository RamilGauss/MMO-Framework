/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AddPropertiesFeature.h"

namespace nsGraphicWrapper
{
    void TAddPropertiesFeature::InitConveyor()
    {
        Add(&mAnchorsAddSystem);
        Add(&mFocusAddSystem);
        Add(&mHorizontalAlignAddSystem);
        Add(&mMaxSizeAddSystem);
        Add(&mMinDistanceToParentAddSystem);
        Add(&mMinSizeAddSystem);
        Add(&mPositionAddSystem);
        Add(&mSizeAddSystem);
        Add(&mTitleAddSystem);
        Add(&mVerticalAlignAddSystem);
        Add(&mVisibilityAddSystem);
    }
}