/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "AnchorsAddSystem.h"
#include "FocusAddSystem.h"
#include "HorizontalAlignAddSystem.h"
#include "MaxSizeAddSystem.h"
#include "MinSizeAddSystem.h"
#include "MinDistanceToParentAddSystem.h"
#include "PositionAddSystem.h"
#include "SizeAddSystem.h"
#include "TitleAddSystem.h"
#include "VerticalAlignAddSystem.h"
#include "VisibilityAddSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TAddPropertiesFeature : public nsECSFramework::TFeature
    {
        TAnchorsAddSystem mAnchorsAddSystem;
        TFocusAddSystem mFocusAddSystem;
        THorizontalAlignAddSystem mHorizontalAlignAddSystem;
        TMaxSizeAddSystem mMaxSizeAddSystem;
        TMinDistanceToParentAddSystem mMinDistanceToParentAddSystem;
        TMinSizeAddSystem mMinSizeAddSystem;
        TPositionAddSystem mPositionAddSystem;
        TSizeAddSystem mSizeAddSystem;
        TTitleAddSystem mTitleAddSystem;
        TVerticalAlignAddSystem mVerticalAlignAddSystem;
        TVisibilityAddSystem mVisibilityAddSystem;

    public:
        void InitConveyor() override;
    };
}