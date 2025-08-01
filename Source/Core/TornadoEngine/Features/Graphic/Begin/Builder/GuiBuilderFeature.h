/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/DialogBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/MainWindowBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/TreeViewBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Frames/WindowBuilderSystem.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Graphic/CameraBuilderFeature.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/AddPropertiesFeature.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/ButtonBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/InputTextBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/LabelBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/MenuNodeBuilderSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Units/TreeNodeBuilderSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiBuilderFeature : public nsECSFramework::TFeature
    {
        TDialogBuilderSystem mDialogBuilderSystem;
        TMainWindowBuilderSystem mMainWindowBuilderSystem;
        TWindowBuilderSystem mWindowBuilderSystem;
        TTreeViewBuilderSystem mTreeViewBuilderSystem;

        TAddPropertiesFeature mAddPropertiesFeature;

        TButtonBuilderSystem mButtonBuilderSystem;
        TInputTextBuilderSystem mInputTextBuilderSystem;
        TLabelBuilderSystem mLabelBuilderSystem;
        TMenuNodeBuilderSystem mMenuNodeBuilderSystem;
        TTreeNodeBuilderSystem mTreeNodeBuilderSystem;

        TCameraBuilderFeature mCameraBuilderFeature;
    public:
        void InitConveyor() override;
    };
}