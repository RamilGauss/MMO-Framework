/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "AnchorsUpdateSystem.h"
#include "FocusUpdateSystem.h"
#include "HorizontalAlignUpdateSystem.h"
#include "MaxSizeUpdateSystem.h"
#include "MinDistanceToParentUpdateSystem.h"
#include "MinSizeUpdateSystem.h"
#include "PositionUpdateSystem.h"
#include "SizeUpdateSystem.h"
#include "TitleUpdateSystem.h"
#include "VerticalAlignUpdateSystem.h"
#include "VisibilityUpdateSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TUpdatePropertiesFeature : public nsECSFramework::TFeature
    {
        TAnchorsUpdateSystem mAnchorsUpdateSystem;
        TFocusUpdateSystem mFocusUpdateSystem;
        THorizontalAlignUpdateSystem mHorizontalAlignUpdateSystem;
        TMaxSizeUpdateSystem mMaxSizeUpdateSystem;
        TMinDistanceToParentUpdateSystem mMinDistanceToParentUpdateSystem;
        TMinSizeUpdateSystem mMinSizeUpdateSystem;
        TPositionUpdateSystem mPositionUpdateSystem;
        TSizeUpdateSystem mSizeUpdateSystem;
        TTitleUpdateSystem mTitleUpdateSystem;
        TVerticalAlignUpdateSystem mVerticalAlignUpdateSystem;
        TVisibilityUpdateSystem mVisibilityUpdateSystem;

    public:
        void InitConveyor() override;
    };
}