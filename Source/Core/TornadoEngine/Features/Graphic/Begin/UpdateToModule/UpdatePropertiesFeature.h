/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Components/Gui/Properties/AnchorsUpdateSystem.h"
#include "Components/Gui/Properties/FocusUpdateSystem.h"
#include "Components/Gui/Properties/HorizontalAlignUpdateSystem.h"
#include "Components/Gui/Properties/MaxSizeUpdateSystem.h"
#include "Components/Gui/Properties/MinDistanceToParentUpdateSystem.h"
#include "Components/Gui/Properties/MinSizeUpdateSystem.h"
#include "Components/Gui/Properties/PositionUpdateSystem.h"
#include "Components/Gui/Properties/SizeUpdateSystem.h"
#include "Components/Gui/Properties/TitleUpdateSystem.h"
#include "Components/Gui/Properties/VerticalAlignUpdateSystem.h"
#include "Components/Gui/Properties/VisibilityUpdateSystem.h"

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