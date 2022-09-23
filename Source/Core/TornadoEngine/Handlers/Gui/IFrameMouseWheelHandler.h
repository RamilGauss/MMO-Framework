/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IHandler.h"

#include <ECS/include/Config.h>
#include <GraphicEngine/Events.h>

namespace nsGuiWrapper
{
    class DllExport IFrameMouseWheelHandler : public nsTornadoEngine::IHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, nsGraphicEngine::TMouseWheelEvent event) = 0;
    };
}