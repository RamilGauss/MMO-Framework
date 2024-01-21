/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Features/Graphic/Begin/UpdateToModule/AnchorsUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/FocusUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/HorizontalAlignUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/MaxSizeUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/MinDistanceToParentUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/MinSizeUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/PositionUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/SizeUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/TitleUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/VerticalAlignUpdateSystem.h"
#include "Features/Graphic/Begin/UpdateToModule/VisibilityUpdateSystem.h"

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