/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/AnchorsAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/FocusAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/HorizontalAlignAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/MaxSizeAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/MinSizeAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/MinDistanceToParentAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/PositionAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/SizeAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/TitleAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/VerticalAlignAddSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/VisibilityAddSystem.h"

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