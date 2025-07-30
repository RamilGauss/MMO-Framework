/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/DialogMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/MainWindowMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/WindowMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/TreeViewMakerSystem.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Graphic/CameraMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Graphic/TextureMakerSystem.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/ButtonMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/InputTextMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/LabelMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/MenuNodeMakerSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/TreeNodeMakerSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TGuiMakerFeature : public nsECSFramework::TFeature
    {
        TButtonMakerSystem mButtonMakerSystem;
        TLabelMakerSystem mLabelMakerSystem;
        TMenuNodeMakerSystem mMenuNodeMakerSystem;
        TInputTextMakerSystem mInputTextMakerSystem;
        TWindowMakerSystem mWindowMakerSystem;
        TDialogMakerSystem mDialogMakerSystem;

        TTreeNodeMakerSystem mTreeNodeMakerSystem;
        TTreeViewMakerSystem mTreeViewMakerSystem;

        TMainWindowMakerSystem mMainWindowMakerSystem;
        
        TTextureMakerSystem mTextureMakerSystem;

        TCameraMakerSystem mCameraMakerSystem;
    public:
        void InitConveyor() override;
    };
}