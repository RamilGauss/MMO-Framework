/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/UpdatePropertiesFeature.h"

namespace nsGraphicWrapper
{
    void TUpdatePropertiesFeature::InitConveyor()
    {
        Add(&mAnchorsUpdateSystem);
        Add(&mFocusUpdateSystem);
        Add(&mHorizontalAlignUpdateSystem);
        Add(&mMaxSizeUpdateSystem);
        Add(&mMinDistanceToParentUpdateSystem);
        Add(&mMinSizeUpdateSystem);
        Add(&mPositionUpdateSystem);
        Add(&mSizeUpdateSystem);
        Add(&mTitleUpdateSystem);
        Add(&mVerticalAlignUpdateSystem);
        Add(&mVisibilityUpdateSystem);
    }
}
