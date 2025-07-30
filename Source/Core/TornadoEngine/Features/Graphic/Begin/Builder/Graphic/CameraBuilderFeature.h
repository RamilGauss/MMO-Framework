/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Graphic/GuiCameraBuilderSystem.h"

namespace nsGraphicWrapper
{
    class DllExport TCameraBuilderFeature : public nsECSFramework::TFeature
    {
        TGuiCameraBuilderSystem mGuiCameraBuilderSystem;
    public:
        void InitConveyor() override;
    };
}
