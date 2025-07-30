/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Config.h"

#include "TornadoEngine/Components/Gui/Widgets/MenuNodeComponent.h"
#include "TornadoEngine/Handlers/Common/ILocalHandler.h"

namespace nsGuiWrapper
{
    class DllExport IMenuNodeClickHandler : public nsTornadoEngine::ILocalHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC) = 0;
    };
}
