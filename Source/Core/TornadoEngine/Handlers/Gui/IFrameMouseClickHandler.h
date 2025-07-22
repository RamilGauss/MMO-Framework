/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Handlers/Common/ILocalHandler.h"

#include "ECS/Include/Config.h"
#include <GraphicEngine/Events.h>

namespace nsGuiWrapper
{
    class DllExport IFrameMouseClickHandler : public nsTornadoEngine::ILocalHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, nsGraphicEngine::TMouseButtonEvent event) = 0;
    };
}